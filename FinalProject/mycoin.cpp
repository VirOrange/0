#include "mycoin.h"
#include <QDebug>

// MyCoin::MyCoin(QWidget *parent)
//     : QWidget{parent}
// {}

MyCoin::MyCoin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("pic %1 loading failed").arg(btnImg);
        qDebug()<< str;
        return ;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    //初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    //监听正面翻反面的信号 翻面
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min ++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //全部翻过了， 将min重置为1
        if(this->min > this->max)
            {
            this->min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });

    //监听反面翻正面的信号 翻面
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max --);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));

        //全部翻过了， 将min重置为1
        if(this->max < this->min)
        {
            this->max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });

}

void MyCoin::changeFlag()
{
    //如果是正面， 变成反面
    if(this->flag)
    {
        //开始正面翻反面的定时器
        timer1->start(30);
        isAnimation = true;
        this->flag = false;
    }
    else
    {
        timer2->start(30);
        isAnimation = true;
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent* e)
{
    if(this->isAnimation || this->isWin)
    {
        return ;
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
