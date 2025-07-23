/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Asma Askri
 * @brief          : Main program body
 ******************************************************************************
 * Bare metal implementation of an Input Capture Timer Driver
 * Rising edge input signal on PA6 is captured using Timer3
 * PA5 is toggled through Timer2 set in output compare mode
 * Use jumper/wire to connect PA6 and PA6
 ******************************************************************************
 */

#include "stm32f4xx.h"

#include "Timer.h"

int timestamp = 0;

int main(void) {


	 GPIOA_Init();

	Timer2_output_compare_init(1, 'h');

	Timer3_input_capture_init();

	while (1) {


		// wait till the raised edge is captured
		while(!(TIM3->SR & SR_CC1IF)) {};

		// Read captured value

		timestamp = TIM3->CCR1;


	}

}
