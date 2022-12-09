
#include "pkmn.h" //inclusione del corrispondente file header.

void nesload(int pkmn_id, int* pkmn_nes)
{
	int i, j;
	char filepath[50]; //stringa che conterrà il percorso del file da aprire.
	int addr[13] = {0x33, 0x39, 0x3F, 0x4B, 0x57, 0x63, 0x69, 0x6F, 0x75, 0x7B, 0x81, 0x87, 0x8D}; //indirizzi della memoria da controllare per i pokèmon della squadra
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

void addr_conv(int* pkmn_nes, int* pkmn_gb)
{
	int i;
	int addr[13] = {0x03, 0x22, 0x26, 0x28, 0x0D, 0x05, 0x06, 0x07, 0x08, 0x1A, 0x1B, 0x1C, 0x1D}; //vettore contenente una tabella di conversione degli indirizzi.
	srand(time(NULL)); //questo comando ha a che fare con la generazione casuale dei numeri, più precisamente con la gestione del tempo.
	for (i = 0; i < 13; i++)
		*(pkmn_gb + addr[i]) = *(pkmn_nes + i);
	*(pkmn_gb + 24) = (rand() % 0xFF) + 1; //randomizzo gli IV.
	*(pkmn_gb + 25) = (rand() % 0xFF) + 1; //randomizzo gli IV.
}

void exp_conv(int* pkmn_gb)
{
	//int i;
	int expgrp[156] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 1, 1, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 1, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4}; //array containing pokémons' experience types (1 = fast; 2 = medium fast; 3 = medium slow; 4 = slow)
	*(pkmn_gb + 0x0B) = *(pkmn_gb + 0x0C) = *(pkmn_gb + 0x0D) = 0; //azzero i valori degli exp del pokémon (per evitare errori di conversione)
	/*for (i=0; i<157; i++)
	{
		printf("%d) ", i + 1);
		printf("%d\n", expgrp[i]);
	}*/
	switch (expgrp[*(pkmn_gb + 0x03) - 1]) //uso una formula diversa a seconda del gruppo di esperienza del pkmn
	{
		case 1:
			*(pkmn_gb + 0x0D) = round(pow(*(pkmn_gb + 34), 3)) * 4/5; 
		break;
		case 2:
			*(pkmn_gb + 0x0D) = round(pow(*(pkmn_gb + 34), 3)); //elevo a potenza
		break;
		case 3:
			*(pkmn_gb + 0x0D) = (round(pow(*(pkmn_gb + 34), 3)) * 6/5) - 15 * round(pow(*(pkmn_gb + 34), 2)) + *(pkmn_gb + 34) * 100 - 140;
		break;
		case 4:
			*(pkmn_gb + 0x0D) = round(pow(*(pkmn_gb + 34), 3)) * 5/4; 
		break;
	}
	while (*(pkmn_gb + 0x0D) > 0xFF && *(pkmn_gb + 0x0C) <= 0xFF) //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	{
		*(pkmn_gb + 0x0D) = *(pkmn_gb + 0x0D) - 0xFF;
		*(pkmn_gb + 0x0C) = *(pkmn_gb + 0x0C) + 1;	
	}
	while (*(pkmn_gb + 0x0C) > 0xFF) //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	{
		*(pkmn_gb + 0x0C) = *(pkmn_gb + 0x0C) - 0xFF;
		*(pkmn_gb + 0x0B) = *(pkmn_gb + 0x0B) + 1;	
	}
}

void id_conv(int* pkmn_gb)
{
	switch (*(pkmn_gb + 0x03))
	{
		case 152: //raikou
			*(pkmn_gb + 0x03) = 243;
		break;
		case 153: //entei
			*(pkmn_gb + 0x03) = 244;
		break;
		case 154: //suicune
			*(pkmn_gb + 0x03) = 245;
		break;
		case 155: //lugia
			*(pkmn_gb + 0x03) = 249;
		break;
		case 156: //oh-ho
			*(pkmn_gb + 0x03) = 250;
		break;
	}
}

void mov_conv(int* pkmn_gb)
{
	int i, j;
	int addr[251] = {0x8B, 0x4F, 0xFF, 0xFF, 0xFF, 0x8D, 0x02, 0x2C, 0x16, 0x8A, 0xFF, 0x9A, 0x95, 0x9F, 0x8F, 0x5C, 0x5E, 0xAC, 0x60, 0xFF, 0xFF, 0x1F, 0x91, 0x50, 0xFF, 0xFF, 0x52, 0x37, 0xFF, 0xFF, 0xFF, 0x9B, 0x89, 0xFF, 0xFF, 0xFF, 0xFF, 0x96, 0xA4, 0x43, 0x3D, 0xFF, 0xFF, 0x80, 0xA0, 0xAB, 0x9C, 0x9E, 0xFF, 0xFF, 0x45, 0x0, 0x03, 0xFF, 0x09, 0x0F, 0x0E, 0x2D, 0x2E, 0x66, 0xB, 0x2B, 0x97, 0x5B, 0x61, 0xFF, 0x4D, 0xFF, 0x54, 0xAF, 0x1C, 0x1D, 0xFF, 0xFF, 0x20, 0x23, 0x4B, 0x28, 0x26, 0xFF, 0x42, 0x79, 0xFF, 0x13, 0x17, 0x1B, 0x1A, 0x38, 0x34, 0x36, 0x32, 0x4C, 0x65, 0x6A, 0x6D, 0xFF, 0x71, 0x8C, 0xFF, 0x6F, 0xFF, 0xFF, 0xFF, 0xA8, 0xA9, 0xA3, 0xFF, 0xA6, 0x77, 0x12, 0xA2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0xFF, 0x72, 0x44, 0x48, 0x33, 0x5, 0xFF, 0x11, 0x90, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6B, 0x4A, 0xFF, 0x3C, 0x9D, 0x64, 0xFF, 0x08, 0xFF, 0x27, 0xA7, 0xFF, 0x87, 0xFF, 0x0D, 0x99, 0xFF, 0x35, 0x6E, 0x3B, 0x94, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xAE, 0xFF, 0xFF, 0x63, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x49, 0x30, 0x0C, 0xFF, 0x18, 0xFF, 0xFF, 0xFF, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0xFF, 0xFF, 0xFF, 0xFF, 0x15, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4, 0xFF, 0x58, 0x40, 0x7A, 0xFF, 0xAA, 0xFF, 0x88, 0xFF, 0x84, 0x82, 0x53, 0xFF, 0xFF, 0xFF, 0x93, 0x57, 0x78, 0xFF, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0x3A, 0x75, 0xFF, 0x4E, 0xFF, 0xFF}; //vettore contenente una tabella di conversione degli indirizzi. 
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
