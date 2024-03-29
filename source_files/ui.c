
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

int show_menu()
{
	int slctd_option, repeat = TRUE;
	printf("*********************************************************\n***               NesBoy Save Converter               ***\n*********************************************************\n* 1)  TRANSFER A PKMN FROM THE NES TO THE GAMEBOY       *\n* 2)  EXIT                                              *\n*********************************************************\n\n");
	do
	{
		printf("Please select one of the listed options: ");
		slctd_option = check_input_if_int("Error! The input value is not valid.");
		
		if (check_num_val(slctd_option, 1, 2)) //se cioè è un numero compreso tra 1 e 2.
			repeat = FALSE;
		else
			printf("The selected option is not valid, please select something else.\n");
	} 
	while (repeat == TRUE);
	clrscr();
	return slctd_option;
}

int select_from_shell(int slctd_option)
{
	clrscr();
	if (check_num_val(slctd_option, 1, 2)) //se cioè è un numero compreso tra 1 e 2.
		return slctd_option;
	else
	{
		printf("The selected option is not valid, please select something else.\n");
		return show_menu();
	}
}
