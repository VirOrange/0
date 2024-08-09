#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <qpushbutton.h>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>//写记事本

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);

    //菜单栏创建
    //菜单栏最多只能有一个 但是工具栏可以有很多
    QMenuBar* bar = new QMenuBar;//相当于menubar

    //将菜单栏放入到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu* fileMenu = bar ->addMenu("file");
    QMenu* editMenu = bar ->addMenu("edit");

    //创建菜单项
    QAction* openAction = fileMenu ->addAction("open");
    fileMenu ->addAction("create");
    editMenu ->addAction("edit");

    //添加分割线
    fileMenu->addSeparator();
    QAction* printAction = fileMenu->addAction("print");

    //工具栏
    QToolBar* toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolbar);//设置为左边

    //后期设置只允许左右停靠
    toolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //设置一个浮动
    toolbar->setFloatable(false);

    //设置一个移动 关闭后无法拖拽工具栏
    toolbar->setMovable(false);

    //工具栏中设置内容
    toolbar->addAction(openAction);
    //添加分割线
    toolbar->addSeparator();
    toolbar->addAction(printAction);

    //工具栏中添加控件 aa button
    QPushButton* btn = new QPushButton("aa",this);
    toolbar->addWidget(btn);

    //状态栏
    QStatusBar* stBar = statusBar();

    //放在窗口中
    setStatusBar(stBar);
    //放标签控件
    QLabel* label = new QLabel("tips", this);
    stBar->addWidget(label);//用widget

    QLabel* label2 = new QLabel("Righr tips", this);//将标签控件放在右侧
    stBar->addPermanentWidget(label2);


    //铆接部件（浮动窗口 可以有多个
    QDockWidget* dockWidget = new QDockWidget("Float", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    //设置停靠范围 后期 只允许上下
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);

    //设置中心部件 只能有一个
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);




}

MainWindow::~MainWindow() {}
