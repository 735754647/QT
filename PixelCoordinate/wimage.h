#ifndef WIMAGE_H
#define WIMAGE_H

#include <QWidget>
#include <QImage>
#include <QList>
#include <QStringList>
#include <QRect>
#include <QPoint>

typedef QList<QRect*>  RectList;

class WImage : public QWidget
{
    Q_OBJECT
public:
    explicit WImage(QWidget *parent = 0);
    int currIndex()
    {
        return m_nCurrIndex;
    }

    int numImages()
    {
        return m_listImagePath.size();
    }

    QString rectsInfo();

signals:
    void arriveFirst();
    void arriveLast();
    void midPic();

public slots:
    void onBtnPreClicked();
    void onBtnNextClicked();
    void onSetImagePath(const QStringList& list);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent* e);


private:
    QList<QImage*>          m_listImages;
    QList<RectList*>        m_listRectList;
    int                     m_nCurrIndex;
    QStringList             m_listImagePath;
    QPoint                  m_pointFirst;
    QPoint                  m_pointSecond;
    bool                    m_bIsFirstPressed;

    void resizeImage(QImage *image, const QSize &newSize);

    // draw rect based on the first and second points
    void myDrawRect();

    // push rect into QList<QList<QRect*>>
    void pushBack(QRect* rect);

    // pop rect out, drop it directly
    void popBack();

    // clear points
    void clearPoints();
};

#endif // WIMAGE_H







