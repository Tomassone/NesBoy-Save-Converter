
#ifndef SAVE_FILE_H

    #define SAVE_FILE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <time.h> //necessaria per la randomizzazione.
    #include <string.h>
    #include "constants.h"
    #include "array_manipulation.h"
    #include "ui.h"
    #include "error_handling.h"
    #include "pkmn.h"
    
    typedef struct
    {
        char name[25];
        int amount;
    } bag_item;
    
    typedef struct
    {
        uint8_t current_save[SAVE_FILE_DIM];
        char player_name[4];
        int player_money;
        int seen_pkmn;
        int caught_pkmn;
        bag_item items[MAX_ITEMS];
        bag_item balls[MAX_BALLS];
        bag_item key_items[MAX_KEY_ITEMS];
        bag_item tms_hms[MAX_TMS_HMS];
        pkmn_nes team[6];
    } save_file;
    
    //funzione per la creazione di una bag_item vuota.
    void fill_bag(bag_item* section, int dim);
    
    //funzione per la creazione di una struttura save_file vuota.
    save_file blanc_save();
    
    //funzione per il caricamento in memoria del salvataggio.
    void load_nes_save_file(char filepath[], save_file* loaded);
    
    //funzione per la stampa a schermo di informazioni relative al giocatore.
    void print_player_info(save_file loaded);
    
    //funzione per la stampa a schermo di informazioni relative alla borsa del giocatore.
    void print_player_bag(save_file loaded);
    
    //funzione per il ricalcolo e la scrittura del nuovo checksum del salvataggio (restituisce quello vecchio).
    int calculate_checksum(save_file* loaded);
    
    //funzione per la scrittura in memoria del salvataggio.
    void write_nes_save_file(char filepath[], save_file loaded);

#endif

