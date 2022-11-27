
#include "conv.h" //inclusione del corrispondente file header.

void in_conv(int *X, int *Y)
{
	int i;
	int G[14] = {3, 34, 38, 40, 13, 5, 6, 7, 8, 26, 27, 28, 29}; //vettore contenente una tabella di conversione degli indirizzi 
	srand(time(NULL)); //questo comando ha a che fare con la generazione casuale dei numeri, più precisamente con la gestione del tempo.
	for (i = 0; i<13; i++)
		*(Y+G[i]) = *(X+i);
	*(Y+24) = (rand() % 255) + 1; //randomizzo gli IV
	*(Y+25) = (rand() % 255) + 1; //randomizzo gli IV
}
void exp_conv(int *X)
{
	//int i;
	int expgrp[157] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 1, 1, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 1, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4}; //array containing pokémons' experience types (1 = fast; 2 = medium fast; 3 = medium slow; 4 = slow)
	*(X+11) = *(X+12) = *(X+13) = 0; //azzero i valori degli exp del pokémon (per evitare errori di conversione)
	/*for (i=0; i<157; i++)
	{
		printf("%d) ", i + 1);
		printf("%d\n", expgrp[i]);
	}*/
	switch (expgrp[*(X+3) - 1]) //uso una formula diversa a seconda del gruppo di esperienza del pkmn
	{
		case 1:
			*(X+13) = round(pow(*(X+34), 3)) * 4/5; 
		break;
		case 2:
			*(X+13) = round(pow(*(X+34), 3)); //elevo a potenza
		break;
		case 3:
			*(X+13) = (round(pow(*(X+34), 3)) * 6/5) - 15 * round(pow(*(X+34), 2)) + *(X+34) * 100 - 140;
		break;
		case 4:
			*(X+13) = round(pow(*(X+34), 3)) * 5/4; 
		break;
	}
	while (*(X+13)>255 && *(X+12)<=255) //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	{
		*(X+13) = *(X+13) - 255;
		*(X+12) = *(X+12) + 1;	
	}
	while (*(X+12)>255) //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	{
		*(X+12) = *(X+12) - 255;
		*(X+11) = *(X+11) + 1;	
	}
}

void scnd_conv(int *X)
{
	switch (*(X+3))
	{
		case 152: //raikou
			*(X+3) = 243;
		break;
		case 153: //entei
			*(X+3) = 244;
		break;
		case 154: //suicune
			*(X+3) = 245;
		break;
		case 155: //lugia
			*(X+3) = 249;
		break;
		case 156: //oh-ho
			*(X+3) = 250;
		break;
	}
}

void mov_conv(int *X)
{
	int i, j;
	int M[251] = {139, 79, 255, 255, 255, 141, 2, 44, 22, 138, 255, 154, 149, 159, 143, 92, 94, 172, 96, 255, 255, 31, 145, 80, 255, 255, 82, 55, 255, 255, 255, 155, 137, 255, 255, 255, 255, 150, 164, 67, 61, 255, 255, 128, 160, 171, 156, 158, 255, 255, 69, 0, 3, 255, 9, 15, 14, 45, 46, 102, 11, 43, 151, 91, 97, 255, 77, 255, 84, 175, 28, 29, 255, 255, 32, 35, 75, 40, 38, 255, 66, 121, 255, 19, 23, 27, 26, 56, 52, 54, 50, 76, 101, 106, 109, 255, 113, 140, 255, 111, 255, 255, 255, 168, 169, 163, 255, 166, 119, 18, 162, 255, 255, 255, 255, 255, 255, 255, 255, 152, 255, 114, 68, 72, 51, 5, 255, 17, 144, 255, 255, 255, 255, 255, 255, 255, 255, 107, 74, 255, 60, 157, 100, 255, 8, 255, 39, 167, 255, 135, 255, 13, 153, 255, 53, 110, 59, 148, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 1, 255, 174, 255, 255, 99, 255, 255, 255, 41, 255, 255, 255, 127, 255, 255, 73, 48, 12, 255, 24, 255, 255, 255, 42, 255, 255, 255, 255, 255, 255, 255, 165, 255, 255, 255, 255, 21, 255, 131, 255, 255, 255, 255, 255, 255, 255, 255, 255, 4, 255, 88, 64, 122, 255, 170, 255, 136, 255, 132, 130, 83, 255, 255, 255, 147, 87, 120, 255, 255, 129, 255, 255, 255, 58, 117, 255, 78, 255, 255}; //vettore contenente una tabella di conversione degli indirizzi 
	/*for (j = 0; j < 251; j++)
	{
		printf ("%d) ", j + 1);
		printf ("%x\n", M[j]);
	}*/
	for (i = 5; i <= 8; i++)
	{
		for (j = 0; j < 251; j++)
		{
			if (*(X+i) == M[j] && M[j] != 255) 
			{
				*(X+i) = j + 1;
				j = 251;
			}
		}
	}
}

