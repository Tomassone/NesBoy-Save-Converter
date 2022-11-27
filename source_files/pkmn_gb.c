
#include "pkmn_gb.h" //inclusione del corrispondente file header.

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

void gbup(int *X)
{
	int i;	
	char FP[50]; //stringa che conterrà il percorso del file da creare.
	FILE *gp; // dichiarazione puntatore file
	printf("Write here the full path in which you want to save the .pk2 file: ");
	scanf("%s", FP);
	gp = fopen(FP, "wb"); //apertura del file
	if(gp == 0) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine
		printf("Error! The program was not able to create the .pk2 file.\n\n");
	else
	{	
		for (i = 0; i<73; i++)
			fputc(*(X+i), gp);
		*(X+73) = EOF;
		printf("\n[Your .pk2 file was successfully created.]\n\n");
	}
	fclose(gp); //chiusura del file
}

