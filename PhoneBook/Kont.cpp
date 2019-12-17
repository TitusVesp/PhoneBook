#include "Kont.h"
#define Is_Name_Corr Is_Surname_Corr
using namespace std;
bool Kont::SetKont(char surnam[64], char nam[64], char num[9], char town[64], char occ[64], int year1, int month1, int day1)
{
	{
		// surname
		if (Is_Surname_Corr(surnam))
		{
			for (int i = 0; i < 64 && surnam[i] > 0; i++)
				surname[i] = surnam[i];
		}
		else
		{
			cout << "The surname is incorrect" << endl;
			return false;
		}

		// name
		if (Is_Name_Corr(nam))
		{
			for (int i = 0; i < 64 && nam[i] > 0; i++)
				name[i] = nam[i];
		}
		else
		{
			cout << "The name is incorrect" << endl;
			return false;
		}

		// phone number
		if (Is_Num_Corr(num))
			for (int i = 0; i < 9; i++)
				nom[i + 4] = num[i];
		else
		{
			cout << "The number is incorrect" << endl;
			return false;
		}

		// Occupation
		for (int i = 0; i < 64 && occ[i] > 0; i++)
			if ((int)occ[i] != -52)
				job[i] = occ[i];

		// city
		if (Is_City_Corr(town))
		{
			for (int i = 0; i < 64 && town[i] > 0; i++)
				city[i] = town[i];
		}
		else
		{
			cout << "The city is incorrect" << endl;
			return false;
		}

		// Birthdate
		if (Is_Birth_Corr(year1, month1, day1))
		{
			date.year = year1;
			date.month = month1;
			date.day = day1;
		}
		else
		{
			cout << "The birthdate is incorrect" << endl;
			return false;
		}
		return true;
	}
}

void Kont::Write(FILE* a)
{
	a = fopen("Abonent.txt", "ab");

	// writing a surname
	for (char qw : surname)
	{
		if (qw < 0) break;
		fwrite(&qw, sizeof(char), 1, a);
	}

	// separate surname and name
	char uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);

	// writing a name
	for (char qw : name)
	{
		if (qw < 0) break;
		fwrite(&qw, sizeof(char), 1, a);
	}
	fwrite(&uy, sizeof(char), 1, a);

	// separate name and mobile phone
	uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);

	// writing mobile phone
	for (int i = 0; i < 13 && nom[i] > 0; i++)
	{
		fwrite(&nom[i], sizeof(char), 1, a);
	}

	// separate mobile phone and city
	uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);


	// writing city
	for (char qw : city)
	{
		if (qw < 0) break;
		fwrite(&qw, sizeof(char), 1, a);
	}
	// separate city and occupation
	uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);

	// writing occupation
	for (char qw : job)
	{
		if (qw < 0) break;
		fwrite(&qw, sizeof(char), 1, a);
	}

	// separate occupation and birthdate
	uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);

	// writing birthdate
	// year
	char temp;
	int t1 = date.year, t2 = 0;
	for (int i = 0; i < 4; i++)
	{
		t2 = t1 % 10;
		temp = (char)(48 + t2);
		fwrite(&temp, sizeof(char), 1, a);
		t1 /= 10;
	}



	uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);

	// month
	char temp2[2] = { "" };
	t1 = date.month, t2 = 0;
	for (int i = 0; i < 2; i++)
	{
		t2 = t1 % 10;
		temp2[1 - i] = (char)(48 + t2);
		t1 /= 10;
	}
	for (char qw : temp2)
		fwrite(&qw, sizeof(char), 1, a);

	uy = ' ';
	fwrite(&uy, sizeof(char), 1, a);

	// day
	char temp3[2] = { "" };
	t1 = date.day, t2 = 0;
	for (int i = 0; i < 2; i++)
	{
		t2 = t1 % 10;
		temp3[1 - i] = (char)(48 + t2);
		t1 /= 10;
	}
	for (char qw : temp3)
		fwrite(&qw, sizeof(char), 1, a);

	// finish writing a contact
	uy = '\n';
	fwrite(&uy, sizeof(char), 1, a);

	fclose(a);
}

