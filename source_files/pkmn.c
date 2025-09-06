
#include "pkmn.h" //inclusione del corrispondente file header.

pkmn_nes blank_pkmn_nes()
{
	pkmn_nes result;
	
	result.id_species = 0x00;
	result.level = 0x00;
	result.current_hp = 0x00;
	result.maximum_hp = 0x00;
	result.exp = 0x00;
	result.id_moves[0] = result.id_moves[1] = result.id_moves[2] = result.id_moves[3] = 0x00;
	result.pp_moves[0] = result.pp_moves[1] = result.pp_moves[2] = result.pp_moves[3] = 0x00;
	
	return result;
}

pkmn_gb blank_pkmn_gb()
{
	srand(time(NULL)); //questo comando ha a che fare con la generazione casuale dei numeri, più precisamente con la gestione del tempo.
	pkmn_gb result;
	
	result.id_species = 0x00;
	result.id_held_item = 0x00;
	result.id_moves[0] = result.id_moves[1] = result.id_moves[2] = result.id_moves[3] = 0x00;
	result.original_trainer_id = rand() % 0xFFFF; //do un valore randomico al trainer_id.
	result.exp[0] = result.exp[1] = result.exp[2] = 0x00;
	result.hp_ev_data = 0x00;
	result.attack_ev_data = 0x00;
	result.defense_ev_data = 0x00;
	result.speed_ev_data = 0x00;
	result.special_ev_data = 0x00;
	result.iv_data = rand() % 0xFFFF; //do un valore randomico agli IV.
	result.pp_moves[0] = result.pp_moves[1] = result.pp_moves[2] = result.pp_moves[3] = 0x00;
	result.friendship = 0x46; //standard friendship value.
	result.pokerus = 0x00;
	result.caught_data = 0x00;
	result.level = 0x00;
	result.status_condition = 0x00;
	result.unused_byte = 0x00; 
	result.current_hp = 0x00;
	result.maximum_hp = 0x00;
	result.attack = 0x00;
	result.defense = 0x00;
	result.speed = 0x00;
	result.special_attack = 0x00;
	result.special_defense = 0x00;
	
	return result;
}

void print_pkmn_nes(pkmn_nes loaded_pkmn)
{
	printf("Pokemon info:\n");
	printf (">	species:       	");
	printf("%d\n", loaded_pkmn.id_species);
	printf (">	level:	        ");
	printf("%d\n", loaded_pkmn.level);
	printf (">	remaining hps:	");
	printf("%d\n", loaded_pkmn.current_hp);
	printf (">	total hps:	");
	printf("%d\n", loaded_pkmn.maximum_hp);
	printf (">	exp:      	");
	printf("%d\n", loaded_pkmn.exp);
	printf (">	first move (id):	");
	printf("0x%X\n", loaded_pkmn.id_moves[0]);
	printf (">	second move (id):	");
	printf("0x%X\n", loaded_pkmn.id_moves[1]);
	printf (">	third move (id):	");
	printf("0x%X\n", loaded_pkmn.id_moves[2]);
	printf (">	fourth move (id):	");
	printf("0x%X\n", loaded_pkmn.id_moves[3]);
	printf (">	pp first move:	");
	printf("%d\n", loaded_pkmn.pp_moves[0]);
	printf (">	pp second move:	");
	printf("%d\n", loaded_pkmn.pp_moves[1]);
	printf (">	pp third move:	");
	printf("%d\n", loaded_pkmn.pp_moves[2]);
	printf (">	pp fourth move:	");
	printf("%d\n", loaded_pkmn.pp_moves[3]);
	printf("\n");
}

void load_pkmn_nes(int pkmn_id, char* filepath, pkmn_nes* loaded_pkmn)
{
	int offset = 0;
	int addr[13] = {0x33, 0x39, 0x3F, 0x4B, 0x57, 0x63, 0x69, 0x6F, 0x75, 0x7B, 0x81, 0x87, 0x8D}; //indirizzi della memoria da controllare per i pokèmon della squadra
	FILE *np; //dichiarazione puntatore file.
	
	np = fopen(filepath, "rb"); //apertura del file.
	if (np == NULL) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		//printf("\nError! The program was not able to open the NES save file.\n\n");
		exit(FILE_NOT_FOUND);
	} 
	else
	{
		//printf("\nYour save file was successfully opened.\n");
		//printf("\nThis is the pokemon you selected:\n\n");
		for (int i = 0; i < 13; i++)
		{
			offset = addr[i] + pkmn_id; //calcolo la distanza del byte da leggere dall'inizio del file.
			fseek(np, offset, SEEK_SET); //posiziono correttamente la testina di lettura.
			switch (i)
			{
				case 0:
					fread(&(loaded_pkmn->id_species), sizeof(uint8_t), 1, np);
					break;
				case 1:
					fread(&(loaded_pkmn->level), sizeof(uint8_t), 1, np);
					break;
				case 2:
					fread(&(loaded_pkmn->current_hp), sizeof(uint8_t), 1, np);
					break;
				case 3:
					fread(&(loaded_pkmn->maximum_hp), sizeof(uint8_t), 1, np);
					break;
				case 4:
					fread(&(loaded_pkmn->exp), sizeof(uint8_t), 1, np);
					break;
				case 5:
					fread(&(loaded_pkmn->id_moves[0]), sizeof(uint8_t), 1, np);
					break;
				case 6:
					fread(&(loaded_pkmn->id_moves[1]), sizeof(uint8_t), 1, np);
					break;
				case 7:
					fread(&(loaded_pkmn->id_moves[2]), sizeof(uint8_t), 1, np);
					break;
				case 8:
					fread(&(loaded_pkmn->id_moves[3]), sizeof(uint8_t), 1, np);
					break;
				case 9:
					fread(&(loaded_pkmn->pp_moves[0]), sizeof(uint8_t), 1, np);
					break;
				case 10:
					fread(&(loaded_pkmn->pp_moves[1]), sizeof(uint8_t), 1, np);
					break;
				case 11:
					fread(&(loaded_pkmn->pp_moves[2]), sizeof(uint8_t), 1, np);
					break;
				case 12:
					fread(&(loaded_pkmn->pp_moves[3]), sizeof(uint8_t), 1, np);
					break;
			}
		}
	}
	fclose(np); //chiusura del file.
}

