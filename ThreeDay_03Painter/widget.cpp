#include "widget.h"
#include "./ui_widget.h"
#include<QPainter>
#include<QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //连接按钮
    connect(ui->btn, &QPushButton::clicked,[=](){
        //如果要手动调用绘图事件 用update更新
        pox+=20;

        update();
    });
}

 void Widget::paintEvent(QPaintEvent* )
{
    // //实例化画家对象 this指定绘图的设备
    // QPainter painter(this);

    // //设置笔的颜色
    // QPen pen(QColor(255,0,0));
    // //设置画笔宽度
    // pen.setWidth(3);

    // //设置画笔的风格
    // pen.setStyle(Qt::DotLine);//虚线

    // //利用画刷填充颜色
    // QBrush brush(Qt::cyan);//直接用系统的设置值
    // //设置画刷的风格
    // brush.setStyle(Qt::Dense1Pattern);
    // //使用画刷
    // painter.setBrush(brush);

    // //让画家使用画笔
    // painter.setPen(pen);

    // //划线
    // painter.drawLine(QPoint(0,0), QPoint(100,100));

    // //画园 用的单词是椭圆
    // painter.drawEllipse(QPoint(100,100), 50, 50);

    // //画矩形
    // painter.drawRect(QRect(20, 20, 50, 50));

    // //画文字
    // painter.drawText(QRect(10,200,200,200), "i love you");

    /////高级设置////

    // QPainter painter(this);
    // //painter.drawEllipse(QPoint(100,50), 50, 50);

    // //设置抗锯齿功能
    // //painter.setRenderHint(QPainter::Antialiasing);
    // //painter.drawEllipse(QPoint(200,50), 50, 50);


    // //画矩形
    // painter.drawRect(QRect(20,20,50,50));

    // //移动画家
    // painter.translate(100,0);
    // painter.save();
    // painter.drawRect(QRect(20,20,50,50));

    // painter.translate(100,0);
    // //还原画家状态
    // painter.restore();//抵消抱起即移动后的状态
    // painter.drawRect(QRect(20,20,50,50));


    //利用画家画图片
    if(pox > this->width())
    {
        pox = 0;
    }
    //结合定时器 变成自动平移
    QPainter painter(this);
    painter.drawPixmap(pox, 0, QPixmap(":/881913BC0AE14C0801712E5500A580EF.jpg"));


}

Widget::~Widget()
{
    delete ui;
}
