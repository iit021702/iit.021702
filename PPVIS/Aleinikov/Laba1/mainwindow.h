#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include "Widget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

private slots:
    void about();

private:
    void createActions();
    void createMenus();


    QMenu   *fileMenu;
    QMenu   *helpMenu;
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    Widget *widget;
};

#endif // MAINWINDOW_H
