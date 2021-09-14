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


	book* books = NULL, *d_book;
	reader* readers, *d_reader;

	int n_books = 0;
	int n_readers = 0;

	readers = (reader*)malloc(sizeof(reader));

	do {
		system("cls");
		printf("demo Билиотека\n\n");

		char act;
		printf("КНИГИ\n1 Добавить новую книгу\n2 Выдача книги\n3 Принятие книги\n4 Удалить книгу\n5 Список книг\n6 Вывод полной информации о книге\n\nЧИТАТЕЛИ\n7 Добавить нового читателя\n8 Список читателей\n9 Удалить читателя\n\n0 Выход\n\nВведите номер действия ");
		do {
			act = _getch();
		} while (act < '0' || act > '9');

		act -= 48;

		//Добавление новой книги
		if (act == 1) {
			system("cls");
			printf("demo Билиотека\n\nНОВАЯ КНИГА\n");

			n_books += 1;
			if (n_books == 1)
				books = (book*)malloc(sizeof(book));
			else
				books = (book*)realloc(books, sizeof(book) * n_books);
			*(books + n_books - 1) = enterBook();
			printf("\n");
			printBook(*(books + n_books - 1));

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Выдача книги
		else if (act == 2) {
			int inv_number, doc_numb, f;
			f = 1;

			system("cls");
			printf("demo Билиотека\n\nВЫДАЧА КНИГИ\n\n");

			if (n_readers > 0 && n_books > 0) {

				printf("Список книг\n\n");
				
				for (int i = 0; i < n_books; i++) {
					printf("%d) ", i + 1);
					printBook(*(books + i));
					printf("\n");
				}

				printf("\nВведите инвентарный номер книги: ");
				cin >> inv_number;
				while (getchar() != '\n');

				if (inv_number > 0 && inv_number <= n_books) {
					if ((books + inv_number - 1)->reader_info == NULL) {
						system("cls");
						printf("demo Билиотека\n\nВЫДАЧА КНИГИ\n\nКнига: %d) \"%s\"\n\nСписок читателей\n\n", inv_number, (books + inv_number - 1)->title);

						for (int i = 0; i < n_readers; i++) {
							printf("%d) ", i + 1);
							printReader(*(readers + i));
							printf("\n");
						}
						printf("\nВведите номер документа читателя: ");
						cin >> doc_numb;
						while (getchar() != '\n');

						for (int i = 0; i < n_readers && f; i++) {
							if ((readers + i)->doc_number == doc_numb) {
								(books + inv_number - 1)->reader_info = (readers + i);
								f = 0;
							}
						}

						if (f)
							printf("\nЧитателя с таким номером документа нет.");
						else
							printf("\nКнига выдана читателю: %d - %s.", (books + inv_number - 1)->reader_info->doc_number, (books + inv_number - 1)->reader_info->full_name);
					}
					else
						printf("\nКнига уже была выдана читателю: %d - %s.", (books + inv_number - 1)->reader_info->doc_number, (books + inv_number - 1)->reader_info->full_name);
				}
				else
					printf("\nКниги с таким инвентарным номером нет.");
			}
			else if (n_readers == 0)
				printf("Список читателей пуст.");
			else
				printf("Список книг пуст.");

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");

		}

		//Принятие книги
		else if (act == 3) {
			int inv_number;
			system("cls");
			printf("demo Билиотека\n\nПРИНЯТИЕ КНИГИ\n\n");

			if (n_readers > 0 && n_books > 0) {

				printf("Список книг\n\n");

				for (int i = 0; i < n_books; i++) {
					printf("%d) ", i + 1);
					printBook(*(books + i));
					printf("\n");
				}

				printf("Введите инвентарный номер книги: ");
				cin >> inv_number;
				while (getchar() != '\n');

				if (inv_number > 0 && inv_number <= n_books) {
					if ((books + inv_number - 1)->reader_info != NULL) {
						(books + inv_number - 1)->reader_info = NULL;
						printf("\nКнига принята.");
					}
					else
						printf("\nКнига уже находится в библиотеке.");
				}
				else
					printf("\nКниги с таким инвентарным номером нет.");
			}
			else if (n_readers == 0)
				printf("Список читателей пуст.");
			else
				printf("Список книг пуст.");

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Удаление книги
		else if (act == 4) {
			int inv_number;
			system("cls");
			printf("demo Билиотека\n\nУДАЛЕНИЕ КНИГИ\n\n");

			if (n_books > 0) {

				printf("Список книг\n\n");

				for (int i = 0; i < n_books; i++) {
					printf("%d) ", i + 1);
					printBook(*(books + i));
					printf("\n");
				}

				printf("Введите инвентарный номер книги: ");
				cin >> inv_number;
				while (getchar() != '\n');

				if (inv_number > 0 && inv_number <= n_books) {
					d_book = (book*)calloc(n_books - 1, sizeof(book));
					for (int i = 0, j = 0; i < n_books; i++)
						if (i != inv_number - 1) {
							*(d_book + j) = *(books + i);
							j++;
						}
					n_books--;
					free(books);
					books = (book*)calloc(n_books, sizeof(book));
					for (int i = 0; i < n_books; i++)
						*(books + i) = *(d_book + i);
					free(d_book);
					printf("\nКнига удалена.");
				}
				else
					printf("\nКниги с таким инвентарным номером нет.");
			}
			else
				printf("Список книг пуст.");

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Вывод списка книг
		else if (act == 5) {
			system("cls");
			printf("demo Билиотека\n\nСПИСОК КНИГ\n\n");

			if (n_books < 1)
				printf("Список пуст.");
			else
				for (int i = 0; i < n_books; i++) {
					printf("%d) ", i + 1);
					printBook(*(books + i));
					printf("\n");
				}

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Вывод полной информации о книге
		else if (act == 6) {
		int inv_number;
		system("cls");
		printf("demo Билиотека\n\nИНФОРМАЦИЯ О КНИГЕ\n\n");

		if (n_books > 0) {

			printf("Список книг\n\n");

			for (int i = 0; i < n_books; i++) {
				printf("%d) ", i + 1);
				printBook(*(books + i));
				printf("\n");
			}

			printf("\nВведите инвентарный номер книги: ");
			cin >> inv_number;
			while (getchar() != '\n');

			if (inv_number > 0 && inv_number <= n_books) {

				system("cls");
				printf("demo Билиотека\n\nИНФОРМАЦИЯ О КНИГЕ\n\n");
				printf("Инвентарный номер: %d\n\n", inv_number);
				printf("КНИГА\n");
				printf("Название: \"%s\"", (books + inv_number - 1)->title);
				printf("\nЖанр: %s", (books + inv_number - 1)->genre);
				printf("\nКоличество страниц: %d", (books + inv_number - 1)->pages_number);
				printf("\nГод публикации: %d", (books + inv_number - 1)->publ_year);

				printf("\n\nАВТОР\n");
				printAuthor((books + inv_number - 1)->author_info);

				printf("\n\nИЗДАТЕЛЬСТВО\n");
				printPublishing((books + inv_number - 1)->publ_info);

				if ((books + inv_number - 1)->reader_info != NULL) {
					printf("\n\nЧИТАТЕЛЬ\n");
					printReader(*(books + inv_number - 1)->reader_info);
				}
			}
			else
				printf("\nКниги с таким инвентарным номером нет.");
		}
		else
			printf("Список книг пуст.");

		printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Добавление нового читателя
		else if (act == 7) {
			system("cls");
			printf("demo Билиотека\n\nНОВЫЙ ЧИТАТЕЛЬ\n\n");

			n_readers += 1;
			if (n_readers == 1) {
				free(readers);
				readers = (reader*)malloc(sizeof(reader));
			}
			else
				readers = (reader*)realloc(readers, sizeof(reader) * n_readers);
			*(readers + n_readers - 1) = enterReader();
			printf("\n");
			printReader(*(readers + n_readers - 1));

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Вывод списка читателей
		else if (act == 8) {
			system("cls");
			printf("demo Билиотека\n\nСПИСОК ЧИТАТЕЛЕЙ\n\n");

			if (n_readers < 1)
				printf("Список пуст.");
			else
				for (int i = 0; i < n_readers; i++) {
					printf("%d) ", i + 1);
					printReader(*(readers + i));
					printf("\n");
				}

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		//Удаление читателя
		else if (act == 9) {
			int doc_numb, f = -1;
			system("cls");
			printf("demo Билиотека\n\nУДАЛЕНИЕ ЧИТАТЕЛЯ\n\n");

			if (n_readers > 0) {
				printf("Список читателей\n\n");

				for (int i = 0; i < n_readers; i++) {
					printf("%d) ", i + 1);
					printReader(*(readers + i));
					printf("\n");
				}
				printf("Введите номер документа читателя: ");
				cin >> doc_numb;
				while (getchar() != '\n');

				for (int i = 0; i < n_readers && f == -1; i++)
					if ((readers + i)->doc_number == doc_numb)
						f = i;

				if (f == -1)
					printf("\nЧитателя с таким номером документа нет.");
				else {
					d_reader = (reader*)calloc(n_readers - 1, sizeof(reader));
					for (int i = 0, j = 0; i < n_readers; i++)
						if (i != f) {
							*(d_reader + j) = *(readers + i);
							j++;
						}
					n_readers--;
					free(readers);
					readers = (reader*)calloc(n_readers, sizeof(reader));
					for (int i = 0; i < n_readers; i++)
						*(readers + i) = *(d_reader + i);
					free(d_reader);
					printf("\nЧитатель удалён.");
				}

			}
			else
				printf("Список читателей пуст.");

			printf("\n\nНажмите любую клавишу для выхода в меню, для выхода из программы нажмите esc.");
		}

		else {
			system("cls");
			printf("demo Билиотека\n\n");
			printf("\n\nВы уверены, что хотите выйти? (Для выхода нажмите esc, для продолжения - любую клавишу.) ");
		}

	} while (_getch() != 27);

	free(readers);
	free(books);
	return 0;
}