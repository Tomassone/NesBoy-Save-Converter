
#include <stdio.h>
#include "pkmn.h"
#include "ui.h"

int main()
{
	int s;
	int NS[14]; //vettore contente la struttura di base del pokèmon [nes].
	int GS[74] = {1, 143, 255, 143, 0, 33, 133, 111, 0, 171, 246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 154, 35, 20, 40, 0, 70, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 146, 135, 0, 0, 0, 0, 0, 0, 0, 0, 151, 151, 151, 151, 151, 151, 151, 80, 80, 80, 80}; //struttura di base del file pokèmon di seconda generazione
	printf ("\n[NesBoy Save Converter]\n\n");
	do
	{
		printf ("Which pokemon of your party would you like to select? ");
		scanf("%d", &s);
		s = s - 1;
		nesload(&s, NS); //carico il pokèmon da convertire.
		in_conv(NS, GS); //effettuo un'iniziale conversione.
		exp_conv(GS); //converto i valori dei punti esperienza.
		if (GS[3] > 151)
			scnd_conv(GS); //conversione degli ultimi 5 pokémon del pokédex (gli unici di 2 gen --> per cui gli id non sono uguali).
		mov_conv(GS); //converto gli index number delle mosse.
		gbup(GS); //creo il file .pk2.
		printf("[Press enter.]");
		getchar();
		clrscr();
	}
	while (1);
	return 0;
}