void Kont::Display()
{
	cout << "Surname: ";
	for (char qw : surname)
		if (qw > 0)
			cout << qw;
	cout << endl;

	cout << "Name: ";
	for (char qw : name)
		if (qw > 0)
			cout << qw;
	cout << endl;

	cout << "Mobile phone: ";
	for (char qw : nom)
		if (qw > 0)
			cout << qw;
	cout << endl;

	cout << "Native city: ";
	for (char qw : city)
		if (qw > 0)
			cout << qw;
	cout << endl;

	cout << "Occupation: ";
	for (char qw : job)
		if (qw > 0)
			cout << qw;
	cout << endl;

	cout << "Birthday: ";
	cout << date.day;
	cout << ".";
	cout << date.month;
	cout << ".";
	cout << date.year;
	cout << endl;
}

void Kont::EditKont()
{

	cout << "What do you want to edit?" << endl;
	cout << "1 - Surname" << endl << "2 - Name" << endl;
	cout << "3 - Mobile phone" << endl << "4 - Native city" << endl << "5 - Occupation" << endl;
	cout << "6 - Birthdate";
	char r;
	cin >> r;
	switch (r)
	{
	case '1': cout << "Enter new surname: "; ChangeSurname(); break;
	case '2': cout << "Enter new name: "; ChangeName(); break;
	case '3': cout << "Enter new mobile phone: "; ChangeMob(); break;
	case '4': cout << "Enter new city: "; ChangeCity(); break;
	case '5': cout << "Enter new occupation: "; ChangeJob(); break;
	case '6': cout << "Enter new birthdate: "; ChangeBirth(); break;
	default:
		cout << "There is no such a commad";
	}
}

void Kont::ContDisplay(FILE* a)
{
	if ((a = fopen("Abonent.txt", "rb")) != NULL)
	{
		int ch;
		int noi = 1;
		char v = ' ';
		cout << noi << ')' << ' ';
		while ((ch = getc(a)) != EOF)
		{

			if ((int)v == 10)
			{
				noi++;
				cout << noi << ')' << ' ';

			}
			cout << (char)ch;
			v = ch;
		}
	}
}

void Kont::AddCont(FILE* a)
{
	char surname[64], name[64], numb[13], city[64], job[64];
	int year, month, day;

	cout << "Enter a surname: ";
	while (strlength(surname) == 0)
	{
		cin.getline(surname, 65);
		while (cin.fail())
		{
			cout << "Incorrect input!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(surname, 65);
		}
	}
	cout << "Enter a name: ";
	while (strlength(name) == 0)
	{
		cin.getline(name, 65);
		while (cin.fail())
		{
			cout << "Incorrect input!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(name, 65);
		}
	}
	cout << "Enter the number: +380";
	while (strlength(numb) == 0)
	{
		cin.getline(numb, 10);
		while (cin.fail())
		{
			cout << "Incorrect input!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "+380";
			cin.getline(numb, 10);
		}
	}
	cout << "Enter a native city: ";
	while (strlength(city) == 0)
	{
		cin.getline(city, 65);
		while (cin.fail())
		{
			cout << "Incorrect input!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(city, 65);
		}
	}
	cout << "Enter an occupation: ";
	while (strlength(job) == 0)
	{
		cin.getline(job, 65);
		while (cin.fail())
		{
			cout << "Incorrect input!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin.getline(job, 65);
		}
	}
	cout << "Enter your birthdate:" << endl;
	cout << "Year: ";
	cin >> year;
	while (cin.fail())
	{
		cout << "Incorrect Input!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> year;
	}
	cout << "Month: ";
	cin >> month;
	while (cin.fail())
	{
		cout << "Incorrect Input!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> month;
	}
	cout << "Day: ";
	cin >> day;
	while (cin.fail())
	{
		cout << "Incorrect Input!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> day;
	}

	
	if (!SetKont(surname, name, numb, city, job, year, month, day))
	{
		
		cout << "Please enter the contact again" << endl;
		system("pause");
		system("cls");
		AddCont(a);
	}
	Write(a);

	system("cls");
	cout << "The contact was successfully added" << endl;
	Display();
	system("pause");
	system("cls");

}

