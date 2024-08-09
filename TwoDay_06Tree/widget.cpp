#include "widget.h"
#include "./ui_widget.h"
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //treeWidget树控件的使用
    //设置水平的头
    ui->treeWidget->setHeaderLabels(QStringList() << "Hero" << "Hero Introduction");

    QTreeWidgetItem* poweritem = new QTreeWidgetItem(QStringList() << "Power");
    QTreeWidgetItem* minitem = new QTreeWidgetItem(QStringList() << "Speed");
    QTreeWidgetItem* zhiitem = new QTreeWidgetItem(QStringList() << "Intelligence");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(poweritem);
    ui->treeWidget->addTopLevelItem(minitem);
    ui->treeWidget->addTopLevelItem(zhiitem);

    //追加子节点
    QStringList heroL1;
    heroL1 << "Pig: " << "is fat, aborb the hurts.";
    QTreeWidgetItem* L1item = new QTreeWidgetItem(heroL1);

    poweritem->addChild(L1item);



}

Widget::~Widget()
{
    delete ui;
}
