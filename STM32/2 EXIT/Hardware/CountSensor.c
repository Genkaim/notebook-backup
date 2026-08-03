#include "stm32f10x.h"
int16_t CountSensor_cnt = 0;
int16_t CountSensor_cnt2 = 0;
void CountSensor_Init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStruct.GPIO_Speed =  GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource1);

    EXTI_InitTypeDef EXTI_InitStruct;
    EXTI_InitStruct.EXTI_Line = EXTI_Line14 | EXTI_Line0 | EXTI_Line1;
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&EXTI_InitStruct);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStucture;
    NVIC_InitStucture.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStucture.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStucture.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStucture.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&NVIC_InitStucture);

    NVIC_InitStucture.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_Init(&NVIC_InitStucture);
    NVIC_InitStucture.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_Init(&NVIC_InitStucture);
}

int16_t Get_CountSensorCnt() {
    return CountSensor_cnt;
}
int16_t Get_CountSensorCnt2() {
    return CountSensor_cnt2;
}
void EXTI15_10_IRQHandler(void) {
    if(EXTI_GetITStatus(EXTI_Line14) == SET) {
        CountSensor_cnt++;
        EXTI_ClearITPendingBit(EXTI_Line14);
    }
} 

void EXTI0_IRQHandler(void) {
    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)==0) CountSensor_cnt2++;
    EXTI_ClearITPendingBit(EXTI_Line0);
}
void EXTI1_IRQHandler(void) {
    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0) CountSensor_cnt2--;
    EXTI_ClearITPendingBit(EXTI_Line1);
}