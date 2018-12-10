#include<stdio.h>

char* alfabet = "abcdefghijklmnopqrstuvwxyz";

void CRIPTARE(char mesaj[], char key[])
{
	int i;
	strcat(key, mesaj);
	for (i = 0; i < strlen(mesaj); ++i)
	{
		int literaMesaj = tolower(mesaj[i]) - 'a';
		int literaCheie = tolower(key[i]) - 'a';
		printf("%c", alfabet[(literaMesaj + literaCheie) % strlen(alfabet)]);
	}
}

void DECRIPTARE(char mesaj[], char key[])
{
	int i;
	int literaCheie;
	char c;
	for (i = 0; i < strlen(mesaj); ++i)
	{
		int literaText = tolower(mesaj[i]) - 'a';
		if (i < strlen(key)) {
			literaCheie = tolower(key[i]) - 'a';
		}
		else {
			literaCheie = tolower(c) - 'a';
		}

		c = alfabet[(literaText - literaCheie + strlen(alfabet)) % strlen(alfabet)];
		printf("%c", c);

	}
}

int main()
{
	int alegere;
	char key[100];
	char mesaj[100];
	while (1)
	{
		printf("\n");
		printf("1) CRIPTARE \n");
		printf("2) DECRIPTARE \n");
		scanf_s("%d", &alegere);
		if (alegere == 1) {

			printf("Introduceti mesajul: ");
			scanf_s("%s", mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%s", key, sizeof(key));
			CRIPTARE(mesaj, key);
		}
		else if (alegere == 2) {

			printf("Introduceti mesajul: ");
			scanf_s("%s", mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%s", key, sizeof(key));
			DECRIPTARE(mesaj, key);
		}
		else {
			printf("Alegeti dintre 1 si 2 ! \n");
		}
	}
	return 0;
}