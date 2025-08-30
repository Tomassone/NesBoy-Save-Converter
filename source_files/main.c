
#include <stdio.h>
#include "constants.h"
#include "pkmn_manipulation.h"
#include "services.h"
#include "ui.h"

int main(int argc, char** argv)
{
	int slctd_option = 0;
	char filepath[50]; 
	save_file loaded = blanc_save();
	
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
			case MNG_PLR_BAG:
				choose_player_bag(&loaded);
				break;
			case MNG_PLR_TEAM:	
				choose_pokemon_from_team(&loaded);
				break;
			case SAVE_CHANGES:
				upload_nes_save_file(filepath, loaded);
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

