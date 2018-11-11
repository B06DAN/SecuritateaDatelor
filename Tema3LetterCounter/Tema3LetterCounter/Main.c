#include <stdio.h>
#include <ctype.h>

int main() {
	char mesaj[100];
	char* alfabet = "abcdefghijklmnopqrstuvwxyz";
	int i, j;
	int count = 0;

		printf("Introduceti cuvantul: ");
		scanf_s("%[^'\n']s", mesaj, sizeof(mesaj));
		for (i = 0; i < strlen(alfabet); ++i) {
			for (j = 0; j < strlen(mesaj); ++j) {
				if (alfabet[i] == mesaj[j]) {
					count++;
				}
			}
			printf("%c este de %d \n", alfabet[i], count);
			count = 0;
		}
	return 0;
}