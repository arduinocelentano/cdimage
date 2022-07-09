// A tool for burning visible pictures on a compact disc surfase
// Copyright (C) 2008-2022 arduinocelentano

//This program is free software: you can redistribute it and/or modify it under the terms
//of the GNU General Public License as published by the Free Software Foundation,
//either version 3 of the License, or (at your option) any later version.

//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//See the GNU General Public License for more details.

//You should have received a copy of the GNU General Public License along with this program.
//If not, see <https://www.gnu.org/licenses/>.

//Converter does the actual job to generate Audio CD track from the image.

//The implementation of this converter if mostly based on an opensource
//project created by a person with username [undefer]. Unfortunately I can't
//find her or his github or whatever repository.
//I acknowledge and am grateful to this developer for their contributions.

#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QImage>
#include <QFile>

#define D 4
const int delays[24]=
		{ -24*(     3),   -24*( 1*D+2)+1,  8-24*( 2*D+3),  8-24*( 3*D+2)+1,
		16-24*( 4*D+3), 16-24*( 5*D+2)+1,  2-24*( 6*D+3),  2-24*( 7*D+2)+1,
		10-24*( 8*D+3), 10-24*( 9*D+2)+1, 18-24*(10*D+3), 18-24*(11*D+2)+1,

		 4-24*(16*D+1),  4-24*(17*D  )+1, 12-24*(18*D+1), 12-24*(19*D  )+1,
		20-24*(20*D+1), 20-24*(21*D  )+1,  6-24*(22*D+1),  6-24*(23*D  )+1,
		14-24*(24*D+1), 14-24*(25*D  )+1, 22-24*(26*D+1), 22-24*(27*D  )+1};
const char pallete[]={'\x10','\x21','\x28','\xAA'};
/**
	@author 
*/
class Converter : public QObject
{
Q_OBJECT
public:
	Converter(QObject *parent = 0);
	Converter(QObject *parent = 0, double tr0 = 22951.52052, double dtr = 1.3865961805, double r0 = 24.5);
	~Converter();
	double tr0(){return m_tr0;}
	double dtr(){return m_dtr;}
	double r0(){return m_r0;}
	bool mixColors(){return m_mixColors;}
	///to do: добавить проверку корректности параметров[
	void setTr0(double tr0){m_tr0 = tr0;}
	void setDtr(double dtr){m_dtr = dtr;}
	void setR0(double r0){m_r0 = r0;}
	void setMixColors(bool m){m_mixColors = m;}
	///]
    bool convert(const QImage img, const QString& filename);
signals:
    void progressChanged(int progress);
public slots:
    void cancelConverting();
private:
	double m_tr0;
	double m_dtr;
	double m_r0;
	bool m_mixColors;
    double progress;
    bool m_canceled;

	char intseq[24*28*D];
	int nh;
	int pinf;
#undef D
	char buffer[2352];
	int c;
	
	void ad (char b, QFile *file);
	inline int n2m(int n);
	void bw (char b, QFile *file);
};

#endif
