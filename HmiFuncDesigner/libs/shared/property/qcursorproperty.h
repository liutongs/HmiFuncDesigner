#ifndef QCURSORPROPERTY_H
#define QCURSORPROPERTY_H

#include "qenumproperty.h"

class QCursorProperty :   public QEnumProperty
{
    Q_OBJECT
public:
    Q_INVOKABLE QCursorProperty(QAbstractProperty* parent = 0);

protected:
    void makeValue();
    void writeValue();
};

#endif // QCURSORPROPERTY_H

