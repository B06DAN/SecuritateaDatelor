#include<stdio.h>



char* alfabet = "abcdefghijklmnopqrstuvwxyz";
char tabel[5][5];

struct position {
	int x;
	int y;
};

void StergeLitereleDuplicate(char text[])
{
	int i, j, k;
	int lungimeText = strlen(text);
	for (i = 0; i < lungimeText; ++i)
	{
		for (j = i + 1; text[j] != '\0'; ++j)
		{
			if (text[j] == text[i])
			{
				for (k = j; text[k] != '\0'; ++k)
				{
					if (text[k] == text[k + 1])
					{
						j -= 1;
					}
					text[k] = text[k + 1];
				}
			}
		}
	}
}

struct position DetecteazaPozitia(char letter)
{
	int i, j;
	struct position letterposition;

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (tabel[i][j] == letter)
			{
				letterposition.x = i;
				letterposition.y = j;
				return letterposition;

			}
		}
	}
	struct position letterposition1;
	letterposition1.x = 0;
	letterposition1.y = 0;
	return letterposition1;
}


void CreazaTabel(char key[])
{
	char* currentAlfabet = strcat(key, alfabet);
	int i, j, k = 0;
	for (i = 0; i < strlen(currentAlfabet); ++i)
	{
		if (currentAlfabet[i] == 'j')
		{
			currentAlfabet[i] = alfabet[8];
		}
	}
	StergeLitereleDuplicate(currentAlfabet);

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			tabel[i][j] = currentAlfabet[k];
			k++;
			printf("%c ", tabel[i][j]);
		}
		printf("\n");
	}

}

void Criptare(char text[], char key[])
{

	CreazaTabel(key);
	int i;
	struct position pozitieCurrenta1;
	struct position pozitieCurrenta2;

	char textCriptat[100];
	strcpy(textCriptat, text);
	int lungimeText = strlen(textCriptat);
	for (i = 0; i < lungimeText; i += 2)
	{
		pozitieCurrenta1 = DetecteazaPozitia(textCriptat[i]);
		if (i + 1 < lungimeText) {
			pozitieCurrenta2 = DetecteazaPozitia(textCriptat[i + 1]);
		}
		else {
			pozitieCurrenta2 = DetecteazaPozitia('x');
		}

		if (textCriptat[i] == textCriptat[i + 1])
		{
			pozitieCurrenta2 = DetecteazaPozitia('x');
		}

		if (pozitieCurrenta1.x - pozitieCurrenta2.x == 0)
		{
			textCriptat[i] = tabel[pozitieCurrenta1.x][(pozitieCurrenta1.y + 1) % 5];
			textCriptat[i + 1] = tabel[pozitieCurrenta2.x][(pozitieCurrenta2.y + 1) % 5];
		}
		else if (pozitieCurrenta1.y - pozitieCurrenta2.y == 0)
		{
			textCriptat[i] = tabel[(pozitieCurrenta1.x + 1) % 5][pozitieCurrenta1.y];
			textCriptat[i + 1] = tabel[(pozitieCurrenta2.x + 1) % 5][pozitieCurrenta2.y];
		}
		else {
			textCriptat[i] = tabel[pozitieCurrenta1.x][pozitieCurrenta2.y];
			textCriptat[i + 1] = tabel[pozitieCurrenta2.x][pozitieCurrenta1.y];
		}
	}
	printf("%s ", textCriptat);
}

void Decriptare(char text[], char key[])
{
	CreazaTabel(key);
	int i;
	struct position pozitieCurrenta1;
	struct position pozitieCurrenta2;

	char textCriptat[100];
	strcpy(textCriptat, text);
	int lungimeText = strlen(textCriptat);
	for (i = 0; i < lungimeText; i += 2)
	{
		pozitieCurrenta1 = DetecteazaPozitia(textCriptat[i]);
		if (i + 1 < lungimeText) {
			pozitieCurrenta2 = DetecteazaPozitia(textCriptat[i + 1]);
		}
		else {
			pozitieCurrenta2 = DetecteazaPozitia('x');
		}

		if (textCriptat[i] == textCriptat[i + 1])
		{
			pozitieCurrenta2 = DetecteazaPozitia('x');
		}

		if (pozitieCurrenta1.x - pozitieCurrenta2.x == 0)
		{
			if (pozitieCurrenta1.y - 1 > 0) {
				textCriptat[i] = tabel[pozitieCurrenta1.x][(pozitieCurrenta1.y - 1) % 5];
			}
			else {
				textCriptat[i] = tabel[pozitieCurrenta1.x][5 + (pozitieCurrenta1.y - 1)]; 
			}
			if (pozitieCurrenta2.y - 1 > 0) {
				textCriptat[i + 1] = tabel[pozitieCurrenta2.x][(pozitieCurrenta2.y - 1) % 5];
			}
			else {
				textCriptat[i + 1] = tabel[pozitieCurrenta2.x][5 + (pozitieCurrenta2.y - 1)];
			}

		}
		else if (pozitieCurrenta1.y - pozitieCurrenta2.y == 0)
		{
			if (pozitieCurrenta1.x - 1 >= 0) {
				textCriptat[i] = tabel[(pozitieCurrenta1.x - 1) % 5][pozitieCurrenta1.y];
			}
			else {
				textCriptat[i] = tabel[5 + (pozitieCurrenta1.x - 1)][pozitieCurrenta1.y];
			}

			if (pozitieCurrenta2.x - 1 >= 0)
			{
				textCriptat[i + 1] = tabel[(pozitieCurrenta2.x - 1) % 5][pozitieCurrenta2.y];
			}
			else {
				textCriptat[i + 1] = tabel[5 + (pozitieCurrenta2.x - 1)][pozitieCurrenta2.y];
			}

		}
		else {
			textCriptat[i] = tabel[pozitieCurrenta1.x][pozitieCurrenta2.y];
			textCriptat[i + 1] = tabel[pozitieCurrenta2.x][pozitieCurrenta1.y];
		}
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
			Criptare(mesaj, key);
		}
		else if (alegere == 2) {

			printf("Introduceti mesajul: ");
			scanf_s("%s", mesaj, sizeof(mesaj));
			printf("Introduceti cheia: ");
			scanf_s("%s", key, sizeof(key));
			Decriptare(mesaj, key);
		}
		else {
			printf("Alegeti dintre 1 si 2 ! \n");
		}
	}
	return 0;
}