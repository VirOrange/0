#include "widget.h"
#include "./ui_widget.h"
#include<QFileDialog>
#include<QTextCodec>
#include<QFileInfo>
#include<QDebug>
#include<QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击按钮 弹出的对话框

    connect(ui->pushButton, &QPushButton::clicked, [=](){
       QString path = QFileDialog::getOpenFileName(this,"Open", "C:\\Users\\ASUS\\Desktop\\一生一芯\\yyy.txt");

       //将路径放入文本框中
       ui->lineEdit->setText(path);

       //编码格式类
       QTextCodec* codec = QTextCodec::codecForName("utf-8");//如果是gbk格式 就需要自己指定格式

       //读取内容 放入textedit中
       //QFile默认支持的格式是utf-8
       QFile file(path);//参数是读取文件的路径
       file.open(QIODevice::ReadOnly);

       //QByteArray array = file.readAll();

       QByteArray array;
       while(!file.atEnd())
        {
           array += file.readLine();//按行读

        }
       //打开之后关闭
       file.close();

       // //进行写入操作
       // file.open(QIODevice::Append);//用追加的方式进行写
       // file.write("i love you, to heart");
       // file.close();

       //将读入的数据放入textedit中
       //ui->textEdit->setText(array);

       ui->textEdit->setText(codec->toUnicode(array));

       //QFIleinfo 文件信息类
       QFileInfo info(path);
       qDebug() << " " << info.size() << "" << info.suffix() << " " << info.fileName() << " " << info.filePath() ;
       qDebug() << " " << info.created().toString("yyyy/MM/dd hh:mm:ss");
       qDebug() << " " << info.lastModified().toString("yyyy-MM-dd hh:mm:ss");

    });
}

Widget::~Widget()
{
    delete ui;
}
