#include"game.h"


void games()
{
	char arr[ROW][COL];
	ini_arr(arr, ROW, COL);
	intboard(arr, ROW, COL);
	while (1)
	{
		peopleplay(arr, ROW, COL);
		intboard(arr, ROW, COL);
		winguide(arr, ROW, COL);
		if (winguide(arr,ROW,COL) == 1)
		{
			printf("���ʤ�ˣ�\n");
			break;
		}
		else if (winguide(arr, ROW, COL) == 0)
		{
			printf("��ʧ���ˣ�\n");
			break;
		}
		else if (winguide(arr, ROW, COL) == 3)
		{
			printf("ƽ�֣�\n");
			break;
		}
		computerplay(arr, ROW, COL);
		intboard(arr, ROW, COL);
		winguide(arr, ROW, COL);
	}

}
int main(void)
{
	srand((unsigned)time(NULL));
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:games();
			break;
		case 0:
			break;
		default:printf("�������\n");
		}

	} while (input);
		return 0;
}