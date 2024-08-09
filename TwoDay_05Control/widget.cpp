#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置男为默认按钮
    ui->radioButton->setChecked(true);

    //选中女后打印信息
    connect(ui->rBtnWomen,&QRadioButton::clicked,[=](){
        qDebug() <<"is_Women";
    });

    //多选按钮 2是选中 0是未选中
    connect(ui->cBox, &QCheckBox::stateChanged,[=](int state){
        qDebug() << "is_good:" << state;
    });

    //利用ListWidget写诗
    // QListWidgetItem* item = new QListWidgetItem("锄禾日当午oo");
    // //放入ListWidget控件中
    // ui->listWidget->addItem(item);
    // item->setTextAlignment(Qt::AlignHCenter);

    //QStringList QList<Qstring>
    QStringList list;
    list << "锄禾日当午oo" << "汗滴禾下土oo" << "谁知盘中餐oo" << "粒粒皆辛苦oo";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
