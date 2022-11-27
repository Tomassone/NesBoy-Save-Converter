
#include <stdlib.h>
#include <math.h> //necessaria per l'elevazione a potenza.
#include <time.h> //necessaria per la randomizzazione

//funzione che effettua la prima conversione e randomizza gli IV di un pokèmon di prima/seconda generazione.
void in_conv(int *X, int *Y); 

//funzione che converte i valori dei punti esperienza dal formato NES a quello GB.
void exp_conv(int *X);

//funzione che converte gli indici di specie dal formato NES a quello GB degli ultimi 5 pokèmon del pokèdex (gli unici di 2 gen --> per cui gli id non sono uguali).
void scnd_conv(int *X);

//funzione che converte gli index number delle mosse dal formato NES a quello GB.
void mov_conv(int *X);
