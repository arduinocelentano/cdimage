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

//This is a preview widget
//It depicts a compact disc and a pixmap on it

#ifndef CDPREVIEW_H
#define CDPREVIEW_H

#include <QWidget>

enum CDPreviewMode {Edit,Progress}; //not used currently

class CDPreview:public QWidget
{
Q_OBJECT
public:
	CDPreview(QWidget* parent = 0);
    void draw(QPainter *painter); //redraw the widget
	const QPixmap& pixmap() const {return m_image;}
    CDPreviewMode mode() const {return m_mode;} //not used currently
    void setMode(CDPreviewMode m){m_mode = m;} //not used currently
    const QImage& getImage(); //get the final image to be burnt onto CD (with needed offset and scale)
public slots:
    void setPixmap(const QPixmap&);
protected: //events
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent ( QMouseEvent * event );
	void mouseMoveEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent* event);
private:
    QPixmap m_image; //pixmap that user can manipulate
    QImage m_cdImage; //final image to be burnt (with given offset and scale)
	QRect m_rect;
	CDPreviewMode m_mode;
    QPoint m_last_click_position; //needed for pixmap dragging
};

#endif
