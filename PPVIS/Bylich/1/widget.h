#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void generateGroupBox1();
    void generateGroupBox2();
    void generateGroupBox3();
    void generateGroupBox4();
    void generateGroupBox5();
    void showError(const QString& s) const;

private slots:
    void action1();
    void action2_1();
    void action2_2();
    void action3();
    void action4();
    void action5_1();
    void action5_2();
    void action5_3();

protected:
    QLineEdit *lineEdit1, *lineEdit2, *lineEdit3, *lineEdit4, *lineEdit5;
    QPushButton *pushButton1, *pushButton2, *pushButton3, *pushButton4, *pushButton5, *pushButton6, *pushButton7, *pushButton8;
    QComboBox *comboBox1;
    QRadioButton *radioButton1, *radioButton2, *radioButton3;
    QButtonGroup *buttonGroup1;
    QCheckBox *checkBox1, *checkBox2, *checkBox3;
    QTableWidget *tableWidget;
};

#endif // WIDGET_H
