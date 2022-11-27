
#include "ui.h" //inclusione del corrispondente file header.

void clrscr()  //ho dovuto "ricreare" la funzione "clear screen", visto che non è una funzione standard di C.
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#else
		int i;
		for (i=0; i<80; i++) 
			printf ("\n");
	#endif
}
