
#ifndef TIMER_H_
#define TIMER_H_

#define SR_CC1IF       (1U << 1)


void Timer2_output_compare_init(int Prescaler, char SecOrFreq);

void Timer3_input_capture_init(void);

void GPIOA_Init(void);


#endif /* TIMER_H_ */
