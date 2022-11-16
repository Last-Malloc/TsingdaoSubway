#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <QPoint>
#include <QString>
#include <string>
#include <String.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//���нṹ��
typedef struct
{
    int q[10000];
    int f,r;
}queue;

//վ����Ϣ
struct
{
    int id;
    int line;
    int istransfer;
	char staname[16];
	//QPoint staPoint;
}sta[63]=
{
    {1,3,0,"�ൺ��վ"},
    {2,3,0,"��ƽ·"},
    {3,3,0,"��·"},
    {4,3,0,"����·"},
    {5,3,1,"���"},
    {6,3,0,"����Ȫ·"},
    {7,3,0,"����·"},
    {8,3,0,"��������"},
    {9,3,0,"��ɳ·"},
    {10,3,0,"˫ɽ"},
    {11,3,0,"�彭·"},
    {12,3,0,"����"},
    {13,3,0,"�ػ�·"},
    {14,3,0,"����·"},
    {15,3,0,"����·"},
    {16,3,1,"���Ĺ㳡"},
    {17,3,0,"�Ӱ���·"},
    {18,3,0,"̫ƽ�ǹ�԰"},
    {19,3,0,"��ɽ��԰"},
    {20,3,0,"��Ȫ�㳡"},
    {21,3,0,"�������"},
    {22,3,0,"�ൺվ"},
    {23,2,0,"̩ɽ·"},
    {24,2,0,"����·"},
    {25,2,0,"̨��"},
    {26,2,0,"������"},
    {27,2,0,"֥Ȫ·"},
    {28,2,0,"��ɽ��"},
    {29,2,0,"�����·"},
    {30,2,0,"����·"},
    {31,2,0,"��"},
    {32,2,0,"����·"},
    {33,2,0,"����·"},
    {34,2,0,"����·"},
    {35,2,0,"ʯ����ԡ��"},
    {36,2,1,"����·",},
    {37,2,0,"ͬ��·"},
    {38,2,0,"������·"},
    {39,2,0,"����"},
    {40,2,0,"��¥ɽ·"},
    {41,2,0,"��ɽ·"},
    {42,2,0,"��幫԰"},
    {43,11,0,"��չ����"},
    {44,11,0,"�ൺ����"},
    {45,11,0,"�ൺ�ƴ�"},
    {46,11,0,"�Ŵ�"},
    {47,11,0,"����"},
    {48,11,0,"�����ѧ"},
    {49,11,0,"����԰"},
    {50,11,0,"��լ"},
    {51,11,0,"����ˮ"},
    {52,11,0,"��ʯ"},
    {53,11,0,"����"},
    {54,11,0,"��ɽ��"},
    {55,11,0,"ɽ����ѧ"},
    {56,11,0,"��ɫ���"},
    {57,11,0,"ˮ��"},
    {58,11,0,"��������"},
    {59,11,0,"��Ȫ��"},
    {60,11,0,"����"},
    {61,11,0,"갴�"},
    {62,11,0,"Ǯ��ɽ"},
    {63,11,0,"��ɽ��"}
};

//��ʾ���ӹ�ϵ�ľ���
int nodelist[65][65];

//--------------------ȫ�ֱ���-------------------
//�洢·��ѡ���ı�
string path;
//��������
queue Q;
//����·������
int z[65];
//����·�߱���(������ţ��������·���ı��ͻ���·����Ϣ)
int finalPath[65];
int finalPath_count;
//վ������
int n;
int i,j,x,y;
//�ж��Ƿ�����ı�־
int finished;

//��Ӳ���
void enq(queue *Q,int x)
{
    Q->q[Q->r]=x;
    if(Q->r==9999)
        Q->r=0;
    else
        Q->r++;
    if(Q->r==Q->f)
        printf("�����!\n");
}
//ȡ��ͷԪ��
int front(queue *Q)
{
    if(Q->r==Q->f)
    {
        printf("front����:�ӿ�!\n");
        return 0;
    }
    else
        return Q->q[Q->f];
}
//���Ӳ���
void dep(queue *Q)
{
    if(Q->r==Q->f)
        printf("dep����:�ӿ�!\n");
    else
    {
        if(Q->f==9999)
            Q->f=0;
        else
            Q->f++;
    }
}
//�ж϶����Ƿ�Ϊ�ն���
int qempty(queue Q)
{
    if(Q.f==Q.r)
        return 1;
    else
        return 0;
}
//����ͼ��ʼ��
void readgraph()
{
    n=63;

    for(i=0;i<65;i++)
        for(j=0;j<65;j++)
            nodelist[i][j]=0;

    for(i=1;i<22;i++)
    {
        nodelist[i][i+1]=1;
        nodelist[i+1][i]=1;
    }
    for(i=23;i<41;i++)
    {
        nodelist[i][i+1]=1;
        nodelist[i+1][i]=1;
    }
    for(i=43;i<63;i++)
    {
        nodelist[i][i+1]=1;
        nodelist[i+1][i]=1;
    }

    nodelist[16][27]=1;
    nodelist[27][16]=1;
    nodelist[16][28]=1;
    nodelist[28][16]=1;
    nodelist[5][42]=1;
    nodelist[42][5]=1;
    nodelist[5][41]=1;
    nodelist[41][5]=1;
    nodelist[36][43]=1;
    nodelist[43][36]=1;

}

//Ѱ�����·��
void shortest(int a,int b)
{
    if(a==b)
        nodelist[a][a]=2;
    else
    {
        enq(&Q,a);
        nodelist[a][a]=2;
        finished=0;
        while(!qempty(Q)&&!finished)
        {
            a=front(&Q);
            dep(&Q);
            j=1;
            while(j<=n&&!finished)
            {
                if(nodelist[a][j]==1&&nodelist[j][j]!=2)
                {
                    enq(&Q,j);
                    nodelist[j][j]=2;
                    z[j]=a;
                    if(j==b)/*&&(nodelist[a][j]==1)*/
                    {
                        finished=1;
                    }

                }
                if(!finished)
                    j++;
            }
        }
        if(!finished)
            printf("û��·��!");
    }
}

//��·����Ϣ��������Ŵ�������finalPath��
void writepath(int a,int b)
{
	finalPath_count = 0;
	int ii = b;
	while (ii != a)
	{
		finalPath[finalPath_count] = ii;
		finalPath_count++;
		ii = z[ii];
	}
	finalPath[finalPath_count] = a;
	finalPath_count++;
	for (int i = 0; i < finalPath_count / 2; i++)
	{
		int temp = finalPath[i];
		finalPath[i] = finalPath[finalPath_count - 1 - i];
		finalPath[finalPath_count - 1 - i] =  temp;
	}
}

//��·��(1-2λ)ת��Ϊstring
string int_to_string(int a)
{
	string result;
	if (a < 10)
	{
		char ch = '0' + a;
		char str[2] = { ch,'\0' };
		result = str;
		return result;
	}
	else
	{
		int shi = a / 10;
		int ge = a % 10;
		char ch1 = '0' + shi;
		char ch2 = '0' + ge;
		char str[3] = { ch1,ch2,'\0' };
		result = str;
		return result;
	}
}
#endif // MAP_H_INCLUDED
