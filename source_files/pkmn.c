
#include "pkmn.h" //inclusione del corrispondente file header.

void nesload(int pkmn_id, int* pkmn_nes)
{
	int i, j;
	char filepath[50]; //stringa che conterrà il percorso del file da aprire.
	int addr[13] = {51, 57, 63, 75, 87, 99, 105, 111, 117, 123, 129, 135, 141}; //indirizzi della memoria da controllare per i pokèmon della squadra
	FILE *np; //dichiarazione puntatore file.
	printf("\nWrite here the full path of your NES save file: ");
	scanf("%s", filepath);
	np = fopen(filepath, "rb"); //apertura del file.
	if(np == NULL) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		printf("Error! The program was not able to open the NES save file.\n");
		exit(FILE_NOT_FOUND);
	} 
	else
	{
		printf("\n[Your save file was successfully opened.]\n");
		printf("\nThis is the pokemon you selected:\n\n");
		for (j = 0; j <= 12; j++)
		{
			if (j == 0)
			{
				for (i = 0; i <= addr[j] + pkmn_id; i++)
					*(pkmn_nes + j) = fgetc(np);
			}
			else
			{
				for (i = addr[j - 1] + 1 + pkmn_id; i <= addr[j] + pkmn_id; i++)
					*(pkmn_nes + j) = fgetc(np);
			}
			switch (j)
			{
				case 0:
					printf (">	species:       	");
				break;
				case 1:
					printf (">	level:	        ");
				break;
				case 2:
					printf (">	remaining hps:	");
				break;
				case 3:
					printf (">	total hps:	");
				break;
				case 4:
					printf (">	exp:      	");
				break;
				case 5:
					printf (">	first move:	");
				break;
				case 6:
					printf (">	second move:	");
				break;
				case 7:
					printf (">	third move:	");
				break;
				case 8:
					printf (">	fourth move:	");
				break;
				case 9:
					printf (">	pp first move:	");
				break;
				case 10:
					printf (">	pp second move:	");
				break;
				case 11:
					printf (">	pp third move:	");
					break;
				case 12:
					printf (">	pp fourth move:	");
				break;
			}
			printf("%d\n", *(pkmn_nes + j));
		}
		printf("\n");
	}
	fclose(np); //chiusura del file.
}

void in_conv(int* pkmn_nes, int* pkmn_gb)
{
	int i;
	int addr[13] = {3, 34, 38, 40, 13, 5, 6, 7, 8, 26, 27, 28, 29}; //vettore contenente una tabella di conversione degli indirizzi.
	srand(time(NULL)); //questo comando ha a che fare con la generazione casuale dei numeri, più precisamente con la gestione del tempo.
	for (i = 0; i < 13; i++)
		*(pkmn_gb + addr[i]) = *(pkmn_nes + i);
	*(pkmn_gb + 24) = (rand() % 255) + 1; //randomizzo gli IV.
	*(pkmn_gb + 25) = (rand() % 255) + 1; //randomizzo gli IV.
}

void exp_conv(int* pkmn_gb)
{
	//int i;
	int expgrp[156] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 1, 1, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 1, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4}; //array containing pokémons' experience types (1 = fast; 2 = medium fast; 3 = medium slow; 4 = slow)
	*(pkmn_gb + 11) = *(pkmn_gb + 12) = *(pkmn_gb + 13) = 0; //azzero i valori degli exp del pokémon (per evitare errori di conversione)
	/*for (i=0; i<157; i++)
	{
		printf("%d) ", i + 1);
		printf("%d\n", expgrp[i]);
	}*/
	switch (expgrp[*(pkmn_gb + 3) - 1]) //uso una formula diversa a seconda del gruppo di esperienza del pkmn
	{
		case 1:
			*(pkmn_gb + 13) = round(pow(*(pkmn_gb + 34), 3)) * 4/5; 
		break;
		case 2:
			*(pkmn_gb + 13) = round(pow(*(pkmn_gb + 34), 3)); //elevo a potenza
		break;
		case 3:
			*(pkmn_gb + 13) = (round(pow(*(pkmn_gb + 34), 3)) * 6/5) - 15 * round(pow(*(pkmn_gb + 34), 2)) + *(pkmn_gb + 34) * 100 - 140;
		break;
		case 4:
			*(pkmn_gb + 13) = round(pow(*(pkmn_gb + 34), 3)) * 5/4; 
		break;
	}
	while (*(pkmn_gb + 13) > 255 && *(pkmn_gb + 12) <= 255) //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	{
		*(pkmn_gb + 13) = *(pkmn_gb + 13) - 255;
		*(pkmn_gb + 12) = *(pkmn_gb + 12) + 1;	
	}
	while (*(pkmn_gb + 12) > 255) //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	{
		*(pkmn_gb + 12) = *(pkmn_gb + 12) - 255;
		*(pkmn_gb + 11) = *(pkmn_gb + 11) + 1;	
	}
}

