#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //重写定时器事件
    void timerEvent(QTimerEvent* ev);
    //QTimerEvent* ev;

    int id1;
    int id2;//定时器1，2的唯一标识

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
