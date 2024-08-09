#ifndef CHOOSELEVELSCENCE_H
#define CHOOSELEVELSCENCE_H

#include <QMainWindow>
#include "playscene.h"

class ChooseLevelScence : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScence(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent* );

    //设置游戏场景对象指针
    PlayScene* play = NULL;
signals:
    //写一个自定义的信号 告诉主场景 点击了返回
    void chooseScenceBack();
};

#endif // CHOOSELEVELSCENCE_H
