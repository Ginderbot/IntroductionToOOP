#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>

// 1 - ����
//7,15 - ���

void main()
{
	//setlocale(LC_ALL, "");
	const int n = 20, m = 40;
	int house[n][m]{};
	int one, thoo;
	int mass = 3;
	int food = n * m * 2;
	bool eat = false, death = false, step = false;
	int _getch();
	int keys = 'd', buff;
	int a = 0, b = 0; //a-��������� b-�����������

	house[1][0] = mass;// ��������� ������
	srand(time(NULL));

	while (!death)
	{
		buff = keys;
		step = false;
		do
		{
			(_kbhit()) ? keys = _getch() : keys = buff;//�������� ������� �������
			if (keys == 'w' || keys == 'W' || keys == 150 || keys == 230 || keys == 72)keys = 'w';
			else if (keys == 'a' || keys == 'A' || keys == 148 || keys == 228 || keys == 75)keys = 'a';
			else if (keys == 's' || keys == 'S' || keys == 155 || keys == 235 || keys == 80)keys = 's';
			else if (keys == 'd' || keys == 'D' || keys == 130 || keys == 162 || keys == 77)keys = 'd';
		} while (!(keys == 'w' || keys == 'a' || keys == 's' || keys == 'd'));

		if (buff == 'w'&&keys == 's' || buff == 's'&&keys == 'w' || buff == 'a'&&keys == 'd' || buff == 'd'&&keys == 'a')keys = buff; //������ �����������
		if (keys == 'w')a = -1, b = 0;
		else if (keys == 'a')a = 0, b = -1;
		else if (keys == 's')a = 1, b = 0;
		else if (keys == 'd')a = 0, b = 1;

		if (!eat) //��������� ���
		{
			do
			{
				one = rand() % (n - 2) + 1;
				thoo = rand() % (m - 2) + 1;
			} while (house[one][thoo] != 0);
			house[one][thoo] = food;
		}
		eat = false;
		for (int i = 0; i < n; i++)//�������
		{
			for (int j = 0; j < m; j++)//������
			{
				if (house[i][j] == food)eat = true;//�������� ���
				if (house[i][j] == mass && ((j + b == m - 1 || j + b == 0 || i + a == n - 1 || i + a == 0) || house[i + a][j + b] != 0 && house[i + a][j + b] != 1 && house[i + a][j + b] != food))death = true;//������� ������
				if (house[i][j] == mass && house[i + a][j + b] == food)house[i][j] = ++mass;//������� �����
				if (house[i][j] == mass && !step) // ��������
				{
					house[i + a][j + b] = mass + 1;
					step = true;
				}
			}
		}
		system("CLS");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (house[i][j] != 0 && house[i][j] != n * m * 2)house[i][j] -= 1;//���������� ������
				(i == 0 || i == n - 1 || j == 0 || j == m - 1) ? std::cout << (char)219 :
					(house[i][j] == food) ? std::cout << char(15) : // ����� �� �����
					(house[i][j] == mass) ? std::cout << (char)2/*<<char(7)*/ :
					(house[i][j] != 0) ? std::cout << (char)176 : std::cout << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "Spore: " << mass - 3;
		Sleep(100);
	}
	system("CLS");
	std::cout << "Game over" << std::endl << "Spore: " << mass - 3;
}