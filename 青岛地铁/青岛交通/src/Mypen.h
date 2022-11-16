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
	//�Ƿ����·���ı���ͼ����Ϣ�ı�־
	void setPaintFlag(int);
	//���������ڴ�������Ϣ�ĺ���������Ϊ·����Ϣ�ı���·��ѡ��������顢�����С
	void setinfo(QString,int*,int);

private:
	//QPainter�ı�־
	int paintFlag;
	//·����Ϣ�ı���·��ѡ��������顢�����С
	QString text;
	int pfin[65];
	int pfin_count;
	//����վ���ڱ����ϵ�λ��(���λ�ã���λΪ����)
	QPoint m_point[63]
	{
		//�ൺ��վ��˫ɽվ��
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
		//�彭·����Ȫ�㳡
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
		//������õ�����·
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
		//�󵺵���¥ɽ·
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
		//��ɽ·����լ
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
		//����ˮ������
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
		//갴嵽��ɽ��
		QPoint(989,55),
		QPoint(1017,39),
		QPoint(1104,39)
	};
	//�������ڱ����ϵ�λ��(���λ�ã���λΪ����)
	QPoint help[4]
	{
		QPoint(272,626),//֥Ȫ·27�����Ĺ㳡16֮��ĸ�����
		QPoint(300,608),//�Ӱ���·17�����Ĺ㳡֮��ĸ�������
		QPoint(286,647),//�Ӱ���·�����Ĺ㳡֮��ĸ�������
		QPoint(335,623)//���Ĺ㳡�����㣩�²�������
	};
	
	//��ʱ��ID
	int time_ID;
	//վ��/·���Ƿ���ƿ��Ʊ���
	int time_flag_point;
	int time_flag_line;
};
