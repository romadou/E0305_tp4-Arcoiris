
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PWM.h"
#include "MEF.h"
#include "RTC.h"
#include "keypad.h"
#include "LED.h"


#ifdef __cplusplus
extern "C"
#endif

void MCU_init(void); /* Device initialization function declaration */

extern unsigned char flag_M;
extern unsigned char flag_O;

void main(void) {
	unsigned char car=0xFF;
	unsigned char tecla;
  MCU_init();	/* call Device Initialization */
  KEYPAD_init();
  PWM_init();
  MEF_init();
   

  for(;;) {
    /* __RESET_WATCHDOG(); By default COP is disabled with device init. When enabling, also reset the watchdog. */
	  
	  if (flag_O && ADCSC1_COCO){
	  	  LED_pote();
	  }
	  if (flag_M){
		  if (KEYPAD_update(&car)){
			  tecla=KEYPAD_char(car);
			  MEF_update(tecla);
		  }
		  else{
			  MEF_update(0xFF);
		  }
		  flag_M=0;
	  }
	  
  } /* loop forever */
  /* please make sure that you never leave main */
}
