#include <stdio.h>

int main()
{
	int alegere;
	int key;
	char mesaj[100];
	//int i;

	while (1)
	{		
		printf("1) CRIPTARE \n");
		printf("2) DECRIPTARE \n");
		scanf_s("%d", &alegere);

		if (alegere == 1) {
			printf("Introduceti mesajul: ");
			scanf_s("%s", &mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%d", &key);

			for (int i = 0; i < strlen(mesaj); ++i)
			{			
				if (mesaj[i] + key < 'z') {
					printf("%c", mesaj[i] + key);
					printf("\n");
				}
				else if (mesaj[i] + key > 'z') {
					printf("%c", (mesaj[i] + key) - 26);
					printf("\n");
				}
			}
		}
		else if(alegere==2){
			printf("Introduceti mesajul: ");
			scanf_s("%s", &mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%d", &key);

			for (int i = 0; i < strlen(mesaj); ++i)
			{			
				 if (mesaj[i] + key > 'a') {
					printf("%c", mesaj[i] - key);
					printf("\n");
				}
				else if (mesaj[i] + key < 'a') {
					printf("%c", (mesaj[i] - key) + 26);
					printf("\n");
				}

			}
		}
		else {
			printf("Alegeti dintre 1 si 2 \n");
		}
	}
	return 0;
}