void Kont::EditCont(FILE* a)
{

	a = fopen("Abonent.txt", "rb");
	int i = 0;
	int nKont = 0;
	int ch;
	// here we count how many contacts the file has
	while ((ch = getc(a)) != EOF)
	{
		if (ch == 10)
			nKont++;
	}
	Kont* mas = new Kont[nKont];

	// here we form the 'Kont* mas'
	int Regulator = 0;
	char surname[64], name[64], nom[13], city[64], job[64];
	int year, month, day;
	fseek(a, 0, SEEK_SET);
	int j = 0;
	while ((ch = getc(a)) != EOF)
	{

		if (ch == 10)
		{
			Regulator++;
			Regulator = Regulator % 8;
			mas[i].SetKont(surname, name, nom, city, job, year, month, day);
			i++;
			j = 0;
			continue;
		}
		if (ch == 32)
		{
			Regulator++;
			j = 0;
			continue;
		}

		if (Regulator == 0)
		{
			surname[j] = (char)ch;
			j++;
		}
		else if (Regulator == 1)
		{
			name[j] = (char)ch;
			j++;
		}
		else if (Regulator == 2)
		{
			nom[j] = (char)ch;
			j++;
		}
		else if (Regulator == 3)
		{
			city[j] = (char)ch;
			j++;
		}
		else if (Regulator == 4)
		{
			job[j] = (char)ch;
			j++;
		}
		else if (Regulator == 5)
		{
			year = ch - '0';
			j++;
		}
		else if (Regulator == 6)
		{
			month = ch - '0';
			j++;
		}
		else
		{
			day = ch - '0';
			j++;
		}
	}

	// now the user chooses a contact which he wants to change
	for (int g = 0; g < nKont; g++)
	{
		cout << "Do you want to change this account?" << endl;
		mas[g].Display();
		cout << "Press 's' if yes" << endl;

		char s;
		cin >> s;
		if (s == 's')
		{
			i = g;
			break;
		}
		else
		{
			system("cls");
			if (g == nKont - 1)
				return;
			continue;
		}
		return;
	}


	mas[i].EditKont();
	system("cls");

	cout << "The contact was successfully edited" << endl;
	system("pause");
	system("cls");

	fclose(a);

	a = fopen("Abonent.txt", "w");

	for (int j = 0; j < nKont; j++)
	{
		mas[j].Write(a);
	}

	fclose(a);
}

void Kont::DelCont(FILE* a)
{
	a = fopen("Abonent.txt", "rb");
	int i = 0;
	int nKont = 0;
	int ch;
	// here we count how many contacts the file has
	while ((ch = getc(a)) != EOF)
	{
		if (ch == 10)
			nKont++;
	}
	Kont* mas = new Kont[nKont];

	// here we form the 'Kont* mas'
	int Regulator = 0;
	char surname[64], name[64], nom[13], city[64], job[64];
	int year, month, day;
	fseek(a, 0, SEEK_SET);
	int j = 0;
	while ((ch = getc(a)) != EOF)
	{

		if (ch == 10)
		{
			Regulator++;
			Regulator = Regulator % 8;
			mas[i].SetKont(surname, name, nom, city, job, year, month, day);
			i++;
			j = 0;
			continue;
		}
		if (ch == 32)
		{
			Regulator++;
			j = 0;
			continue;
		}

		if (Regulator == 0)
		{
			surname[j] = (char)ch;
			j++;
		}
		else if (Regulator == 1)
		{
			name[j] = (char)ch;
			j++;
		}
		else if (Regulator == 2)
		{
			nom[j] = (char)ch;
			j++;
		}
		else if (Regulator == 3)
		{
			city[j] = (char)ch;
			j++;
		}
		else if (Regulator == 4)
		{
			job[j] = (char)ch;
			j++;
		}
		else if (Regulator == 5)
		{
			year = ch - '0';
			j++;
		}
		else if (Regulator == 6)
		{
			month = ch - '0';
			j++;
		}
		else
		{
			day = ch - '0';
			j++;
		}
	}

	// now the user chooses a contact which he wants to delete
	for (int g = 0; g < nKont; g++)
	{
		cout << "Do you want to delete this account?" << endl;
		mas[g].Display();
		cout << "Press 's' if yes" << endl;

		char s;
		cin >> s;
		if (s == 's')
		{
			i = g;
			break;
		}
		else
		{
			system("cls");
			if (g == nKont - 1)
				return;
			continue;
		}
		return;
	}

	system("cls");
	cout << "The contact was successfully deleted" << endl;
	system("pause");
	system("cls");

	a = fopen("Abonent.txt", "w");


	for (int j = 0; j < nKont; j++)
	{
		if (j != i)
			mas[j].Write(a);
	}
	fclose(a);
	return;
}

