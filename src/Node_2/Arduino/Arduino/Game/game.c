/*
 * game.c
 *
 * Created: 16.11.2022 10:18:15
 * Author :
 *	Andreas Holleland
 *	Daniel Guarecuco
 *	Marcus Tjomsaas
 */ 

#include <sam.h>
#include "game.h"

 static uint8_t temp_count_blocked=0;
 static uint8_t temp_count_non_blocked=0;
	
uint8_t count_goals(uint8_t goals){
	if (check_ir() == 1){
		temp_count_blocked++;
	}

	if (temp_count_blocked >= 1){
		if (check_ir() == 0){
			temp_count_non_blocked++;
		}
	}
	if (temp_count_non_blocked > 10) {
		temp_count_blocked=0;
		temp_count_non_blocked=0;
		goals++;
	}
return goals;
}