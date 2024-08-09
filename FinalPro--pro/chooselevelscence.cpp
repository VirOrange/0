#include "chooselevelscence.h"
#include <QMenu>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QDebug>
#include <qsound.h>
#include <QLabel>
#include "playscene.h"

ChooseLevelScence::ChooseLevelScence(QWidget *parent)
    : QMainWindow{parent}
{
    //配置选择关卡场景
    this->setFixedSize(500, 800);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("SelectStage");

    //创建菜单栏
    QMenuBar* bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu* startMenu = bar->addMenu("Start");
    //创建退出菜单项
    QAction* quitAction = startMenu->addAction("Quit");

    //实现点击退出 退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //选择关卡音效
    QSound* chooseSound = new QSound(":/res/TapButtonSound.wav");
    //返回按钮音效
    QSound* backSound = new QSound(":/res/BackButtonSound.wav") ;

    //返回按钮 之间的切换
    MyPushButton* backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    //点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        qDebug() << "click back";

        //告诉主场景 我返回了 主场景监听chooselevelscence的返回按钮
        //延时发送信号 延时返回
        //播放返回音效
        backSound->play();
        QTimer::singleShot(500, this, [=](){
            emit this->chooseScenceBack();
        });

    });

    //创建选择关卡按钮
    for(int i = 0; i < 20; i ++)
    {
        MyPushButton* menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(5 + i % 4 * 120, 125 + i/4 * 120);

        //监听每一个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=](){
            QString str = QString("The task is in %1 stage").arg(i + 1);
            qDebug() <<str;

            //播放选择关卡按钮的音效
            chooseSound->play();
            //进入游戏
            this->hide();//将选择关卡的场景隐藏
            play = new PlayScene(i + 1);//创建游戏场景
             //设置游戏场景的初始位置
            play->setGeometry(this->geometry());
            play->show();//显示游戏场景

            //连接
            connect(play, &PlayScene::chooseScenceBack, [=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;//玩完这关直接删除 下次在创建
                play = NULL;
            });
        });

        QLabel* label = new QLabel;
        label->setParent(this);
        QFont font;
        font.setFamily("华文新魏");
        font.setPointSize(20);
        QString str1 = QString("%1").arg(QString::number(i));
        //将字体设置到标签控件中
        label->setFont(font);
        label->setText(str1);
        // label->setFixedSize(100,500);
        // label->move(100, 600);
        //label->setGeometry(30, this->height() - 60, 200, 50);//代替上面俩行的内容
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        //label->setText(QString::number(i + 1));
        label-> move(7 + i % 4 * 120, 130 + i/4 * 120);

        //设置label的文字对齐方式 水平居中 和 垂直居中
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        //让鼠标进行穿透 穿透后label控件才不会覆盖btn控件
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}

void ChooseLevelScence::paintEvent(QPaintEvent* )
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width()) *0.5, 30, pix.width(), pix.height(), pix);


}
