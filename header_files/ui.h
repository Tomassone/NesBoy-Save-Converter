
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

    //funzione che stampa un menù e fa selezionare un'opzione da esso (valore ritornato).
    int show_menu();
    
    //funzione che richiede la pressione di invio per confermare per poi pulire lo schermo.
    void conf_dialog();

#endif
