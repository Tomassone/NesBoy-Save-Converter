
#include "ui.h" //inclusione del corrispondente file header.

void conf_dialog()
{
	printf("[Press enter to conferm.]");
	getchar();
	clrscr();
}

void clrscr()  //ho dovuto "ricreare" la funzione "clear screen", visto che non è una funzione standard di C.
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__ || __APPLE__
		system("clear");
	#else
		int i;
		for (i = 0; i < 80; i++) 
			printf ("\n");
	#endif
}

int print_menu(char* title, char** options, int number_of_options)
{
	int slctd_option, repeat = TRUE;
	printf("%-31s\n", title);
	for (int i = 0; i < number_of_options; i++)
		printf("%d>	%-31s\n", i + 1, options[i]);
	printf("\n");
	do
	{
		printf("Please select one of the listed options: ");
		slctd_option = check_input_if_int("Error! The input value is not valid.");
		
		if (check_num_val(slctd_option, 1, number_of_options)) //se cioè è un numero compreso tra 1 e number_of_options.
			repeat = FALSE;
		else
			printf("The selected option is not valid, please select something else.\n");
	}
	while (repeat == TRUE);
	clrscr();
	return slctd_option;
}

int print_main_menu()
{
	char* options[5];
	options[0] = "MANAGE PLAYER INFORMATION";
	options[1] = "MANAGE PLAYER BAG";
	options[2] = "MANAGE PLAYER TEAM";
	options[3] = "SAVE CHANGES TO SAVE FILE";
	options[4] = "EXIT";
	return print_menu("NesBoy Save Editor", options, 5);
}

int print_manage_player_info_menu()
{
	char* options[3];
	options[0] = "CHECK PLAYER INFORMATION";
	options[1] = "EDIT PLAYER INFORMATION";
	options[2] = "EXIT";
	return print_menu("Manage player information:", options, 3);
}

int print_edit_player_info_menu()
{
	char* options[4];
	options[0] = "EDIT PLAYER MONEY";
	options[1] = "EDIT PLAYER SEEN POKEMON";
	options[2] = "EDIT PLAYER CAUGHT POKEMON";
	options[3] = "EXIT";
	return print_menu("Edit player information:", options, 4);
}

int print_manage_player_team_menu()
{
	char* options[3];
	options[0] = "CHECK POKEMON INFORMATION";
	options[1] = "EDIT POKEMON INFORMATION";
	options[2] = "EXIT";
	return print_menu("Manage player information:", options, 3);
}

int print_choose_player_bag_section_menu()
{
	char* options[5];
	options[0] = "SELECT ITEMS SECTION";
	options[1] = "SELECT BALLS SECTION";
	options[2] = "SELECT KEY ITEMS SECTION";
	options[3] = "SELECT TMs AND HMs SECTION";
	options[4] = "EXIT";
	return print_menu("Choose bag section:", options, 5);
}

int print_manage_player_bag_section_menu()
{
	char* options[3];
	options[0] = "CHECK BAG SECTION";
	options[1] = "EDIT BAG SECTION";
	options[2] = "EXIT";
	return print_menu("Manage player bag section:", options, 3);
}

int print_manage_pokemon_info_menu()
{
	char* options[4];
	options[0] = "CHECK POKEMON INFORMATION";
	options[1] = "EDIT POKEMON INFORMATION";
	options[2] = "TRANSFER POKEMON FROM THE NES TO THE GAMEBOY";
	options[3] = "EXIT";
	return print_menu("Manage pokemon information:", options, 4);
}

int print_edit_pokemon_info_menu()
{
	char* options[8];
	options[0] = "EDIT POKEMON SPECIES";
	options[1] = "EDIT POKEMON LEVEL";
	options[2] = "EDIT POKEMON EXPERIENCE POINTS";
	options[3] = "EDIT POKEMON ID MOVE 1";
	options[4] = "EDIT POKEMON ID MOVE 2";
	options[5] = "EDIT POKEMON ID MOVE 3";
	options[6] = "EDIT POKEMON ID MOVE 4";
	options[7] = "EXIT";
	return print_menu("Edit pokemon information:", options, 8);
}

int select_from_shell(int slctd_option)
{
	clrscr();
	if (check_num_val(slctd_option, 1, 5)) //se cioè è un numero compreso tra 1 e 5.
		return slctd_option;
	else
	{
		printf("The selected option is not valid, please select something else.\n");
		return print_main_menu();
	}
}
