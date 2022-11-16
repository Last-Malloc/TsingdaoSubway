#include "QtGuiApplication.h"
#include "map.h"
#include "patternmatch.h"
#include "GBK.h"
#include <QPoint>
#include <QString>
#include <string>
#include <string.h>
#include <QStringList>
#include <QLineEdit>
#include <QCompleter>
#include <QStringListModel>
#include <QMessageBox>

QtGuiApplication::QtGuiApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//数据成员变量的初始化
	a = 0;
	b = 0;

	//信合合槽
	connect(ui.LineStart, SIGNAL(returnPressed()), this, SLOT(OnLineStartPressed()));
	connect(ui.LineEnd, SIGNAL(returnPressed()), this, SLOT(OnLineEndPressed()));
	connect(ui.LineStart, SIGNAL(textChanged(QString)), this, SLOT(OnLineStartChanged()));
	connect(ui.LineEnd, SIGNAL(textChanged(QString)), this, SLOT(OnLineEndChanged()));
	connect(ui.btnOK, SIGNAL(clicked()), this, SLOT(OnBtnOKClicked()));
	connect(ui.close, SIGNAL(clicked()), this, SLOT(OnBtnCloseClicked()));
	connect(ui.min, SIGNAL(clicked()), this, SLOT(OnBtnMinClicked()));

	//为输入框添加自动补全功能（注意要将QCompleter添加在ui.setupUi(this);的后面）
	QCompleter *completer = new QCompleter();
	//设置匹配模式为内容匹配
	completer->setFilterMode(Qt::MatchContains);
	completer->setCompletionMode(QCompleter::PopupCompletion);
	QStringList station;	
	station << GBK::ToUnicode("青岛北站") << GBK::ToUnicode("永平路") << GBK::ToUnicode("振华路") << GBK::ToUnicode("君峰路") << GBK::ToUnicode("李村");
	station << GBK::ToUnicode("万年泉路") << GBK::ToUnicode("海游路") << GBK::ToUnicode("地铁大厦") << GBK::ToUnicode("长沙路") << GBK::ToUnicode("双山");
	station << GBK::ToUnicode("清江路") << GBK::ToUnicode("错埠岭") << GBK::ToUnicode("敦化路") << GBK::ToUnicode("宁夏路") << GBK::ToUnicode("江西路");
	station << GBK::ToUnicode("五四广场") << GBK::ToUnicode("延安三路") << GBK::ToUnicode("太平角公园") << GBK::ToUnicode("中山公园") << GBK::ToUnicode("汇泉广场");
	station << GBK::ToUnicode("人民会堂") << GBK::ToUnicode("泰山路") << GBK::ToUnicode("芝泉路") << GBK::ToUnicode("海信桥") << GBK::ToUnicode("燕儿岛路");
	station << GBK::ToUnicode("青岛站") << GBK::ToUnicode("利津路") << GBK::ToUnicode("台东") << GBK::ToUnicode("浮山所") << GBK::ToUnicode("高雄路");
	station << GBK::ToUnicode("麦岛") << GBK::ToUnicode("海游路") << GBK::ToUnicode("东韩") << GBK::ToUnicode("张村") << GBK::ToUnicode("青岛科大");
	station << GBK::ToUnicode("海川路") << GBK::ToUnicode("苗岭路") << GBK::ToUnicode("华楼山路") << GBK::ToUnicode("会展中心") << GBK::ToUnicode("世博园");
	station << GBK::ToUnicode("海安路") << GBK::ToUnicode("同安路") << GBK::ToUnicode("枣山路") << GBK::ToUnicode("枯桃") << GBK::ToUnicode("海洋大学");
	station << GBK::ToUnicode("石老人浴场") << GBK::ToUnicode("辽阳东路") << GBK::ToUnicode("李村公园") << GBK::ToUnicode("青岛二中") << GBK::ToUnicode("北宅");
	station << GBK::ToUnicode("北九水") << GBK::ToUnicode("水泊") << GBK::ToUnicode("博览中心") << GBK::ToUnicode("皋虞") << GBK::ToUnicode("钱谷山");
	station << GBK::ToUnicode("庙石") << GBK::ToUnicode("蓝色硅谷") << GBK::ToUnicode("温泉东") << GBK::ToUnicode("臧村") << GBK::ToUnicode("鳌山湾");
	station << GBK::ToUnicode("浦里") << GBK::ToUnicode("鳌山卫") << GBK::ToUnicode("山东大学");	
	QStringListModel *listModel;
	listModel = new QStringListModel(station, this);
	completer->setModel(listModel);
	//绑定到两个LineEdit输入框
	ui.LineEnd->setCompleter(completer);
	ui.LineStart->setCompleter(completer);
}

