
#ifndef SAVE_FILE_H

    #define SAVE_FILE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <time.h> //necessaria per la randomizzazione.
    #include "constants.h"
    #include "array_manipulation.h"
    #include "ui.h"
    #include "error_handling.h"
    
    typedef struct
    {
        uint8_t current_save[SAVE_FILE_DIM];
    } save_file;
    
    //funzione per la creazione di una struttura save_file vuota.
    save_file blanc_save();
    
    //funzione per il caricamento in memoria del salvataggio.
    void load_nes_save_file(char filepath[], save_file* loaded);
    
    //funzione per il ricalcolo e la scrittura del nuovo checksum del salvataggio (restituisce quello vecchio).
    int calculate_checksum(save_file* loaded);
    
    //funzione per la scrittura in memoria del salvataggio.
    void write_nes_save_file(char filepath[], save_file loaded);

#endif

