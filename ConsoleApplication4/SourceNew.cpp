#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>

#define lenght 20
enum Gender { male, female };

struct dateTime {
	int day;
	int month;
	int year;
	int h;
	int m;
	int s;
};

struct people
{
	char surname[lenght];
	char name[lenght];
	char mName[lenght];
	Gender gender;
	dateTime dob;
	//char doljnost[];
};

struct place
{
	char placeName[100];
	dateTime vpr;
};


struct train
{
	//№ поезда
	int numberOfTrain;
	//Пункт и время прибытия 
	place arrive;
	//Пункт и время отбытия
	place dest;

	double timeInDest;
};
void generatePlace(char *name, int a)
{
	strcpy(name, "place #");

	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void generateTrain(train *t)
{
	t->numberOfTrain = 0 + rand() % 400;
	generatePlace(t->arrive.placeName, 0);
	t->arrive.vpr.day = 1 + rand() % 30;
	t->arrive.vpr.month = 1 + rand() % 11;
	t->arrive.vpr.year = 2018;
	t->arrive.vpr.h = 0 + rand() % 23;
	t->arrive.vpr.m = 0 + rand() % 59;
	t->arrive.vpr.s = 0 + rand() % 59;


	generatePlace(t->dest.placeName, 0);
	t->dest.vpr.day = 1 + rand() % 30;
	t->dest.vpr.month = 1 + rand() % 11;
	t->dest.vpr.year = 2018;
	t->dest.vpr.h = 0 + rand() % 23;
	t->dest.vpr.m = 0 + rand() % 59;
	t->dest.vpr.s = 0 + rand() % 59;

	t->timeInDest = (t->dest.vpr.h * 60 + t->dest.vpr.m) - (t->arrive.vpr.h * 60 + t->arrive.vpr.m);
}

void generateName2(char *name, int a)
{
	strcpy(name, "person #");

	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}



void randomPeople(people *p)
{
	int a = 1 + rand() % 15;

	generateName2(p->surname, a);
	generateName2(p->name, a);
	generateName2(p->mName, a);

	a = 0 + rand() % 1;
	switch (a)
	{
	case 0:
		p->gender = male;
		break;
	default:
		p->gender = female;
		break;
	}

	p->dob.day = 1 + rand() % 30;
	p->dob.month = 1 + rand() % 11;
	p->dob.year = 1924 + rand() % 70;
}

void printfInfo(people *p)
{
	printf("%s %s %s - %d\n", p->name, p->surname, p->mName, p->gender);
	printf("%d.%d.%d\n", p->dob.day, p->dob.month, p->dob.year);
	printf("--------------------------------------------------\n");
}

void showInfoaboutGrand(people *p)
{
	for (int i = 0;i < lenght;i++)
	{
		if ((2018 - p->dob.year) > 65)
			printfInfo(p);
		p++;
	}
}