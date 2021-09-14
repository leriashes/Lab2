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

//Ввод даты
date enterDate() {
	date e_date;
	string dat;
	int f;

	do {
		do {
			f = 0;
			printf("Введите дату (например: 01.01.1999): ");
			getline(cin, dat);

			if (dat.length() >= 10) {
				for (int i = 0; i < 10; i++)
					if (i != 2 && i != 5 && !isdigit(dat[i]))
						f = 1;
			}
			else
				f = 1;

		} while (f);

		e_date.day = dat[0] * 10 + dat[1] - 528;
		e_date.month = dat[3] * 10 + dat[4] - 528;
		e_date.year = dat[6] * 1000 + dat[7] * 100 + dat[8] * 10 + dat[9] - 53328;

		if (e_date.day < 1 || e_date.day > 31 || e_date.month < 1 || e_date.month > 12 || e_date.year < 1 || e_date.year > 2100)
			f = 1;
	} while (f);

	return e_date;
}

//Печать даты
void printDate(date p_date) {
	printf("%d.%d.%d", p_date.day, p_date.month, p_date.year);
	return;
}



//Автор
struct author {
	char full_name[50];	//ФИО
	date birth;			//Дата рождения
	char country[30];	//Страна
};

//Ввод информации об авторе
author enterAuthor() {
	author e_author;
	printf("Введите ФИО автора: ");
	gets_s(e_author.full_name);

	printf("\nДата рождения автора\n");
	e_author.birth = enterDate();

	printf("\nВведите страну рождения автора: ");
	gets_s(e_author.country);

	return e_author;
}

//Печать информации об авторе
void printAuthor(author p_author) {
	cout << p_author.full_name << "(";
	printDate(p_author.birth);
	cout << ", " << p_author.country << ")";

	return;
}



//Адрес
struct address {
	char city[30];	//Название населённого пункта
	char street[40];	//Название улицы
	int house;		//Номер дома
	int flat;		//Номер квартиры
};

//Ввод адреса
address enterAddress() {
	address e_address;

	printf("Введите название населённого пункта (например: г. Барнаул): ");
	gets_s(e_address.city);

	printf("\nВведите название улицы: ");
	gets_s(e_address.street);

	printf("\nВведите номер дома: ");
	cin >> e_address.house;
	while (getchar() != '\n');

	printf("\nВведите номер квартиры: ");
	cin >> e_address.flat;
	while (getchar() != '\n');

	return e_address;
}

//Печать адреса
void printAddress(address p_address) {
	cout << p_address.city << ", ул. " << p_address.street;
	printf(", д. %d, кв. %d", p_address.house, p_address.flat);

	return;
}



//Читатель
struct reader {
	char full_name[50];	//ФИО
	date birth;			//Дата рождения
	address r_address;	//Адрес
	int doc_number;		//Номер документа, удостоверяющего личность
};

//Ввод информации о читателе
reader enterReader() {
	reader e_reader;

	printf("Введите ФИО читателя: ");
	gets_s(e_reader.full_name);

	printf("\nВведите номер документа, удостоверяющего личность: ");
	cin >> e_reader.doc_number;
	while (getchar() != '\n');

	printf("\nДата рождения читателя\n");
	e_reader.birth = enterDate();

	printf("\nАдрес проживания\n");
	e_reader.r_address = enterAddress();

	return e_reader;
}

//Печать информации о читателе
void printReader(reader p_reader) {
	cout << p_reader.doc_number << " " << p_reader.full_name << " (дата рождения: ";
	printDate(p_reader.birth);
	printf("; адрес: ");
	printAddress(p_reader.r_address);
	printf(")");

	return;
}



//Издательство
struct publishing {
	char name[30];	//Название
	char city[30];	//Город
};

//Ввод информации об издательстве
publishing enterPublishing() {
	publishing e_publishing;
	setlocale(LC_ALL, "Rus");
	printf("Введите название издательства: ");
	gets_s(e_publishing.name);

	printf("\nВведите город, в котором находится издательство: ");
	gets_s(e_publishing.city);

	return e_publishing;
}

//Печать информации об издательстве
void printPublishing(publishing p_publishing) {
	cout << p_publishing.name << ", " << p_publishing.city;
	return;
}


//Книга
struct book {
	char title[30];			//Название книги
	author author_info;		//Автор
	int pages_number;		//Количество страниц
	char genre[20];			//Жанр
	reader* reader_info = NULL;	//Читатель
	publishing publ_info;	//Издательство
	int publ_year;			//Год
};

//Ввод информации о книге
book enterBook() {
	book e_book;

	printf("\nВведите название книги: ");
	gets_s(e_book.title);

	printf("\n");
	e_book.author_info = enterAuthor();

	printf("\nВведите количество страниц в книге: ");
	cin >> e_book.pages_number;
	while (getchar() != '\n');

	printf("\nВведите жанр книги: ");
	gets_s(e_book.genre);

	printf("\n");
	e_book.publ_info = enterPublishing();

	printf("\nВведите год выпуска книги: ");
	cin >> e_book.publ_year;
	while (getchar() != '\n');

	return e_book;
}

//Печать информации о книге
void printBook(book p_book) {
	cout << "\"" << p_book.title << "\", " << p_book.author_info.full_name << " / " << p_book.genre << ", " << p_book.publ_year << ", " << p_book.publ_info.name;
	if (p_book.reader_info != NULL)
		cout << " (" << p_book.reader_info->doc_number << " - " << p_book.reader_info->full_name << ")";
	return;
}