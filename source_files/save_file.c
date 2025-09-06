
#include "save_file.h" //inclusione del corrispondente file header.

void fill_bag(bag_item* section, int dim)
{
	for (int i = 0; i < dim; i++) 
		section[i].amount = 0;
}

save_file blanc_save()
{
	save_file loaded;
	for (int i = 0; i < SAVE_FILE_DIM; i++)
		(loaded.current_save)[i] = 0x00;
		
	loaded.player_name[0] = 'A';
	loaded.player_name[1] = 's';
	loaded.player_name[2] = 'h';
	loaded.player_name[3] = '\0';
	loaded.player_money = 0;
	loaded.caught_pkmn = 0;
	
	fill_bag(loaded.items, MAX_ITEMS);
	strcpy(loaded.items[0].name, "Potion");
	strcpy(loaded.items[1].name, "Super Potion");
	strcpy(loaded.items[2].name, "Hyper Potion");
	strcpy(loaded.items[3].name, "Max Potion");
	strcpy(loaded.items[4].name, "Antidote");
	strcpy(loaded.items[5].name, "Paralyze Heal");
	strcpy(loaded.items[6].name, "Sleep Heal");
	strcpy(loaded.items[7].name, "Ice Heal");
	strcpy(loaded.items[8].name, "Burn Heal");
	strcpy(loaded.items[9].name, "Full Heal");
	strcpy(loaded.items[10].name, "Revive");
	strcpy(loaded.items[11].name, "Ether");
	strcpy(loaded.items[12].name, "Max Ether");
	strcpy(loaded.items[13].name, "Rare Candy");
	strcpy(loaded.items[14].name, "Fire Stone");
	strcpy(loaded.items[15].name, "Water Stone");
	strcpy(loaded.items[16].name, "Thunder Stone");
	strcpy(loaded.items[17].name, "Leaf Stone");
	strcpy(loaded.items[18].name, "Moon Stone");
	
	fill_bag(loaded.balls, MAX_BALLS);
	strcpy(loaded.balls[0].name, "Poke Ball");
	strcpy(loaded.balls[1].name, "Great Ball");
	strcpy(loaded.balls[2].name, "Hyper Ball");
	strcpy(loaded.balls[3].name, "Master Ball");
	
	fill_bag(loaded.key_items, MAX_KEY_ITEMS);
	strcpy(loaded.key_items[0].name, "Oak Parcel");
	strcpy(loaded.key_items[1].name, "Pokedex");
	strcpy(loaded.key_items[2].name, "Map");
	strcpy(loaded.key_items[3].name, "Helix Fossil");
	strcpy(loaded.key_items[4].name, "Dome Fossil");
	strcpy(loaded.key_items[5].name, "S.S. Ticket");
	strcpy(loaded.key_items[6].name, "Lemonade");
	strcpy(loaded.key_items[7].name, "Silph Scope");
	strcpy(loaded.key_items[8].name, "PokeFlute");
	strcpy(loaded.key_items[9].name, "Gold Teeth");
	strcpy(loaded.key_items[10].name, "Secret Key");
	
	fill_bag(loaded.tms_hms, MAX_TMS_HMS);
	strcpy(loaded.tms_hms[0].name, "Cut HM");
	strcpy(loaded.tms_hms[1].name, "Fly HM");
	strcpy(loaded.tms_hms[2].name, "Surf HM");
	strcpy(loaded.tms_hms[3].name, "Strength HM");
	strcpy(loaded.tms_hms[4].name, "Flash HM");
	
	char temp[6];
	for (int i = 5; i < MAX_TMS_HMS; i++)
	{
		sprintf(temp, "TM %02d", (i - 4));
		strcpy(loaded.tms_hms[i].name, temp);
	}
	
	for (int i = 0; i < 5; i++)
		loaded.team[i] = blank_pkmn_nes();
	return loaded;
}

void load_bag_section(bag_item* section, int dim, int offset, uint8_t* save_dump)
{
	for (int i = 0; i < dim; i++) 
		section[i].amount = (int) save_dump[i + offset];
}

void upload_bag_section(bag_item* section, int dim, int offset, uint8_t* save_dump)
{
	for (int i = 0; i < dim; i++) 
		save_dump[i + offset] = (uint8_t) section[i].amount;
}

void load_nes_save_file(char filepath[], save_file* loaded)
{
	FILE *fp; //dichiarazione puntatore file.
	fp = fopen(filepath, "rb"); //apertura del file.
	if (fp == NULL) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		printf("\nError! The program was not able to open the NES save file.\n\n");
		exit(FILE_NOT_FOUND);
	} 
	else
	{
		printf("\nYour save file was successfully opened.\n");
		fread(loaded->current_save, sizeof(uint8_t), SAVE_FILE_DIM, fp);
		fclose(fp); //chiusura del file.
		loaded->player_money = (int) //conversione del valore dei soldi accumulati da 3 byte binari a intero
			(((loaded->current_save)[0x0C25] & 0xFF) << 16) |
			(((loaded->current_save)[0x0C24] & 0xFF) << 8)  |
			((loaded->current_save)[0x0C23] & 0xFF);
		loaded->seen_pkmn = (int) (loaded->current_save)[0x0C31];
		loaded->caught_pkmn = (int) (loaded->current_save)[0x0C32];
		load_bag_section(loaded->items, MAX_ITEMS, 0x0CD4, loaded->current_save); //copiatura dei rispettivi valori con funzione necessaria
		load_bag_section(loaded->balls, MAX_BALLS, 0x0CD0, loaded->current_save);
		load_bag_section(loaded->key_items, MAX_KEY_ITEMS, 0x0CE7, loaded->current_save);
		load_bag_section(loaded->tms_hms, MAX_TMS_HMS, 0x0CF2, loaded->current_save);
		for (int i = 0; i < 6; i++)
			load_pkmn_nes(i, filepath, &(loaded->team[i]));
	}
}    

