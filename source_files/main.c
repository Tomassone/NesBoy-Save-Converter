
#include <stdio.h>
#include "constants.h"
#include "pkmn.h"
#include "pkmn_manipulation.h"
#include "ui.h"

int main(int argc, char** argv)
{
	int slctd_option = 0, pkmn_choice = 0, valid = FALSE, repeat = TRUE;
	pkmn_nes loaded_pkmn; //struttura contente la struttura di base del pokèmon [nes].
	pkmn_gb stored_pkmn; //struttura di base del file pokèmon di seconda generazione.
	
	clrscr();
	if (argc == 1) //programma lanciato senza argomenti.
		slctd_option = show_menu(); //stampo il menù e lascio scegliere all'utente cosa selezionare.
	else
		slctd_option = select_from_shell(atoi(argv[1])); //l'utente ha già selezionato cosa fare (conversione da stringa ad intero).
	
	if (slctd_option == TRNSFR_PKMN)
	{
		do
		{
			while (valid == FALSE) //controllo del valore inserito.
			{
				printf ("Which pokemon of your party would you like to select? ");
				pkmn_choice = check_if_int("Error! The input value is not valid."); //controllo che il valore inserito sia un intero.
				pkmn_choice--;
				
				if (check_num_val(pkmn_choice, 0, 5)) //se cioè è un numero compreso tra 0 e 5.
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
			conf_dialog();
		}
		while (repeat == TRUE);
	}
	else //se cioè è stato richiesto di chiudere il programma.
	{
		printf("Shutting off the program...\n");
		conf_dialog();
	}
	
	return 0;
}

