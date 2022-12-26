
#ifndef PKMN_H

    #define PKMN_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <math.h> //necessaria per l'elevazione a potenza.
    #include <time.h> //necessaria per la randomizzazione.
    #include "constants.h"
    #include "array_manipulation.h"

    typedef struct
    {
        uint8_t id_species;
        uint8_t level;
        uint8_t current_hp;
        uint8_t maximum_hp;
        uint8_t exp;
        uint8_t id_moves[4];
        uint8_t pp_moves[4];
    } pkmn_nes;

    typedef struct
    {
        uint8_t id_species;
        uint8_t id_held_item;
        uint8_t id_moves[4];
        uint16_t original_trainer_id; //2bit
        uint8_t exp[3]; //3bit
        uint16_t hp_ev_data; //2bit
        uint16_t attack_ev_data; //2bit
        uint16_t defense_ev_data; //2bit
        uint16_t speed_ev_data; //2bit
        uint16_t special_ev_data; //2bit
        uint16_t iv_data; //2bit
        uint8_t pp_moves[4];
        uint8_t friendship;
        uint8_t pokerus;
        uint16_t caught_data; //2bit
        uint8_t level;
        uint8_t status_condition;
        uint8_t unused_byte;
        uint16_t current_hp;  //2bit
        uint16_t maximum_hp;  //2bit
        uint16_t attack; 	//2 bytes
        uint16_t defense;  //2 bytes
     	uint16_t speed;  //2 bytes
     	uint16_t special_attack;  //2 bytes
        uint16_t special_defense;  //2 bytes
    } pkmn_gb;

    typedef struct
    {
        uint8_t starting_bytes[3];
        pkmn_gb base;
        uint8_t player_name[7];
        uint8_t middle_area[4];
        uint8_t nickname[10];
        uint8_t closing_byte;
    } pk2_file_structure;

    //funzione che restituisce la struttura di base di un pokémon di seconda generazione.
    pkmn_gb blank_pkmn_gb();

    //funzione che estrae un pokémon in formato NES da un file di salvaggio.
    void nesload(int pkmn_id, pkmn_nes* loaded_pkmn);

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

    //funzione che restituisce la struttura di un file pk2.
    pk2_file_structure build_pk2(pkmn_gb base);

    //funzione che salva un pokémon di seconda generazione in un file .pk2.
    void gbup(pkmn_gb stored_pkmn);

#endif
