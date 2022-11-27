
#include "pkmn_nes.h" //inclusione del corrispondente file header.

void nesload(int *x, int *X)
{
	int i, j;
	char FP[50]; //stringa che conterrà il percorso del file da aprire.
	int N[14] = {51, 57, 63, 75, 87, 99, 105, 111, 117, 123, 129, 135, 141}; //indirizzi della memoria da controllare per i pokèmon della squadra
	FILE *np; //dichiarazione puntatore file
	printf("\nWrite here the full path of your NES save file: ");
	scanf("%s", FP);
	np = fopen(FP, "rb"); //apertura del file
	if(np == 0) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine
		printf("Error! The program was not able to open the NES save file.\n"); 
	else
	{
		printf("\n[Your save file was successfully opened.]\n");
		printf("\nThis is the pokemon you selected:\n\n");
		for (j = 0; j<=12; j++)
		{
			if (j == 0)
			{
				for (i = 0; i<=N[j] + *x; i++)
					*(X+j) = fgetc(np);
			}
			else
			{
				for (i = N[j-1] + 1 + *x; i<=N[j] + *x; i++)
					*(X+j) = fgetc(np);
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
			printf("%d\n", *(X+j));
		}
		printf("\n");
	}
	fclose(np); //chiusura del file
}
