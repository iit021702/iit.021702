#include <QApplication>
#include <QtGui>
#include "mainwindow.h"

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    mainwindow window;

    if(window.readFile() == true)
    {
        window.show();
        return app.exec();
    }
    return 62097;
}
