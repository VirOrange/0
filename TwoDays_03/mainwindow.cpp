#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮 弹出对话框
    connect(ui->actionnew,&QAction::triggered,[=](){
        //对话框分类
        //模态化对话框（不可以对其他窗口进行操作 非模态对话框 （可以对其他对话框进行操作
        //模态方式创建 阻塞的功能
        // QDialog dlg(this);
        // dlg.resize(600,300);
        // dlg.exec();
        // qDebug() << "模态对话弹出了Ok";

        //创建非模态对话框
        // QDialog* dlg2 = new QDialog(this);
        // dlg2->resize(600,300);
        // dlg2->show();
        // dlg2->setAttribute(Qt::WA_DeleteOnClose);//设置属性 避免反复构建内存泄露

        //消息对话框

        // //错误对话框
        // QMessageBox::critical(this,"critical","Wrong");
        // //信息对话框
        // QMessageBox::information(this,"info","Message");
        //提问对话框
        //对应参数 父亲 标题 提示内容 按键内容 默认回车关联键
        // if(QMessageBox::Save == QMessageBox::question(this,"question","Question",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
        // {
        //     qDebug() << "save";
        // }
        // else
        // {
        //     qDebug() << "Cancel";
        // }
        //加上判断条件后方便知道用户的选择 给出提示

        //警告对话框
        //QMessageBox::warning(this,"Warning","warning");

        //其他标准对话框
        //颜色的对话框
        // QColor color = QColorDialog::getColor(QColor(255,0,0));
        // qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue();

        //文件对话框
        //父亲 标题 默认打开路径 过滤文件格式
        //返回值是文件的路径 QString
        // QString str = QFileDialog::getOpenFileName(this,"Open","C:\\Users\\ASUS\\Pictures\\Saved Pictures","(*.txt)");//加最后一个参数留下txt文件
        // qDebug() << str;

        //字体对话框
        bool flag = 1;
        QFont font = QFontDialog::getFont(&flag, QFont("华文彩云",36));
        qDebug() <<"字体: " << font.family().toUtf8().data() << "字号:" << font.pointSize() << "是否加粗:" << font.bold() << "是否倾斜:" << font.italic();


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
