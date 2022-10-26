#include <iostream>
#include <string>
#include <ctime>
#include "Vector.h"
//<Required>
using namespace std;

void cont(int i)
{
	cout << "����� ���������: " << i << endl;
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
	cout << "��������! � ���� ������� ����� ����� ����� ����� �����,\n� ��������� �� ������������� �������� �������� �� 0\n" << endl;
	cout << "������� ����� ��������� � �������: ";
	do
	{
		cin >> len;
		if (len <= 0)
		{
			cout << "������������ ���� ������!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

	} while (len <= 0);
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	cout << "���� ������ �������: " << len << endl;

	vec<int> a(len);
	int r = 0, r1 = 0, tmp_con = 0;
	bool content = true;
	cout << "��� ������ ��������� ������?\n" << "1.�������\n" << "2.��������\n";
	do
	{
		cin >> t;
		switch (t)
		{
		case 1:
			system("cls");
			cout << "������� ��������: " << endl;
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
			cout << "�������� ���� ����������, ������� �����: ";
			content = true;
			break;
		}
	} while (content);

	auto iter = a.begin();
	int forIt = 0;
	int fm2 = 0;

	t = 0;
	do
	{
		system("cls");

		cout << "1. ������� ������ � ������� ���������� �������" << endl;
		cout << "2. ������� ������ � ������� ����������" << endl;
		cout << "3. ������� ������ � �������� ������� � ������� ����������" << endl;
		cout << "4. ������ ������ �������" << endl;
		cout << "5. �������� ������ �� ���������" << endl;
		cout << "6. ���������, ���� �� ������� � �������" << endl;
		cout << "7. ������� ������� ������� �� �������" << endl;
		cout << "8. �������� ������� ������� �� �������" << endl;
		cout << "9. ����� ������� �������� � �������" << endl;
		cout << "10. �������� ������� � ����� �������" << endl;
		cout << "11. �������� ������� �� ������� � �������" << endl;
		cout << "12. ������� ������ ������ ������� � �������" << endl;
		cout << "13. ������� ������� �� ������� � �������" << endl;
		cout << "14. �������� � ����������" << endl;
		cout << "15. ����� �� ���������" << endl;
		cin >> t;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		system("cls");

		switch (t)
		{
		case 1:
		{
			cout << "������� ������: " << endl;
			a.Print();
			cont(a.GetCounView());
		}
			break;

		case 2:
		{
			cout << "������� ������: " << endl;
			for (auto i : a)
				cout << i << " ";
			cout << endl;
			cont(a.Len() + 2);
		}
			break;

		case 3:
		{
			cout << "������� ������: " << endl;
			for (auto i = a.rbegin(); i != a.rend(); ++i)
				cout << *i << " ";
			cout << endl;
			cont(a.Len() + 2);
		}
			break;

		case 4:
		{
			cout << "������ �������: " << a.Len() << endl;
			cont(a.GetCounView());
		}
			break;

		case 5:
		{
			a.Clear();
			cout << "������ ������!" << endl;
			cont(a.GetCounView());
		}
			break;

		case 6:
		{
			cout << "������� �������, ������� ����� ���������: ";
			cin >> r;
			system("cls");
			content = false;
			content = a.SeekEl(r);
			if (content)
				cout << "����� ������� ����!";
			else
				cout << "������ �������� ���.";
			cout << endl;
			cont(a.GetCounView());
		}
			break;

		case 7:
		{
			if (a.Empty())
				cout << "������ ������, ������ ��������!" << endl;
			else
			{
				cout << "������� ������ �� 1 �� " << a.Len() << endl;
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "������� ������� ��������, ������� ������ �� 1 �� " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");
				cout << "������� �� ������� " << r << " ����� " << a.SeekByInd(r - 1) << endl;
			}

			cont(a.GetCounView());
		}
			break;

		case 8:
		{
			if (a.Empty())
				cout << "������ ������, ������ ��������!" << endl;
			else
			{
				cout << "������� ������ �� 1 �� " << a.Len() << endl;
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "������� ������� ��������, ������� ������ �� 1 �� " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");

				cout << "������� �� ����� ������� �� ������ ��������: ";
				cin >> r1;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				a.RefactorByInd(r - 1, r1);
				cout << "������ �����������!" << endl;
			}

			cont(a.GetCounView());
		}
			break;

		case 9:
		{
			tmp_con = 0;
			if (a.Empty())
				cout << "������ ����, ������ ������!" << endl;
			else
			{
				cout << "������� �������, ������� �������� ����� �������: ";
				cin >> r;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (a.SeekEl(r))
				{
					system("cls");
					tmp_con += a.GetCounView();
					cout << "������� " << r << " ��������� �� ������� " << a.GetPosByEl(r) + 1 << endl;
					tmp_con += a.GetCounView();
				}
				else
				{
					cout << "������ �������� �� ����������!" << endl;
					tmp_con += a.GetCounView();
				}
			}

			cont(tmp_con);
		}
			break;

		case 10:
		{
			cout << "������� �������, ������� ����� ���������: ";
			cin >> r;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			a.Push(r);
			cout << "������ ������ ��������!" << endl;
			cont(a.GetCounView());
		}
			break;

		case 11:
		{
			if (a.Empty())
				cout << "������ ����! ��� ������� ������� �������� �������������� ������� 10." << endl;
			else
			{
				cout << "������� ������� �� 1 �� " << a.Len() << ": ";
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "������� ������� ��������, ������� ������ �� 1 �� " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");
				cout << "������� �������, ������� ����� ��������: ";
				cin >> r1;

				system("cls");
				a.Insert(r - 1, r1);
				cout << "������� " << r1 << " ������� �������� � ������� " << r << endl;

			}

			cont(a.GetCounView());
		}
			break;

		case 12:
		{
			cout << "������� ��������� �������: ";
			cin >> r;

			if (a.Remove(r))
				cout << "������� ������� �����!" << endl;
			else
				cout << "������ �������� �� �������!" << endl;

			cont(a.GetCounView());
		}
			break;

		case 13: 
		{
			if (a.Empty())
				cout << "������ ����!" << endl;
			else
			{
				cout << "������� ������� �� 1 �� " << a.Len() << ": ";
				do
				{
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (r < 1 || r > a.Len())
					{
						system("cls");
						cout << "������� ������� ��������, ������� ������ �� 1 �� " << a.Len() << endl;
					}

				} while (r < 1 || r > a.Len());

				system("cls");
				a.RemoveByInd(r - 1);
				cout << "������� ������� �����!" << endl;

			}

			cont(a.GetCounView());
		}
			break;

		case 14:
		{
			fm2 = 0;
			do
			{
				do
				{
					cout << "1. �������� +1\n2. ������� -1\n3. ������������ ������� ��������\n4. ���������� �������� �� �������\n5. ���������� �������� �� ������\n6. ���������� �������� �� �����\n7. ��������� � ���������� ����" << endl;
					cin >> r;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					system("cls");
					if (r < 1 || r > 7)
					{
						system("cls");
						cout << "������� ������� ��������, ������� ����� �� 1 �� 6" << endl;
					}
				} while (r > 7 || r < 1);

				try
				{
					switch (r)
					{
					case 1: {++iter; forIt++; cout << "�������� ���������������." << endl; } break;
					case 2: {--iter; forIt--; cout << "�������� ���������������." << endl; } break;
					case 3: {
						if (forIt < a.Len() && forIt > -1)
							cout << "�������������� ��������: " << *iter << endl;
						else
							throw new exception("123");
					} break;
					case 4: {
						cout << "������� ������� �� 1 �� " << a.Len() << ": ";
						do
						{
							cin >> r1;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							if (r1 < 1 || r1 > a.Len())
							{
								system("cls");
								cout << "������� ������� ��������, ������� ������ �� 1 �� " << a.Len() << endl;
							}

						} while (r1 < 1 || r1 > a.Len());

						iter = a.begin();
						for (int i = 0; i < r1 - 1; i++)
							++iter;

						cout << "�������� ����������!" << endl;

					} break;
					case 5: {
						iter = a.begin(); 
						forIt = 0; 
						cout << "�������� ���������� �� ������." << endl; 
					} break;
					case 6: {
						iter = --(a.end()); 
						forIt = a.Len() - 1;
						cout << "�������� ���������� �� �����." << endl; 
					}break;
					case 7: fm2 = -1; break;
					}

				}
				catch (...)
				{
					cout << "�������� �� ����������." << endl;
				}
				cont(0);
				system("cls");
			} while (fm2 != -1);
		}
			break;

		case 15:
		{
			t = -1;
			exit(1);
		}
			break;

		default:
			cout << "������� ������� �������� ������ ����.";
			cont(0);
			
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