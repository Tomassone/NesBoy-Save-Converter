
#include "services.h"

void edit_player_info(save_file* loaded)
{
	int input_value = 0, slctd_option = 0, valid = FALSE;
	while ((slctd_option = print_edit_player_info_menu()))
	{
		switch (slctd_option)
		{
			case EDIT_PLR_MONEY:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 16777215); //controllo che il valore digitato sia conservabile in 3 byte.
				if (valid == TRUE)
					loaded->player_money = input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_SEEN_PKMN:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 156);
				if (valid == TRUE)
					loaded->seen_pkmn = input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_CGHT_PKMN:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 156); //controllo che il numero di pokemon catturati sia in un range sensato.
				if (valid == TRUE)
					loaded->caught_pkmn = input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}

void edit_pokemon_info(pkmn_nes* selected)
{
	int input_value = 0, slctd_option = 0, valid = FALSE;
	while ((slctd_option = print_edit_pokemon_info_menu()))
	{
		switch (slctd_option)
		{
			case EDIT_PKMN_SPECIES:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 1, 156); //controllo che sia una specie di pokemon valida.
				if (valid == TRUE)
					selected->id_species = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_PKMN_LEVEL:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 1, 100);
				if (valid == TRUE)
					selected->level = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_PKMN_EXP:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 255);
				if (valid == TRUE)
					selected->exp = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_PKMN_ID_MOVE_1:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 255);
				if (valid == TRUE)
					selected->id_moves[0] = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_PKMN_ID_MOVE_2:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 255);
				if (valid == TRUE)
					selected->id_moves[1] = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_PKMN_ID_MOVE_3:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 255);
				if (valid == TRUE)
					selected->id_moves[2] = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			case EDIT_PKMN_ID_MOVE_4:
				printf("Enter a new value: ");
				input_value = check_input_if_int("Error! The input value is of valid type.\n");
				valid = check_num_val(input_value, 0, 255);
				if (valid == TRUE)
					selected->id_moves[3] = (uint8_t) input_value;
				else
					printf("Error! The input value is not valid.\n");
				valid = FALSE;
				break;
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}

void manage_pokemon_info(pkmn_nes* selected)
{
	int slctd_option = 0;
	while ((slctd_option = print_manage_pokemon_info_menu()))
	{
		switch (slctd_option)
		{
			case CHCK_PKMN_INFO:
				print_pkmn_nes(*selected);
				break;
			case EDIT_PKMN_INFO:
				edit_pokemon_info(selected);
				break;
			case TRNSFR_PKMN:
				transfer_pkmn_to_gb(*selected);
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}

void manage_player_info(save_file* loaded)
{
	int slctd_option = 0;
	while ((slctd_option = print_manage_player_info_menu()))
	{
		switch (slctd_option)
		{
			case CHCK_PLR_INFO:
				print_player_info(*loaded);
				break;
			case EDIT_PLR_INFO:
				edit_player_info(loaded);
				break;
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}

void edit_bag_section(bag_item* section, int size)
{
	int slctd_item = 0, amount = 0;
	printf("Which item do you want to select?\n");
	slctd_item = check_input_if_int("Error! The input value is not valid.\n");
	slctd_item--;
	printf("How many units do you want?\n");
	amount = check_input_if_int("Error! The input value is not valid.\n");
	if (check_num_val(slctd_item, 0, size - 1) && check_num_val(amount, 0, 255))
		section[slctd_item].amount = amount;
	else
		printf("One of the given values is not valid.\n");
}

void manage_player_bag(bag_item* section, int size, char* name)
{
	int slctd_option = 0;
	while ((slctd_option = print_manage_player_bag_section_menu()))
	{
		switch (slctd_option)
		{
			case CHCK_SCT_INFO:
				print_bag_section(section, size, name);
				break;
			case EDIT_SCT_INFO:
				edit_bag_section(section, size);
				break;
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}

void choose_player_bag(save_file* loaded)
{
	int slctd_option = 0;
	while ((slctd_option = print_choose_player_bag_section_menu()))
	{
		switch (slctd_option)
		{
			case ITEMS:
				manage_player_bag((loaded->items), MAX_ITEMS, "Items");
				break;
			case BALLS:
				manage_player_bag((loaded->balls), MAX_BALLS, "Balls");
				break;
			case KEY_ITEMS:
				manage_player_bag((loaded->key_items), MAX_KEY_ITEMS, "Key items");
				break;
			case TMS_HMS:
				manage_player_bag((loaded->tms_hms), MAX_TMS_HMS, "TMs and HMs");
				break;
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}

void choose_pokemon_from_team(save_file* loaded)
{
	int pkmn_choice = 0, valid = FALSE;
	while (valid == FALSE) //controllo del valore inserito.
	{
		printf ("Which pokemon of your party would you like to select? ");
		pkmn_choice = check_input_if_int("Error! The input value is not valid."); //controllo che il valore inserito sia un intero.
		pkmn_choice--;
		
		if (check_num_val(pkmn_choice, 0, 5)) //se cioè è un numero compreso tra 0 e 5.
		{
			manage_pokemon_info(&loaded->team[pkmn_choice]);
			valid = TRUE;
		}
		else
			printf("The selected pokemon does not exist. Please choose another one.\n");
	}
	valid = FALSE;
}


