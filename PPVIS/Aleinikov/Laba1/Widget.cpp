#include <QtGui>
#include "Widget.h"

Widget::Widget( QWidget *parent )
    : QWidget( parent )
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout -> addWidget( firstPart() );
    layout -> addWidget( secondPart() );
    layout -> addWidget( thirdPart() );
    layout -> addWidget( fourthPart() );
    layout -> addWidget( fifthPart() );
    setLayout( layout );
}

QGroupBox *Widget::firstPart()
{
    QGroupBox *groupBox = new QGroupBox("First part");

    lineEdit = new QLineEdit;
    button = new QPushButton( tr("&Add") );
    comboBox = new QComboBox();

    connect( button, SIGNAL( clicked() ), this, SLOT( addString_SLOT() ) );

    QVBoxLayout *box = new QVBoxLayout;

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox -> addWidget( lineEdit );
    hbox -> addWidget( button );

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox -> addWidget( comboBox );

    box -> addLayout( hbox );
    box -> addLayout( vbox );

    groupBox -> setLayout( box );

    return groupBox;
}

QGroupBox *Widget::secondPart()
{
    QGroupBox *groupBox = new QGroupBox("Second part");

    lineEdiat2 = new QLineEdit;
    button_2_1 = new QPushButton( tr("&Ok") );
    button_2_2 = new QPushButton("");

    connect( button_2_1, SIGNAL( clicked() ), this, SLOT( button1_SLOT() ) );
    connect( button_2_2, SIGNAL( clicked() ), this, SLOT( button2_SLOT() ) );


    QVBoxLayout *box = new QVBoxLayout;

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox -> addWidget( button_2_1 );
    hbox -> addWidget( button_2_2 );

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox -> addWidget( lineEdiat2 );

    box -> addLayout( vbox );
    box -> addLayout( hbox );

    groupBox -> setLayout( box );

    return groupBox;
}

QGroupBox *Widget::thirdPart()
{
    QGroupBox *groupBox = new QGroupBox("Third part");

    lineEdit3 = new QLineEdit;
    pushBatton = new QPushButton(tr("&push"));
    radioBatton1 = new QRadioButton("xxx");
    radioBatton2 = new QRadioButton("yyy");
    radioBatton3 = new QRadioButton("zzz");
    radioBatton2 -> setChecked( true );

    buttonGroup = new QButtonGroup();
    buttonGroup -> setExclusive( true );
    buttonGroup -> addButton( radioBatton1 );
    buttonGroup -> addButton( radioBatton2 );
    buttonGroup -> addButton( radioBatton3 );

    connect( pushBatton, SIGNAL( clicked() ), this, SLOT( radioButton_SLOT() ) );

    QVBoxLayout *box = new QVBoxLayout;

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox -> addWidget( lineEdit3 );
    hbox -> addWidget( pushBatton );

    QHBoxLayout *h1box = new QHBoxLayout;
    h1box -> addWidget( radioBatton1 );
    h1box -> addWidget( radioBatton2 );
    h1box -> addWidget( radioBatton3 );

    box -> addLayout( hbox );
    box -> addLayout( h1box );

    groupBox -> setLayout( box );

    buttonGroup -> setExclusive( true );

    return groupBox;
}

QGroupBox *Widget::fourthPart()
{
    QGroupBox *groupBox = new QGroupBox("Fourth part");

    lineEdit4 = new QLineEdit;
    button_4 = new QPushButton( tr("p&ush") );
    checkbox1 = new QCheckBox("xxx");
    checkbox2 = new QCheckBox("yyy");
    checkbox3 = new QCheckBox("zzz");

    connect( button_4, SIGNAL( clicked() ), this, SLOT( checkBox_SLOT() ) );

    QVBoxLayout *box = new QVBoxLayout;

    QHBoxLayout *hbox = new QHBoxLayout;
    hbox -> addWidget( lineEdit4 );
    hbox -> addWidget( button_4 );

    QHBoxLayout *h1box = new QHBoxLayout;
    h1box -> addWidget( checkbox1 );
    h1box -> addWidget( checkbox2 );

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox -> addWidget( checkbox3 );

    box -> addLayout( hbox );
    box -> addLayout( h1box );
    box -> addLayout( vbox );

    groupBox -> setLayout( box );

    return groupBox;
}

