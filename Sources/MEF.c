/*
 * MEF.c
 *
 *  Created on: 10/07/2017
 *      Author: Krasowski - Madou
 */

#include "MEF.h"
#include "LED.h"
#include "PWM.h"
#include "derivative.h"

/* Variables privadas */
static estado actual; /* Estado actual de la MEF */

/* Variables globales */
unsigned char flag_P;
unsigned char flag_B;
unsigned char flag_O;
unsigned int velocidad=1;

/* Funciones privadas */
void estado_off(unsigned char entrada);
void estado_on(unsigned char entrada);
void on_update(unsigned char entrada);
void setP(void);
void setB(void);


void MEF_init(void){
	actual=OFF;
	flag_P=0;
	flag_B=0;
	flag_O=0;
	LED_init();
}

void MEF_update(unsigned char entrada){
	if (entrada != 0xFF){
		if (actual == ON){
			estado_on(entrada);
		}
		else{
			estado_off(entrada);
		}
	}
}

void estado_on(unsigned char entrada){
	if (entrada == '#'){
		flag_O=0;
		PWM_init();
		actual=OFF;
	}
	else if (entrada!=0xFF){
		on_update(entrada);
	}
}

void estado_off(unsigned char entrada){
	if (entrada=='*'){
		flag_O=1;
		PWM_init();
		actual=ON;
	}
}

void on_update(unsigned char entrada){
	if (!flag_B){
		switch(entrada){
		case '0':
			/* Prender el blanco */
			LED_init();
			break;
			;
		case '1':
			/* Prender el rojo */
			LED_red();
			break;
			;
		case '2':
			/* Prender el verde */
			LED_green();
			break;
			;
		case '3':
			/* Prender el azul */
			LED_blue();
			break;
			;
		case '4':
			/* Aumentar la intensidad del rojo */
			LED_incR();
			break;
			;
		case '5':
			/* Aumentar la intensidad del verde */
			LED_incG();
			break;
			;
		case '6':
			/* Aumentar la intensidad del azul */
			LED_incB();
			break;
			;
		case '7':
			/* Disminuir la intensidad del rojo */
			LED_decR();
			break;
			;
		case '8':
			/* Disminuir la intensidad del verde */
			LED_decG();
			break;
			;
		case '9':
			/* Disminuir la intensidad del azul */
			LED_decB();
			break;
			;
		case 'A':
			/* Aumentar la velocidad de parpadeo y barrido */
			if (flag_P && velocidad<VEL_MAX){
				velocidad++;
			}
			break;
			;
		case 'B':
			/* Disminuir la velocidad de parpadeo y barrido */
			if (flag_P && velocidad>VEL_MIN){
				velocidad--;
			}
			break;
			;
		case 'C':
			setP(); /* Encender o apagar el modo parpadeo */
			break;
			;
		case 'D':
			setB(); /* Encender o apagar el modo barrido */
			break;
			;
		default:
		;
		}
	}
	else{
		switch(entrada){
		case 'A':
			/* Aumentar la velocidad de parpadeo y barrido */
			if (velocidad<VEL_MAX){
				velocidad++;
			}
			break;
			;
		case 'B':
			/* Disminuir la velocidad de parpadeo y barrido */
			if (velocidad>VEL_MIN){
				velocidad--;
			}
			break;
			;
		case 'C':
			setP(); /* Encender o apagar el modo parpadeo */
			break;
			;
		case 'D':
			setB(); /* Encender o apagar el modo barrido */
			break;
			;
		default:
		;
		}
	}
}

void setP(void){
	flag_P = !flag_P;
}

void setB(void){
	flag_B = !flag_B;
}
