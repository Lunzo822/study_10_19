#include "game.h"

//��ʼ�����̵�����Ϊ���ո���ʾ
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

//�����̵ķָ���
//����row = 3��col = 3
//Ч��ͼ����
//�������С�		|	  |	
//���ָ��С�	---|---|---
//�������С�		|	  |	
//���ָ��С�	---|---|---
//�������С�		|	  |	
void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	//��ʼ��ӡ
	for(i = 0;i<row;i++)		//��ӡ����С��row
	{
		int j = 0;
		for(j = 0;j<col;j++)		//��ӡ����С��col
		{
			//��ӡ��һ�е�����
			printf(" %c ",board[i][j]);		//�������ַ�
			if(j<col-1)		//�������С��col-1�����ӡ��|�����������һ�в���ӡ��|��
			{
				printf("|");	
			}
		}
		printf("\n");			//��һ�С������С���ӡ�����
		//��ӡ�ָ���
		if(i<row-1)		//�������С��row-1�����ӡ��---|---�����������һ�в���ӡ��---|---��
		{
			for(j = 0;j<col;j++)		//�������С��col�����ӡ��---��
			{
				printf("---");
				if(j<col-1)		//�������С��col-1�����ӡ��|�����������һ�в���ӡ��|��
				{
					printf("|");
				}
			}
			printf("\n");			//��һ�С��ָ��С���ӡ�����
		}
	}
}


//��ʼ����
//�������
void PlayerMove(char board[ROW][COL],int row,int col)
{
	//��������
	int x = 0;
	int y = 0;
	printf("������ӡ���>\n");
	while(1)
	{
		printf("���������꣺");
		scanf("%d %d",&x,&y);
		//�ж���������ĺϷ���
		//Ϊ���û������飬������±���㿪ʼ����������㿪ʼ
		if(x>=1 && x<=row && y>=1 && y<=col)		//���xy������Ҫ��Χ�ڣ����жϸ������Ƿ�Ϊ������
		{
			if(board[x-1][y-1] == ' ')		//�������Ϊ�գ������롰*��
			{
				board[x-1][y-1] = '*';
				break;
			}
			else		//������걻ռ�ã�����ʾ
			{
				printf("�����걻ռ��\n");
			}
		}
		else		//������곬������Ҫ������ʾ
		{
			printf("����Ƿ����룬���������룡����\n");
		}
	}
}

//��������
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("���������У���ȴ�... ...\n");
	//���������
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

//����1��������������
//����0����������û��
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
				return 0;		//û��
			}
		}
	}
	return 1;		//����
}

//�ж���Ӯ
char IsWin(char board[ROW][COL],int row,int col)
{
	int i = 0;
	//�ж����������Ƿ��ַ�һ��
	for(i = 0;i<row;i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж����������Ƿ��ַ�һ��
	for(i = 0;i<col;i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�ж��ҶԽ����Ƿ��ַ�һ��
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж���Խ����Ƿ��ַ�һ��
	if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж������Ƿ������ˣ�ƽ�֣�
	if(1 == IsFull(board,row,col))
	{
		return 'Q';
	}
	return 'C';
}