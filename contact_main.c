#include <stdio.h>
#include  "contact.h"

int main() {

	read_contact();

	while (1) {

		printf("----------------------------\n");
		printf("1:add contact\n");
		printf("2:show contact\n");
		printf("3:found contact\n");
		printf("4:delete contact\n");
		printf("5:modify contact\n");
		printf("6:exit\n");
		printf("input number:");

		int n;

		scanf("%d", &n);

		switch (n) {
		case 1:
			add_contact();
			sort_contact();
			save_contact();
			break;

		case 2:
			show_contact();
			break;

		case 3:
			find_contact();
			break;

		case 4:
			delete_contact();
			sort_contact();
			save_contact();
			break;

		case 5:
			modify_contact();
			save_contact();
			break;

		case 6:
			save_contact();
			return 0;
		}

	}
	return 0;
}