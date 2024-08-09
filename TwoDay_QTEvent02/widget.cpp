#include "widget.h"
#include "./ui_widget.h"
#include<QtEvents>
#include<QTimerEvent>
#include<QTimer>//定时器的类

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //重写定时器的事件

    //启动定时器
    id1 = startTimer(1000); //参数1 间隔 单位 毫秒
    id2 =  startTimer(2000); //参数1 间隔 单位 毫秒

    //定时器的第二种方式
    QTimer* timer = new QTimer(this);
    //启动定时器
    timer->start(500);//ms

    connect(timer, &QTimer::timeout, [=](){
        static int num3 = 1;
        ui ->label_4->setText(QString :: number(num3 ++ ));
    });

    connect(ui->btn, &QPushButton::clicked, [=]()
            {timer->stop();

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent* ev)
{
    if(ev->timerId() == id1)
    {
        static int num = 1;
        ui ->label_2->setText(QString :: number(num ++ ));
    }

    if(ev->timerId() == id2){
    //label3 每隔2s + 1
     static int num2 = 1;
    ui ->label_3->setText(QString :: number(num2 ++ ));

    }
    //

}

