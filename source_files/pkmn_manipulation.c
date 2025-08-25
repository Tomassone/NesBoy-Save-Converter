
#include "pkmn_manipulation.h" //inclusione del corrispondente file header.

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
	//variabili contatrici.
	int i, j;
	//variabile di controllo.
	int found = FALSE;
	//vettore contenente una tabella di conversione degli indirizzi.
	int addr[251] = {0x8B, 0x4F, 0xFF, 0xFF, 0xFF, 0x8D, 0x02, 0x2C, 0x16, 0x8A, 0xFF, 0x9A, 0x95, 
					 0x9F, 0x8F, 0x5C, 0x5E, 0xAC, 0x60, 0xFF, 0xFF, 0x1F, 0x91, 0x50, 0xFF, 0xFF, 
					 0x52, 0x37, 0xFF, 0xFF, 0xFF, 0x9B, 0x89, 0xFF, 0xFF, 0xFF, 0xFF, 0x96, 0xA4, 
					 0x43, 0x3D, 0xFF, 0xFF, 0x80, 0xA0, 0xAB, 0x9C, 0x9E, 0xFF, 0xFF, 0x45, 0x00, 
					 0x03, 0xFF, 0x09, 0x0F, 0x0E, 0x2D, 0x2E, 0x66, 0x0B, 0x2B, 0x97, 0x5B, 0x61, 
					 0xFF, 0x4D, 0xFF, 0x54, 0xAF, 0x1C, 0x1D, 0xFF, 0xFF, 0x20, 0x23, 0x4B, 0x28, 
					 0x26, 0xFF, 0x42, 0x79, 0xFF, 0x13, 0x17, 0x1B, 0x1A, 0x38, 0x34, 0x36, 0x32, 
					 0x4C, 0x65, 0x6A, 0x6D, 0xFF, 0x71, 0x8C, 0xFF, 0x6F, 0xFF, 0xFF, 0xFF, 0xA8, 
					 0xA9, 0xA3, 0xFF, 0xA6, 0x77, 0x12, 0xA2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
					 0xFF, 0xFF, 0x98, 0xFF, 0x72, 0x44, 0x48, 0x33, 0x05, 0xFF, 0x11, 0x90, 0xFF, 
					 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6B, 0x4A, 0xFF, 0x3C, 0x9D, 0x64, 
					 0xFF, 0x08, 0xFF, 0x27, 0xA7, 0xFF, 0x87, 0xFF, 0x0D, 0x99, 0xFF, 0x35, 0x6E, 
					 0x3B, 0x94, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
					 0xFF, 0xFF, 0x01, 0xFF, 0xAE, 0xFF, 0xFF, 0x63, 0xFF, 0xFF, 0xFF, 0x29, 0xFF, 
					 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x49, 0x30, 0x0C, 0xFF, 0x18, 0xFF, 0xFF, 0xFF, 
					 0x2A, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA5, 0xFF, 0xFF, 0xFF, 0xFF, 
					 0x15, 0xFF, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 
					 0xFF, 0x58, 0x40, 0x7A, 0xFF, 0xAA, 0xFF, 0x88, 0xFF, 0x84, 0x82, 0x53, 0xFF, 
					 0xFF, 0xFF, 0x93, 0x57, 0x78, 0xFF, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0x3A, 0x75, 
					 0xFF, 0x4E, 0xFF, 0xFF}; 
	/*for (i = 0; i < 251; i++)
	{
		printf("%d) ", i + 1);
		printf("0x%X\n", addr[i]);
	}*/
	for (i = 0; i < 4; i++)
	{
		for (j = 0; (j < 251) && (found == FALSE); j++)
		{
			//se cioè c'è una corrispondenza tra l'indice della mossa e la tabella di conversione.
			if (stored_pkmn->id_moves[i] == addr[j])
			{
				if (addr[j] == 0xFF)
				{
					stored_pkmn->id_moves[i] = 0x00;
					stored_pkmn->pp_moves[i] = 0x00;
					found = TRUE;
				}
				else 
				{
					//printf("%d) addr = 0x%X\n", j + 1, addr[j]);
					stored_pkmn->id_moves[i] = j + 1;
					found = TRUE;
				}
			}
		}
		found = FALSE;
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

void transfer_pkmn_to_gb(pkmn_nes loaded_pkmn)
{
	pkmn_gb stored_pkmn; //struttura di base del file pokèmon di seconda generazione.
	addr_conv(loaded_pkmn, &stored_pkmn); //effettuo la conversione della struttura.
	upload_to_gb(stored_pkmn); //creo il file .pk2.
}
