/*
 * LED.c
 *
 *  Created on: 10/07/2017
 *      Author: Krasowski - Madou
 */

#include "LED.h"
#include "MEF.h"
#include "RTC.h"
#include "derivative.h"

/* Variables globales */
unsigned int RED;
unsigned int GREEN;
unsigned int BLUE;

extern unsigned char flag_POff;
extern unsigned char flag_B;
extern unsigned char flag_O;
extern unsigned char flag_Sw;

/* Variables privadas */
static unsigned int factor=0;
static unsigned int preRED=0;
static unsigned int preGREEN=0;
static unsigned int preBLUE=0;
static colores color; /* color actual en modo barrido */


void LED_init(void){
	preRED=COLOR_MAX;
	preGREEN=COLOR_MAX;
	preBLUE=COLOR_MAX;
	color=ROJO;
}

void LED_red(void){
	preRED=COLOR_MAX;
	preGREEN=COLOR_MIN;
	preBLUE=COLOR_MIN;
}

void LED_green(void){
	preRED=COLOR_MIN;
	preGREEN=COLOR_MAX;
	preBLUE=COLOR_MIN;
}

void LED_blue(void){
	preRED=COLOR_MIN;
	preGREEN=COLOR_MIN;
	preBLUE=COLOR_MAX;
}

void LED_incR(void){
	if(preRED<COLOR_MAX){
		preRED++;
	}
}

void LED_incG(void){
	if(preGREEN<COLOR_MAX){
		preGREEN++;
	}
}

void LED_incB(void){
	if(preBLUE<COLOR_MAX){
		preBLUE++;
	}
}

void LED_decR(void){
	if(preRED>COLOR_MIN){
		preRED--;
	}
}

void LED_decG(void){
	if(preGREEN>COLOR_MIN){
		preGREEN--;
	}
}

void LED_decB(void){
	if(preBLUE>COLOR_MIN){
		preBLUE--;
	}
}

void LED_pote(void){
	if (!flag_POff && flag_O){
		factor=ADCR;
		if (!flag_B){
			RED=((preRED*factor)/ADC_MAX);
			GREEN=((preGREEN*factor)/ADC_MAX);
			BLUE=((preBLUE*factor)/ADC_MAX);
		}
		else{
			if (flag_Sw){
				/* Cambio del color por barrido */
				switch(color){
				case ROJO:
					color=VERDE;
					RED=COLOR_MIN;
					GREEN=((COLOR_MAX*factor)/ADC_MAX);
					BLUE=COLOR_MIN;
					break;
				case VERDE:
					color=AZUL;
					RED=COLOR_MIN;
					GREEN=COLOR_MIN;
					BLUE=((COLOR_MAX*factor)/ADC_MAX);;
					break;
				case AZUL:
					color=ROJO;
					RED=((COLOR_MAX*factor)/ADC_MAX);;
					GREEN=COLOR_MIN;
					BLUE=COLOR_MIN;
					break;
				default:;
				}
				flag_Sw=0;
			}
		}
	}
	else{
		/* Apagado o en tiempo bajo del parpadeo */
		RED=COLOR_MIN;
		GREEN=COLOR_MIN;
		BLUE=COLOR_MIN;
	}
}
