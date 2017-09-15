/*
 * RTC.c
 *
 *  Created on: 07/07/2017
 *      Author: usuario
 */
#include "derivative.h"
#include "PWM.h"
#include "RTC.h"
#include "LED.h"
#include "MEF.h"

static unsigned int cnt=0;
static unsigned int contP=0;
static unsigned int contB=0;

unsigned char flag_M=0;
unsigned char flag_POff=0;
unsigned char flag_Sw=0;

extern unsigned char flag_P;
extern unsigned char flag_B;
extern unsigned char flag_O;
extern unsigned int velocidad;



void Scheduler_MEF(void);
void Scheduler_PWM(void);
void Scheduler_LED(void);

void RTC_Handler(){
	cnt++;
	Scheduler_MEF();
	Scheduler_LED();
	Scheduler_PWM();
	RTCSC_RTIF=1;
}

void Scheduler_MEF(void){
	if (cnt==PULSOS_MEF){
		flag_M=1;
		cnt=0;
	}
}

void Scheduler_LED(void){
	if (flag_P){
		contP++;
		if (contP*velocidad>STD){
			flag_POff=!flag_POff;
			contP=0;
		}
	}
	else{
		flag_POff=0;
	}
	if (flag_B){
		contB++;
		if (contB*velocidad>2*STD){
			flag_Sw=1;
			contB=0;
		}
	}
}

void Scheduler_PWM(void){
	if (flag_O){
		PWM_update();
	}
}