pk2_file_structure build_pk2(pkmn_gb base)
{
	pk2_file_structure result;
	uint8_t temp_starting_bytes[] = {0x01, 0x00, 0xFF};
	uint8_t temp_player_name[] = {0x80, 0x92, 0x87, 0x50, 0x50, 0x50, 0x50};
	uint8_t temp_middle_area[] = {0x00, 0x00, 0x00, 0x00};
	uint8_t temp_nickname[] = {0x8F, 0x8A, 0x8C, 0x8D, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50};
	
	temp_starting_bytes[1] = base.id_species; //il secondo byte di quelli inziali e quello rappresentante la specie del pokemon risultano essere uguali.
	copy_array(result.starting_bytes, temp_starting_bytes, 3);
	result.base = base;
	copy_array(result.player_name, temp_player_name, 7);
	copy_array(result.middle_area, temp_middle_area, 4);
	copy_array(result.nickname, temp_nickname, 10);
	result.closing_byte = 0x50;
	
	return result;
}

void upload_pkmn_gb(pkmn_gb stored_pkmn)
{
	char filepath[100]; //stringa che conterrà il percorso del file da creare.
	FILE *gp; //dichiarazione puntatore file.
	pk2_file_structure to_be_uploated = build_pk2(stored_pkmn);
	
	printf("Write here the full path in which you want to save the .pk2 file: ");
	scanf("%s", filepath);
	getchar(); //necessario per pulire il buffer (per andare oltre il carattere invio letto).
	
	gp = fopen(filepath, "wb"); //apertura del file.
	if (gp == NULL) //se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		printf("\nError! The program was not able to create the .pk2 file.\n\n");
		exit(FILE_NOT_CREATED);
	}
	else
	{	
		//scrivo i byte iniziali (non scrivo sul file direttamente lo struct complessivo, perchè presenta byte aggiuntivi che non mi servono).
		fwrite(&to_be_uploated.starting_bytes, sizeof(char) * 3, 1, gp);
		//scrivo la struttuta pkmn_gb effettiva.
		fwrite(&to_be_uploated.base.id_species, sizeof(uint8_t), 1, gp);
       	fwrite(&to_be_uploated.base.id_held_item, sizeof(uint8_t), 1, gp);
        fwrite(to_be_uploated.base.id_moves, sizeof(uint8_t) * 4, 1, gp);
        fwrite(&to_be_uploated.base.original_trainer_id, sizeof(uint16_t), 1, gp);
        fwrite(to_be_uploated.base.exp, sizeof(uint8_t) * 3, 1, gp);
        fwrite(&to_be_uploated.base.hp_ev_data, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.attack_ev_data, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.defense_ev_data, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.speed_ev_data, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.special_ev_data, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.iv_data, sizeof(uint16_t), 1, gp);
        fwrite(to_be_uploated.base.pp_moves, sizeof(uint8_t) * 4, 1, gp);
        fwrite(&to_be_uploated.base.friendship, sizeof(uint8_t), 1, gp);
        fwrite(&to_be_uploated.base.pokerus, sizeof(uint8_t), 1, gp);
        fwrite(&to_be_uploated.base.caught_data, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.level, sizeof(uint8_t), 1, gp);
        fwrite(&to_be_uploated.base.status_condition, sizeof(uint8_t), 1, gp);
        fwrite(&to_be_uploated.base.unused_byte, sizeof(uint8_t), 1, gp);
        fwrite(&to_be_uploated.base.current_hp, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.maximum_hp, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.attack, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.defense, sizeof(uint16_t), 1, gp);
     	fwrite(&to_be_uploated.base.speed, sizeof(uint16_t), 1, gp);
     	fwrite(&to_be_uploated.base.special_attack, sizeof(uint16_t), 1, gp);
        fwrite(&to_be_uploated.base.special_defense, sizeof(uint16_t), 1, gp);
		//scrivo i byte addizionali.
		fwrite(&to_be_uploated.player_name, sizeof(char) * 7, 1, gp);
		fwrite(&to_be_uploated.middle_area, sizeof(char) * 4, 1, gp);
		fwrite(&to_be_uploated.nickname, sizeof(char) * 10, 1, gp);
		fwrite(&to_be_uploated.closing_byte, sizeof(char), 1, gp);
		printf("\nYour .pk2 file was successfully created.\n\n");
		fclose(gp); //chiusura del file
	}
}
