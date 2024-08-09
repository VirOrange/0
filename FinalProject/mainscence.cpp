#include "mainscence.h"
#include "./ui_mainscence.h"
#include <QPainter>
#include "mypushbutton.h"
#include "chooselevelscence.h"
#include <QDebug>
#include <QTimer>

MainScence::MainScence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScence)
{
    ui->setupUi(this);

    //设置主场景
    //设置固定大小
    setFixedSize(500, 800);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币主场景");

    //退出按钮
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });

    //设置背景

    //创建画家 指定绘图设备 在重写绘画事件里面实现

    //准备开始按钮的音效
    //QSound

    //开始按钮
    MyPushButton* startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() *0.5 - startBtn->width() *0.5, this->height() * 0.7);

    //实例化选择关卡场景
    chooseScence = new ChooseLevelScence;

     //监听选择关卡的返回按钮的信号
    connect(chooseScence, &ChooseLevelScence::chooseScenceBack, this, [=](){
        chooseScence->hide();//将选择关卡场景隐藏
        this->show();//显示主界面
    });

    connect(startBtn, &MyPushButton::clicked, [=](){
        qDebug() << "clicked";
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入
        QTimer::singleShot(500,this, [=](){
            //开始进入选择关卡场景
            //自身隐藏
            this->hide();
            chooseScence->show();

        });

    });

}

MainScence::~MainScence()
{
    delete ui;
}

void MainScence:: paintEvent(QPaintEvent* )
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画上背景图标
    pix.load(":/res/Title.png");
    pix.scaled(pix.width()*2, pix.height()*2);//改变尺寸
    painter.drawPixmap(50, 100, pix);
}
