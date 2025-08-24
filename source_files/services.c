
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
