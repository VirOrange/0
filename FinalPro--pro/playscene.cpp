#include "playscene.h"
#include <QDebug>
#include <QString>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QSound>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QPropertyAnimation>
#include "mycoin.h"
#include "dataconfig.h"

// PlayScene::PlayScene(QWidget *parent)
//     : QMainWindow{parent}
// {}

PlayScene::PlayScene(int levelNum)
{
    QString str = QString("You are in %1 stage").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum;

    //初始化游戏场景
    //设置固定大小
    this->setFixedSize(500, 800);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("CoinFlip");


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

    //返回按钮的音效
    QSound* backSound = new QSound(":/res/BackButtonSound.wav",this);
    //返金币的音效
    QSound* flipSound = new QSound(":/res/ConFlipSound.wav",this);
    //胜利的音效
    QSound* winSound = new QSound(":/res/LevelWinSound.wav", this);

    //返回按钮
    //返回按钮 之间的切换
    MyPushButton* backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    //点击返回
    connect(backBtn, &MyPushButton::clicked, [=](){
        qDebug() << "In Stage: click back";

        //播放音效
        backSound->play();
        QTimer::singleShot(500, this, [=](){
            emit this->chooseScenceBack();
        });

    });

    //显示当前关卡数
    QLabel* label = new QLabel;
    label->setParent(this);
    //设置字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str1 = QString("Level: %1").arg(this->levelIndex);
    //将字体设置到标签控件中
    label->setFont(font);
    label->setText(str1);
    // label->setFixedSize(100,500);
    // label->move(100, 600);
    label->setGeometry(30, this->height() - 60, 200, 50);//代替上面俩行的内容

    DataConfig config;
    //初始化每一个关卡的二维数组
    for(int i = 0; i < 4; i ++ )
    {
        for(int j = 0; j < 4; j ++ )
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    //胜利图片显示
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move(tmpPix.width() * 0.5 + 25, -tmpPix.height());


    //显示金币背景图案
    for(int i = 0; i < 4; i ++ )
    {
        for(int j = 0; j < 4; j ++ )
        {
            //绘制背景图片
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel* label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(11 + i * 120, 180 + j * 120);

            //创建金币
            if(this->gameArray[i][j] == 1)
            {
                //显示金币
                str = ":/res/Coin0001.png";
            }
            else
            {
                str = ":/res/Coin0008.png";
            }

            MyCoin* coin = new MyCoin(str);
            coin->setParent(this);
            coin->move(15 + i * 120, 184 + j * 120);

            //给金币属性赋值
            coin->posx = i;
            coin->posy = j;
            coin->flag = this->gameArray[i][j];//1是正面 0是反面 前面实现过01

            //将金币放入金币二维数组中 以便于后期的维护
            coinBtn[i][j] = coin;

            //点击金币 翻转
            connect(coin, &MyCoin::clicked, [=](){

                //音效播放
                flipSound->play();
                //翻转时所有按钮禁用 翻转后解开
                for(int i = 0; i < 4; i ++ )
                {
                    for(int j = 0; j < 4; j ++ )
                    {
                        coinBtn[i][j]->isWin = true;
                    }
                }

                coin->changeFlag();
                this->gameArray[i][j] =this->gameArray[i][j] == 0 ? 1 : 0;

                //翻转周围的金币
                //右边
                QTimer::singleShot(300, this, [=]()
                                   {
                                       if(coin->posx + 1 <= 3)
                                       {
                                           coinBtn[coin->posx + 1][coin->posy]->changeFlag();
                                           this->gameArray[coin->posx + 1][coin->posy] = this->gameArray[coin->posx + 1][coin->posy] == 0 ? 1 : 0;
                                       }
                                       //左边
                                       if(coin->posx - 1 >= 0)
                                       {
                                           coinBtn[coin->posx - 1][coin->posy]->changeFlag();
                                           this->gameArray[coin->posx - 1][coin->posy] = this->gameArray[coin->posx - 1][coin->posy] == 0 ? 1 : 0;
                                       }
                                       //下面
                                       if(coin->posy + 1 <= 3)
                                       {
                                           coinBtn[coin->posx][coin->posy + 1]->changeFlag();
                                           this->gameArray[coin->posx][coin->posy + 1] = this->gameArray[coin->posx][coin->posy + 1] == 0 ? 1 : 0;
                                       }
                                       //上面
                                       if(coin->posy - 1 >= 0)
                                       {
                                           coinBtn[coin->posx][coin->posy - 1]->changeFlag();
                                           this->gameArray[coin->posx][coin->posy - 1] = this->gameArray[coin->posx][coin->posy - 1] == 0 ? 1 : 0;
                                       }
                                       //防止手快造成的bug,这里解开
                                       for(int i = 0; i < 4; i ++ )
                                       {
                                           for(int j = 0; j < 4; j ++ )
                                           {
                                               coinBtn[i][j]->isWin = false;
                                           }
                                       }
                                       //判断是否胜利 每翻一次
                                       this->isWin = true;
                                       for(int i = 0; i < 4; i ++ )
                                       {
                                           for(int j = 0; j < 4; j ++ )
                                           {
                                               if(coinBtn[i][j]->flag == false)
                                               {
                                                   this->isWin = false;
                                                   break;
                                               }
                                           }
                                       }

                                       if(this->isWin == true)
                                       {
                                           qDebug() << "You Win !!";
                                           //播放音效
                                           winSound->play();

                                           //将所有的按钮胜利标志改为true 再次点击不响应 return;
                                           for(int i = 0; i < 4; i ++ )
                                           {
                                               for(int j = 0; j < 4; j ++ )
                                               {
                                                   coinBtn[i][j]->isWin = true;
                                               }
                                           }

                                           //移动胜利的图片
                                           QPropertyAnimation* animation = new QPropertyAnimation(winLabel,"geometry");
                                           //设置时间间隔
                                           animation->setDuration(1000);
                                           //设置开始位置
                                           animation->setStartValue(QRect(winLabel->x(), winLabel->y(),winLabel->width(), winLabel->height()));
                                           //设置结束位置
                                           animation->setEndValue(QRect(winLabel->x(), winLabel->y() + 175, winLabel->width(), winLabel->height()));
                                           //设置缓和曲线
                                           animation->setEasingCurve(QEasingCurve::OutBounce);
                                           //执行
                                           animation->start();
                                       }
                                   });

            });

        }
    }
}


void PlayScene::paintEvent(QPaintEvent* )
{
    //创建背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //画上背景图标
    pix.load(":/res/Title.png");
    pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(10, 30, pix);
}

