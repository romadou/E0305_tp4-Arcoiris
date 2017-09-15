/*
 * LED.h
 *
 *  Created on: 10/07/2017
 *      Author: Krasowski - Madou
 */

#ifndef LED_H_
#define LED_H_

/* Valor m�ximo de color */
#ifndef COLOR_MAX
#define COLOR_MAX 31
#endif

/* Valor m�nimo de color */
#ifndef COLOR_MIN
#define COLOR_MIN 1
#endif

/* Valor m�ximo del ADC */
#ifndef ADC_MAX
#define ADC_MAX 255
#endif

/* Valor m�ximo del ADC */
#ifndef ADC_MAX
#define ADC_MAX 255
#endif

void LED_init(void);
void LED_red(void);
void LED_green(void);
void LED_blue(void);
void LED_incR(void);
void LED_incG(void);
void LED_incB(void);
void LED_decR(void);
void LED_decG(void);
void LED_decB(void);
void LED_pote(void);

typedef enum {ROJO, VERDE, AZUL, BLANCO} colores;

#endif /* LUZ_H_ */
