#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //开始按钮是没有切换的状态，只是弹出新窗口，猜测是因为不让你说是第一个窗口，第二个按钮是切换会原来的窗口，所以重新写了一个类代表俩个不同的按钮
    //按下的按钮代表是否需要切换
    //构造函数 正常显示的图片路径 以及按下后显示的图片路径
    MyPushButton(QString normalImg, QString pressImg = "");

    //成员属性 保存用户传入的默认显示路径 以及按下显示后显示的图片路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1();//上
    void zoom2();//下

    //重写按钮的按下和释放事件
    void mousePressEvent(QMouseEvent* );
    void mouseReleaseEvent(QMouseEvent* );


signals:
};

#endif // MYPUSHBUTTON_H