int Kont::menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> Show all the contacts" << endl;
		else  cout << "   Show all the contacts" << endl;
		if (key == 1) cout << "-> Add a contact" << endl;
		else  cout << "   Add a contact" << endl;
		if (key == 2) cout << "-> Edit a contact" << endl;
		else  cout << "   Edit a contact" << endl;
		if (key == 3) cout << "-> Delete a contact" << endl;
		else  cout << "   Delete a contact" << endl;
		if (key == 4) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

void Kont::MENU(FILE* a)
{
	bool NonExit = 0;
	int answer = menu();
	switch (answer)
	{
	case 0: ContDisplay(a); break;
	case 1: AddCont(a); break;
	case 2: EditCont(a); break;
	case 3: DelCont(a); break;
	case 4: NonExit = 1; break;
	}
	system("pause");
	if (NonExit)
		return;
	else
		MENU(a);
}

bool Kont::Is_Surname_Corr(char* name)
{
	if (strlength(name) == 0) return false;
	for (int i = 0; i < strlength(name); i++)
		if (!isalpha(name[i]))
		{
			cout << "Incorrect Name Input!" << endl;
			return false;
		}
	return true;
}

bool Kont::Is_Num_Corr(char* mobilePhone)
{
	if (strlength(mobilePhone) == 0) return false;
	for (int i = 0; i < strlength(mobilePhone); i++) if (!isdigit(mobilePhone[i]) && mobilePhone[i] != '+')
	{
		cout << "Incorrect Phone Input!" << endl;
		return false;
	}
	return true;
}

bool Kont::Is_City_Corr(char* name)
{
	if (strlength(name) == 0) return false;
	for (int i = 0; i < strlength(name); i++)
		if (!isalpha(name[i]))
		{
			cout << "Incorrect Town Input!" << endl;
			return false;
		}
	return true;
}

bool Kont::Is_Birth_Corr(int year, int month, int day)
{
	if (year > 2019 || year < 1899)
		return false;
	if (month > 12 || month < 0 || day < 1)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	else if (month == 2)
	{
		if (year % 4 != 0 || year % 100 == 0)
		{
			if (day > 28)
				return false;
		}
		else
			if (day > 29)
				return false;
	}
	else
		if (day > 31)
			return false;


	return true;
}

void Kont::ChangeSurname()
{
	while (true)
	{
		char surnam[64] = { " " };
		while (surnam == " ")
			cin.getline(surnam, 64);
		if (Is_Surname_Corr(surnam))
			for (int i = 0; i < 64; i++)
			{
				if (surnam[i] != ' ')
					surname[i] = surnam[i];
				else
					return;
			}


	}
}

void Kont::ChangeName()
{
	while (true)
	{
		char nam[64] = { " " };
		while (nam == " ")
			cin.getline(nam, 64);
		if (Is_Name_Corr(nam))
			for (int i = 0; i < 64; i++)
			{
				if (nam[i] != ' ')
					name[i] = nam[i];
				else
					return;
			}


	}
}

void Kont::ChangeMob()
{

	while (true)
	{
		char mob[13] = { "e" };
		while (mob == "e")
			cin.getline(mob, 64);
		if (Is_Name_Corr(mob))
			for (int i = 0; i < 13; i++)
			{
				nom[i] = mob[i];
			}
	}

}

void Kont::ChangeCity()
{
	while (true)
	{
		char tow[64] = { " " };
		while (tow == " ")
			cin.getline(tow, 64);
		if (Is_City_Corr(tow))
			for (int i = 0; i < 64; i++)
			{
				if (tow[i] != ' ')
					city[i] = tow[i];
				else
					return;
			}
	}
}

void Kont::ChangeJob()
{
	while (true)
	{
		char work[64] = { " " };
		while (work == " ")
			cin.getline(work, 64);
		for (int i = 0; i < 64; i++)
		{
			if (work[i] != ' ')
				city[i] = work[i];
			else
				return;
		}
	}
}

void Kont::ChangeBirth()
{
	birthdate newdate;
	while (true)
	{
		try {
			cin >> newdate.day >> newdate.month >> newdate.year;
		}
		catch (int e)
		{
			cout << "Verify day, month and year!" << endl;
			continue;
		}
		if (Is_Birth_Corr(newdate.day, newdate.month, newdate.year))
		{
			date = newdate;
			return;
		}
	}
}

int Kont::strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0' && str[i] > 0) i++;
	return i;
}