void print_player_info(save_file loaded)
{
	printf("Player info:\n");
	printf (">	Player name:              	");
	printf("%s\n", loaded.player_name);
	printf (">	Available money:	        ");
	printf("%3d\n", loaded.player_money);
	printf (">	Seen pokemon:	                ");
	printf("%3d\n", loaded.seen_pkmn);
	printf (">	Caught pokemon:	                ");
	printf("%3d\n\n", loaded.caught_pkmn);
}

void print_bag_section(bag_item* section, int dim, char* name)
{
	printf("%s:\n", name);
	for (int i = 0; i < dim; i++)
		printf ("%d>	%-31s %3d\n", i + 1, section[i].name, section[i].amount);
	printf("\n");
}

void print_player_bag(save_file loaded)
{
	printf("\n");
	print_bag_section(loaded.items, MAX_ITEMS, "Items");
	print_bag_section(loaded.balls, MAX_BALLS, "Balls");
	print_bag_section(loaded.key_items, MAX_KEY_ITEMS, "Key items");
	print_bag_section(loaded.tms_hms, MAX_TMS_HMS, "TMs and HMs");
}

int calculate_checksum(save_file* loaded)
{
	int checksum = 0;
    int carry = 0;
    int old_checksum = 0;
    for (int i = 0x0C00; i < 0x1600; i++)
    {
		checksum = checksum + (loaded->current_save)[i] + carry;
		carry = 0;
        if (checksum > 255)
        {
			checksum = checksum & 255;
			carry = 1;
		}
	}
	for (int i = 0x1C00; i < 0x1C10; i++)
    {
		checksum = checksum + (loaded->current_save)[i];
		carry = 0;
        if (checksum > 255)
        {
			checksum = checksum & 255;
			carry = 1;
		}
	}
    checksum = checksum & 255;
    old_checksum = (loaded->current_save)[0x1C20];
    (loaded->current_save)[0x1C20] = checksum;
    return old_checksum;
}

void upload_pkmn_nes(pkmn_nes loaded_pkmn, int team_position, save_file* loaded)
{
	int offset = 0;
	int addr[13] = {0x33, 0x39, 0x3F, 0x4B, 0x57, 0x63, 0x69, 0x6F, 0x75, 0x7B, 0x81, 0x87, 0x8D}; //indirizzi della memoria da controllare per i pokèmon della squadra

	for (int i = 0; i < 13; i++)
	{
		offset = addr[i] + team_position + 0x0C00; //calcolo la distanza del byte da leggere dall'inizio del file.
		switch (i)
		{
			case 0:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.id_species;
				break;
			case 1:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.level;
				break;
			case 2:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.current_hp;
				break;
			case 3:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.maximum_hp;
				break;
			case 4:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.exp;
				break;
			case 5:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.id_moves[0];
				break;
			case 6:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.id_moves[1];
				break;
			case 7:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.id_moves[2];
				break;
			case 8:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.id_moves[3];
				break;
			case 9:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.pp_moves[0];
				break;
			case 10:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.pp_moves[1];
				break;
			case 11:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.pp_moves[2];
				break;
			case 12:
				loaded->current_save[offset] = (uint8_t) loaded_pkmn.pp_moves[3];
				break;
		}
	}
}


void save_changes(save_file* loaded)
{
	//conversione del valore dei soldi accumulati da intero a 3 byte binari
	loaded->current_save[0x0C23] = (uint8_t)loaded->player_money & 0xFF;
	loaded->current_save[0x0C24] = (uint8_t)(loaded->player_money & 0xFF00) >> 8;
	loaded->current_save[0x0C25] = (uint8_t)(loaded->player_money & 0xFF0000) >> 16;		
		
	loaded->current_save[0x0C31] = (uint8_t) loaded->seen_pkmn; 
	loaded->current_save[0x0C32] = (uint8_t) loaded->caught_pkmn;
	
	//copiatura dei rispettivi valori con funzione necessaria
	upload_bag_section(loaded->items, MAX_ITEMS, 0x0CD4, loaded->current_save); 
	upload_bag_section(loaded->balls, MAX_BALLS, 0x0CD0, loaded->current_save);
	upload_bag_section(loaded->key_items, MAX_KEY_ITEMS, 0x0CE7, loaded->current_save);
	upload_bag_section(loaded->tms_hms, MAX_TMS_HMS, 0x0CF2, loaded->current_save);
	
	for (int i = 0; i < 6; i++)
		upload_pkmn_nes(loaded->team[i], i, loaded);
}

void upload_nes_save_file(char filepath[], save_file loaded)
{
	FILE *fp; //dichiarazione puntatore file.
	fp = fopen(filepath, "wb"); //apertura del file.
	if (fp == NULL) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		printf("Error! The program was not able to write to the NES save file.\n\n");
		exit(FILE_NOT_FOUND);
	} 
	else
	{
		save_changes(&loaded);
		calculate_checksum(&loaded); //ricalcolo il checksum del salvataggio.
		fwrite(loaded.current_save, sizeof(uint8_t), SAVE_FILE_DIM, fp);
		printf("Your save file was successfully updated.\n\n");
		fclose(fp); //chiusura del file.
	}
}    
