#ifndef MAINSCENCE_H
#define MAINSCENCE_H

#include <QMainWindow>
#include "chooselevelscence.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScence;
}
QT_END_NAMESPACE

class MainScence : public QMainWindow
{
    Q_OBJECT

public:
    MainScence(QWidget *parent = nullptr);
    ~MainScence();

    //重新paintEvent事件  画背景图
    void paintEvent(QPaintEvent* );
    ChooseLevelScence* chooseScence = NULL;

private:
    Ui::MainScence *ui;
};
#endif // MAINSCENCE_H
