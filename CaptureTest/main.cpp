#include "CaptureTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CaptureTest w;
	w.show();
	return a.exec();
}
