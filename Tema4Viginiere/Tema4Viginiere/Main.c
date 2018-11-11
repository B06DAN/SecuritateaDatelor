#include <stdio.h>

char* alfabet = "abcdefghijklmnopqrstuvwxyz";

void CRIPTARE(char mesaj[], char key[])
{
	int i;
	int literaMesaj, literaKey;
	for (i = 0; i < strlen(mesaj); ++i)
	{
		literaMesaj = mesaj[i] - 'a';
		literaKey = key[i % strlen(key)] - 'a';
		printf("Litera criptata %c cu cheia %c este %c \n",mesaj[i],key[i], alfabet[(literaMesaj + literaKey) % strlen(alfabet)]);
	}
}

void DECRIPTARE(char mesaj[], char key[])
{
	int i;
	int literaMesaj, literaKey;
	for (i = 0; i < strlen(mesaj); ++i)
	{
		literaMesaj = mesaj[i] - 'a';
		literaKey = key[i % strlen(key)] - 'a';
		printf("Litera criptata %c cu cheia %c este %c \n", mesaj[i], key[i], alfabet[(literaMesaj - literaKey + strlen(alfabet)) % strlen(alfabet)]);
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
		else{
			printf("Alegeti dintre 1 si 2 ! \n");
		}
	}
	return 0;
}