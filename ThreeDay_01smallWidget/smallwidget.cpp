#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    //QSpin移动 QSrcoll也跟着移动
    void(QSpinBox:: *value)(int) = &QSpinBox::valueChanged;//函数指针
    connect(ui->spinBox, value, ui->horizontalSlider, &QSlider::setValue);

    //反过来也需要一起变化
    connect(ui->horizontalSlider,&QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
