#pragma once

#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include "ui_MyTip.h"

class MyTip : public QDialog
{
	Q_OBJECT

public:
	MyTip(QWidget *parent = Q_NULLPTR);
	~MyTip();
	//存储提示窗口用户选择的站点名称，确定后回放到站点输入框中
	QString tempStationName;

public:
	Ui::MyTip ui;

private slots:
	int OnTipOKClicked();
	int OnTipCancelClicked();

//以下函数和变量均用来实现窗口的拖动
protected:
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //鼠标相对于窗体的位置
	bool isMousePressed;    //鼠标是否按下
};
