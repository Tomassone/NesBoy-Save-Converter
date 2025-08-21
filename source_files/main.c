
#include <stdio.h>
#include "constants.h"
#include "pkmn_manipulation.h"
#include "services.h"
#include "ui.h"

int main(int argc, char** argv)
{
	int slctd_option = 0, pkmn_choice = 0, valid = FALSE, repeat = TRUE;
	char filepath[50]; 
	save_file loaded = blanc_save();
	pkmn_gb stored_pkmn; //struttura di base del file pokèmon di seconda generazione.
	
	printf("\nWrite here the full path of your NES save file: ");
	scanf("%s", filepath);
	load_nes_save_file(filepath, &loaded); //carico contenuto dei salvataggi nella rispettiva struttura in memoria.
	clrscr();
	
	if (argc == 1) //programma lanciato senza argomenti.
		slctd_option = print_main_menu(); //stampo il menù e lascio scegliere all'utente cosa selezionare.
	else
	{
		slctd_option = check_str_if_int(argv[1], "Error! The input value is not valid.\n"); //l'utente ha già selezionato cosa fare (controllo dunque che il valore inserito sia un intero e converto il tipo).
		getchar();
	}
	
	do
	{
		switch (slctd_option)
		{
			case MNG_PLR_INFO:
				manage_player_info(&loaded);
				break;
			case CHCK_PLR_BAG:
				print_player_bag(loaded);
				break;
			case CHCK_PLR_TEAM:
				for (int i = 0; i < 6; i++)
					print_pkmn_nes(loaded.team[i]);
				break;
			case FIX_CHECKSUM:
				write_nes_save_file(filepath, loaded);
				break;
			case TRNSFR_PKMN:
				do
				{
					while (valid == FALSE) //controllo del valore inserito.
					{
						printf ("Which pokemon of your party would you like to select? ");
						pkmn_choice = check_input_if_int("Error! The input value is not valid."); //controllo che il valore inserito sia un intero.
						pkmn_choice--;
						
						if (check_num_val(pkmn_choice, 0, 5)) //se cioè è un numero compreso tra 0 e 5.
						{
							print_pkmn_nes(loaded.team[pkmn_choice]); //stampo ciò che ho caricato a schermo.
							valid = TRUE;
						}
						else
							printf("The selected pokemon does not exist. Please choose another one.\n");
					}
					valid = FALSE;
					addr_conv(loaded.team[pkmn_choice], &stored_pkmn); //effettuo la conversione della struttura.
					upload_to_gb(stored_pkmn); //creo il file .pk2.
					conf_dialog();
				}
				while (repeat == TRUE);
				break;
			default:
				printf("Shutting off the program...\n");
				conf_dialog();
				exit(NO_ERRORS);
				break;
		}
		conf_dialog();
		clrscr();
	}
	while((slctd_option = print_main_menu()));
	
	return 0;
}

