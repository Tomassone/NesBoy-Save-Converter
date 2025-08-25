
#ifndef SERV_H

    #define SERV_H

    #include <stdio.h>
    #include <stdlib.h>
    #include "constants.h"
    #include "save_file.h"
    #include "pkmn.h"
    #include "pkmn_manipulation.h"
    #include "error_handling.h"
    
    void edit_player_info(save_file* loaded);
    
    void manage_player_info(save_file* loaded);
    
    void manage_player_bag(bag_item* section, int size, char* name);
    
    void choose_player_bag(save_file* loaded);
    
    void edit_bag_section(bag_item* section, int size);
        
    void manage_pokemon_info(pkmn_nes* selected);
    
    void choose_pokemon_from_team(save_file* loaded);
    
    void edit_pokemon_info(pkmn_nes* selected);

#endif
