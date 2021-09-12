#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

//Дата
struct date {
	int day;	//День
	int month;	//Месяц
	int year;	//Год
};

//Автор
struct author {
	string full_name;	//ФИО
	date birth;			//Дата рождения
	date death;			//Дата смерти?
	string country;		//Страна
};

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
	date book_get;		//Дата взятия книги
	address r_address;	//Адрес
};

//Издательство
struct publishing {
	string name;	//Название
	string city;	//Город
};

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

	book *books;
	publishing *publishings;
	reader *readers;
	author *authors;

	do {
		system("cls");
		printf("demo Билиотека\n\n");

		char act;
		printf("1 Добавить новую книгу\n2 Добавить нового читателя\n3 Добавить нового писателя\n4 Добавить новове издательство\n5 Взятие книги\n6 Сдача книги\n\n7 Выход\n\nВведите номер действия ");
		do {
			act = _getch();
		} while (act < '1' || act > '7');

		act -= 48;
		if (act == 1) {

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