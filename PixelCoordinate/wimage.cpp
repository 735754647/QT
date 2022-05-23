#include "wimage.h"
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QMessageBox>
#include <QDebug>

WImage::WImage(QWidget *parent) : QWidget(parent)
{
    m_nCurrIndex    = -1;
    m_pointFirst    = QPoint(-1, -1);
    m_pointSecond   = QPoint(-1, -1);
    m_bIsFirstPressed = false;
}

void WImage::onBtnPreClicked()
{
    if (m_listImagePath.isEmpty())
    {
        return;
    }

    setFocus();
    clearPoints();

    m_nCurrIndex--;

    if (m_nCurrIndex < 0)
    {
        m_nCurrIndex = 0;
    }

    if (m_nCurrIndex == 0)
    {
        emit arriveFirst();
    }
    else
    {
        emit midPic();
    }

    update();

}

void WImage::onBtnNextClicked()
{
    if (m_listImagePath.isEmpty())
    {
        return;
    }

    setFocus();
    clearPoints();

    m_nCurrIndex++;

    if (m_nCurrIndex == m_listImagePath.size())
    {
        m_nCurrIndex--;
    }
    else if (m_nCurrIndex == m_listImages.size())
    {
        QImage* tmp = new QImage;
        tmp->load(m_listImagePath.at(m_nCurrIndex));
        m_listImages << tmp;

        // process of RECT
        RectList* rectList = new RectList;
        m_listRectList << rectList;
    }


    if (m_nCurrIndex == m_listImagePath.size()-1)
    {
        emit arriveLast();
    }
    else
    {
        emit midPic();
    }


    update();

}

void WImage::onSetImagePath(const QStringList& list)
{
    if (list.isEmpty())
    {
        return;
    }

    // 清理掉原来的
    if (!m_listImages.isEmpty())
    {
        for (int i=0; i<m_listImages.size(); ++i)
        {
            delete m_listImages.at(i);
        }

        m_listImages.clear();
        m_listImagePath.clear();

        for (int m=0; m<m_listRectList.size(); ++m)
        {
            RectList* listTmp = m_listRectList.at(m);

            if (listTmp->isEmpty())
            {
                continue;
            }

            for (int n=0; n<listTmp->size(); ++n)
            {
                delete listTmp->at(n);
            }
        }

        m_listRectList.clear();
    }

    m_listImagePath = list;

    // 指向第一个
    m_nCurrIndex = 0;

    QImage* tmp = new QImage;
    if (!tmp->load(m_listImagePath.at(m_nCurrIndex)))
    {
        qDebug() << "load failed";
    }

    m_listImages << tmp;

    QSize newSize = tmp->size().expandedTo(size());
    resizeImage(m_listImages.at(m_nCurrIndex), newSize);
    update();

    // process of RECT
    RectList* rectList = new RectList;
    m_listRectList << rectList;
}



QString WImage::rectsInfo()
{
    QString strTmp;

    for (int i=0; i<m_listImagePath.size(); ++i)
    {
        RectList* rListTmp = m_listRectList.at(i);

        if (rListTmp->isEmpty())
        {
            continue;
        }

        strTmp += m_listImagePath.at(i) + " ";
        for (int j=0; j<rListTmp->size(); ++j)
        {
            strTmp += QString::number(rListTmp->at(j)->x()) + " ";
            strTmp += QString::number(rListTmp->at(j)->y()) + " ";
            strTmp += QString::number(rListTmp->at(j)->width()) + " ";
            strTmp += QString::number(rListTmp->at(j)->height()) + " ";
        }

        strTmp += "\n";
    }

    return strTmp;
}


void WImage::paintEvent(QPaintEvent *event)
{
    if (m_nCurrIndex < 0 || m_nCurrIndex > m_listImagePath.size()-1)
    {
        return;
    }

    // draw picture
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, *m_listImages.at(m_nCurrIndex), dirtyRect);

    // draw rects
    myDrawRect();
}


