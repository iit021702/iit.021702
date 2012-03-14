#ifndef WIDGET_H
#define WIDGET_H


#include <QtGui>
#include <QWidget>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget( QWidget *parent = 0 );

private slots:
    void  addString_SLOT();
    void  button1_SLOT();
    void  button2_SLOT();
    void  radioButton_SLOT();
    void  checkBox_SLOT();
    void  table_SLOT();
    void  table_1to2_SLOT();
    void  table_2to1_SLOT();


private:
    QGroupBox *firstPart();
    QGroupBox *secondPart();
    QGroupBox *thirdPart();
    QGroupBox *fourthPart();
    QGroupBox *fifthPart();


//-------first part---------|
    QLineEdit   *lineEdit;
    QPushButton *button;
    QComboBox   *comboBox;
//--------------------------

//-------second part--------
    QLineEdit   *lineEdiat2;
    QPushButton *button_2_1;
    QPushButton *button_2_2;
//--------------------------

//-------third part---------
    QButtonGroup *buttonGroup;
    QLineEdit    *lineEdit3;
    QPushButton  *pushBatton;
    QRadioButton *radioBatton1;
    QRadioButton *radioBatton2;
    QRadioButton *radioBatton3;
//--------------------------

//-------fourth part--------
    QLineEdit   *lineEdit4;
    QPushButton *button_4;
    QCheckBox   *checkbox1;
    QCheckBox   *checkbox2;
    QCheckBox   *checkbox3;
//--------------------------

//-------fifth part---------
    QLineEdit *lineEdit5;
    QPushButton *button_5_1;
    QPushButton *button_5_2;
    QPushButton *button_5_3;
    QTableWidget *table;
    int              leftSize;
    int              rightSize;
//--------------------------
};

#endif // WIDGET_H
