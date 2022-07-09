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

//This is a widget for compact disc preview

#include "cdpreview.h"
#include <QPainter>
#include <QMouseEvent>
#include <QRegion>

CDPreview::CDPreview ( QWidget* parent )
:QWidget ( parent )
{
	setMode(Progress);
}

void CDPreview::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	int side = qMin(width(), height());
//virtual coordinate system with 0,0 at center
	painter.setViewport((width() - side) / 2, (height() - side) / 2,
			     side, side);
	painter.setWindow(-6000, -6000, 12000, 12000);
	painter.setClipRect(-6000, -6000, 12000, 12000);
	draw(&painter); 
}

void CDPreview::draw(QPainter *p)
{
    QPen thickPen(palette().windowText(), 1.5);
    QPen thinPen(palette().windowText(), 0.5);
	QColor niceBlue(150, 150, 200);
//draw compact disc
	p->setPen(Qt::NoPen);
	QConicalGradient coneGradient(0, 0, -90.0);
	coneGradient.setColorAt(0.0, Qt::darkGray);
	coneGradient.setColorAt(0.2, niceBlue);
	coneGradient.setColorAt(0.5, Qt::white);
	coneGradient.setColorAt(1.0, Qt::darkGray);
	p->setBrush(Qt::darkRed);
	p->drawRect(-6000, -6000, 12000, 12000);
	p->setBrush(coneGradient);
	p->drawEllipse(-6000, -6000, 12000, 12000);
	
	QRadialGradient haloGradient(0, 0, 4400, 0, 0);
	haloGradient.setColorAt(0.0, Qt::lightGray);
	haloGradient.setColorAt(0.48, Qt::lightGray);
	haloGradient.setColorAt(0.5, Qt::white);
	haloGradient.setColorAt(0.52, niceBlue);
	p->setBrush(haloGradient);
	p->drawEllipse(-2500, -2500, 5000, 5000);
	p->setBrush(Qt::darkRed);
	p->drawEllipse(-750, -750, 1500, 1500);
	p->setBrush(QColor(100,0,0,100));
	p->drawEllipse(-2500, -2500, 5000, 5000);
//draw pixmap
    p->setOpacity(0.5);
    p->drawPixmap(m_rect,m_image);
}

void CDPreview::setPixmap(const QPixmap& pix)
{
	m_image = pix;
	QImage img = pix.toImage();
	QPainter p(&m_image);
	for(int x = 0; x<img.width(); x++)
		for(int y = 0; y<img.height();y++)
		{
			p.setPen(QColor(qGray(img.pixel(x,y)),qGray(img.pixel(x,y)),qGray(img.pixel(x,y))));
			p.drawPoint(x,y);
		}
	p.end();
	m_rect = pix.rect();
	m_rect.moveCenter(QPoint(0,0));
	update();
}

void CDPreview::mouseMoveEvent(QMouseEvent *e)
{
	int side = qMin(width(), height());
    QPoint offset = (e->pos() - m_last_click_position)*12000/side;
    m_rect.moveCenter(m_rect.center() + offset);
    m_last_click_position = e->pos();
	update();
}

void CDPreview::mouseDoubleClickEvent(QMouseEvent*)
{
    m_rect.moveCenter(QPoint(0,0));
	update();
}

void CDPreview::mousePressEvent(QMouseEvent* e)
{
    m_last_click_position = e->pos();
}


void CDPreview::wheelEvent(QWheelEvent *e)
{
    m_rect.adjust(e->angleDelta().y()*m_image.width()/1200,e->angleDelta().y()*m_image.height()/1200,-e->angleDelta().y()*m_image.width()/1200,-e->angleDelta().y()*m_image.height()/1200);
	e->accept();
	update();
}

const QImage& CDPreview::getImage()
{
	m_cdImage = QImage(3000,3000,QImage::Format_RGB32);
	QPainter painter(&m_cdImage);
	painter.setWindow(-6000, -6000, 12000, 12000);
	painter.setBrush(Qt::white);
	painter.drawRect(-6000, -6000, 12000, 12000);
	painter.drawPixmap(m_rect,m_image);
	return m_cdImage;
}
