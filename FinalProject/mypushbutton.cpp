#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>//动画特效

// MyPushButton::MyPushButton(QWidget *parent)
//     : QWidget{parent}
// {}
MyPushButton ::MyPushButton(QString normalImg, QString pressImg )
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug() << "Loading Failed";
        return ;
    }

    //设置图片固定大小
    this->setFixedSize( pix.width(), pix.height());

    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");//边框零像素 变成不规则图片

    //设置图标
    this ->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));

}

void MyPushButton:: zoom1()
{
    //创建动态对象
    QPropertyAnimation* animation =new QPropertyAnimation(this, "geometry");

    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}

void MyPushButton:: zoom2()
{
    //创建动态对象
    QPropertyAnimation* animation =new QPropertyAnimation(this, "geometry");

    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}

 void MyPushButton::mousePressEvent(QMouseEvent* e)
{
     if(this->pressImgPath != "")//不为空 切换图片
    {
        QPixmap pix;
        bool ret = pix.load(pressImgPath);
        if(!ret)
        {
            qDebug() << "Loading Failed";
            return ;
        }

        //设置图片固定大小
        this->setFixedSize( pix.width(), pix.height());

        //设置不规则图片的样式
        this->setStyleSheet("QPushButton{border:0px;}");//边框零像素 变成不规则图片

        //设置图标
        this ->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));

     }

     //让父类执行其他的内容
     return QPushButton::mousePressEvent(e);
}
 void MyPushButton::mouseReleaseEvent(QMouseEvent* e)
{
     if(this->pressImgPath != "")//不为空 切换为初始图片
     {
         QPixmap pix;
         bool ret = pix.load(normalImgPath);
         if(!ret)
         {
             qDebug() << "Loading Failed";
             return ;
         }

         //设置图片固定大小
         this->setFixedSize( pix.width(), pix.height());

         //设置不规则图片的样式
         this->setStyleSheet("QPushButton{border:0px;}");//边框零像素 变成不规则图片

         //设置图标
         this ->setIcon(pix);

         //设置图标大小
         this->setIconSize(QSize(pix.width(), pix.height()));

     }

     //让父类执行其他的内容
     return QPushButton::mouseReleaseEvent(e);
}
