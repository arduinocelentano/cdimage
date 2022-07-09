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

//track generation dialog

#ifndef CREATETRACKDIALOG_H
#define CREATETRACKDIALOG_H

#include "ui_createtrackdialog.h"

class CreateTrackDialog: public QDialog, public Ui::CreateTrackDialog
{
Q_OBJECT
public:
	CreateTrackDialog ( QWidget* parent=0 );
public slots:
    void selectFile(); //select file to save
    void loadPreset(int); //load values for a certain CD
private:
    QMap<QString, QVector<double>> m_presets; //known CD parameters for different brands
};


#endif
