
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //necessaria per l'elevazione a potenza.
#include <time.h> //necessaria per la randomizzazione.

#define FILE_NOT_FOUND 1
#define FILE_NOT_CREATED 2

//funzione che estrae un pokémon in formato NES da un file di salvaggio.
void nesload(int pkmn_id, int* pkmn_nes);

//funzione che effettua la prima conversione e randomizza gli IV di un pokèmon di prima/seconda generazione.
void addr_conv(int* pkmn_nes, int* pkmn_gb);

//funzione che converte i valori dei punti esperienza dal formato NES a quello GB.
void exp_conv(int* pkmn_gb);

//funzione che converte gli indici di specie dal formato NES a quello GB degli ultimi 5 pokèmon del pokèdex (gli unici di 2 gen --> per cui gli id non sono uguali).
void id_conv(int* pkmn_gb);

//funzione che converte gli index number delle mosse dal formato NES a quello GB.
void mov_conv(int* pkmn_gb);

//funzione che salva un pokémon di seconda generazione in un file .pk2.
void gbup(int* pkmn_gb);
