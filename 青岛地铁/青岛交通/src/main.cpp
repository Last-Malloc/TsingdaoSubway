#include "QtGuiApplication.h"
#include "AfCd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//�л�ϵͳ��ǰ�ļ��У�.exe���ڵ��ļ��У�
	AfCd::cd();
	QApplication a(argc, argv);
	QtGuiApplication w;
	//�����������ޱ߿�
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.show();
	return a.exec();
}
