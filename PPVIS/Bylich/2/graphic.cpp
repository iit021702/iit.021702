#include "graphic.h"
#include <QtGui>
#include <QDebug>
#include <QtDebug>
#include <QPair>

Graphic::Graphic(QWidget *parent) {
    paddingX = 10;
    paddingY = -5;
    strelka = 5;
    w = h = -1;
    zoom=1;
    setGeometry(100, 100, 100, 100);
    this->setCursor(QCursor(Qt::OpenHandCursor));
}

void Graphic::defineGeometry() {
    if (w == -1 && h == -1) {
        w = this->width() - 10;
        h = this->height() - 10;
    }
}

void Graphic::paintEvent(QPaintEvent *) {
    defineGeometry();
    painter = new QPainter(this);
    painter->setBrush(Qt::NoBrush);
    painter->setPen(Qt::black);
//    оси
    QPoint top(paddingX, -paddingY);
    QPoint o(paddingX, h-paddingY);
    QPoint right(w+paddingX, h-paddingY);
    painter->drawLine(top*zoom, o*zoom);
    painter->drawLine(o*zoom, right*zoom);
//    стрелки на осях
    painter->drawLine(top*zoom, top*zoom+QPoint(-strelka, strelka));
    painter->drawLine(top*zoom, top*zoom+QPoint( strelka, strelka));
    painter->drawLine(right*zoom, right*zoom + QPoint(-strelka, -strelka));
    painter->drawLine(right*zoom, right*zoom + QPoint(-strelka,  strelka));
//    o, x, y

//    сам график
    QPoint d(paddingX*zoom, -paddingY*zoom);
    for (int i=1; i<points.size(); i++) {
        QPoint p1 = points[i]*zoom;
        QPoint p2 = points[i-1]*zoom;
        p1.setY(h*zoom- p1.y());
        p2.setY(h*zoom - p2.y());
        painter->drawLine(p1 + d, p2 + d);
    }
    painter->save();
}

void Graphic::setZoom(int zoom) {
    this->zoom = zoom;
    repaint(0,0,w,h);
}

void Graphic::mousePressEvent(QMouseEvent * event) {
    wasX = event->x();
    wasY = event->y();
    wasPaddingX = paddingX;
    wasPaddingY = paddingY;
    setCursor(Qt::ClosedHandCursor);
}

void Graphic::mouseMoveEvent(QMouseEvent *event) {
    paddingX = wasPaddingX + (event->x() - wasX);
    paddingY = wasPaddingY + (wasY - event->y());
    repaint();
}

void Graphic::addPoint(int x, int y) {
    points << QPoint(x,y);
    if (x>w) {
        setMinimumWidth(x+100);
        w = x;
    }
    if (y>h) {
        setMinimumHeight(y+100);
        h=y;
    }
    repaint();
}

void Graphic::wheelEvent(QWheelEvent *event) {
    if (event->modifiers().testFlag(Qt::ControlModifier)) {
        int delta = event->delta() > 0 ? 1 : -1;
        zoom += delta;
        repaint();
    }
}

void Graphic::mouseReleaseEvent(QMouseEvent *event) {
    setCursor(Qt::OpenHandCursor);
}
