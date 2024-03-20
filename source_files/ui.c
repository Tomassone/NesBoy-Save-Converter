
#include "ui.h" //inclusione del corrispondente file header.

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
		scanf("%d%*c", &slctd_option);
		
		if (slctd_option > 0 && slctd_option < 4) //se cioè è un numero compreso tra 1 e 3.
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
	if (slctd_option > 0 && slctd_option < 4) //se cioè è un numero compreso tra 1 e 3.
		return slctd_option;
	else
	{
		printf("The selected option is not valid, please select something else.\n");
		return show_menu();
	}
}
