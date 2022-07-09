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

//main window class

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include "cdpreview.h"

class MainWindow: public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindow ( QWidget* parent=0 );
public slots:
    void loadImage(); //load pixmap from file
    void createTrack(); //generate track
    void about();
private:
	CDPreview centralView;
	QImage m_image;
    QString m_path;
};


#endif
