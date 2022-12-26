
#include <stdio.h>
#include "constants.h"
#include "pkmn.h"
#include "ui.h"

int main()
{
	int choice = 0, valid = FALSE, repeat = TRUE;
	pkmn_nes loaded_pkmn; //struttura contente la struttura di base del pokèmon [nes].
	pkmn_gb stored_pkmn; //struttura di base del file pokèmon di seconda generazione.
	printf ("\n[NesBoy Save Converter]\n\n");
	do
	{
		while (valid == FALSE) //controllo del valore inserito.
		{
			printf ("Which pokemon of your party would you like to select? ");
			scanf("%d", &choice);
			choice--;
			if (choice >= 0 && choice <= 5) //se cioè è un numero compreso tra 0 e 5.
			{
				nesload(choice, &loaded_pkmn); //carico il pokèmon da convertire.
				valid = TRUE;
			}
			else
				printf("The selected pokemon does not exist. Please choose another one.\n");
		}
		addr_conv(loaded_pkmn, &stored_pkmn); //effettuo la conversione della struttura.
		gbup(stored_pkmn); //creo il file .pk2.
		printf("[Press enter.]");
		getchar();
		clrscr();
	}
	while (repeat == TRUE);
	return 0;
}

