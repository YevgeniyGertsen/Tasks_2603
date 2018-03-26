#include<iostream>
#include<locale.h>
#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>

#define max30 30
using namespace std;
struct age {
	int year;
	int month;
	int day;
};

void generateAge(age *t)
{
	t->day = 1 + rand() % 30;
	t->month = 1 + rand() % 11;
	t->year = 1950 + rand() % 60;
}

void generateName(char *name, int type)
{
	if (type == 0)
		strcpy(name, "person #");
	else
		strcpy(name, "kurs #");

	int a = 1 + rand() % 30;

	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

struct group
{
	char *name;
	age * Age;
	int * ses;
};

struct student
{
	int id;
	char *name;
	age * Age;
	int * ses;
	char *kurs;
	double srBal;
};

void sortSES(int* a, int r)
{
	int temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
			/*if (*(a+j) < *(a - j))
			{
				temp = *(a-j);
				*(a-j) = *(a + j);
				*(a + j) = temp;
			}*/
		}
	}
}

void sortStudents(student * a, int r)
{
	student temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->id > (a + j)->id)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
			/*if (*(a+j) < *(a - j))
			{
			temp = *(a-j);
			*(a-j) = *(a + j);
			*(a + j) = temp;
			}*/
		}
	}
}
//
//void SortString(char *strings,int count)
//{
//	char *str=NULL;
//	for (int i = 1; i < count; i++)
//		for (int j = 0; j < count - i; j++)
//			if (strcmp(strings[j], strings[j + 1]) > 0) {
//				strcpy(str, strings[j]);
//				strcpy(strings[j], strings[j + 1]);
//				strcpy(strings[j + 1], str);
//		
//}

