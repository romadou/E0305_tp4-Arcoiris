/*
 * PWM.c
 *
 *  Created on: 03/07/2017
 *      Author: usuario
 */

#include "mc9s08sh8.h"
#include "derivative.h"
#include "MEF.h"
#include "PWM.h"

static unsigned int cont_PWM;

extern unsigned int RED;
extern unsigned int GREEN;
extern unsigned int BLUE;

void PWM_init(void){
	cont_PWM=0;
	PTCDD_PTCDD1=1;
	PTCDD_PTCDD2=1;
	PTCDD_PTCDD3=1;
	PTCDS=0xFF;
	PTCD_PTCD1=1;
	PTCD_PTCD2=1;
	PTCD_PTCD3=1;
}

void PWM_update(void){
	if (++cont_PWM>MOD_PWM){
		cont_PWM=0;
		if (RED!=0){
			PTCD_PTCD1=0;
		}
		if (GREEN!=0){
			PTCD_PTCD2=0;
		}
		if (BLUE!=0){
			PTCD_PTCD3=0;
		}
	}
	if (cont_PWM==RED){
		PTCD_PTCD1=1;
	}
	if (cont_PWM==GREEN){
		PTCD_PTCD2=1;
	}
	if (cont_PWM==BLUE){
		PTCD_PTCD3=1;
	}
}
