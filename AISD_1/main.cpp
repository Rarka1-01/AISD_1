#include <iostream>
#include <string>
#include <ctime>
#include "Vector.h"

using namespace std;

void cont(int i)
{
	cout << "Число обращений: " << i << endl;
	system("pause");
}

void rnd(vec<int> *a, int n)
{
	for (int i = 0; i < n; i++)
		(*a).Push(rand() % 10);
}

void mainMenu()
{
	int t = 0, len = 0;
	bool f = true;
	cout << "ВНИМАНИЕ! У всех дробных чисел будет взята целая часть,\nа остальные не целочисленные элементы заменены на 0\n" << endl;
	cout << "Введите число элементов в векторе: ";
	do
	{
		cin >> len;
		if (len <= 0)
		{
			cout << "Некорректный ввод данных!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	} while (len <= 0);
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	cout << "Ваша длинна вектора: " << len << endl;

	vec<int> a(len);
	int r = 0, r1 = 0, tmp_con = 0;
	bool content = true;
	cout << "Как хотите заполнить вектор?\n" << "1.Вручную\n" << "2.Случайно\n";
	do
	{
		cin >> t;
		switch (t)
		{
		case 1:
			system("cls");
			cout << "Введите элементы: " << endl;
			for (int i = 0; i < len; i++)
			{
				cin >> r;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				a.Push(r);
			}

			content =false;
			break;
		case 2: rnd(&a, len);
			content = false;
			break;
		default:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверный ввод переменной, введите снова: ";
			content = true;
			break;
		}
	} while (content);

	t = 0;
	do
	{
		system("cls");

		cout << "1. Вывести вектор с помощью встроенной функции" << endl;
		cout << "2. Вывести вектор с помощью итераторов" << endl;
		cout << "3. Вывести вектор в обратном порядке с помощью итераторов" << endl;
		cout << "4. Узнать длинну вектора" << endl;
		cout << "5. Очистить вектор от элементов" << endl;
		cout << "6. Проверить, есть ли элемент в векторе" << endl;
		cout << "7. Вывести элемент вектора по индексу" << endl;
		cout << "8. Изменить элемент вектора по индексу" << endl;
		cout << "9. Найти позицию элемента в векторе" << endl;
		cout << "10. Добавить элемент в конец вектора" << endl;
		cout << "11. Вставить элемент на позицию в векторе" << endl;
		cout << "12. Удалить первый данный элемент в векторе" << endl;
		cout << "13. Удалить элемент на позиции в векторе" << endl;
		cout << "14. Выйти из программы" << endl;
		cin >> t;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		system("cls");

		switch (t)
		{
		case 1:
			cout << "Текущий вектор: " << endl;
			a.Print();
			cont(a.GetCounView());
			break;

		case 2:
			cout << "Текущий вектор: " << endl;
			for (auto i : a)
				cout << i << " ";
			cout << endl;
			cont(a.Len() + 2);
			break;

		case 3:
			cout << "Текущий вектор: " << endl;
			for (auto i = a.rbegin(); i != a.rend(); ++i)
				cout << *i << " ";
			cout << endl;
			cont(a.Len() + 2);
			break;

		case 4:
			cout << "Длинна вектора: " << a.Len() << endl;
			cont(a.GetCounView());
			break;

		case 5:
			a.Clear();
			cout << "Вектор очищен!" << endl;
			cont(a.GetCounView());
			break;

		case 6:

			cout << "Введите элемент, который нужно проверить: ";
			cin >> r;
			system("cls");
			content = false;
			content = a.SeekEl(r);
			if (content)
				cout << "Такой элемент есть!";
			else
				cout << "Такого элемента нет.";
			cout << endl;
			cont(a.GetCounView());

			break;

		case 7:

			if (a.Empty())
				cout << "Вектор пустой, нечего выводить!" << endl;
			else
			{
				cout << "Введите индекс от 1 до " << a.Len() << endl;
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "Неверно введено значение, введите индекс от 1 до " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");
				cout << "Элемент на позиции " << r << " равен " << a.SeekByInd(r - 1) << endl;
			}

			cont(a.GetCounView());

			break;

		case 8:

			if (a.Empty())
				cout << "Вектор пустой, нечего изменять!" << endl;
			else
			{
				cout << "Введите индекс от 1 до " << a.Len() << endl;
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "Неверно введено значение, введите индекс от 1 до " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");

				cout << "Введите на какой элемент вы хотите заменить: ";
				cin >> r1;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				a.RefactorByInd(r - 1, r1);
				cout << "Замена произведена!" << endl;
			}

			cont(a.GetCounView());

			break;

		case 9:
			tmp_con = 0;
			if (a.Empty())
				cout << "Вектор пуст, нечего искать!" << endl;
			else
			{
				cout << "Введите элемент, позицию которого нужно вывести: ";
				cin >> r;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (a.SeekEl(r))
				{
					system("cls");
					tmp_con += a.GetCounView();
					cout << "Элемент " << r << " находится на позиции " << a.GetPosByEl(r) + 1 << endl;
					tmp_con += a.GetCounView();
				}
				else
				{
					cout << "Такого элемента не существует!" << endl;
					tmp_con += a.GetCounView();
				}
			}

			cont(tmp_con);

			break;

		case 10:

			cout << "Введите элемент, который будем вставлять: ";
			cin >> r;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			a.Push(r);
			cout << "Элемен успешо вставлен!" << endl;
			cont(a.GetCounView());

			break;

		case 11:

			if (a.Empty())
				cout << "Вектор пуст! Для вставки первого элемента воспользуйтесь пунктом 10." << endl;
			else
			{
				cout << "Введите позицию от 1 до " << a.Len() << ": ";
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "Неверно введено значение, введите индекс от 1 до " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");
				cout << "Введите элемент, который будем вствлять: ";
				cin >> r1;

				system("cls");
				a.Insert(r - 1, r1);
				cout << "Элемент " << r1 << " успешно вставлен в позицию " << r << endl;

			}

			cont(a.GetCounView());

			break;

		case 12:

			cout << "Введите удаляемый элемент: ";
			cin >> r;

			if (a.Remove(r))
				cout << "Элемент успешно удалён!" << endl;
			else
				cout << "Такого элемента не найдено!" << endl;

			cont(a.GetCounView());
			break;

		case 13: 
			
			if (a.Empty())
				cout << "Вектор пуст!" << endl;
			else
			{
				cout << "Введите позицию от 1 до " << a.Len() << ": ";
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "Неверно введено значение, введите индекс от 1 до " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");
				a.RemoveByInd(r - 1);
				cout << "Элемент успешно удалён!" << endl;

			}

			cont(a.GetCounView());

			break;

		case 14: t = -1; break;

		default:
			cout << "Неверный ввод переменной, для продолжения нажмите Enter...\n";
			
			break;
		}
	} while (t != -1);
}

int main()
{
	system("chcp 1251");
	system("cls");
	srand(time(NULL));

	mainMenu();

	return 0;
}