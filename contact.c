#include <stdio.h>
#include <string.h>
#include  "contact.h"

static int count = 0;
contact book[100];

void modify_contact() {
	char name[20];
	int counter = 0;

	printf("input name to modify:");
	scanf("%s", name);

	for (int i = 0; i < count; i++) {
		if (strcmp(book[i].name, name) == 0) {

			printf("input new phone:");

			scanf("%s", book[i].phone);

			printf("modify success");

			counter = 1;
			break;
		}
	}
	if (counter == 0) {
		printf("contact not found\n");
		return;
	}
}

void sort_contact() {
	contact temp;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
		{
			if (strcmp(book[j].name, book[j + 1].name) > 0) {

				temp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = temp;

			}
		}
	}
	printf("sort success\n");
}

void save_contact() {
	FILE* pf;
	pf = fopen("contact_dat", "wb");

	if (pf == NULL) {
		printf("file open error\n");
		return;
	}

	fwrite(book, sizeof(contact), count, pf);
	fclose(pf);
}

void read_contact() {
	FILE* pf;
	pf = fopen("contact_dat", "rb");

	if (pf == NULL) {
		return;
	}

	count = fread(book, sizeof(contact), 100, pf);
	fclose(pf);
}

void add_contact() {
	if (count >= 100) {

		printf("list full");
		return;
	}
	printf("input contract name\n");

	scanf("%s", book[count].name);

	printf("input contract phone\n");

	scanf("%s", book[count].phone);

	count++;
}

void show_contact() {
	if (count == 0) {

		printf("no contact\n");

		return;
	}
	for (int i = 0; i < count; i++) {

		printf("contract name:%s\n", book[i].name);

		printf("contract phone:%s\n", book[i].phone);
	}
}

void find_contact() {
	char name[20];
	int found = 0;
	printf("input name to found:");
	scanf("%s", name);
	for (int i = 0; i < count; i++) {
		if (strcmp(book[i].name, name) == 0) {

			printf("name:%s\n", book[i].name);

			printf("phone:%s\n", book[i].phone);

			found = 1;

			break;
		}
	}
	if (found == 0) {
		printf("contact not found \n");
		return;
	}
}

void delete_contact() {

	char name[20];
	int delete = -1;

	printf("input name to delete:");
	scanf("%s", name);

	for (int i = 0; i < count; i++) {

		if (strcmp(book[i].name, name) == 0) {
			delete = i;
			break;
		}
	}
	if (delete == -1) {
		printf("contact not found \n");
		return;
	}
	for (int i = delete; i < count - 1; i++) {
		book[i] = book[i + 1];
	}
	count--;
	printf("contact delete scuessful\n ");
}