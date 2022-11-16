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

//队列结构体
typedef struct
{
    int q[10000];
    int f,r;
}queue;

//站点信息
struct
{
    int id;
    int line;
    int istransfer;
	char staname[16];
	//QPoint staPoint;
}sta[63]=
{
    {1,3,0,"青岛北站"},
    {2,3,0,"永平路"},
    {3,3,0,"振华路"},
    {4,3,0,"君峰路"},
    {5,3,1,"李村"},
    {6,3,0,"万年泉路"},
    {7,3,0,"海游路"},
    {8,3,0,"地铁大厦"},
    {9,3,0,"长沙路"},
    {10,3,0,"双山"},
    {11,3,0,"清江路"},
    {12,3,0,"错埠岭"},
    {13,3,0,"敦化路"},
    {14,3,0,"宁夏路"},
    {15,3,0,"江西路"},
    {16,3,1,"五四广场"},
    {17,3,0,"延安三路"},
    {18,3,0,"太平角公园"},
    {19,3,0,"中山公园"},
    {20,3,0,"汇泉广场"},
    {21,3,0,"人民会堂"},
    {22,3,0,"青岛站"},
    {23,2,0,"泰山路"},
    {24,2,0,"利津路"},
    {25,2,0,"台东"},
    {26,2,0,"海信桥"},
    {27,2,0,"芝泉路"},
    {28,2,0,"浮山所"},
    {29,2,0,"燕儿岛路"},
    {30,2,0,"高雄路"},
    {31,2,0,"麦岛"},
    {32,2,0,"海游路"},
    {33,2,0,"海川路"},
    {34,2,0,"海安路"},
    {35,2,0,"石老人浴场"},
    {36,2,1,"苗岭路",},
    {37,2,0,"同安路"},
    {38,2,0,"辽阳东路"},
    {39,2,0,"东韩"},
    {40,2,0,"华楼山路"},
    {41,2,0,"枣山路"},
    {42,2,0,"李村公园"},
    {43,11,0,"会展中心"},
    {44,11,0,"青岛二中"},
    {45,11,0,"青岛科大"},
    {46,11,0,"张村"},
    {47,11,0,"枯桃"},
    {48,11,0,"海洋大学"},
    {49,11,0,"世博园"},
    {50,11,0,"北宅"},
    {51,11,0,"北九水"},
    {52,11,0,"庙石"},
    {53,11,0,"浦里"},
    {54,11,0,"鳌山卫"},
    {55,11,0,"山东大学"},
    {56,11,0,"蓝色硅谷"},
    {57,11,0,"水泊"},
    {58,11,0,"博览中心"},
    {59,11,0,"温泉东"},
    {60,11,0,"皋虞"},
    {61,11,0,"臧村"},
    {62,11,0,"钱谷山"},
    {63,11,0,"鳌山湾"}
};

//表示连接关系的矩阵
int nodelist[65][65];

//--------------------全局变量-------------------
//存储路线选择文本
string path;
//队列声明
queue Q;
//决策路径保存
int z[65];
//最终路线保存(正序序号，用于输出路线文本和绘制路线信息)
int finalPath[65];
int finalPath_count;
//站点总数
int n;
int i,j,x,y;
//判断是否结束的标志
int finished;

//入队操作
void enq(queue *Q,int x)
{
    Q->q[Q->r]=x;
    if(Q->r==9999)
        Q->r=0;
    else
        Q->r++;
    if(Q->r==Q->f)
        printf("队溢出!\n");
}
//取队头元素
int front(queue *Q)
{
    if(Q->r==Q->f)
    {
        printf("front函数:队空!\n");
        return 0;
    }
    else
        return Q->q[Q->f];
}
//出队操作
void dep(queue *Q)
{
    if(Q->r==Q->f)
        printf("dep函数:队空!\n");
    else
    {
        if(Q->f==9999)
            Q->f=0;
        else
            Q->f++;
    }
}
//判断队列是否为空队列
int qempty(queue Q)
{
    if(Q.f==Q.r)
        return 1;
    else
        return 0;
}
//将地图初始化
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

//寻找最短路径
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
            printf("没有路径!");
    }
}

//将路线信息以正序序号存入数组finalPath中
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

//线路号(1-2位)转化为string
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
