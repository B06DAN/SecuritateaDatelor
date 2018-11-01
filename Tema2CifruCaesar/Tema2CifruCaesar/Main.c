#include <stdio.h>


int main()
{
	int alegere,key;
	char mesaj[100];
	while (1)
	{		
		printf("\n");
		printf("1) CRIPTARE \n");
		printf("2) DECRIPTARE \n");
		scanf_s("%d", &alegere);

		if (alegere == 1) {
			printf("Introduceti mesajul: ");
			scanf_s("%s", &mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%d", &key);
			printf("Mesajul \"%s\" criptat cu cheia %d este: ", &mesaj, key);
			for (int i = 0; i < strlen(mesaj); ++i)
			{			
				if (mesaj[i] + key < 'z') {
					printf("%c", mesaj[i] + key);
				}
				else if (mesaj[i] + key > 'z') {
					printf("%c", (mesaj[i] + key) - 26);
				}
			}
		}
		else if(alegere==2){
			printf("Introduceti mesajul: ");
			scanf_s("%s", &mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%d", &key);
			printf("Mesajul \"%s\" decriptat cu cheia %d este: ", &mesaj, key);
			for (int i = 0; i < strlen(mesaj); ++i)
			{			
				 if (mesaj[i] + key > 'a') {
					printf("%c", mesaj[i] - key);
				}
				else if (mesaj[i] + key < 'a') {
					printf("%c", (mesaj[i] - key) + 26);
				}
			}
		}
		else {
			printf("Alegeti dintre 1 si 2 \n");
		}
	}
}