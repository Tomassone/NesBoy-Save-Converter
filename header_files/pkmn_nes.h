
#include <stdio.h>
#include <math.h> //necessaria per l'elevazione a potenza.

//funzione che estrae un pkmn_nes (struttura contente un pokémon in formato NES) da un file di salvaggio.
void nesload(int *x, int *X);

//funzione che converte i valori dei punti esperienza dal formato NES a quello GB.
void exp_conv(int *X);

//funzione che converte gli indici di specie dal formato NES a quello GB degli ultimi 5 pokèmon del pokèdex (gli unici di 2 gen --> per cui gli id non sono uguali).
void scnd_conv(int *X);

//funzione che converte gli index number delle mosse dal formato NES a quello GB.
void mov_conv(int *X);
