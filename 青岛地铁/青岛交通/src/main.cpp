#include "QtGuiApplication.h"
#include "AfCd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//切换系统当前文件夹（.exe所在的文件夹）
	AfCd::cd();
	QApplication a(argc, argv);
	QtGuiApplication w;
	//设置主窗口无边框
	w.setWindowFlags(Qt::FramelessWindowHint);
	w.show();
	return a.exec();
}
