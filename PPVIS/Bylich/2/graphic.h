#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>
#include <QVector>

class Graphic : public QWidget
{
    Q_OBJECT
public:
    Graphic(QWidget* parent=0);
    void setZoom(int zoom);
    void addPoint(int x, int y);
protected:
    void drowAxis();
    void paintEvent(QPaintEvent *);
    int paddingX;
    int paddingY;
    int w,h;
    QPainter* painter;
    int zoom;
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    QVector<QPoint> points;
    int strelka;
    int wasX, wasY;
    void defineGeometry();
    int wasPaddingX, wasPaddingY;
};

#endif // GRAPHIC_H
