
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
	return loaded;
}

void load_bag_section(bag_item* section, int dim, int offset, uint8_t* save_dump)
{
	for (int i = 0; i < dim; i++) 
		section[i].amount = (int) save_dump[i + offset];
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
		printf("\n[Your save file was successfully opened.]\n");
		fread(loaded->current_save, sizeof(uint8_t), SAVE_FILE_DIM, fp);
		fclose(fp); //chiusura del file.
		loaded->player_money = (int)
			(((loaded->current_save)[0x0C25] & 0xFF) << 16) |
			(((loaded->current_save)[0x0C24] & 0xFF) << 8)  |
			((loaded->current_save)[0x0C23] & 0xFF);
		loaded->caught_pkmn = (int) (loaded->current_save)[0x0C32];
		load_bag_section(loaded->items, MAX_ITEMS, 0x0CD4, loaded->current_save);
		load_bag_section(loaded->balls, MAX_BALLS, 0x0CD0, loaded->current_save);
		load_bag_section(loaded->key_items, MAX_KEY_ITEMS, 0x0CE7, loaded->current_save);
		load_bag_section(loaded->tms_hms, MAX_TMS_HMS, 0x0CF2, loaded->current_save);
	}
}    

void print_player_info(save_file loaded)
{
	printf("\n");
	printf (">	Player name:              	");
	printf("%s\n", loaded.player_name);
	printf (">	Available money:	        ");
	printf("%d\n", loaded.player_money);
	printf (">	Caught pokemon:	                ");
	printf("%3d\n", loaded.caught_pkmn);
}

void print_player_section(bag_item* section, int dim)
{
	printf("\n");
	for (int i = 0; i < dim; i++)
		printf (">	%-31s %3d\n", section[i].name, section[i].amount);
	printf("\n");
}

void print_player_bag(save_file loaded)
{
	printf("\n");
	printf (">	ITEMS:              	");
	print_player_section(loaded.items, MAX_ITEMS);
	printf (">	BALLS:              	");
	print_player_section(loaded.balls, MAX_BALLS);
	printf (">	KEY ITEMS:              	");
	print_player_section(loaded.key_items, MAX_KEY_ITEMS);
	printf (">	TMS and HMS:              	");
	print_player_section(loaded.tms_hms, MAX_TMS_HMS);
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

void write_nes_save_file(char filepath[], save_file loaded)
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
		calculate_checksum(&loaded); //ricalcolo il checksum del salvataggio.
		fwrite(loaded.current_save, sizeof(uint8_t), SAVE_FILE_DIM, fp);
		printf("[Your save file was successfully updated.]\n");
		fclose(fp); //chiusura del file.
	}
}    
