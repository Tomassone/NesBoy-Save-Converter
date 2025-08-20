
#include "ui.h" //inclusione del corrispondente file header.

void conf_dialog()
{
	printf("[Press enter.]");
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
		printf(">	%-31s\n", options[i]);
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
	char* options[6];
	options[0] = "CHECK PLAYER INFORMATION";
	options[1] = "CHECK PLAYER BAG";
	options[2] = "CHECK PLAYER TEAM";
	options[3] = "FIX CHECKSUM";
	options[4] = "TRANSFER A PKMN FROM THE NES TO THE GAMEBOY";
	options[5] = "EXIT";
	return print_menu("NesBoy Save Converter", options, 6);
}

int select_from_shell(int slctd_option)
{
	clrscr();
	if (check_num_val(slctd_option, 1, 2)) //se cioè è un numero compreso tra 1 e 2.
		return slctd_option;
	else
	{
		printf("The selected option is not valid, please select something else.\n");
		return print_main_menu();
	}
}
