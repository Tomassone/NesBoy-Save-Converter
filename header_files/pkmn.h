
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //necessaria per l'elevazione a potenza.
#include <time.h> //necessaria per la randomizzazione.

#define FILE_NOT_FOUND 1
#define FILE_NOT_CREATED 2

//funzione che estrae un pkmn_nes (struttura contente un pokémon in formato NES) da un file di salvaggio.
void nesload(int *x, int *X);

//funzione che effettua la prima conversione e randomizza gli IV di un pokèmon di prima/seconda generazione.
void in_conv(int *X, int *Y); 

//funzione che converte i valori dei punti esperienza dal formato NES a quello GB.
void exp_conv(int *X);

//funzione che converte gli indici di specie dal formato NES a quello GB degli ultimi 5 pokèmon del pokèdex (gli unici di 2 gen --> per cui gli id non sono uguali).
void scnd_conv(int *X);

//funzione che converte gli index number delle mosse dal formato NES a quello GB.
void mov_conv(int *X);

//funzione che salva un pkmn_gb (struttura contente un pokémon di seconda generazione) in un file .pk2.
void gbup(int *X);
