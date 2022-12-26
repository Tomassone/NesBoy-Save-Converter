
#ifndef ARRAY_MANIP_H

    #define ARRAY_MANIP_H

    #include <stdio.h>
    #include <stdint.h>

    //funzione che stampa i primi dim elenmenti di un array.
    void print_array(uint8_t* array, int dim);

    //funzione che copia i primi dim elementi da un vettore all'altro.
    void copy_array(uint8_t* destination, uint8_t* source, int dim);

#endif