//获取起始站点标号a
int QtGuiApplication::OnLineStartPressed()
{
	a = 0;
	//初始化提示窗口，设置提示窗口半透明且无边框；
	MyTip stationTip;
	stationTip.setWindowOpacity(0.9);
	stationTip.setWindowFlags(Qt::FramelessWindowHint);

	QString Qbegin_name = ui.LineStart->text();
	string begin_name = GBK::FromUnicode(Qbegin_name);
	//输入与站点完全匹配的标志
	int allOk = 0;
	for (i = 0; i < 63; i++)
	{
		if (strcmp(begin_name.c_str(), sta[i].staname) == 0)
		{
			a = sta[i].id;
			allOk = 1;
			break;
		}
	}
	if (!allOk)
	{
		///输入与站点部分匹配的标志
		int partOk = 0;
		//将显示到提示窗口combobox控件的站点数量和名称
		int combo_count = 0;
		string com_station[63];
		//当前待进入控件站点是否已经在com_station中（1为是）
		int combo_flag;

		for (i = 0; i < 63; i++)
		{
			if (patternmatch(begin_name.c_str(), sta[i].staname))
			{
				combo_flag = 0;
				for (int j = 0; j < combo_count; j++)
				{
					if (strcmp(com_station[j].c_str(), sta[i].staname) == 0)
					{
						combo_flag = 1;
					}
				}
				if (!combo_flag)
				{
					com_station[combo_count] = sta[i].staname;
					stationTip.ui.mohu_station->addItem(GBK::ToUnicode(sta[i].staname));
					partOk = 1;
				}
			}
			if (patternmatch(sta[i].staname, begin_name.c_str()))
			{
				combo_flag = 0;
				for (int j = 0; j < combo_count; j++)
				{
					if (strcmp(com_station[j].c_str(), sta[i].staname) == 0)
					{
						combo_flag = 1;
					}
				}
				if (!combo_flag)
				{
					com_station[combo_count] = sta[i].staname;
					stationTip.ui.mohu_station->addItem(GBK::ToUnicode(sta[i].staname));
					partOk = 1;
				}
			}
		}
		/*若模糊匹配不成功，则输出错误信息提示，否则运行提示窗口，当用户点击提示窗口的
		确认键时将用户选择返回到输入框并匹配站点序号*/
		if (!partOk)
		{
			ui.LineStart->clear();
			QMessageBox::information(this, GBK::ToUnicode("起始站Error"), GBK::ToUnicode("您的输入有误，请重新输入！！！"));
		}
		else
		{
			//提示窗口的返回值
			int tipFanhu = stationTip.exec();
			if (tipFanhu == QDialog::Accepted)
			{
				QString Qtemp = stationTip.tempStationName;
				string temp = GBK::FromUnicode(Qtemp);
				ui.LineStart->setText(Qtemp);
				for (i = 0; i < 63; i++)
				{
					if (strcmp(temp.c_str(), sta[i].staname) == 0)
					{
						a = sta[i].id;
						break;
					}
				}
			}
		}
	}
	return 0;
}

//获取终止站点标号b(注释参考OnLineStartPressed)
int QtGuiApplication::LineEndIsOk()
{
	b = 0;
	MyTip stationTip;
	stationTip.setWindowOpacity(0.9);
	stationTip.setWindowFlags(Qt::FramelessWindowHint);

	QString Qend_name = ui.LineEnd->text();
	string end_name = GBK::FromUnicode(Qend_name);
	int allOk = 0;
	for (i = 0; i < 63; i++)
	{
		if (strcmp(end_name.c_str(), sta[i].staname) == 0)
		{
			b = sta[i].id;
			allOk = 1;
			break;
		}
	}
	if (!allOk)
	{
		int partOk = 0;
		int combo_count = 0;
		string com_station[63];
		int combo_flag = 0;
		for (i = 0; i < 63; i++)
		{
			if (patternmatch(end_name.c_str(), sta[i].staname))
			{
				combo_flag = 0;
				for (int j = 0; j < combo_count; j++)
				{
					if (strcmp(com_station[j].c_str(), sta[i].staname) == 0)
					{
						combo_flag = 1;
					}
				}
				if (!combo_flag)
				{
					com_station[combo_count] = sta[i].staname;
					stationTip.ui.mohu_station->addItem(GBK::ToUnicode(sta[i].staname));
					partOk = 1;
				}
			}
			if (patternmatch(sta[i].staname, end_name.c_str()))
			{
				combo_flag = 0;
				for (int j = 0; j < combo_count; j++)
				{
					if (strcmp(com_station[j].c_str(), sta[i].staname) == 0)
					{
						combo_flag = 1;
					}
				}
				if (!combo_flag)
				{
					com_station[combo_count] = sta[i].staname;
					stationTip.ui.mohu_station->addItem(GBK::ToUnicode(sta[i].staname));
					partOk = 1;
				}
			}
		}
		if (!partOk)
		{
			ui.LineEnd->clear();
			QMessageBox::information(this, GBK::ToUnicode("终点站Error"), GBK::ToUnicode("您的输入有误，请重新输入！！！"));
		}
		else
		{
			int tipFanhu = stationTip.exec();
			if (tipFanhu == QDialog::Accepted)
			{
				QString Qtemp = stationTip.tempStationName;
				string temp = GBK::FromUnicode(Qtemp);
				ui.LineEnd->setText(Qtemp);
				for (i = 0; i < 63; i++)
				{
					if (strcmp(temp.c_str(), sta[i].staname) == 0)
					{
						b = sta[i].id;
						break;
					}
				}
			}
		}
	}
	return 0;
}

