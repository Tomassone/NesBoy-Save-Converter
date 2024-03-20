
#ifndef ERR_HAND_H

    #define ERR_HAND_H
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
	#include <string.h>
	#include "constants.h"

    //costanti relative alla gestione dei file.

    #define FILE_NOT_FOUND 1
    #define FILE_NOT_CREATED 2
    
    //costanti relative al controllo dei tipi.

    #define INPUT_IS_NOT_INTEGER 3
    
    //controllo che il valore inserito dall'utente stia all'interno di un intervallo.
    int check_num_val(int val, int min, int max);
    //controllo che la stringa in input sia un intero (in tal caso lo restituisco).
    int check_str_if_int(char string[], char* error_msg);
    //controllo che il valore inserito dall'utente sia un intero (in tal caso lo restituisco).
    int check_input_if_int(char* error_msg);

#endif