struct NOTE
{
	char *name;
	char *phone;
	age *age;
};
void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n, exit;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		printf("please enter exemple: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		{
			/*1.	ќписать структуру с именем GROUP, содержащую пол€ :
				a.Name Ц фамили€ и инициалы
				b.DAT Ц дата рождени€(год, мес€ц, число)
				c.SES Ц успеваемость(массив из трех элементов).
				Ќаписать программу, выполн€ющую:
				Х	ввод с клавиатуры данных в массив GR5, состо€щий из 10 структур типа GROUP;
				вывод на экран записей, упор€доченных по возрастанию пол€ SES;
				Х	вывод списка студентов, возраст которых на 01.12.2010 года не превышает 20 лет;
				Х	если таких студентов нет Ц выдать сообщение
*/
			int a = 1 + rand() % 25;
			printf("кол-во студентов: %d\n", a);

			group *students = NULL;
			students = (group*)malloc(a * sizeof(group));

			if (students == NULL)
			{
				printf("пам€ть не выделена\n");
				system("exit");
				//exit(EXIT_FAILURE);
			}
			else
			{
				for (int i = 0;i < a;i++)
				{
					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name,0);

					(students + i)->Age = (age*)malloc(1 * sizeof(age));
					generateAge((students + i)->Age);

					int k = (1 + rand() % 10);
					(students + i)->ses = (int*)calloc(k, sizeof(int));

					if ((2018 - (students + i)->Age->year) <= 20)
					{
						printf("# %d \t %s \t %d.%d.%d\n", i + 1, (students + i)->name,
							(students + i)->Age->day, (students + i)->Age->month, (students + i)->Age->year);
						int sum = 0;
						for (int j = 0; j < k; j++)
						{
							(students + i)->ses[j] = 2 + rand() % 4;
							//printf("--> %d\n", (students + i)->ses[j]);
							sum += (students + i)->ses[j];
						}
						printf("после сортировки:\n");
						sortSES((students + i)->ses, k);

						for (int j = 0; j < k; j++)
						{
							printf("--> %d\n", (students + i)->ses[j]);
						}

						if (k != 0)
						{
							printf("----------------------------------------\n");
							printf("средний балл студента составл€ет: %d\n", sum / k);
						}
					}
					else printf("студент %d старше 20 лет\n", i + 1);
				}
			}


		}break;
		/*
2.	ќписать структуру с именем STUDENT, содержащую пол€:
a.	Name Ц фамили€ и инициалы
b.	Kurs Ц курс
c.	SES Ц успеваемость (массив из п€ти элементов).

Ќаписать программу, выполн€ющую:
Х	ввод с клавиатуры данных в массив STUD, состо€щий из 10 структур типа STUDENT, записи должны быть упор€дочены по алфавиту;
Х	вывод на экран записей, упор€доченного списка студентов, средний бал которых превышает общий средний бал;
Х	если таких студентов нет Ц выдать сообщение
*/
		case 2:
		{
			int TSum = 0;
			int count = 5 + rand() % 30;
			student *students = (student*)malloc(count * sizeof(student));
			if (students != NULL)
			{
				for (int i = 0;i < count;i++)
				{
					(students + i)->id = 1 + rand() % 1000;

					(students + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((students + i)->name,0);

					(students + i)->Age = (age*)malloc(1 * sizeof(age));
					generateAge((students + i)->Age);

					(students + i)->kurs = (char*)malloc(10 * sizeof(char));
					generateName((students + i)->kurs, 1);

					(students + i)->ses = (int*)malloc(5 * sizeof(int));
					int sum = 0;
					for (int j = 0;j < 5;j++)
					{
						(students + i)->ses[j] = 2 + rand() % 3;
						sum += (students + i)->ses[j];
					}
					(students + i)->srBal = sum / 5;
					TSum += (students + i)->srBal;

				}

				TSum = TSum / count;
				int p = 0;
				
				for (int i = 0;i < count; i++)
				{
					if ((students + i)->srBal > TSum)
					{
						SetConsoleTextAttribute(hConsole, 12);

						printf("# %d\t %s \t %d \t (%s) - \t\t %2.2lf \n",
							(students + i)->id, (students + i)->name, (students + i)->Age->year, (students + i)->kurs, (students + i)->srBal);

						p++;
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 15);
						printf("# %d\t %s \t %d \t (%s) - \t\t %2.2lf \n",
							(students + i)->id, (students + i)->name, (students + i)->Age->year, (students + i)->kurs, (students + i)->srBal);

					}
				}

				if (p > 0)
				{
					printf("\n----------------------------------------------------------------\n");
					SetConsoleTextAttribute(hConsole, 15);
					//вывод на экран записей, упор€доченного списка студентов, средний бал которых превышает общий средний бал;
					sortStudents(students, count);
				
					for (int i = 0;i < count;i++)
					{
						if ((students)->srBal > TSum)
						{
							printf("# %d\t %s \t %d \t (%s) - \t\t %2.2lf \n",
								students->id, students->name, students->Age->year, students->kurs, students->srBal);
						}
						students++;
					}
				}
			}

		}break;

		/*4.	ќписать структуру с именем NOTE, содержащую пол€: 
a.	Name Ц фамили€ и инициалы
b.	TELE Ц номер телефона
c.	DATE Ц дата рождени€ (год, мес€ц, число)

Ќаписать программу, выполн€ющую:
Х	ввод с клавиатуры данных в массив BLOCKNOTE, состо€щий из 10 структур типа NOTE, записи должны быть упор€дочены по возрастанию даты рождени€;
Х	вывод на экран сведений о человеке, номер телефона которого введен с клавиатуры;
Х	если такого человека нет Ц выдать сообщение.

*/
		case 3: {
			int k = 0;
			int count = 0;
			NOTE *human = (NOTE*)malloc(sizeof(NOTE));
			while (true)
			{
				count++;
				printf("¬ведите им€: ");
				human->name = (char*)malloc(50 * sizeof(char));
				fgets(human->name, 50, stdin);
				cin.get();

				printf("¬ведите телефон: ");
				human->phone= (char*)malloc(50 * sizeof(char));
				fgets(human->phone, 50, stdin);
				cin.get();

				printf("¬ведите дату рождени€: ");
				human->age = (age*)malloc(sizeof(age));
				scanf("%2d.%2d.%4d", human->age->day, human->age->month, human->age->year);

				cin.get();
				printf("ѕродолжить? 1/0\n");
				scanf("%d", &k);
				if (k == 1)
					break;
				else
					human =(NOTE*)realloc(human, count + 1* sizeof(NOTE));

				system("cls");
			} 

			for (int i = 0;i < count;i++)
			{
				printf("%s - %s\n", (human + i)->name, (human + i)->phone);
			}


		}break;

		}
		printf("ѕродолжить? 1-Yes 2-No:");
		scanf("%d", &exit);
		printf("\n");
	} while (exit == 1);
}


