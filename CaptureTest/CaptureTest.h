#pragma once

#include <QtWidgets/QWidget>
#include "ui_CaptureTest.h"

class CaptureScreen;
class CaptureTest : public QWidget
{
	Q_OBJECT

public:
	CaptureTest(QWidget *parent = Q_NULLPTR);

private:
	// ��ؼ����¼�;
	void keyPressEvent(QKeyEvent *event);
	// ����Ctrl + Alt + D��;������ʼ��ͼ;
	void startCatureImage();
private slots:
	// ��ʾ�ڽ�����;
	void onCompleteCature(QPixmap captureImage);

private:
	Ui::CaptureTestClass ui;
	// ��ͼ����ָ��;
	CaptureScreen* m_captureHelper;
};
