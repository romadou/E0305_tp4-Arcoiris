/*
 * MEF.h
 *
 *  Created on: 10/07/2017
 *      Author: Krasowski - Madou
 */

#ifndef MEF_H_
#define MEF_H_

#ifndef VEL_MAX 
#define VEL_MAX 6
#endif

#ifndef VEL_MIN 
#define VEL_MIN 1
#endif

typedef enum {ON, OFF} estado;

void MEF_init(void);
void MEF_update(unsigned char entrada);

#endif /* MEF_H_ */
