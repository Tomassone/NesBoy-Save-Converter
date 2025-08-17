
#include "save_file.h" //inclusione del corrispondente file header.

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
	return loaded;
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
	}
}    

void print_player_info(save_file loaded)
{
	printf("\n");
	printf (">	player name:              	");
	printf("%s\n", loaded.player_name);
	printf (">	available money:	        ");
	printf("%d\n", loaded.player_money);
	printf (">	caught pokemon:	                ");
	printf("%3d\n", loaded.caught_pkmn);
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
		printf("\nError! The program was not able to write to the NES save file.\n\n");
		exit(FILE_NOT_FOUND);
	} 
	else
	{
		calculate_checksum(&loaded); //ricalcolo il checksum del salvataggio.
		fwrite(loaded.current_save, sizeof(uint8_t), SAVE_FILE_DIM, fp);
		printf("\n[Your save file was successfully updated.]\n");
		fclose(fp); //chiusura del file.
	}
}    
