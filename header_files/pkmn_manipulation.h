
#ifndef PKMN_MANIP_H

    #define PKMN_MANIP_H

    #include <math.h> //necessaria per l'elevazione a potenza.
    #include "constants.h"
    #include "pkmn.h"

    //funzione che copia direttamente i valori che non richiedono particolari conversioni da una struttura all'altra.
    void direct_conv(pkmn_nes loaded_pkmn, pkmn_gb* stored_pkmn);

    //funzione che converte i valori dei punti esperienza dal formato NES a quello GB.
    void exp_conv(pkmn_gb* stored_pkmn);

    //funzione che converte gli indici di specie dal formato NES a quello GB degli ultimi 5 pokèmon del pokèdex (gli unici di 2 gen --> per cui gli id non sono uguali).
    void id_conv(pkmn_gb* stored_pkmn);

    //funzione che converte gli index number delle mosse dal formato NES a quello GB.
    void mov_conv(pkmn_gb* stored_pkmn);

    //funzione che converte una struttura pkmn_nes in una struttura pkmn_gb.
    void addr_conv(pkmn_nes loaded_pkmn, pkmn_gb* stored_pkmn);

#endif
