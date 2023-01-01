
#ifndef UI_H

    #define UI_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "constants.h"

    //funzione che "pulisce" lo schermo.
    void clrscr(); 

    //funzione che stampa un menù e fa selezionare un'opzione da esso.
    void show_menu(int* slctd_option);

#endif
