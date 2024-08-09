#include "widget.h"
#include "./ui_widget.h"
#include<QPainter>
#include<QImage>
#include<qpicture.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // //Pixmap绘图 专门为平台作了显示的优化
    // QPixmap pix(300, 300);
    // //填充颜色
    // pix.fill(Qt::white);
    // //声明画家
    // QPainter painter(&pix);

    // painter.setPen(QPen(Qt::green));
    // painter.drawEllipse(QPoint(150, 150), 100, 100);

    // //保存
    // pix.save("E:\\pix.png");


    //QImage 绘图设备
    QImage img(300, 300, QImage::Format_RGB32);
    img.fill(Qt::white);

    QPainter painter(&img);
    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    img.save("E:\\img.png");


}

Widget::~Widget()
{
    delete ui;
}
