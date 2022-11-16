#pragma once

#include <QFrame>
#include <QString>
#include <QPoint>

class Mypen : public QFrame
{
	Q_OBJECT

public:
	Mypen(QWidget *parent);
	~Mypen();

	virtual void paintEvent(QPaintEvent *event);
	virtual void timerEvent(QTimerEvent *event);
	//是否绘制路线文本和图像信息的标志
	void setPaintFlag(int);
	//放置主窗口传来的信息的函数，依次为路线信息文本、路线选择序号数组、数组大小
	void setinfo(QString,int*,int);

private:
	//QPainter的标志
	int paintFlag;
	//路线信息文本、路线选择序号数组、数组大小
	QString text;
	int pfin[65];
	int pfin_count;
	//各个站点在背景上的位置(相对位置，单位为像素)
	QPoint m_point[63]
	{
		//青岛北站到双山站点
		QPoint(100,346),
		QPoint(188,346),
		QPoint(275,346),
		QPoint(378,346),
		QPoint(495,345),
		QPoint(494,393),
		QPoint(477,407),
		QPoint(461,421),
		QPoint(448,435),
		QPoint(433,448),
		//清江路到汇泉广场
		QPoint(417,469),
		QPoint(417,503),
		QPoint(417,527),
		QPoint(417,556),
		QPoint(417,604),
		QPoint(335,608),
		QPoint(270,648),
		QPoint(222,648),
		QPoint(178,648),
		QPoint(132,648),
		//人民会堂到高雄路
		QPoint(86,648),
		QPoint(38,648),
		QPoint(91,512),
		QPoint(160,512),
		QPoint(186,539),
		QPoint(215,569),
		QPoint(246,597),
		QPoint(375,623),
		QPoint(418,623),
		QPoint(467,621),
		//麦岛到华楼山路
		QPoint(512,621),
		QPoint(563,623),
		QPoint(592,603),
		QPoint(619,583),
		QPoint(650,560),
		QPoint(647,525),
		QPoint(647,469),
		QPoint(647,427),
		QPoint(647,388),
		QPoint(647,344),
		//枣山路到北宅
		QPoint(575,344),
		QPoint(497,271),
		QPoint(691,527),
		QPoint(739,527),
		QPoint(737,471),
		QPoint(737,434),
		QPoint(737,396),
		QPoint(737,362),
		QPoint(770,335),
		QPoint(798,319),
		//北九水到皋虞
		QPoint(831,299),
		QPoint(861,279),
		QPoint(892,259),
		QPoint(934,225),
		QPoint(932,190),
		QPoint(931,163),
		QPoint(930,141),
		QPoint(929,120),
		QPoint(928,97),
		QPoint(961,75),
		//臧村到鳌山湾
		QPoint(989,55),
		QPoint(1017,39),
		QPoint(1104,39)
	};
	//辅助点在背景上的位置(相对位置，单位为像素)
	QPoint help[4]
	{
		QPoint(272,626),//芝泉路27和五四广场16之间的辅助点
		QPoint(300,608),//延安三路17和五四广场之间的辅助点上
		QPoint(286,647),//延安三路和五四广场之间的辅助点下
		QPoint(335,623)//五四广场（长点）下部辅助点
	};
	
	//定时器ID
	int time_ID;
	//站点/路线是否绘制控制变量
	int time_flag_point;
	int time_flag_line;
};
