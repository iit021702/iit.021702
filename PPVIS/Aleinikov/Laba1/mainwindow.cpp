#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    widget = new Widget;
    setCentralWidget( widget );
    createActions();
    createMenus();

    setWindowTitle("Lab number 1");
}

void MainWindow::about()
{
    QMessageBox::information( this, "About Lab number 1",
                      "Lab number 1.\n\n"
                      "Aleinikov Evgeny");
}

void MainWindow::createActions()
{
    exitAct = new QAction( tr("E&xit"), this );
    exitAct -> setShortcut( tr("Ctrl+Q", "Quit") );

    connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );

    aboutAct = new QAction( tr("&Aubout"), this );
    aboutAct -> setShortcut( Qt::Key_F1 );
    connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );

    aboutQtAct = new QAction( tr("About &Qt"), this );
    connect( aboutQtAct, SIGNAL( triggered() ), qApp, SLOT( aboutQt() ) );
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar() -> addMenu( tr("&File") );
    fileMenu->addAction(exitAct);

    menuBar() -> addSeparator();

    QMenu *helpMenu = menuBar() -> addMenu( tr("&Help") );
    helpMenu -> addAction( aboutAct );
    helpMenu -> addAction( aboutQtAct );
}
