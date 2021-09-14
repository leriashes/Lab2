#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "../myLib.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");	//Для вывода на русском языке
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Статические переменные
	date date_st;
	address address_st;
	publishing publ_st;
	reader reader_st;
	author author_st;
	book book_st;

	//Динамические переменные
	date* date_d;
	address* address_d;
	publishing* publ_d;
	reader* reader_d;
	author* author_d;
	book* book_d;

	//Выделение памяти для динамических переменных
	date_d = (date*)malloc(sizeof(date));
	address_d = (address*)malloc(sizeof(address));
	publ_d = (publishing*)malloc(sizeof(publishing));
	reader_d = (reader*)malloc(sizeof(reader));
	author_d = (author*)malloc(sizeof(author));
	book_d = (book*)malloc(sizeof(book));

	//Работа со структурой date
	//Ввод данных
	date_st = enterDate();
	*date_d = enterDate();

	return 0;
}