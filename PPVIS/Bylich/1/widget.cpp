#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);
    generateGroupBox1();
    generateGroupBox2();
    generateGroupBox3();
    generateGroupBox4();
    generateGroupBox5();
}

Widget::~Widget()
{
}

void Widget::generateGroupBox1()
{
    QGroupBox* groupBox = new QGroupBox("1");
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);

    lineEdit1 = new QLineEdit();
    pushButton1 = new QPushButton("Add");
    comboBox1 = new QComboBox();

    groupBox->layout()->addWidget(lineEdit1);
    groupBox->layout()->addWidget(pushButton1);
    groupBox->layout()->addWidget(comboBox1);
    this->layout()->addWidget(groupBox);

    connect(pushButton1,SIGNAL(clicked()),this,SLOT(action1()));
}

void Widget::generateGroupBox2()
{
    QGroupBox* groupBox = new QGroupBox("2");
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    lineEdit2 = new QLineEdit();
    pushButton2 = new QPushButton("Button1");
    pushButton3 = new QPushButton("Button2");
    layout->addWidget(lineEdit2);
    layout->addWidget(pushButton2);
    layout->addWidget(pushButton3);
    this->layout()->addWidget(groupBox);

    connect(pushButton2,SIGNAL(clicked()),this,SLOT(action2_1()));
    connect(pushButton3,SIGNAL(clicked()),this,SLOT(action2_2()));
}

void Widget::generateGroupBox3()
{
    QGroupBox* groupBox = new QGroupBox("3");
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    lineEdit3 = new QLineEdit();
    pushButton4 = new QPushButton("Button");
    buttonGroup1 = new QButtonGroup();
    radioButton1 = new QRadioButton("qwe");
    radioButton2 = new QRadioButton("asd");
    radioButton3 = new QRadioButton("zxc");
    buttonGroup1->addButton(radioButton1);
    buttonGroup1->addButton(radioButton2);
    buttonGroup1->addButton(radioButton3);
    layout->addWidget(lineEdit3);
    layout->addWidget(pushButton4);
    layout->addWidget(radioButton1);
    layout->addWidget(radioButton2);
    layout->addWidget(radioButton3);
    this->layout()->addWidget(groupBox);

    buttonGroup1->setExclusive(true);

    connect(pushButton4,SIGNAL(clicked()),this,SLOT(action3()));
}

void Widget::generateGroupBox4()
{
    QGroupBox* groupBox = new QGroupBox("4");
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    lineEdit4 = new QLineEdit();
    pushButton5 = new QPushButton("Button");
    checkBox1 = new QCheckBox("qwe");
    checkBox2 = new QCheckBox("asd");
    checkBox3 = new QCheckBox("zxc");
    layout->addWidget(lineEdit4);
    layout->addWidget(pushButton5);
    layout->addWidget(checkBox1);
    layout->addWidget(checkBox2);
    layout->addWidget(checkBox3);

    this->layout()->addWidget(groupBox);

    connect(pushButton5,SIGNAL(clicked()),this,SLOT(action4()));
}

void Widget::generateGroupBox5()
{
    QGroupBox* groupBox = new QGroupBox("4");
    QVBoxLayout* layout = new QVBoxLayout();
    groupBox->setLayout(layout);
    lineEdit5 = new QLineEdit();
    pushButton6 = new QPushButton("Button");
    pushButton7 = new QPushButton("Button");
    pushButton8 = new QPushButton("Button");
    tableWidget = new QTableWidget(0,2);
    layout->addWidget(lineEdit5);
    layout->addWidget(pushButton6);
    layout->addWidget(pushButton7);
    layout->addWidget(pushButton8);
    layout->addWidget(tableWidget);

    this->layout()->addWidget(groupBox);

    connect(pushButton6,SIGNAL(clicked()),this,SLOT(action5_1()));
    connect(pushButton7,SIGNAL(clicked()),this,SLOT(action5_2()));
    connect(pushButton8,SIGNAL(clicked()),this,SLOT(action5_3()));
}

