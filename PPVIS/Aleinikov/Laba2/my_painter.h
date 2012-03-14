#ifndef MY_PAINTER_H
#define MY_PAINTER_H

#include <QWidget>
#include <QtGui>

class My_Painter : public QWidget
{
    Q_OBJECT
public:
    explicit My_Painter(QWidget *parent = 0);


protected:
    void paintEvent(QPaintEvent *event);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;



private:
    void drawCoordinates(QPainter &painter);
    void forCoordinates();


    QRect xBoundingRect;
    QRect yBoundingRect;



};

#endif // MY_PAINTER_H
