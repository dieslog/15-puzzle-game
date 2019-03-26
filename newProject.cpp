#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//запись значений в масив от 0 до 15
void writeMas(int **mas, int n, int m) {
	int x, y;
	for (int i = 0; i < 16;) {
		x = rand() % 4;
		y = rand() % 4;
		if (mas[x][y] == 0) {
			mas[x][y] = i;
			i++;
		}
	}
}
//поиск и возврат позиции нуля
int *posZero(int **mas, int n, int m) {
	int temp[2]{ 0, 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] == 0)
			{
				temp[0] = i;
				temp[1] = j;
			}
		}
	}
	return temp;
}

//проверка на завершение игры
bool checkGameOver(int **mas, int n, int m) {
	int count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] != count && count < 16)
			{
				return false;
			}
			count++;
		}
	}
	return true;
}

//вывод масива на экран
void showMas(int **mas, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas[i][j] <= 9)
				cout << " ";
			cout << mas[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//перестановка значений в пятнашках (управление)
void updateMas(int **mas, int n, int m, char sing) {
	int *pos = posZero(mas, n, m);
	int x = pos[0];
	int y = pos[1];
	switch (sing) {
	case 't': {
		if (x != 0)
			swap(mas[x][y], mas[x - 1][y]);
		break;
	}
	case 'r': {
		if (y != m - 1)
			swap(mas[x][y], mas[x][y + 1]);
		break;
	}
	case 'b': {
		if (x != n - 1)
			swap(mas[x][y], mas[x + 1][y]);
		break;
	}
	case 'l': {
		if (y != 0)
			swap(mas[x][y], mas[x][y - 1]);
		break;
	}
	}
	system("cls");
	showMas(mas, n, m);
}

int main()
{
	setlocale(0, "russian");
	srand(time(NULL));
	int key = 0;
	int n = 4, m = 4;
	int **mas = new int *[n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m] {};
	}

	writeMas(mas, n, m);
	showMas(mas, n, m);

	do {
		key = _getch();

		switch (key) {
		case 72:
		{
			updateMas(mas, n, m, 't');
			break;
		}
		case 77:
		{
			updateMas(mas, n, m, 'r');
			break;
		}
		case 80:
		{
			updateMas(mas, n, m, 'b');
			break;
		}
		case 75:
		{
			updateMas(mas, n, m, 'l');
			break;
		}
		
		}
		if (checkGameOver(mas, n, m)) {
			cout << "\nПоздравляем! Игра окончена.";
			break;
		}
	} while (true);

	for (int i = 0; i < n; i++) {
		delete[]mas[i];
	}
	delete[] mas;
	cout << "\n";
	system("pause");
	return 0;
}