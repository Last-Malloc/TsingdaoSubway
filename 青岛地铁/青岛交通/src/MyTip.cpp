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
	//获取combobox控件中的站点名称
	tempStationName = ui.mohu_station->currentText();
	//关闭窗口，返回accepted
	accept();
	return 0;
}

int MyTip::OnTipCancelClicked()
{
	//关闭窗口，返回rejected
	reject();
	return 0;
}

//鼠标按下事件
void MyTip::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void MyTip::mouseMoveEvent(QMouseEvent *event)
{
	//若鼠标左键被按下
	if (isMousePressed == true)
	{

		//鼠标相对于屏幕的位置
		QPoint curMousePoint = event->globalPos() - mousePoint;
		//移动主窗体位置
		move(curMousePoint);
	}
	event->accept();
}

//鼠标释放事件
void MyTip::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}