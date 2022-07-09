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

#include <QFileDialog>
#include <QProgressDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "converter.h"
#include "createtrackdialog.h"

MainWindow::MainWindow(QWidget* parent)
    :QMainWindow(parent)
{
	setupUi(this);
	setCentralWidget(&centralView);
    m_path = QDir::currentPath();
	
    connect(actionLoad_image,SIGNAL(triggered()),this,SLOT(loadImage()));
    connect(actionCreate_track,SIGNAL(triggered()),this,SLOT(createTrack()));
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(about()));
}

//load image from file
void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),m_path,tr("Images (*.png *.xpm *.jpg)"));
    if(!fileName.isNull()){
        m_path = QFileInfo(fileName).path();
		centralView.setPixmap(QPixmap(fileName));
    }
}

//generate audio track from image
void MainWindow::createTrack()
{
	m_image = centralView.getImage();
	CreateTrackDialog dial(this);
	if(!dial.exec())
		return;
	Converter converter(this, dial.leTr0->text().toDouble(), dial.leDtr->text().toDouble(), dial.leR0->text().toDouble());
	converter.setMixColors(dial.cbMixColors->isChecked());
//show progress bar
    QProgressDialog progress("Generating track...", "Abort", 0, 100, this);
    progress.setWindowModality(Qt::WindowModal);
    connect(&converter, SIGNAL(progressChanged(int)), &progress, SLOT(setValue(int)));
    connect(&progress, SIGNAL(canceled()), &converter, SLOT(cancelConverting()));

    if(converter.convert(m_image, dial.leFileName->text()))
        QMessageBox::information(this, tr("Success"), tr("The track successfully created. "
                                                         "Now you should be able to burn it onto compact disc "
                                                         "with any CD burning tool you like.<br>"
                                                         "For example:<br>"
                                                         "<b>cdrecord -audio dev=CD-RW_device %1</b>").arg(dial.leFileName->text()));
    else
        QMessageBox::warning(this, tr("Stopped"), tr("Cancelled by user."));
}

void MainWindow::about(){
    QMessageBox::about(this, tr("About"), tr("<h1>CDImage</h1>"
                                             "<h2>A tool for burning pictures on a compact disc surface</h2>"
                                             "<h3>version 0.0</h3>"
                                             "Copyright (C) 2008-2022 arduinocelentano<hr>"
                                             "<font color=gray><p>This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.</p>"

                                         "<p>This program is distributed in the hope that it will be useful,"
                                         " but WITHOUT ANY WARRANTY; without even the implied warranty of"
                                         " MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the"
                                         " GNU General Public License for more details."

                                         " You should have received a copy of the GNU General Public License"
                                         " along with this program.  If not, see "
                                         "<a href=https://www.gnu.org/licenses/>https://www.gnu.org/licenses/</a>.</p></font>"
                                         ));
}
