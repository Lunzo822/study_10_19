#include "game.h"

//初始化棋盘的数据为“空格”显示
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i<ROW;i++)
	{
		for(j = 0;j<COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

//画棋盘的分割线
//假设row = 3，col = 3
//效果图如下
//“数据行”		|	  |	
//“分割行”	---|---|---
//“数据行”		|	  |	
//“分割行”	---|---|---
//“数据行”		|	  |	
void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	//开始打印
	for(i = 0;i<row;i++)		//打印行数小于row
	{
		int j = 0;
		for(j = 0;j<col;j++)		//打印列数小于col
		{
			//打印第一行的数据
			printf(" %c ",board[i][j]);		//先输入字符
			if(j<col-1)		//如果列数小于col-1，则打印“|”，即，最后一列不打印“|”
			{
				printf("|");	
			}
		}
		printf("\n");			//当一行“数据行”打印完后换行
		//打印分割行
		if(i<row-1)		//如果行数小于row-1，则打印“---|---”，即，最后一行不打印“---|---”
		{
			for(j = 0;j<col;j++)		//如果列数小于col，则打印“---”
			{
				printf("---");
				if(j<col-1)		//如果列数小于col-1，则打印“|”，即，最后一列不打印“|”
				{
					printf("|");
				}
			}
			printf("\n");			//当一行“分割行”打印完后换行
		}
	}
}


//开始下棋
//玩家落子
void PlayerMove(char board[ROW][COL],int row,int col)
{
	//输入坐标
	int x = 0;
	int y = 0;
	printf("玩家落子——>\n");
	while(1)
	{
		printf("请输入坐标：");
		scanf("%d %d",&x,&y);
		//判断输入坐标的合法性
		//为了用户的体验，数组的下标从零开始，而坐标从零开始
		if(x>=1 && x<=row && y>=1 && y<=col)		//如果xy在行列要求范围内，则判断该坐标是否为空坐标
		{
			if(board[x-1][y-1] == ' ')		//如果坐标为空，则输入“*”
			{
				board[x-1][y-1] = '*';
				break;
			}
			else		//如果坐标被占用，则提示
			{
				printf("该坐标被占用\n");
			}
		}
		else		//如果坐标超过行列要求，则提示
		{
			printf("坐标非法输入，请重新输入！！！\n");
		}
	}
}

//电脑落子
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("电脑落子中，请等待... ...\n");
	//生成随机数
	x = rand()%row;
	y = rand()%col;
	while(1)
	{
		if(board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//返回1，表明棋盘满了
//返回0，表明棋盘没满
char IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 0;i<row;i++)
	{
		for(j = 0;j<col;j++)
		{
			if(board[i][j] == ' ')
			{
				return 0;		//没满
			}
		}
	}
	return 1;		//满了
}

//判断输赢
char IsWin(char board[ROW][COL],int row,int col)
{
	int i = 0;
	//判断三个横行是否字符一样
	for(i = 0;i<row;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//判断三个纵列是否字符一样
	for(i = 0;i<col;i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断右对角线是否字符一样
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断左对角线是否字符一样
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断棋盘是否下满了（平局）
	if(1 == IsFull(board,row,col))
	{
		return 'Q';
	}
	return 'C';
}