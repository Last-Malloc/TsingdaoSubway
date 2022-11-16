#include "Mypen.h"
#include <QPainter>
#include <QTimerEvent>
#include <QFontMetrics>
#include <cstdlib>
#include <QDateTime>

Mypen::Mypen(QWidget *parent)
	: QFrame(parent)
{
	//������ʱ��
	time_ID = startTimer(500);

	//����Ա�����ĳ�ʼ��
	time_flag_point = 1;
	time_flag_line = 1;
	paintFlag = 0;
}

Mypen::~Mypen()
{
	killTimer(time_ID);
}

//��ͼ����
void Mypen::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	//����ʱ������
	QDateTime time = QDateTime::currentDateTime();
	painter.setPen(Qt::yellow);
	QFont font("Times", 20, QFont::Bold, false);
	painter.setFont(font);
	QString qTime = time.toString("yyyy-MM-dd");
	painter.drawText(660, 670, qTime);
	qTime = time.toString("hh:mm:ss dddd");
	painter.setPen(QColor(255, 255, 255));
	painter.drawText(850, 670, qTime);

	if (paintFlag)
	{
		//����·��ѡ����ı���Ϣ
		painter.setPen(QColor(255,255,255));
		QFont font("Times", 14, QFont::Bold, false);
		painter.setFont(font);
		QTextOption option;
		option.setWrapMode(QTextOption::WrapAnywhere);
		QRect rect(10, 10, 860, this->height());
		painter.drawText(rect, text, option);

		QPen pen;
		pen.setCapStyle(Qt::RoundCap);
		//������·
		if (time_flag_line % 3)
		{
			pen.setColor(Qt::green);
			pen.setWidth(10);
			painter.setPen(pen);
			for (int i = 0; i < pfin_count - 1; i++)
			{
				if ((pfin[i] == 27 && pfin[i+1] == 16)||(pfin[i] == 16 && pfin[i+1] == 27))
				{
					painter.drawLine(m_point[26], help[0]);
					painter.drawLine(help[0], help[3]);
				}
				else if ((pfin[i] == 28 && pfin[i + 1] == 16) || (pfin[i] == 16 && pfin[i + 1] == 28))
				{
					painter.drawLine(m_point[27], help[3]);
				}
				else if ((pfin[i] == 17 && pfin[i + 1] == 16) || (pfin[i] == 16 && pfin[i + 1] == 17))
				{
					painter.drawLine(m_point[16], help[2]);
					painter.drawLine(help[2], help[1]);
					painter.drawLine(help[1], m_point[15]);
				}
				else
				{
					painter.drawLine(m_point[pfin[i] - 1], m_point[pfin[i + 1] - 1]);
				}
			}
			time_flag_line++;
		}
		else
		{
			time_flag_line++;
		}
		//����վ��
		if (time_flag_point % 4 < 2)
		{
			pen.setColor(Qt::red);
			pen.setWidth(16);
			painter.setPen(pen);
			for (int i = 0; i < pfin_count; i++)
			{
				//��������·�����⴦��
				if (pfin[i] == 5 || pfin[i] == 36)
				{
					pen.setWidth(22);
					painter.setPen(pen);
					painter.drawPoint(m_point[pfin[i] - 1]);
					pen.setWidth(16);
					painter.setPen(pen);
				}
				//���Ĺ㳡�����⴦��
				else if (pfin[i] == 16)
				{
					pen.setWidth(22);
					painter.setPen(pen);
					painter.drawLine(QPoint(335,623),QPoint(335,604));
					pen.setWidth(16);
					painter.setPen(pen);
				}
				else
				{
					painter.drawPoint(m_point[pfin[i] - 1]);
				}
			}
			time_flag_point++;
		}
		else
		{
			pen.setColor(Qt::white);
			pen.setWidth(16);
			painter.setPen(pen);
			for (int i = 0; i < pfin_count; i++)
			{
				//��������·�����⴦��
				if (pfin[i] == 5 || pfin[i] == 36)
				{
					pen.setWidth(22);
					painter.setPen(pen);
					painter.drawPoint(m_point[pfin[i] - 1]);
					pen.setWidth(16);
					painter.setPen(pen);
				}
				//���Ĺ㳡�����⴦��
				else if (pfin[i] == 16)
				{
					pen.setWidth(22);
					painter.setPen(pen);
					painter.drawLine(QPoint(335, 623), QPoint(335, 604));
					pen.setWidth(16);
					painter.setPen(pen);
				}
				else
				{
					painter.drawPoint(m_point[pfin[i] - 1]);
				}
			}
			time_flag_point++;
		}
	}
}

//ʹ�ö�ʱ��ʵ�е�Ƶ������ʽ
void Mypen::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == time_ID)
	{
		update();
	}
}

void Mypen::setinfo(QString t,int *finarr,int fin)
{
	text = "";
	text = t;
	pfin_count = 0;
	pfin_count = fin;
	for (int i = 0;i < fin;i++)
	{
		pfin[i] = finarr[i];
	}
}

void Mypen::setPaintFlag(int flag)
{
	paintFlag = flag;
}

