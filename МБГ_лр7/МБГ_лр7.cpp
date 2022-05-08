// Метод блажийшего города
// Л.р. №7

#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	vector<int> x(5);
	vector<int> s;           // обход
	vector<int> dist;       // вектор расстояний
	int i, j = 0;
	int G[5];            // массив городов
	int	prevmin = 0;
	int g = 0;
	int min = 50;
	int mindist = 50;
	const int N = 5;
	int	matr[N][N];     // матрица расстояний
	int matr1[N][N];   // матрица для проверки


	cout << "x: " << ' ';

	for (i = 0; i < N; i++)
	{
		x[i] = i;
		G[i] = i;
		cout << x[i] << ' ';
	}
	cout << endl << endl;;

	cout << '\t' << "Матрица расстояний: " << endl << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j) matr[i][j] = 0;                  // расстояние из города до себя 0
			else
			{
				if (i < j)
				{
					matr[i][j] = rand() % (20) + 1;
					matr[j][i] = matr[i][j];          // заполнили симметрично, считая, что в обе стороны расстояние одинаковое
				}
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << matr[i][j] << '\t';
		}
		cout << endl;
	}
	
	int y = 0;
	int g1 = 0;             // первый город
	int k = 5;
	int m = 0;
	int str = 0; 
	int l = 0;            // длина цикла
	int i1 = 1; 
	int z = 0;
	vector<int> gdist;  // для запоминания "соседей" у городов обхода
	int d = 0;
	int firstc, lastc = 0;
	int c,i2,j2 = 0;
	j = 0;
	g = rand() % 4;

	cout << endl;
	cout << "i: " << i1 << endl;
	cout << "Выбраный город: " << g << endl;
	g1 = g;

	s.push_back(g);                  // добавляем город в обход
	cout << "Текущий обход: ";
	for (i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;

	for (i = 0; i < k; i++)   // ищем позицию города чтобы исключить iтый элемент вектора удалить
	{
		if (x[i] == g)      // если выбранный город найден на i том месте (5 находится на 5 месте)
		{
			y = i;
			str = i;      // занесли номер строки
		}
	}
	x.erase(x.begin() + y);                 // исключаем город

	k = k - 1;

	while (x.size() > 0)                  // пока города остались
	{
		for (i = 0; i < s.size(); i++)   // ищем min путь каждого города в обходе
		{
			g1 = s[i];
			min = 50;
			str = s[i];                 // Занесли номер строки
			
			// Ищем минимальный путь
			
			for (j = 0; j < N; j++)
			{
				if ((matr[str][j] != 0))                 // можно ли брать город
				{
					if (min >= matr[str][j]) 
					{
						if (matr1[str][j] != 1)         // проверка брали ли этот минимум
						{
							g = j;               
							min = matr[str][j];         // запоминаем минимум
						}
					}
				}
			}
			matr1[str][g] = 1;	                      // брали ли город, 1-да, 0-нет
			matr1[g][str] = 1;
			
			dist.push_back(min);                     // запоминаем min расстояние
			cout << g1 << " -> " << g << " "<< "Расстояние: " << min << endl;
			gdist.push_back(g);                     // заносим город с мин расстоянием
		}
		
		// оцениваем минимальный путь
		for (z = 0; z < dist.size(); z++)
		{
			if (mindist >= dist[z])
			{
				prevmin = mindist;// Предыдущий мин
				mindist = dist[z];
				c = z; // запоминаем позицию в векторе
			}
		}

		// нашли mindist теперь узнаем какой это город в обходе и его "соседа"
		cout << "Выбранный город: " << gdist[c] << endl;
		d = dist[c] + d;                                  // присваиваем min
		cout << "Длина текущего обхода: " << d << endl;
		s.insert(s.begin() + (c + 1), gdist[c]);         // вставляем в обход новый город
		dist.clear();
		gdist.clear();
		prevmin = 0;
		m = 0; c = 0;
		min = 50;
		mindist = 50;
		 
		cout << "Текущий обход: ";
		for (i = 0; i < s.size(); i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;

		for (i = 0; i < N; i++)
		{
			if (G[i] == g) str = i;
		}

		for (i = 0; i < k; i++)
		{
			if (x[i] == g) y = i;
		}

		x.erase(x.begin() + y);         // исключаем город

		k--;

		for (i = 0; i < s.size(); i++)             // ищем первый и последний города в обходе
		{
			if (i == 0) firstc = s[i];            //первый город обхода
			if (i == (s.size() - 1)) lastc= s[i];
		}

		l = d + matr[firstc][lastc];  //длина цикла
		i1++;
		cout << endl;
		cout << "i: " << i1 << endl;
	}
	cout << "Выполнение алгоритма завершено, все города пройдены!" << endl;

	cout << endl << "-----------------------------------------" << endl;
	cout << "Ответ: " << endl;
	s.push_back(firstc);
	cout << "Итоговый цикл: ";
	for (i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout <<endl<< "Длина цикла: " << l << endl;
	cout << "-----------------------------------------" << endl;
	
}
