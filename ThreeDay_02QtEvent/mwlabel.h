#ifndef MWLABEL_H
#define MWLABEL_H

#include <QLabel>

class mwLabel : public QLabel
{
    Q_OBJECT
public:
    explicit mwLabel(QWidget *parent = nullptr);

    //鼠标进入事件
    void enterEvent(QEvent *event);
    //鼠标离开事件
    void leaveEvent(QEvent* );

    //鼠标的移动
    virtual void mouseMoveEvent(QMouseEvent *ev) ;
    //鼠标按下
    virtual void mousePressEvent(QMouseEvent *ev) ;
    //鼠标的释放
    virtual void mouseReleaseEvent(QMouseEvent *ev) ;

signals:
};

#endif // MWLABEL_H
