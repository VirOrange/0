#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TableWidget 控件
    //设置列数
    ui->tableWidget->setColumnCount(3);

    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "name" << "gender" << "age");

    //设置行数
    ui->tableWidget->setRowCount(5);

    // //设置正文
    // ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Bob"));


    QStringList name;
    name << "Tom" << "Bob" << "John" << "lucy" << "Amy";

    QList<QString>gender;
    gender << "m" << "m" << "m" << "w" << "w";

    for(int i = 0; i < 5; i ++ )
    {
        int j = 0;
        ui->tableWidget->setItem(i, j ++, new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i, j ++, new QTableWidgetItem(gender.at(i)));//数组越界则抛出异常  不会直接终止

        //int 转为 QString
        ui->tableWidget->setItem(i, j ++, new QTableWidgetItem(QString::number(i + 18)));
    }
}

Widget::~Widget()
{
    delete ui;
}
