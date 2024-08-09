#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //栈控件使用
    //设置默认页面
    ui->stackedWidget->setCurrentIndex(2);


    //btnScr
    connect(ui->btnScr, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);

    });

    //btnTool
    connect(ui->btnTool, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);

    });

    //btnTab
    connect(ui->btnTab, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);

    });

    //下拉框
    ui->comboBox->addItem("car");
    ui->comboBox->addItem("toy");

    //点击按钮选中toy
    connect(ui->btnToy, &QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(1);
        ui->comboBox->setCurrentText("toy");
    });
}

Widget::~Widget()
{
    delete ui;
}
