#include "stm32f10x.h"
#include "delay.h"
#include "OLED.h"

BitAction Invert(uint16_t temp) {
    switch (temp) {
        case 0x01:
            return Bit_RESET;
        case 0x00:
            return Bit_SET;
        default:
            return Bit_SET;
    }
}

int main() {
    delay_init();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef GPIO_Init_Struct;
    GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_Init(GPIOA, &GPIO_Init_Struct);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOB, &GPIO_Init_Struct);

    GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
    GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);


    OLED_Init();
    OLED_ShowString(1, 1, "Hello");
    OLED_ShowString(2, 1, "World");
    while(1) {
        if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0){
            delay_ms(30);
            while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)==0);
            delay_ms(30);
            GPIO_WriteBit(GPIOA, GPIO_Pin_0, Invert(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_0)));
            GPIO_WriteBit(GPIOA, GPIO_Pin_1, Invert(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1)));
        }
        
    }
}
