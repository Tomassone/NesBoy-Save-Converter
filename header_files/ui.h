
#ifndef UI_H

    #define UI_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "constants.h"
    #include "error_handling.h"

    //funzione che "pulisce" lo schermo.
    void clrscr(); 
    
    //funzione che gestisce l'opzione scelta prima dell'avvio del programma.
    int select_from_shell(int slctd_option);

    //funzione che stampa il menù principale e fa selezionare un'opzione da esso (valore ritornato).
    int print_main_menu();
    
    int print_manage_player_info_menu();
    
    int print_edit_player_info_menu();
    
    //funzione che stampa un menù e fa selezionare un'opzione da esso (valore ritornato).
    int print_menu(char* title, char** options, int number_of_options);
    
    //funzione che richiede la pressione di invio per confermare per poi pulire lo schermo.
    void conf_dialog();

#endif
