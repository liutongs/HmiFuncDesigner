#ifndef QIMAGEBOX_H
#define QIMAGEBOX_H

#include <QLabel>
#include <QPaintEvent>

class QImageBox : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QString ImageFile READ getImageFile WRITE setImageFile)
    Q_PROPERTY(bool NoScale READ isNoScale WRITE setNoScale)
    Q_PROPERTY(int BoardWidth READ getBoardWidth WRITE setBoardWidth)
    Q_PROPERTY(QColor BoardColor READ getBoardColor WRITE setBoardColor)

public:
    explicit QImageBox(QWidget *parent = nullptr);

    QString getImageFile();
    void setImageFile(const QString szName);

    bool isNoScale();
    void setNoScale(bool bNoScale);

    int getBoardWidth();
    void setBoardWidth(int iWidth);

    QColor getBoardColor();
    void setBoardColor(QColor color);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QString m_szImageFile;
    QImage m_imageObj;
    bool m_bNoScale;
    int m_iBoardWidth;
    QColor m_boardColorObj;
};

#endif // QIMAGEBOX_H
