#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void DisplayMap();
const int completelevel=5;//总关数
int dataMap[30][20][20]= //图标和地图来自网络
{

	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,2,0,5,1,1,0,0,0,0,0,0,0,            //0:可移动 1:墙 2:目的地 3:箱子 5:人
		0,0,0,0,0,0,0,1,0,3,3,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,1,2,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,5,0,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,3,1,3,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,1,0,2,2,0,2,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,1,0,0,3,3,0,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,0,1,2,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,2,0,3,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,2,0,5,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,3,0,1,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,5,0,0,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,3,3,1,0,1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,1,0,3,0,1,0,1,2,1,0,0,0,0,0,
		0,0,0,0,0,0,1,1,1,0,1,1,1,2,1,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,0,0,0,0,2,1,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},
	{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,
		0,0,0,1,1,3,1,1,1,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,1,0,0,5,3,0,0,3,0,1,0,0,0,0,0,0,0,
		0,0,0,1,0,2,2,1,0,3,0,1,1,0,0,0,0,0,0,0,
		0,0,0,1,1,2,2,1,0,0,0,1,0,0,0,0,0,0,0,0,
		0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	}
};
int Map[20][20];
int level=0;
int x,y;
int ReadHandle()//读取键盘
{
	int HandleInit;
	HandleInit=getch();
	if(HandleInit==114)//R
		return 0;
	if(HandleInit==122)//Z
		return 10;
	if(HandleInit==120)//X
		return 11;
    if(HandleInit==224)
    {
		HandleInit=getch();
		switch(HandleInit)
		{
		case 72:return 1;//上
		case 75:return 2;//下
		case 80:return 3;//左
		case 77:return 4;//右
		}
	}
    else
		return 0;
}
void FindPlayer()
{
	int i,j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			if(Map[i][j]==5 || Map[i][j]==7)
			{
				x=i;
				y=j;
				break;
			}
}
void GameStart()
{
    int i,j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			Map[i][j]=dataMap[level][i][j];
		FindPlayer();
		DisplayMap();
		printf("第 %d 关\t\t\n\nR:重玩\tZ:上关\tX:下关\n",level+1);
}
void Handleinput(int Handle)
{
	if(Handle==1)//上
	{
        int x1,x2;
		x1=x-1;
		x2=x-2;
		if(x1<0)
			return;
		else
            if(Map[x1][y]==3 || Map[x1][y]==4)
            {
                if(Map[x2][y]==3 || Map[x2][y]==4 || Map[x2][y]==1)
                    return;
                else
                    if(Map[x2][y]==0 || Map[x2][y]==2)
                    {
                        Map[x][y]-=5;
                        if(Map[x1][y]==3)
                            Map[x1][y]=5;
                        else
                            if(Map[x][y]==4)
                                Map[x1][y]=7;
                        if(Map[x2][y]==0)
                            Map[x2][y]=3;
                        else
                            if(Map[x2][y]==2)
                                Map[x2][y]=4;
                        FindPlayer();
                    }
            }
            else
            if(Map[x1][y]==0 || Map[x1][y]==2)
            {
                Map[x][y]-=5;Map[x1][y]+=5;
                FindPlayer();
            }
	}
	else if(Handle==2) //左
	{
		int y1,y2;
		y1=y-1;
		y2=y-2;
		if(y1<0)
			return;
		else
            if(Map[x][y1]==1)
                return;
		else
            if(Map[x][y1]==3 || Map[x][y1]==4)
            {
                if(Map[x][y2]==3 || Map[x][y2]==4 || Map[x][y2]==1)
                    return;
                else
                    if(Map[x][y2]==0 ||Map[x][y2]==2)
                    {
                        Map[x][y]-=5;
                        if(Map[x][y1]==3)
                            Map[x][y1]=5;
                        else
                            if(Map[x][y1]==4)
                                Map[x][y1]=7;
                        if(Map[x][y2]==0)
                            Map[x][y2]=3;
                        else
                            if(Map[x][y2]==2)
                                Map[x][y2]=4;
                        FindPlayer();
                    }
            }
		else
            if(Map[x][y1]==0 || Map[x][y1]==2)
            {
                Map[x][y]-=5;Map[x][y1]+=5;
                FindPlayer();
            }
	}
	else if(Handle==3)//下
	{
		int x1,x2;
		x1=x+1;
		x2=x+2;
		if(x1>=20)
			return;
		else
            if(Map[x1][y]==3 || Map[x1][y]==4)
            {
                if(Map[x2][y]==3 || Map[x2][y]==4 || Map[x2][y]==1)
                    return;
                else
                    if(Map[x2][y]==0 || Map[x2][y]==2)
                    {
                        Map[x][y]-=5;
                        if(Map[x1][y]==3)
                            Map[x1][y]=5;
                        else
                            if(Map[x][y]==4)
                                Map[x1][y]=7;
                        if(Map[x2][y]==0)
                            Map[x2][y]=3;
                        else
                            if(Map[x2][y]==2)
                                Map[x2][y]=4;
                        FindPlayer();
                    }
            }
            else
            if(Map[x1][y]==0 || Map[x1][y]==2)
            {
                Map[x][y]-=5;Map[x1][y]+=5;
                FindPlayer();
            }
	}
	else if(Handle==4)//右
	{
		int y1,y2;
		y1=y+1;
		y2=y+2;
		if(y1>=20)
			return ;
		else
            if(Map[x][y1]==1)
                return;
		else
            if(Map[x][y1]==3 || Map[x][y1]==4)
            {
                if(Map[x][y2]==3 || Map[x][y2]==4 || Map[x][y2]==1)
                    return;
                else
                    if(Map[x][y2]==0 ||Map[x][y2]==2)
                    {
                        Map[x][y]-=5;
                        if(Map[x][y1]==3)
                            Map[x][y1]=5;
                        else
                            if(Map[x][y1]==4)
                                Map[x][y1]=7;
                        if(Map[x][y2]==0)
                            Map[x][y2]=3;
                        else
                            if(Map[x][y2]==2)
                                Map[x][y2]=4;
                        FindPlayer();
                    }
            }
		else
            if(Map[x][y1]==0 || Map[x][y1]==2)
            {
                Map[x][y]-=5;Map[x][y1]+=5;
                FindPlayer();
            }
	}
}
void DisplayMap()
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			switch(Map[i][j])
			{
				case 0:
					printf("  ");
				break;
				case 1:
					printf("▓");
				break;
				case 2:
					printf("※");
				break;
            	case 3:
					printf("□");
				break;
            	case 4:
					printf("■");
				break;
            	case 5:
					printf("♀");
				break;
            	case 7:
					printf("♀");
				break;
			}
		}
		printf("\n");
	}
}
int JudgeComplete()
{
	int i,j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			if(Map[i][j]==2 || Map[i][j]==3)
                return 0;
    return 1;
}

int main()
{
	int Handle,move,movex,movey;
	while(1){
		GameStart();
		move=0;
		while(1)
		{
			movex=x;
			movey=y;
			Handle=ReadHandle();
			if(1!=Handle&&2!=Handle&&3!=Handle&&4!=Handle) break;
			Handleinput(Handle);
			if(movex!=x||movey!=y)move++;
			system("cls");
			DisplayMap();
			printf("第 %d 关\n\nR:重玩\tZ:上关\tX:下关\n",level+1,move);
			if(JudgeComplete()) break;
		}
		if(Handle==10)
		{
			if(level==0)
			{
				printf("你已经到头部了!!!");
				system("pause");
			}
			else level--;
		}
		else if(Handle==11)
		{
			if (completelevel==level+1)
			{
				printf("欢迎来到ASSHOLE!!!");
				system("pause");
			}
			else level++;
		}
		else if(Handle!=0)
		{
			printf("恭喜进入下一关\n");
			level++;
			system("pause");
			system("cls");
		}
		if(level==completelevel)
		{
			printf("世界毁灭!!!\n");
			system("pause");
			return 0;
		}
		system("cls");
	}
	return 0;
}