void WImage::resizeEvent(QResizeEvent *event)
{
    if (m_nCurrIndex < 0)
    {
        return;
    }

    if (width() > m_listImages.at(m_nCurrIndex)->width() || height() > m_listImages.at(m_nCurrIndex)->height())
    {
        int newWidth = qMax(width() + 128, m_listImages.at(m_nCurrIndex)->width());
        int newHeight = qMax(height() + 128, m_listImages.at(m_nCurrIndex)->height());
        resizeImage( m_listImages.at(m_nCurrIndex), QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void WImage::mousePressEvent(QMouseEvent *e)
{
    if (m_listImages.isEmpty())
    {
        return;
    }

    if (!m_bIsFirstPressed)
    {
        m_pointFirst.setX(e->pos().x());
        m_pointFirst.setY(e->pos().y());
    }
    else
    {
        m_pointSecond.setX(e->pos().x());
        m_pointSecond.setY(e->pos().y());

        QRect* rect = new QRect(m_pointFirst.x(),
                                m_pointFirst.y(),
                                m_pointSecond.x()-m_pointFirst.x(),
                                m_pointSecond.y()-m_pointFirst.y());
        pushBack(rect);

        clearPoints();

        update();
    }

}

void WImage::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)

    if (m_listImages.isEmpty())
    {
        return;
    }

    m_bIsFirstPressed = !m_bIsFirstPressed;
    update();
}

void WImage::mouseMoveEvent(QMouseEvent *e)
{
    if (m_bIsFirstPressed)
    {
        m_pointSecond.setX(e->pos().x());
        m_pointSecond.setY(e->pos().y());
        update();
    }

}

void WImage::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
        case Qt::Key_Backspace:
        {
            popBack();
            clearPoints();
            update();
            break;
        }
        case Qt::Key_Left:
        case Qt::Key_Up:
        {
            onBtnPreClicked();
            break;
        }
        case Qt::Key_Right:
        case Qt::Key_Down:
        {
            onBtnNextClicked();
            break;
        }
        case Qt::Key_Enter:
        {
            break;
        }
        default:
            break;
    }
}

void WImage::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void WImage::myDrawRect()
{
    QPainter pter(this);
    pter.setPen(QPen(Qt::blue, 2, Qt::DashLine));

    // draw the stored rects
    RectList* listRectTmp = m_listRectList.at(m_nCurrIndex);
    for (int i=0; i<listRectTmp->size(); ++i)
    {
        pter.drawRect(*listRectTmp->at(i));
    }

    // draw the current rect
    if (m_pointFirst == QPoint(-1, -1) || m_pointSecond == QPoint(-1, -1))
    {
        return;
    }

    pter.drawRect(m_pointFirst.x(),
                  m_pointFirst.y(),
                  m_pointSecond.x()-m_pointFirst.x(),
                  m_pointSecond.y()-m_pointFirst.y());

}

void WImage::pushBack(QRect *rect)
{
    if (m_nCurrIndex < 0 || m_nCurrIndex >= m_listRectList.size())
    {
        return;
    }

    (m_listRectList.at(m_nCurrIndex))->append(rect);
}

void WImage::popBack()
{
    // pop the unstored points
    if (m_bIsFirstPressed)
    {
        clearPoints();
        m_bIsFirstPressed = false;
        return;
    }

    if (m_nCurrIndex < 0 || m_nCurrIndex >= m_listRectList.size() || m_listRectList.at(m_nCurrIndex)->isEmpty())
    {
        return;
    }

    delete *((m_listRectList.at(m_nCurrIndex))->end()-1);
    (m_listRectList.at(m_nCurrIndex))->removeLast();
}

void WImage::clearPoints()
{
    m_pointFirst    = QPoint(-1, -1);
    m_pointSecond   = QPoint(-1, -1);
}

