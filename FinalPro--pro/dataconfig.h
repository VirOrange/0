#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QWidget>
#include <QMap>
#include <QVector>

class DataConfig : public QWidget
{
    Q_OBJECT
public:
    explicit DataConfig(QWidget *parent = nullptr);
    QMap<int, QVector< QVector<int> > >mData;//双端数组 int 相当于关卡

signals:
};

#endif // DATACONFIG_H
