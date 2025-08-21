
#ifndef SERV_H

    #define SERV_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "constants.h"
    #include "save_file.h"
    #include "pkmn.h"
    #include "error_handling.h"
    
    void edit_player_info(save_file* loaded);
    
    void manage_player_info(save_file* loaded);

#endif
