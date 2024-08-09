#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击获取当前控件的值
    connect(ui->btn_get, &QPushButton::clicked,[=](){
        qDebug() << ui->widget->getNum();
    });


}

Widget::~Widget()
{
    delete ui;
}
