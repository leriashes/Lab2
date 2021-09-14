#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <windows.h>
using namespace std;

//����
struct date {
	int day;	//����
	int month;	//�����
	int year;	//���
};

//���� ����
date enterDate() {
	date e_date;
	string dat;
	int f;

	do {
		do {
			f = 0;
			printf("������� ���� (��������: 01.01.1999): ");
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

//������ ����
void printDate(date p_date) {
	printf("%d.%d.%d", p_date.day, p_date.month, p_date.year);
	return;
}



//�����
struct author {
	char full_name[50];	//���
	date birth;			//���� ��������
	char country[30];	//������
};

//���� ���������� �� ������
author enterAuthor() {
	author e_author;
	printf("������� ��� ������: ");
	gets_s(e_author.full_name);

	printf("\n���� �������� ������\n");
	e_author.birth = enterDate();

	printf("\n������� ������ �������� ������: ");
	gets_s(e_author.country);

	return e_author;
}

//������ ���������� �� ������
void printAuthor(author p_author) {
	cout << p_author.full_name << "(";
	printDate(p_author.birth);
	cout << ", " << p_author.country << ")";

	return;
}



//�����
struct address {
	char city[30];	//�������� ���������� ������
	char street[40];	//�������� �����
	int house;		//����� ����
	int flat;		//����� ��������
};

//���� ������
address enterAddress() {
	address e_address;

	printf("������� �������� ���������� ������ (��������: �. �������): ");
	gets_s(e_address.city);

	printf("\n������� �������� �����: ");
	gets_s(e_address.street);

	printf("\n������� ����� ����: ");
	cin >> e_address.house;
	while (getchar() != '\n');

	printf("\n������� ����� ��������: ");
	cin >> e_address.flat;
	while (getchar() != '\n');

	return e_address;
}

//������ ������
void printAddress(address p_address) {
	cout << p_address.city << ", ��. " << p_address.street;
	printf(", �. %d, ��. %d", p_address.house, p_address.flat);

	return;
}



//��������
struct reader {
	char full_name[50];	//���
	date birth;			//���� ��������
	address r_address;	//�����
	int doc_number;		//����� ���������, ��������������� ��������
};

//���� ���������� � ��������
reader enterReader() {
	reader e_reader;

	printf("������� ��� ��������: ");
	gets_s(e_reader.full_name);

	printf("\n������� ����� ���������, ��������������� ��������: ");
	cin >> e_reader.doc_number;
	while (getchar() != '\n');

	printf("\n���� �������� ��������\n");
	e_reader.birth = enterDate();

	printf("\n����� ����������\n");
	e_reader.r_address = enterAddress();

	return e_reader;
}

//������ ���������� � ��������
void printReader(reader p_reader) {
	cout << p_reader.doc_number << " " << p_reader.full_name << " (���� ��������: ";
	printDate(p_reader.birth);
	printf("; �����: ");
	printAddress(p_reader.r_address);
	printf(")");

	return;
}



//������������
struct publishing {
	char name[30];	//��������
	char city[30];	//�����
};

//���� ���������� �� ������������
publishing enterPublishing() {
	publishing e_publishing;
	setlocale(LC_ALL, "Rus");
	printf("������� �������� ������������: ");
	gets_s(e_publishing.name);

	printf("\n������� �����, � ������� ��������� ������������: ");
	gets_s(e_publishing.city);

	return e_publishing;
}

//������ ���������� �� ������������
void printPublishing(publishing p_publishing) {
	cout << p_publishing.name << ", " << p_publishing.city;
	return;
}


//�����
struct book {
	char title[30];			//�������� �����
	author author_info;		//�����
	int pages_number;		//���������� �������
	char genre[20];			//����
	reader* reader_info = NULL;	//��������
	publishing publ_info;	//������������
	int publ_year;			//���
};

//���� ���������� � �����
book enterBook() {
	book e_book;

	printf("\n������� �������� �����: ");
	gets_s(e_book.title);

	printf("\n");
	e_book.author_info = enterAuthor();

	printf("\n������� ���������� ������� � �����: ");
	cin >> e_book.pages_number;
	while (getchar() != '\n');

	printf("\n������� ���� �����: ");
	gets_s(e_book.genre);

	printf("\n");
	e_book.publ_info = enterPublishing();

	printf("\n������� ��� ������� �����: ");
	cin >> e_book.publ_year;
	while (getchar() != '\n');

	return e_book;
}

//������ ���������� � �����
void printBook(book p_book) {
	cout << "\"" << p_book.title << "\", " << p_book.author_info.full_name << " / " << p_book.genre << ", " << p_book.publ_year << ", " << p_book.publ_info.name;
	if (p_book.reader_info != NULL)
		cout << " (" << p_book.reader_info->doc_number << " - " << p_book.reader_info->full_name << ")";
	return;
}