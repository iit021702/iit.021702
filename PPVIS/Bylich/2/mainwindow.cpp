#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include "kmp.h"
#include <string>
#include <QtDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g = new Graphic();
    ui->scrollArea->setWidget(g);
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::start() {
    QString filaname = QFileDialog::getOpenFileName(this,"Choose your file", ".");
    QFile file(filaname);
    file.open(QIODevice::ReadOnly);
    text = QString(file.readAll());
    int n = ui->spinBox->value();
    for (int i=1; i<n; i++) {
        int time = getKMPTime(100);
        g->addPoint(i,time);
    }
}

string rands(int len) {
    string res;
    for (int i=0; i<len; i++) {
        res += (char)(rand()%25 + 'a');
    }
    return res;
}

int MainWindow::getKMPTime(int n) {
    char* p = const_cast<char*>(rands(n).c_str());
    char* t = const_cast<char*>(text.toStdString().c_str());
    qDebug()<<p;
    return KMP(t, p);
}