QGroupBox *Widget::fifthPart()
{
    QGroupBox *groupBox = new QGroupBox("Fifth part");

    button_5_1 = new QPushButton("Add");
    button_5_2 = new QPushButton("-->");
    button_5_3 = new QPushButton("<--");
    lineEdit5 = new QLineEdit;
    table = new QTableWidget( 0, 2 );

    connect( button_5_1, SIGNAL( clicked() ), this, SLOT( table_SLOT() ) );
    connect( button_5_2, SIGNAL( clicked() ), this, SLOT( table_1to2_SLOT() ) );
    connect( button_5_3, SIGNAL( clicked() ), this, SLOT( table_2to1_SLOT() ) );

    QHBoxLayout *vhbox = new QHBoxLayout;
    QVBoxLayout *vvbox = new QVBoxLayout;
    vvbox -> addWidget( lineEdit5 );
    vvbox -> addWidget( button_5_1 );
    vvbox -> addWidget( button_5_2 );
    vvbox -> addWidget( button_5_3 );

    QVBoxLayout *VvVBox = new QVBoxLayout;
    VvVBox -> addWidget( table );
    vhbox -> addLayout( VvVBox );
    vhbox -> addLayout( vvbox );

    groupBox -> setLayout( vhbox );

    return groupBox;
}


void Widget::addString_SLOT()
{

    QString string = lineEdit -> text();

    if( ( comboBox -> findText(string) ) < 0 )
    {
        comboBox -> addItem( string );
        lineEdit -> clear();
    }
    else
    {
        QMessageBox::warning( this, "Warning",
                             tr("The input string <b>\"%1\"</b> already exists!!!").arg( string ) );
        lineEdit -> clear();
    }
}

void Widget::button1_SLOT()
{
    QString string = lineEdiat2 -> text();
    button_2_2 -> setText( string );
    lineEdiat2 -> clear();
}

void Widget::button2_SLOT()
{
    QString string2 = button_2_1 -> text();
    QString string1 = button_2_2 -> text();

    button_2_1 -> setText( string1 );
    button_2_2 -> setText( string2 );
}

void Widget::radioButton_SLOT()
{
    QString string = lineEdit3 -> text();
    if( (radioBatton1 -> text() == string) || (radioBatton2 -> text() == string) || (radioBatton3 -> text() == string) )
    {
        if(radioBatton1 -> text() == string)
            {
                 radioBatton1 -> setChecked( true );
                 lineEdit3 -> clear();
            }
        if(radioBatton2 -> text() == string)
            {
                 radioBatton2 -> setChecked( true );
                 lineEdit3 -> clear();
            }
        if(radioBatton3 -> text() == string)
            {
                  radioBatton3 -> setChecked( true );
                  lineEdit3 -> clear();
            }
    }else
        QMessageBox::warning( this, "Warning", tr("Current text is not in LineEdit").arg(string) );
}

void Widget::checkBox_SLOT()
{
    QString string = lineEdit4 -> text();

    if( (checkbox1 -> text() == string) || (checkbox2 -> text() == string) || (checkbox3 -> text() == string) )
    {
        if( checkbox1 -> text() == string )
        {
            checkbox1 -> click();
        }

        if( checkbox2 -> text() == string )
        {
           checkbox2 -> click();
        }

        if( checkbox3 -> text() == string )
        {
            checkbox3 -> click();
        }
    }
    else
        QMessageBox::warning( this, "Warning", tr("Current text is not in LineEdit").arg(string) );
}

void Widget::table_SLOT()
{
    QString string = lineEdit5 -> text();
    int row = table -> rowCount();
    table -> setRowCount( row + 1 );
    table -> setItem( row, 0, new QTableWidgetItem(string) );

}

void Widget::table_1to2_SLOT()
{
    QList<QTableWidgetItem*> selected = table -> selectedItems();
       foreach ( QTableWidgetItem* item, selected )
           if(item && item->column() == 0 && item->text() != "")
           {
           QString string = item -> text();
           table->setItem(item->row(),1,new QTableWidgetItem(string));
           table->setItem(item->row(),0,new QTableWidgetItem(""));
           }
}

void Widget::table_2to1_SLOT()
{
    QList<QTableWidgetItem*> selected = table -> selectedItems();
        foreach ( QTableWidgetItem* item, selected )
            if(item && item->column() == 1 && item->text() != "")
            {
            QString string = item -> text();
            table->setItem(item->row(),0,new QTableWidgetItem(string));
            table->setItem(item->row(),1,new QTableWidgetItem(""));
            }
}
