#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

struct date {
	int day;	//День
	int month;	//Месяц
	int year;	//Год
};

struct author {
	string full_name;	//ФИО
	date birth;			//Дата рождения
	date death;			//Дата смерти?
	string country;		//Страна
};

struct reader {
	string full_name;	//ФИО
	date birth;			//Дата рождения
	date book_get;		//Дата взятия книги
	string address;		//Адрес
};

struct publishing {
	string name;	//Название
	string city;	//Город
};

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

}