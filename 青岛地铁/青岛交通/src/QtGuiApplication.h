#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication.h"
#include "MyTip.h"
#include <string>
#include <QMouseEvent>

using std::string;

class QtGuiApplication : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplicationClass ui;

	//存储起始站、终点站标号
	int a, b;
	//存储路线选择的文本信息(GBK和Unicode编码形式)
	string allPath;
	QString QAllpath;
	/*路径生成函数，将map.h中的最短路径选择函数shortest和
	writepath生成路径选择序号转化成文本信息并将序号信息传递给绘图类MyPen*/
	int PathMake();
	//关闭拦截函数
	virtual void closeEvent(QCloseEvent *event);

private slots:
	int OnLineStartPressed();
	int LineEndIsOk();
	int OnLineEndPressed();

	int OnLineStartChanged();
	int OnLineEndChanged();

	int OnBtnOKClicked();

	int OnBtnCloseClicked();
	int OnBtnMinClicked();

	//以下函数和变量均用来实现窗口的拖动
protected:
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
