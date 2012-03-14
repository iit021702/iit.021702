#include "my_painter.h"

#include <QtGui>

My_Painter::My_Painter(QWidget *parent) :
    QWidget(parent)
{
    QFont newFont = font();
    newFont.setPixelSize(12);
    setFont(newFont);

    QFontMetrics fontMetrics(newFont);
    xBoundingRect = fontMetrics.boundingRect(tr("t"));
    yBoundingRect = fontMetrics.boundingRect(tr("n"));

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidget(this);
}

void My_Painter::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    drawCoordinates(painter);
}

void My_Painter::drawCoordinates(QPainter &painter)
 {

     painter.setPen(QPen(Qt::black, 4, Qt::SolidLine));
     painter.setRenderHints(QPainter::Antialiasing, true);
     painter.drawPoint(10, 200);

     painter.setPen(Qt::black);

     painter.drawText(2 - xBoundingRect.width() / 2,
                      203 + xBoundingRect.height() / 2, tr("0") );

//---------------| t |------------------------------------------
     painter.drawLine(10, 10, 10, 200);
     painter.drawLine(10, 10, 15, 15);
     painter.drawLine(10, 10, 5, 15);
     painter.drawText( 2 - xBoundingRect.width() / 2,
                       5 + xBoundingRect.height() / 2, tr("t") );
//--------------------------------------------------------------

//---------------| n |------------------------------------------
     painter.drawLine(10, 200, 320, 200);
     painter.drawLine(320, 200, 315, 195);
     painter.drawLine(320, 200, 315, 205);
     painter.drawText(326 - yBoundingRect.width() / 2,
                      201 + yBoundingRect.height() / 2, tr("n"));
//--------------------------------------------------------------
 }

QSize My_Painter::sizeHint() const
 {
     return QSize(440, 310);
 }

QSize My_Painter::minimumSizeHint() const
{
    return QSize(250, 250);
}

void My_Painter::forCoordinates()
{

}


