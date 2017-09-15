/*
 * keypad.c
 *
 *  Created on: 10/07/2017
 *      Author: Krasowski - Madou
 */

#include "keypad.h"
#include "derivative.h"

/* Variables privadas */
static unsigned char last_valid_key;
static unsigned char last_key;

/* Funciones privadas */
/* Escaneo del teclado para verificar si hay alguna tecla presionada */
void scan (unsigned char *key);

void KEYPAD_init(void){
	PTBDD = 0x0F; /* FILAS como salidas, COLUMNAS como entradas */
	PTBPE = 0xF0; /* Activación de resistencias de pull-up para las columnas */
}

unsigned char KEYPAD_update(unsigned char *tecla){
	unsigned char key = 0xFF; 
	/* Lectura de teclado */
	scan(&key);
	if (key == 0xFF){
		last_key = 0xFF;
		last_valid_key = 0xFF;
		return 0;
	}
	if (key == last_key){
		if (key != last_valid_key){
			*tecla = key;
			last_valid_key = key;
			return 1;
		}
	}
	last_key = key;
	return 0;
}

unsigned char KEYPAD_char(unsigned char tecla){
	static char teclado[] =
	{'1','2','3','A',
			'4','5','6','B',
			'7','8','9','C',
			'*','0','#','D'
	};
	return teclado[tecla];
}

void scan(unsigned char *key){
	unsigned char i, j;
	unsigned char maskF; /* FILAS => salidas */
	unsigned char maskC; /* COLUMNAS => entradas */
	
	/* Asignación inicial: 1 a todos los bits fila */
	PTBD = PTBD | 0b00001111;
	
	maskF = 1;
	for (i=0;i<4;i++){
		/* Seteo de un bit fila a 0 - Fila a analizar */
		PTBD = PTBD & (~maskF);
		
		maskC=0x10;
		for (j=0; j<4; j++){
			/* Búsqueda y detección de un valor bajo en algún bit de la entrada */
			if ((~PTBD) & maskC){
				*key = 4*i+j; /* Asignación del valor de la tecla presionada */
				return;
			}
			maskC = maskC << 1; 
		}
		
		maskF = maskF << 1;
		PTBD = PTBD | 0b00001111;
	}
}
