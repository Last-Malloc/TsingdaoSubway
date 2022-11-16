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
	//�洢��ʾ�����û�ѡ���վ�����ƣ�ȷ����طŵ�վ���������
	QString tempStationName;

public:
	Ui::MyTip ui;

private slots:
	int OnTipOKClicked();
	int OnTipCancelClicked();

//���º����ͱ���������ʵ�ִ��ڵ��϶�
protected:
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	QPoint mousePoint;      //�������ڴ����λ��
	bool isMousePressed;    //����Ƿ���
};
