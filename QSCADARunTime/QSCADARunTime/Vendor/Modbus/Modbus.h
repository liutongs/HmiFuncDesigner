﻿#ifndef MODBUS_H
#define MODBUS_H

#include "IPort.h"
#include "DataPack.h"
#include "IOTag.h"
#include <QObject>

typedef enum _TModbusVerifyMode
{
    VerifyMode_CRC = 0,
    VerifyMode_LRC = 1
}TModbusVerifyMode;

typedef enum _TModbus_CPUMEM
{
    CM_NON = 0,
    CM_0x = 1,
    CM_1x = 2,
    CM_3x = 3,
    CM_4x = 4
}TModbus_CPUMEM;

typedef enum _TModbus_ReadWrite
{
    FLAG_NON = 0,
    FLAG_READ = 1,
    FLAG_WRITE = 2
}TModbus_ReadWrite;

class Modbus : public QObject
{
    Q_OBJECT
public:
    explicit Modbus(QObject *parent = nullptr);
    virtual ~Modbus();

public:
    void setPort(IPort *pPort);
    IPort *getPort();
    TModbus_CPUMEM getCpuMem(const QString &szRegisterArea);
    //获取功能码
    quint8 getFuncode(IOTag* pTag, TModbus_ReadWrite rw_flag);
    // 获得寄存器个数
    quint16 getRegNum(IOTag* pTag);
    // 生成modbus报文
    virtual quint16 makeMessagePackage(quint8 */* pSendData */,
                                       IOTag* /* pTag */,
                                       TModbus_ReadWrite /* RW_flag */,
                                       quint16 */* retVarLen */){return 0;}

    virtual bool isCanWrite(IOTag* /* pTag */){return false;}
    virtual int writeData(IOTag* /* pTag */){return 0;}
    virtual bool isCanRead(IOTag* /* pTag */){return false;}
    virtual int readData(IOTag* /* pTag */){return 0;}

    void set2BytesOrder(const QString &s);
    QString get2BytesOrder();
    void set3BytesOrder(const QString &s);
    QString get3BytesOrder();
    void set4BytesOrder(const QString &s);
    QString get4BytesOrder();
    void setFloatBytesOrder(const QString &s);
    QString getFloatBytesOrder();


public:
    unsigned char GetBoolValue();
    unsigned char GetBoolValue(int add);
    short GetShortValue();
    short GetShortValue(int add);
    unsigned short GetUnsignedShortValue();
    unsigned short GetUnsignedShortValue(int add);
    int GetIntValue();
    int GetIntValue(int add);
    unsigned int GetUnsignedIntValue();
    unsigned int GetUnsignedIntValue(int add);
    float GetFloatValue();
    float GetFloatValue(int add);
    void ClearBuffer();

signals:

public slots:

public:
    quint8 readDataBuffer_[512] = {0};
    quint8 writeDataBuffer_[512] = {0};
    quint8 tempBuffer_[512] = {0};

    quint8 m_pReadBuf[512] = {0};
    quint8 m_pWriteBuf[512] = {0};
    quint8 m_pDataBuf[512] = {0};
    quint8 m_pTmpBuf[1024] = {0};
    int m_iCurReadAddress;

private:
    QString str2BytesOrder_;
    QString str3BytesOrder_;
    QString str4BytesOrder_;
    QString strFloatBytesOrder_;

private:
    IPort *iFacePort_;


};


#endif // MODBUS_H
