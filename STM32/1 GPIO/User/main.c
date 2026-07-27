#include "stm32f10x.h"
#include "delay.h"

int main() {
    delay_init();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_Init_Struct;
    GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_All;
    GPIO_Init(GPIOA, &GPIO_Init_Struct);
    uint16_t temp = ~0x01;
    GPIO_Write(GPIOA, temp);
    while(1) {
        temp = ~((~temp)<<1);
        if((temp & 0x00FF) >= 0xFF) temp = ~0x0001;
        GPIO_Write(GPIOA, temp);
        delay_ms(100);
    }
}
