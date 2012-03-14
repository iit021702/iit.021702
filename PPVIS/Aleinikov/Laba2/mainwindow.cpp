#include "mainwindow.h"
#include "my_painter.h"
#include <QtGui>

mainwindow::mainwindow(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *menuVBox = new QHBoxLayout;
    QHBoxLayout *tableWork = new QHBoxLayout;
    tableWork->addWidget(createWindowGadget());
    QVBoxLayout *graphicWork = new QVBoxLayout;
    //my_paint = new My_Painter();
    graphicWork->addWidget(createGraphicGadget());
     //graphicWork->addWidget(my_paint);
    QVBoxLayout *info = new QVBoxLayout;
    info->addWidget(createInfoMenu());
    info->addWidget(forGeneration());
    QVBoxLayout *box = new QVBoxLayout;
    box->addLayout(graphicWork);
    box->addLayout(info);

    menuVBox->addLayout(tableWork);
    menuVBox->addLayout(box);

    setLayout(menuVBox);
    setWindowTitle(tr("Second Lab"));
    resize(620, 400);
}

QGroupBox *mainwindow::createWindowGadget()
{
    QGroupBox *groupBox = new QGroupBox("Table Gadget");
    QStringList labels;
    tWidget = new QTableWidget(0,2);

    labels << tr("Time(t)") << tr("Number(n)");
    tWidget->setHorizontalHeaderLabels(labels);

    QHBoxLayout *tWidgetLayout = new QHBoxLayout;
    tWidgetLayout->addWidget(tWidget);
    groupBox->setLayout(tWidgetLayout);

    return groupBox;
}

QGroupBox *mainwindow::createGraphicGadget()
{
    QGroupBox *groupBox = new QGroupBox("Graphic Gadget");

    my_paint = new My_Painter;


    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidget(my_paint);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(scrollArea);
    groupBox->setLayout(layout);

    return groupBox;
}

QGroupBox *mainwindow::createInfoMenu()
{
    QGroupBox *groupBox = new QGroupBox("Information");
    QLabel *label = new QLabel("Privet America : ");

    QHBoxLayout *labelwork = new QHBoxLayout;
    labelwork->addWidget(label);
    groupBox->setLayout(labelwork);
    return groupBox;
}

QGroupBox* mainwindow::forGeneration()
{
    QGroupBox *groupBox = new QGroupBox;
    QLabel *label = new QLabel("Number of elements( n ): ");
    QLineEdit *lineEdit = new QLineEdit;
    QPushButton *button = new QPushButton(tr("&Generation of the line"));
    QPushButton *button2 = new QPushButton(tr("To &construct a graph"));
    QVBoxLayout *mainBoxLayout = new QVBoxLayout;
    QHBoxLayout *labelwork = new QHBoxLayout;
    labelwork->addWidget(label);
    labelwork->addWidget(lineEdit);
    QVBoxLayout *labelwork2 = new QVBoxLayout;
    labelwork2->addWidget(button);
    labelwork2->addWidget(button2);
    mainBoxLayout->addLayout(labelwork);
    mainBoxLayout->addLayout(labelwork2);
    groupBox->setLayout(mainBoxLayout);

    return groupBox;
}

bool mainwindow::readFile()
{
    QFile file("file.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Warning", tr("File <b>\"%1\"</b> is not opened!").arg( file.fileName() ) );
        return false;
    }
    QString string = file.readLine();


    file.close();
    return true;
}

void mainwindow::randomGenerationOfString()
{

}


