#include "CaptureTest.h"
#include <QKeyEvent>
#include "capturescreen.h"

CaptureTest::CaptureTest(QWidget *parent)
	: QWidget(parent)
	, m_captureHelper(NULL)
{
	ui.setupUi(this);
}

// ��ؼ����¼�;
void CaptureTest::keyPressEvent(QKeyEvent *event)
{
	// ���Ctrl + Alt + D��;
	if (event->key() == Qt::Key_D  &&  event->modifiers() == (Qt::AltModifier | Qt::ControlModifier))
	{
		startCatureImage();
	}
}

// ���� Ctrl + Alt + D������ʼ��ͼ;
void CaptureTest::startCatureImage()
{
	// �����ͼ��ť��ʼ��ͼ;
	m_captureHelper = new CaptureScreen();
	connect(m_captureHelper, SIGNAL(signalCompleteCature(QPixmap)), this, SLOT(onCompleteCature(QPixmap)));
	m_captureHelper->show();
}

// ��ʾ�ڽ�����;
void CaptureTest::onCompleteCature(QPixmap captureImage)
{
	ui.label->setPixmap(captureImage);
	m_captureHelper->deleteLater();
	m_captureHelper = NULL;
}