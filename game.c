#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("************1.Yes*********\n");
	printf("************0.No**********\n");
	printf("**************************\n");

}
void ini_arr(char arr[ROW][COL] )
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void intboard(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}

			}
		}
		printf("\n");
	}
	
}

void peopleplay(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请玩家落棋\n");
		scanf("%d %d", &x, &y);
	
		if (x <= row && x > 0 && y <= col && y > 0 && arr[x-1][y-1] != '*' && arr[x-1][y-1] != '#')
		{
			arr[x-1][y-1] = '*';
			break;
		}
		else
		{
			printf("输入无效，请重新输入");
		}
	}
}
void computerplay(char arr[ROW][COL],int row,int col)
{

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (arr[x][y] != '*' && arr[x][y] != '#')
		{
			arr[x][y] = '#';
			break;
		}
	}

}
int winguide(char arr[ROW][COL], int row, int col)//o输 1赢 2继续 3平局 n用来计算落子个数
{
	int i, j;
	int flag = 2;
	int n = 0;

	for (i = 0; i < row - 2; i++)//竖直判断
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j]&&arr[i+1][j]=='*')
			{
				flag = 1;
			}
			else if (arr[i][j] == arr[i + 1][j] && arr[i + 1][j] == arr[i + 2][j] && arr[i + 1][j] == '#')
			{
				flag = 0;
			}
		}
	}
	for (j = 0; j < col - 2; j++)//水平判断
	{
		for (i = 0; i < row; i++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2] && arr[i][j + 1] == '*')
			{
				flag = 1;
			}
			else if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2] && arr[i][j + 1] == '#')
			{
				flag = 0;
			}
		}

	}

	int shorter = (row < col ? row : col);
	for (i = 0; i < row - 3; i++)//倾斜判断，以两条边为基础
	{
		for (j = 0; j < shorter - 2; j++)
		{
			if (arr[i + 1][j] == arr[i + 2][j + 1] && arr[i + 2][j + 1] == arr[i + 3][j + 2] && arr[i + 2][j + 1] == '*')
			{
				flag = 1;
			}
			else if (arr[i + 1][j] == arr[i + 2][j + 1] && arr[i + 2][j + 1] == arr[i + 3][j + 2] && arr[i + 2][j + 1] == '#')
			{
				flag = 0;
			}
		}
		for (j = 0; j < shorter - 2; j++)
		{
			if (arr[i + 1][col-j-1] == arr[i + 2][col-j-2] && arr[i + 2][col-j-2] == arr[i + 3][col-j-3] && arr[i + 2][col-j-2] == '*')
			{
				flag = 1;
			}
			else if (arr[i + 1][col - j - 1] == arr[i + 2][col - j - 2] && arr[i + 2][col - j - 2] == arr[i + 3][col - j - 3] && arr[i + 2][col - j - 2] == '#')
			{
				flag = 0;
			}
		}
	}
	for (j = 0; j < col - 2; j++)
	{
		for (i = 0; i < shorter - 2; i++)
		{
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i + 1][j + 1] == arr[i + 2][j + 2] && arr[i + 1][j + 1] == '*')
			{
				flag = 1;
			}
			else if (arr[i][j] == arr[i + 1][j + 1] && arr[i + 1][j + 1] == arr[i + 2][j + 2] && arr[i + 1][j + 1] == '#')
			{
				flag = 0;
			}
		}
		for (i = 0; i < shorter - 2; i++)
		{
			if (arr[row-1-i][j] == arr[row-i-2][j + 1] && arr[row-i-2][j + 1] == arr[row-i-3][j + 2] && arr[row-i-2][j + 1] == '*')
			{
				flag = 1;
			}
			else if (arr[row - 1 - i][j] == arr[row - i - 2][j + 1] && arr[row - i - 2][j + 1] == arr[row - i - 3][j + 2] && arr[row - i - 2][j + 1] == '#')
			{
				flag = 0;
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] != ' ')
			{
				n += 1;
			}
			if (n == row * col)
			{
				flag = 3;
			}
		}
	}
	return flag;
}