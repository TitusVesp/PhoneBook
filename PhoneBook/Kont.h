#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Kont
{
private:
	char surname[64];
	char name[64];
	char nom[13] = { '+','3','8','0' };
	char city[64];
	char job[64];
	struct birthdate { unsigned int year, month, day; } date;
	int strlength(char* str);
	bool Is_Surname_Corr(char* name);
	bool Is_Num_Corr(char* mobilePhone);
	bool Is_City_Corr(char* name);
	bool Is_Birth_Corr(int year, int month, int day);
	void ChangeSurname();
	void ChangeName();
	void ChangeMob();
	void ChangeCity();
	void ChangeJob();
	void ChangeBirth();
public:
	void SetKont(char surnam[64], char nam[64], char num[9], char town[64], char occ[64], int year1, int month1, int day1);
	void Write(FILE* a);
	void Display();
	void EditKont();
	void ContDisplay(FILE* a);
	void AddCont(FILE* a);
	void EditCont(FILE* a);
	void DelCont(FILE* a);
	int menu();
	void MENU(FILE* a);
};

void Kontacts()
{
	Kont a;
	FILE* f;
	f = nullptr;
	a.MENU(f);
}

