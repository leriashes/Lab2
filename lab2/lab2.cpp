#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

//Дата
struct date {
	int day;	//День
	int month;	//Месяц
	int year;	//Год
};

//Установка значений по умолчанию
date setDate() {
	date s_date;
	s_date.day = s_date.month = s_date.year = 0;
	return s_date;
}

//Ввод даты
date enterDate() {
	date e_date;
	char dat[10];

	printf("Введите дату (например: 01.01.1999): ");
	gets_s(dat);

	e_date.day = dat[0] * 10 + dat[1];
	e_date.month = dat[3] * 10 + dat[4];
	e_date.year = dat[6] * 1000 + dat[7] * 100 + dat[8] * 10 + dat[9];

	return e_date;
}

//Печать даты
void printDate(date p_date) {
	printf("%d.%d.%d", p_date.day, p_date.month, p_date.year);
	return;
}



//Автор
struct author {
	string full_name;	//ФИО
	date birth;			//Дата рождения
	string country;		//Страна
};

//Ввод информации об авторе
author enterAuthor() {
	author e_author;
	printf("Введите ФИО автора: ");
	getline(cin, e_author.full_name);

	printf("\nДата рождения автора\n");
	e_author.birth = enterDate();

	printf("\nВведите страну рождения автора: ");
	getline(cin, e_author.country);

	return e_author;
}

//Печать информации об авторе
void printAuthor(author p_author) {
	printf("%s (", p_author.full_name);
	printDate(p_author.birth);
	printf(", %s)", p_author.country);

	return;
}



//Адрес
struct address {
	string city;	//Название населённого пункта
	string street;	//Название улицы
	int house;		//Номер дома
	int flat;		//Номер квартиры
};

//Читатель
struct reader {
	string full_name;	//ФИО
	date birth;			//Дата рождения
	address r_address;	//Адрес
	int doc_number;		//Номер документа, удостоверяющего личность
};


//Издательство
struct publishing {
	string name;	//Название
	string city;	//Город
};

//Ввод информации об издательстве
publishing enterPublishing() {
	publishing e_publishing;
	setlocale(LC_ALL, "Rus");
	printf("Введите название издательства: ");
	getline(cin, e_publishing.name);

	printf("\nВведите город, в котором находится издательство: ");
	getline(cin, e_publishing.city);

	return e_publishing;
}

//Печать информации об издательстве
void printPublishing(publishing p_publishing) {
	cout << p_publishing.name << ", " << p_publishing.city;
	return;
}


//Книга
struct book {
	string title;			//Название книги
	author author_info;		//Автор
	int pages_number;		//Количество страниц
	string genre;			//Жанр
	reader reader_info;		//Читатель
	publishing publ_info;	//Издательство
	int inv_number;			//Инвентарный номер
	int publ_year;			//Год
};

int main() {
	setlocale(LC_ALL, "Rus");	//Для вывода на русском языке
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	book *books;
	publishing *publishings;
	reader *readers;
	author *authors;
	
	do {
		system("cls");
		printf("demo Билиотека\n\n");

		publishing p = enterPublishing();
		printPublishing(p);
		string newfilm;
		getline(cin, newfilm);

		char act;
		printf("1 Добавить новую книгу\n2 Добавить нового читателя\n3 Добавить нового писателя\n4 Добавить новове издательство\n5 Взятие книги\n6 Сдача книги\n\n7 Выход\n\nВведите номер действия ");
		do {
			act = _getch();
		} while (act < '1' || act > '7');

		act -= 48;
		if (act == 1) {
			;
		}
		else if (act == 2) {
			;
		}
		else if (act == 3) {
			;
		}
		else if (act == 4) {

		}
		else if (act == 5) {
			;
		}
		else if (act == 6) {
			;
		}
		else {
			printf("\n\nВы уверены, что хотите выйти? (Для выхода нажмите esc, для продолжения - любую клавишу.) ");
		}

	} while (_getch() != 27);

	return 0;
}