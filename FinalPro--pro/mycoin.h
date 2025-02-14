#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>


class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);

    //参数代表 传入的路径是金币还是银币
    MyCoin(QString btnImg);

    //金币的属性
    int posx;
    int posy;
    bool flag;//正反面

    //改变标志的方法
    void changeFlag();
    QTimer* timer1 = NULL;//正面翻反面党的定时器
    QTimer* timer2 = NULL;//反面翻正面的定时器

    int min = 1;
    int max = 8;

    //执行动画 标志
    bool isAnimation = false;

    //重写 按下
    void mousePressEvent(QMouseEvent* );


    //是否胜利的标志
    bool isWin = false;


signals:
};

#endif // MYCOIN_H
