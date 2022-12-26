
#include "array_manipulation.h" //inclusione del corrispondente file header.
#include "pkmn.h"

void print_array(uint8_t* array, int dim)
{
	int i;
	for (i = 0; i < dim; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void copy_array(uint8_t* destination, uint8_t* source, int dim)
{
	int i;
	for (i = 0; i < dim; i++)
		destination[i] = source[i];  
}