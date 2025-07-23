/*
 *
 *
 *
 *
 */

#include "stm32f4xx.h"

#include "Timer.h"

#define CR1_CEN   			  (1U << 0)

#define CR1_DIR   				  (1U << 4)

#define SR_UIF    				  (1U << 0)

#define RCC_GPIOA_EN              (1U << 0)

#define GPIOA_MODER_1             (1U << 10)

#define GPIOA_MODER_2             (1U << 11)

#define TIM2EN                    (1U << 0)

#define SysCLCK                   16000000UL

#define OC_TOGGLE                 ((1U << 4) | (1U << 5))

#define CCMR1_OC1PE                (1U << 3)

#define CCER_CC1P                 (1U << 1)

#define CCER_CC1E                (1U << 0)

#define AFR5_TIM				  (1U << 20)

#define TIM3EN                    (1U << 1)

#define GPIOA_MODER_3             (1U << 12)

#define GPIOA_MODER_4             (1U << 13)

#define AFR6_TIM				  (1U << 25)

#define CCMR1_CC1S                 (1U << 0)

#define CCMR1_IC1F                 ((1U << 4) | (1U << 5))

#define CCER_CC1P                  (1U << 1)

#define CCER_CC1NP                 (1U << 3)

#define SR_CC1IF                   (1U << 1)


void Timer2_output_compare_init(int Prescaler, char SecOrFreq) {


	uint32_t Preload_VAL = 0, Timer_Prescaler = 0;

	Timer_Prescaler = 1600;

	// Enable clock acess to timer 2

	RCC->APB1ENR |= TIM2EN  ;

	// set Timer prescaler to 2


	 TIM2->PSC =  Timer_Prescaler -1 ; // 16 000 000 / 1600 --> 10 000

	// Enable Upcounting mode :  CR1_DIR

	TIM2->CR1 |= CR1_DIR;

	// read the preload value

	if (SecOrFreq == 'h' ) {

		 Preload_VAL =  ( SysCLCK/Timer_Prescaler)/ Prescaler  ;

	}

	if (SecOrFreq == 's' ) {

		Preload_VAL =  Prescaler * ( SysCLCK/Timer_Prescaler)  ;

	}

	TIM2->ARR = Preload_VAL - 1;

	// Select the output mode

	TIM2->CCMR1 |= 	 OC_TOGGLE ;

	TIM2->CCMR1 &=~CCMR1_OC1PE ;

	TIM2->CCER &=~CCER_CC1P ;

	TIM2->CCER |= CCER_CC1E;

	// clear counter

	TIM2->CNT = 0;

	// Enable counter TIMx_CR1 : CEN bit

	 TIM2->CR1 |= CR1_CEN ;

}


void Timer3_input_capture_init(void){

	// enable clock access to Timer 3 : 16-bit

	  RCC->APB1ENR |= TIM3EN;

	  // define the direction of the channel CH1 as input

	  TIM3->CCMR1 &= ~CCMR1_CC1S;

	  TIM3->CCMR1 &= ~(1U << 4);
	  TIM3->CCMR1 &= ~(1U << 5);
	  TIM3->CCMR1 &= ~(1U << 6);

	  TIM3->CCMR1 |= CCMR1_CC1S;

	  // Set prescaler

	  TIM3->PSC = 16000 -1;


	  // set input filter duration to 8

	  TIM3->CCMR1 |= CCMR1_IC1F;

	  // Enable input capture at rising edge

	  TIM3->CCER &=~CCER_CC1P;

	  TIM3->CCER &=~CCER_CC1NP ;

	  // enable capture mode

	  TIM3->CCER = CCER_CC1E;

	  // enable timer

	  TIM3->CR1 |= CR1_CEN;
}


void GPIOA_Init(void){

	// enable clock access to port A

	RCC->AHB1ENR |= RCC_GPIOA_EN ;

	// set PA5 mode to alternate function

	GPIOA->MODER &=  ~GPIOA_MODER_1 ;

    GPIOA->MODER |=  GPIOA_MODER_2 ;


    // set PA6 to alternate function

    GPIOA->MODER &= ~GPIOA_MODER_3;

    GPIOA->MODER |= GPIOA_MODER_4;

    // set alternate function to AF1, for PA5

    GPIOA->AFR[0] |= AFR5_TIM;

    // set alternate function to AF2, for PA6

    GPIOA->AFR[0] |=  AFR6_TIM;

}



