/*
 * keypad.h
 *
 *  Created on: 10/07/2017
 *      Author: Krasowski - Madou
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

void KEYPAD_init(void); /* Inicializaci�n del teclado */
unsigned char KEYPAD_update(unsigned char *tecla); /* Actualizaci�n del teclado */
unsigned char KEYPAD_char(unsigned char tecla); /* Transformaci�n de c�digo de teclado al caracter correspondiente */

#endif /* KEYPAD_H_ */
