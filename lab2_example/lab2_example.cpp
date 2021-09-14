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
	printf("Работа со структурой date\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	date_st = enterDate();

	printf("\nВвод данных в динамическую переменную\n");
	*date_d = enterDate();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printDate(date_st);

	printf("\n\nПечать данных динамической переменной\n");
	printDate(*date_d);



	//Работа со структурой address
	printf("\n\n\nРабота со структурой address\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	address_st = enterAddress();

	printf("\nВвод данных в динамическую переменную\n");
	*address_d = enterAddress();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printAddress(address_st);

	printf("\n\nПечать данных динамической переменной\n");
	printAddress(*address_d);


	//Работа со структурой publishing
	printf("\n\n\nРабота со структурой publishing\n");
	//Ввод данных
	printf("Ввод данных в статическую переменную\n");
	publ_st = enterPublishing();

	printf("\nВвод данных в динамическую переменную\n");
	*publ_d = enterPublishing();

	//Вывод данных
	printf("\n\nПечать данных статической переменной\n");
	printPublishing(publ_st);

	printf("\n\nПечать данных динамической переменной\n");
	printPublishing(*publ_d);
	return 0;
}