void scnd_conv(int* pkmn_gb)
{
	switch (*(pkmn_gb + 3))
	{
		case 152: //raikou
			*(pkmn_gb + 3) = 243;
		break;
		case 153: //entei
			*(pkmn_gb + 3) = 244;
		break;
		case 154: //suicune
			*(pkmn_gb + 3) = 245;
		break;
		case 155: //lugia
			*(pkmn_gb + 3) = 249;
		break;
		case 156: //oh-ho
			*(pkmn_gb + 3) = 250;
		break;
	}
}

void mov_conv(int* pkmn_gb)
{
	int i, j;
	int addr[251] = {139, 79, 255, 255, 255, 141, 2, 44, 22, 138, 255, 154, 149, 159, 143, 92, 94, 172, 96, 255, 255, 31, 145, 80, 255, 255, 82, 55, 255, 255, 255, 155, 137, 255, 255, 255, 255, 150, 164, 67, 61, 255, 255, 128, 160, 171, 156, 158, 255, 255, 69, 0, 3, 255, 9, 15, 14, 45, 46, 102, 11, 43, 151, 91, 97, 255, 77, 255, 84, 175, 28, 29, 255, 255, 32, 35, 75, 40, 38, 255, 66, 121, 255, 19, 23, 27, 26, 56, 52, 54, 50, 76, 101, 106, 109, 255, 113, 140, 255, 111, 255, 255, 255, 168, 169, 163, 255, 166, 119, 18, 162, 255, 255, 255, 255, 255, 255, 255, 255, 152, 255, 114, 68, 72, 51, 5, 255, 17, 144, 255, 255, 255, 255, 255, 255, 255, 255, 107, 74, 255, 60, 157, 100, 255, 8, 255, 39, 167, 255, 135, 255, 13, 153, 255, 53, 110, 59, 148, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 1, 255, 174, 255, 255, 99, 255, 255, 255, 41, 255, 255, 255, 127, 255, 255, 73, 48, 12, 255, 24, 255, 255, 255, 42, 255, 255, 255, 255, 255, 255, 255, 165, 255, 255, 255, 255, 21, 255, 131, 255, 255, 255, 255, 255, 255, 255, 255, 255, 4, 255, 88, 64, 122, 255, 170, 255, 136, 255, 132, 130, 83, 255, 255, 255, 147, 87, 120, 255, 255, 129, 255, 255, 255, 58, 117, 255, 78, 255, 255}; //vettore contenente una tabella di conversione degli indirizzi. 
	/*for (j = 0; j < 251; j++)
	{
		printf ("%d) ", j + 1);
		printf ("%x\n", M[j]);
	}*/
	for (i = 5; i <= 8; i++)
	{
		for (j = 0; j < 251; j++)
		{
			if (*(pkmn_gb + i) == addr[j] && addr[j] != 255) 
			{
				*(pkmn_gb + i) = j + 1;
				j = 251;
			}
		}
	}
}

void gbup(int* pkmn_gb)
{
	int i;	
	char filepath[50]; //stringa che conterrà il percorso del file da creare.
	FILE *gp; //dichiarazione puntatore file.
	printf("Write here the full path in which you want to save the .pk2 file: ");
	scanf("%s", filepath);
	getchar(); //necessario per pulire il buffer (per andare oltre il carattere invio letto).
	gp = fopen(filepath, "wb"); //apertura del file.
	if(gp == NULL) //se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		printf("Error! The program was not able to create the .pk2 file.\n\n");
		exit(FILE_NOT_CREATED);
	}
	else
	{	
		for (i = 0; i < 73; i++)
			fputc(*(pkmn_gb + i), gp);
		*(pkmn_gb + 73) = EOF;
		printf("\n[Your .pk2 file was successfully created.]\n\n");
	}
	fclose(gp); //chiusura del file
}