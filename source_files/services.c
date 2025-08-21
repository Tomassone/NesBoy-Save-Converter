
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
