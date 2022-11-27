
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //necessaria per la randomizzazione

//funzione randomizzante gli IV di un pokèmon di prima/seconda generazione.
void in_conv(int *X, int *Y); 

//funzione che salva un pkmn_gb (struttura contente un pokémon di seconda generazione) in un file .pk2.
void gbup(int *X);
