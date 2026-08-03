#include "stm32f10x.h"

uint16_t timerCnt=0;
uint16_t timerCnt2=0;
void TIM_Init() {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
    
    TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x00);
    //tim2 use external clock
    TIM_InternalClockConfig(TIM3);//tim3 use internal clock

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructue;
    TIM_TimeBaseInitStructue.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructue.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructue.TIM_Period = 10 - 1;
    TIM_TimeBaseInitStructue.TIM_Prescaler = 1 - 1;
    //中断频率 = 定时器时钟 ÷ ((Prescaler + 1) × (Period + 1))
    TIM_TimeBaseInitStructue.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructue);
    TIM_TimeBaseInitStructue.TIM_Period = 1000 - 1;
    TIM_TimeBaseInitStructue.TIM_Prescaler = 7200-1;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructue);

    TIM_ClearFlag(TIM2, TIM_IT_Update);TIM_ClearFlag(TIM3, TIM_IT_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructrue;
    NVIC_InitStructrue.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructrue.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructrue.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructrue.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_InitStructrue);
    NVIC_InitStructrue.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_Init(&NVIC_InitStructrue);
    TIM_Cmd(TIM2, ENABLE);TIM_Cmd(TIM3, ENABLE);
}
uint16_t Get_TimerCnt() {
    return timerCnt;
}
uint16_t Get_TimerCnt2() {
    return timerCnt2;
}

void TIM2_IRQHandler(void) {
    if(TIM_GetITStatus(TIM2, TIM_IT_Update)==SET) {
        timerCnt2++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    } 
}
void TIM3_IRQHandler(void) {
    static uint16_t tempCnt=0;
    if(TIM_GetITStatus(TIM3, TIM_IT_Update)==SET) {
        tempCnt++;
        if(tempCnt>=10) {
            tempCnt=0;
            timerCnt++;
        }
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    } 
}