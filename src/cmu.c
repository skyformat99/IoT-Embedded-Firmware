//***********************************************************************************
// Include files
//***********************************************************************************
#include "cmu.h"
#include "sleep.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
void cmu_init(sleepstate_enum e){

	// By default, HFRCO is enabled  cmuHFRCOFreq_19M0Hz
	CMU_HFRCOBandSet(cmuHFRCOFreq_19M0Hz); 				// Set HFRCO frequency
	CMU_HFXOAutostartEnable(0, false, false);
	CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO);

	CMU_OscillatorEnable(cmuOsc_HFXO, false, false);	// Disable HFXO


	// By default, LFRCO is enabled
	//CMU_OscillatorEnable(cmuOsc_LFXO, false, false);		// Disable LFXO


	 if (e < EM3) {
	        CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
	        CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
	    } else {
	        CMU_OscillatorEnable(cmuOsc_ULFRCO,true,true);
	        CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);
	    }

		CMU_ClockEnable(cmuClock_CORELE, true);
		CMU_ClockEnable(cmuClock_LETIMER0, true);

	// Peripheral clocks enabled
	CMU_ClockEnable(cmuClock_GPIO, true);
}

