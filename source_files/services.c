
#include "services.h"

void manage_player_info(save_file loaded)
{
	int slctd_option = 0;
	while ((slctd_option = print_manage_player_info_menu()))
	{
		switch (slctd_option)
		{
			case CHCK_PLR_INFO:
				print_player_info(loaded);
				break;
			case EDIT_PLR_INFO:
				print_player_info(loaded);
				break;
			default:
				return;
				break;
		}
		conf_dialog();
		clrscr();
	}
}
