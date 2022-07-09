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

#include "createtrackdialog.h"
#include <QFileDialog>

CreateTrackDialog::CreateTrackDialog(QWidget* parent)
    :QDialog(parent)
{
	setupUi(this);
//todo: implement some database
    m_presets["Verbatim CD-RW Hi-Speed 8x-10x 700 MB SERL 1"] = {22951.52,1.3865961};
    m_presets["Verbatim CD-RW Hi-Speed 8x-10x 700 MB SERL 2"] = {22951.07,1.3865958};
    m_presets["eProformance CD-RW 4x-10x 700 MB Prodisk Technology Inc"] = {22936.085,1.38314};
    m_presets["TDK CD-RW 4x-12x HIGH SPEED 700MB 80MIN"] = {23000.145,1.38659775};
    QMapIterator<QString, QVector<double>> i(m_presets);
    while (i.hasNext()) {
        i.next();
        cbPresets->insertItem(0, i.key());
    }
    loadPreset(0);
    connect(tbBrowse, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(cbPresets, SIGNAL(activated(int)), this, SLOT(loadPreset(int)));
}

//select file to save
void CreateTrackDialog::selectFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"),leFileName->text(),tr("All files (*)"));
    if(!fileName.isNull())
        leFileName->setText(fileName);
}

//load parameters of selected CD
void CreateTrackDialog::loadPreset(int)
{
    leTr0->setText(QString::number(m_presets[cbPresets->currentText()][0],'g',QLocale::FloatingPointShortest));
    leDtr->setText(QString::number(m_presets[cbPresets->currentText()][1],'g',QLocale::FloatingPointShortest));
}
