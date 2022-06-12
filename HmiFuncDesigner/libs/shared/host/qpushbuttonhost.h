#ifndef QPUSHBUTTONHOST_H
#define QPUSHBUTTONHOST_H

#include "qabstractbuttonhost.h"

class QPushButtonHost: public QAbstractButtonHost
{
    Q_OBJECT
public:
    Q_INVOKABLE QPushButtonHost(QAbstractHost *parent = 0);

    static QString getShowName();
    static QString getShowIcon();
    static QString getShowGroup();

protected:
    void initProperty() override;

protected:
    void createObject() override;
};

#endif // QPUSHBUTTONHOST_H