int QtGuiApplication::OnLineEndPressed()
{
	OnBtnOKClicked();
	return 0;
}

int QtGuiApplication::OnBtnOKClicked()
{
	if (ui.LineStart->text().isEmpty() || ui.LineEnd->text().isEmpty())
	{
		QMessageBox::information(this, "Error", GBK::ToUnicode("起点站或终点站为空，请输入！！！"));
	}
	else
	{
		OnLineStartPressed();
		LineEndIsOk();
		if (a != 0 && b != 0)
			PathMake();
	}
	a = 0;
	b = 0;
	return 0;
}

int QtGuiApplication::PathMake()
{
	//地图初始化与最短路经选择
	readgraph();
	Q.f = 0;
	Q.r = 0;
	int aa = a;
	int bb = b;
	shortest(aa, bb);
	writepath(aa, bb);

	//将路线选择序号转化为路线选择文本信息
	QAllpath = "";
	allPath = "";
	if (finalPath_count == 2)
	{
		allPath = "(起点站)[" + int_to_string(sta[finalPath[0] - 1].line) + "号线]" + sta[finalPath[0] - 1].staname;
		allPath = allPath + "->" + sta[finalPath[1] - 1].staname + "(终点站)";
	}
	else
	{
		allPath = "(起点站)[" + int_to_string(sta[finalPath[0] - 1].line) + "号线]" + sta[finalPath[0] - 1].staname;
		for (int i = 1; i < finalPath_count - 1; i++)
		{
			if (sta[finalPath[i] - 1].istransfer && (sta[finalPath[i - 1] - 1].line != sta[finalPath[i + 1] - 1].line))
			{
				allPath = allPath + "->[换乘" + int_to_string(sta[finalPath[i + 1] - 1].line) + "号线]" + sta[finalPath[i] - 1].staname;
			}
			else
			{
				allPath = allPath + "->" + sta[finalPath[i] - 1].staname;
			}
		}
		allPath = allPath + "->" + sta[finalPath[finalPath_count - 1] - 1].staname + "(终点站)";
	}
	QAllpath = GBK::ToUnicode(allPath);

	//将所有获得和生成信息传递给绘图对象mypen作绘图处理
	ui.mypen->setPaintFlag(1);
	ui.mypen->setinfo(QAllpath,finalPath,finalPath_count);
	ui.mypen->update();
	return 0;
}

int QtGuiApplication::OnBtnCloseClicked()
{
	this->close();
	return 0;
}

int QtGuiApplication::OnBtnMinClicked()
{
	this->showMinimized();
	return 0;
}

int QtGuiApplication::OnLineStartChanged()
{
	ui.mypen->setPaintFlag(0);
	ui.mypen->update();
	return 0;
}
int QtGuiApplication::OnLineEndChanged()
{
	ui.mypen->setPaintFlag(0);
	ui.mypen->update();
	return 0;
}

//鼠标按下事件
void QtGuiApplication::mousePressEvent(QMouseEvent *event)
{
	mousePoint = event->pos();
	isMousePressed = true;
	event->accept();
}

//窗体拖动事件
void QtGuiApplication::mouseMoveEvent(QMouseEvent *event)
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
void QtGuiApplication::mouseReleaseEvent(QMouseEvent *event)
{
	//鼠标未按下
	isMousePressed = false;
	event->accept();
}

void QtGuiApplication::closeEvent(QCloseEvent *event)
{
	switch (QMessageBox::information(this, GBK::ToUnicode("提示"), GBK::ToUnicode("您确定要退出该软件?"), GBK::ToUnicode("确定"), GBK::ToUnicode("取消"), 0, 1))
	{
	case 0:event->accept();break;
	case 1:
	default:event->ignore();break;
	}
}