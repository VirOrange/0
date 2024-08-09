#include "mwlabel.h"
#include <QDebug>
#include <QMouseEvent>

mwLabel::mwLabel(QWidget *parent)
    : QLabel{parent}
{}

//鼠标进入
void mwLabel :: enterEvent(QEvent *event)
{
    //qDebug() << "mouse enter";
}

//鼠标离开
 void mwLabel::leaveEvent(QEvent* )
{
     //qDebug() << "mouse leave";
}

//鼠标按下
void mwLabel::mousePressEvent(QMouseEvent *ev)
{
    //当鼠标左键 按下时提示信息
    if(ev->button() == Qt::LeftButton)
    {
        qDebug() << "mouse press ";
        QString str = QString ("mouse press x = %1 y = %2 ").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }

}

//鼠标释放
void mwLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug() << "mouse Release";
}

//鼠标移动
void mwLabel::mouseMoveEvent(QMouseEvent *ev)
{
    qDebug() << "Mouse Move";

}

