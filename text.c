#include"game.h"		//引用自己创建的头文件用双引号

//三子棋
void menu()
{
	printf("**************************\n");
	printf("**1 - open	0 - exit**\n");
	printf("**************************\n");
}

//游戏的算法实现
void game()
{
	int ret = 0;
	//创建数组 - 存放棋盘的信息
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while(1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//判断玩家是否赢
		ret = IsWin(board,ROW,COL);
		if(ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW,COL);
		//判断电脑是否赢
		ret = IsWin(board,ROW,COL);
		if(ret != 'C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("玩家赢了，恭喜！！！\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢了，你真菜！！！\n");
	}
	else
	{
		printf("平局，继续加油！！！\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));		//srand需要引头文件stdlib.h			time需要引头文件time.h
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("开始三子棋（新游戏）\n");
				game();
				break;
			case 0:
				printf("游戏退出\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	}while(input);
}
int main ()
{
	test();

	return 0;
}