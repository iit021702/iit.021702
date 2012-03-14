#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtGui>
#include "my_painter.h"

class mainwindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = 0);
    bool readFile();
    void randomGenerationOfString();

private:
    QTableWidget *tWidget;
    QGroupBox *createWindowGadget();
    QGroupBox *createGraphicGadget();
    QGroupBox *createInfoMenu();
    QGroupBox *forGeneration();
    QScrollArea *createGraphicGadgetWithScrollArea();

    My_Painter* my_paint;
};

#endif // MAINWINDOW_H
