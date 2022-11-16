#include "MyTip.h"
#include <QString>

MyTip::MyTip(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.tipOK, SIGNAL(clicked()), this, SLOT(OnTipOKClicked()));
	connect(ui.tipCancel, SIGNAL(clicked()), this, SLOT(OnTipCancelClicked()));
}

MyTip::~MyTip()
{
}

int MyTip::OnTipOKClicked()
{
	//��ȡcombobox�ؼ��е�վ������
	tempStationName = ui.mohu_station->currentText();
	//�رմ��ڣ�����accepted
	accept();
	return 0;
}

int MyTip::OnTipCancelClicked()
{
	//�رմ��ڣ�����rejected
	reject();
	return 0;
}

//��갴���¼�
void MyTip::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//�����϶��¼�
void MyTip::mouseMoveEvent(QMouseEvent *event)
{
	//��������������
	if (isMousePressed == true)
	{

		//����������Ļ��λ��
		QPoint curMousePoint = event->globalPos() - mousePoint;
		//�ƶ�������λ��
		move(curMousePoint);
	}
	event->accept();
}

//����ͷ��¼�
void MyTip::mouseReleaseEvent(QMouseEvent *event)
{
	//���δ����
	isMousePressed = false;
	event->accept();
}