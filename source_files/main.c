
#include <stdio.h>
#include "pkmn.h"
#include "ui.h"

int main()
{
	int choice;
	int pkmn_nes[13]; //vettore contente la struttura di base del pokèmon [nes].
	int pkmn_gb[73] = {1, 143, 255, 143, 0, 33, 133, 111, 0, 171, 246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 154, 35, 20, 40, 0, 70, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 146, 135, 0, 0, 0, 0, 0, 0, 0, 0, 151, 151, 151, 151, 151, 151, 151, 80, 80, 80, 80}; //struttura di base del file pokèmon di seconda generazione
	printf ("\n[NesBoy Save Converter]\n\n");
	do
	{
		printf ("Which pokemon of your party would you like to select? ");
		scanf("%d", &choice);
		choice--;
		nesload(choice, pkmn_nes); //carico il pokèmon da convertire.
		addr_conv(pkmn_nes, pkmn_gb); //effettuo un'iniziale conversione.
		exp_conv(pkmn_gb); //converto i valori dei punti esperienza.
		if (pkmn_gb[3] > 151)
			id_conv(pkmn_gb); //conversione degli ultimi 5 pokémon del pokédex (gli unici di 2 gen --> per cui gli id non sono uguali).
		mov_conv(pkmn_gb); //converto gli index number delle mosse.
		gbup(pkmn_gb); //creo il file .pk2.
		printf("[Press enter.]");
		getchar();
		clrscr();
	}
	while (1);
	return 0;
}

