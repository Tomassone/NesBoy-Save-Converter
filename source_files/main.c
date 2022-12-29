
#include <stdio.h>
#include "constants.h"
#include "pkmn.h"
#include "pkmn_manipulation.h"
#include "ui.h"

int main()
{
	int pkmn_choice = 0, valid = FALSE, repeat = TRUE;
	pkmn_nes loaded_pkmn; //struttura contente la struttura di base del pokèmon [nes].
	pkmn_gb stored_pkmn; //struttura di base del file pokèmon di seconda generazione.
	printf ("\n[NesBoy Save Converter]\n\n");
	do
	{
		while (valid == FALSE) //controllo del valore inserito.
		{
			printf ("Which pokemon of your party would you like to select? ");
			scanf("%d", &pkmn_choice);
			pkmn_choice--;
			if (pkmn_choice >= 0 && pkmn_choice <= 5) //se cioè è un numero compreso tra 0 e 5.
			{
				load_from_nes(pkmn_choice, &loaded_pkmn); //carico il pokèmon da convertire.
				show_pkmn_nes(loaded_pkmn); //stampo ciò che ho caricato a schermo.
				valid = TRUE;
			}
			else
				printf("The selected pokemon does not exist. Please choose another one.\n");
		}
		valid = FALSE;
		addr_conv(loaded_pkmn, &stored_pkmn); //effettuo la conversione della struttura.
		upload_to_gb(stored_pkmn); //creo il file .pk2.
		printf("[Press enter.]");
		getchar();
		clrscr();
	}
	while (repeat == TRUE);
	return 0;
}