void Widget::showError(const QString &s) const
{
    QMessageBox messageBox;
    messageBox.setText(s);
    messageBox.setIcon(QMessageBox::Critical);
    messageBox.addButton(QMessageBox::Ok);
    messageBox.exec();
}

void Widget::action1()
{
    QString text = lineEdit1->text();
    bool find = false;
    for (int i=0; i<comboBox1->count(); i++)
        if (comboBox1->itemText(i) == text)
            find = true;
    if (!find)
        comboBox1->addItem(text);
    else
        showError("This value already exist");
}

void Widget::action2_1()
{
    pushButton3->setText(lineEdit2->text());
}

void Widget::action2_2()
{
    QString tmp = pushButton2->text();
    pushButton2->setText(pushButton3->text());
    pushButton3->setText(tmp);
}

void Widget::action3()
{
    QString text = lineEdit3->text();
    QAbstractButton* foundButton = NULL;
    foreach(QAbstractButton* button, buttonGroup1->buttons())
        if (button->text() == text)
            foundButton = button;
    if (foundButton)
        foundButton->click();
    else
        showError("Value not found");
}

void Widget::action4()
{
    QString text = lineEdit4->text();
    bool showMessage = true;
    if (checkBox1->text() == text) {
        if (!checkBox1->isChecked())
            checkBox1->click();
        showMessage = false;
    }
    if (checkBox2->text() == text) {
        if (!checkBox2->isChecked())
            checkBox2->click();
        showMessage = false;
    }
    if (checkBox3->text() == text) {
        if (!checkBox3->isChecked())
            checkBox3->click();
        showMessage = false;
    }
    if (showMessage)
        showError("Value not found");
}

void Widget::action5_1()
{
    QString text = lineEdit5->text();
    if (text == "")
        showError("Text can't be blank");
    else {
        bool findPlace = false;
        for (int i=0; i<tableWidget->rowCount(); i++)
            if (tableWidget->item(i,0)) {
                if (tableWidget->item(i,0)->text() == "") {
                    tableWidget->setItem(i,0, new QTableWidgetItem(text));
                    findPlace = true;
                    break;
                }
            }
            else {
                tableWidget->setItem(i,0,new QTableWidgetItem(text));
                findPlace = true;
                break;
            }
        if (!findPlace) {
            int rows = tableWidget->rowCount();
            tableWidget->setRowCount(rows+1);
            tableWidget->setItem(rows,0,new QTableWidgetItem(text));
        }
    }
}

void Widget::action5_2()
{
    QList<QTableWidgetItem*> selected = tableWidget->selectedItems();
    foreach (QTableWidgetItem* item, selected) {
        QString text = item->text();
        bool findPlace = false;
        for (int i=0; i<tableWidget->rowCount(); i++)
            if (tableWidget->item(i,1)) {
                if (tableWidget->item(i,1)->text() == "") {
                    tableWidget->setItem(i,1, new QTableWidgetItem(text));
                    findPlace = true;
                    break;
                }
            }
            else {
                tableWidget->setItem(i,1,new QTableWidgetItem(text));
                findPlace = true;
                break;
            }
        if (!findPlace) {
            int rows = tableWidget->rowCount();
            tableWidget->setRowCount(rows+1);
            tableWidget->setItem(rows,1,new QTableWidgetItem(text));
        }
    }
}

void Widget::action5_3()
{
    QList<QTableWidgetItem*> selected = tableWidget->selectedItems();
    foreach (QTableWidgetItem* item, selected) {
        QString text = item->text();
        bool findPlace = false;
        for (int i=0; i<tableWidget->rowCount(); i++)
            if (tableWidget->item(i,0)) {
                if (tableWidget->item(i,0)->text() == "") {
                    tableWidget->setItem(i,0, new QTableWidgetItem(text));
                    findPlace = true;
                    break;
                }
            }
            else {
                tableWidget->setItem(i,0,new QTableWidgetItem(text));
                findPlace = true;
                break;
            }
        if (!findPlace) {
            int rows = tableWidget->rowCount();
            tableWidget->setRowCount(rows+1);
            tableWidget->setItem(rows,0,new QTableWidgetItem(text));
        }
    }
}
