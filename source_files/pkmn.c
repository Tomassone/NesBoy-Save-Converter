
#include "pkmn.h" //inclusione del corrispondente file header.

pkmn_gb blank_pkmn_gb()
{
	srand(time(NULL)); //questo comando ha a che fare con la generazione casuale dei numeri, più precisamente con la gestione del tempo.
	pkmn_gb result;
	result.id_species = 0x00;
	result.id_held_item = 0x00;
	result.id_moves[0] = result.id_moves[1] = result.id_moves[2] = result.id_moves[3] =0x00;
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

void nesload(int pkmn_id, pkmn_nes* loaded_pkmn)
{
	int i, distance = 0;
	char filepath[50]; //stringa che conterrà il percorso del file da aprire.
	int addr[13] = {0x33, 0x39, 0x3F, 0x4B, 0x57, 0x63, 0x69, 0x6F, 0x75, 0x7B, 0x81, 0x87, 0x8D}; //indirizzi della memoria da controllare per i pokèmon della squadra
	FILE *np; //dichiarazione puntatore file.
	printf("\nWrite here the full path of your NES save file: ");
	scanf("%s", filepath);
	np = fopen(filepath, "rb"); //apertura del file.
	if(np == NULL) // se il puntatore restituisce "NULL", allora l'apertura del file non è andata a buon fine.
	{
		printf("Error! The program was not able to open the NES save file.\n");
		exit(FILE_NOT_FOUND);
	} 
	else
	{
		printf("\n[Your save file was successfully opened.]\n");
		printf("\nThis is the pokemon you selected:\n\n");
		for (i = 0; i <= 12; i++)
		{
			distance = addr[i] + pkmn_id; //calcolo la distanza del byte da leggere dall'inizio del file.
			fseek(np, distance, SEEK_SET); //posiziono correttamente la testina di lettura.
			switch (i)
			{
				case 0:
					printf (">	species:       	");
					fread(&(loaded_pkmn->id_species), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->id_species);
				break;
				case 1:
					printf (">	level:	        ");
					fread(&(loaded_pkmn->level), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->level);
				break;
				case 2:
					printf (">	remaining hps:	");
					fread(&(loaded_pkmn->current_hp), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->current_hp);
				break;
				case 3:
					printf (">	total hps:	");
					fread(&(loaded_pkmn->maximum_hp), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->maximum_hp);
				break;
				case 4:
					printf (">	exp:      	");
					fread(&(loaded_pkmn->exp), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->exp);
				break;
				case 5:
					printf (">	first move:	");
					fread(&(loaded_pkmn->id_moves[0]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->id_moves[0]);
				break;
				case 6:
					printf (">	second move:	");
					fread(&(loaded_pkmn->id_moves[1]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->id_moves[1]);
				break;
				case 7:
					printf (">	third move:	");
					fread(&(loaded_pkmn->id_moves[2]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->id_moves[2]);
				break;
				case 8:
					printf (">	fourth move:	");
					fread(&(loaded_pkmn->id_moves[3]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->id_moves[3]);
				break;
				case 9:
					printf (">	pp first move:	");
					fread(&(loaded_pkmn->pp_moves[0]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->pp_moves[0]);
				break;
				case 10:
					printf (">	pp second move:	");
					fread(&(loaded_pkmn->pp_moves[1]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->pp_moves[1]);
				break;
				case 11:
					printf (">	pp third move:	");
					fread(&(loaded_pkmn->pp_moves[2]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->pp_moves[2]);
					break;
				case 12:
					printf (">	pp fourth move:	");
					fread(&(loaded_pkmn->pp_moves[3]), sizeof(uint8_t), 1, np);
					printf("%d\n", loaded_pkmn->pp_moves[3]);
				break;
			}
		}
		printf("\n");
	}
	fclose(np); //chiusura del file.
}

void direct_conv(pkmn_nes loaded_pkmn, pkmn_gb* stored_pkmn)
{
	stored_pkmn->id_species = loaded_pkmn.id_species;
	stored_pkmn->level = loaded_pkmn.level;
	stored_pkmn->current_hp = loaded_pkmn.current_hp;
	stored_pkmn->maximum_hp = loaded_pkmn.maximum_hp;
	stored_pkmn->current_hp = stored_pkmn->current_hp << 8; //shifto il risultato di un byte per via della differenza di grandezza tra i due valori (uno è lungo 8 bit, l'altro 16).
	stored_pkmn->maximum_hp = stored_pkmn->maximum_hp << 8;
	copy_array(stored_pkmn->id_moves, loaded_pkmn.id_moves, 4);
	copy_array(stored_pkmn->pp_moves, loaded_pkmn.pp_moves, 4);
}

void exp_conv(pkmn_gb* stored_pkmn)
{
	long int total_exp; //variabile che conterrà il valore totale dei punti esperienza (prima che venga diviso in modo da stare in tre byte). 
	int expgrp[156] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 1, 1, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 1, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 4, 4}; //array containing pokémons' experience types (1 = fast; 2 = medium fast; 3 = medium slow; 4 = slow)
	switch (expgrp[stored_pkmn->id_species - 1]) //uso una formula diversa a seconda del gruppo di esperienza del pkmn
	{
		case 1:
			total_exp = pow((uint8_t) stored_pkmn->level, 3) * 4/5; 
		break;
		case 2:
			total_exp = pow((uint8_t) stored_pkmn->level, 3); //elevo a potenza
		break;
		case 3:
			total_exp = (pow((uint8_t) stored_pkmn->level, 3)) * 6/5 - 15 * pow(stored_pkmn->level, 2) + stored_pkmn->level * 100 - 140;
		break;
		case 4:
			total_exp = pow((uint8_t) stored_pkmn->level, 3) * 5/4; 
		break;
	}
	stored_pkmn->exp[0] = (uint8_t) (total_exp >> 16) & 0xFF; //necessario perchè gli exp sono rappresentati da 3 byte (ognuno di essi può contenere valori da 0 a 255)
	stored_pkmn->exp[1] = (uint8_t) (total_exp >> 8) & 0xFF;
	stored_pkmn->exp[2] = (uint8_t) (total_exp >> 0) & 0xFF;
}

void id_conv(pkmn_gb* stored_pkmn)
{
	switch (stored_pkmn->id_species)
	{
		case 152: //raikou
			stored_pkmn->id_species = 243;
		break;
		case 153: //entei
			stored_pkmn->id_species = 244;
		break;
		case 154: //suicune
			stored_pkmn->id_species = 245;
		break;
		case 155: //lugia
			stored_pkmn->id_species = 249;
		break;
		case 156: //oh-ho
			stored_pkmn->id_species = 250;
		break;
	}
}

void mov_conv(pkmn_gb* stored_pkmn)
{
	int i, j;
	int addr[251] = {0x8B, 0x4F, 0xFF, 0xFF, 0xFF, 0x8D, 0x02, 0x2C, 0x16, 0x8A, 0xFF, 0x9A, 0x95, 0x9F, 0x8F, 0x5C, 0x5E, 0xAC, 0x60, 0xFF, 0xFF, 0x1F, 0x91, 0x50, 0xFF, 0xFF, 0x52, 0x37, 0xFF, 0xFF, 0xFF, 0x9B, 0x89, 0xFF, 0xFF, 0xFF, 0xFF, 0x96, 0xA4, 0x43, 0x3D, 0xFF, 0xFF, 0x80, 0xA0, 0xAB, 0x9C, 0x9E, 0xFF, 0xFF, 0x45, 0x0, 0x03, 0xFF, 0x09, 0x0F, 0x0E, 0x2D, 0x2E, 0x66, 0xB, 0x2B, 0x97, 0x5B, 0x61, 0xFF, 0x4D, 0xFF, 0x54, 0xAF, 0x1C, 0x1D, 0xFF, 0xFF, 0x20, 0x23, 0x4B, 0x28, 0x26, 0xFF, 0x42, 0x79, 0xFF, 0x13, 0x17, 0x1B, 0x1A, 0x38, 0x34, 0x36, 0x32, 0x4C, 0x65, 0x6A, 0x6D, 0xFF, 0x71, 0x8C, 0xFF, 0x6F, 0xFF, 0xFF, 0xFF, 0xA8, 0xA9, 0xA3, 0xFF, 0xA6, 0x77, 0x12, 0xA2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x98, 0xFF, 0x72, 0x44, 0x48, 0x33, 0x5, 0xFF, 0x11, 0x90, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6B, 0x4A, 0xFF, 0x3C, 0x9D, 0x64, 0xFF, 0x08, 0xFF, 0x27, 0xA7, 0xFF, 0x87, 0xFF, 0x0D, 0x99, 0xFF, 0x35, 0x6E, 0x3B, 0x94, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xAE, 0xFF, 0xFF, 0x63, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x49, 0x30, 0x0C, 0xFF, 0x18, 0xFF, 0xFF, 0xFF, 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0xFF, 0xFF, 0xFF, 0xFF, 0x15, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4, 0xFF, 0x58, 0x40, 0x7A, 0xFF, 0xAA, 0xFF, 0x88, 0xFF, 0x84, 0x82, 0x53, 0xFF, 0xFF, 0xFF, 0x93, 0x57, 0x78, 0xFF, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0x3A, 0x75, 0xFF, 0x4E, 0xFF, 0xFF}; //vettore contenente una tabella di conversione degli indirizzi. 
	for (i = 0; i < 4; i++)
		for (j = 0; j < 251; j++)
			if (stored_pkmn->id_moves[i] == addr[j] && addr[j] != 0xFF) 
			{
				stored_pkmn->id_moves[i] = j + 1;
				j = 251;
			}
}

void addr_conv(pkmn_nes loaded_pkmn, pkmn_gb* stored_pkmn)
{
	*stored_pkmn = blank_pkmn_gb();
	direct_conv(loaded_pkmn, stored_pkmn); //copio da una struttura all'altra gli elementi che non richiedono conversioni particolari.
	exp_conv(stored_pkmn); //converto i valori dei punti esperienza.
	if (stored_pkmn->id_species > 151)
		id_conv(stored_pkmn); //conversione degli ultimi 5 pokémon del pokédex (gli unici di 2 gen --> per cui gli id non sono uguali).
	mov_conv(stored_pkmn); //converto gli index number delle mosse.
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

void gbup(pkmn_gb stored_pkmn)
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
		printf("Error! The program was not able to create the .pk2 file.\n\n");
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
		printf("\n[Your .pk2 file was successfully created.]\n\n");
		fclose(gp); //chiusura del file
	}
}
