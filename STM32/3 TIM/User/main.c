#include "stm32f10x.h"
#include "delay.h"
#include "OLED.h"
#include "CountSensor.h"
#include "TIM.h"

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
    OLED_Init();
    CountSensor_Init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    TIM_Init();
    OLED_ShowString(1, 1 , "Count:");
    OLED_ShowNum(1, 10 , 0,3);

    OLED_ShowString(2, 1 , "TimerCnt");
    OLED_ShowNum(2, 11 , 0, 3);

    OLED_ShowString(3, 1 , "TimerCnt2:");
    OLED_ShowNum(3, 11 , 0,3);
    OLED_ShowString(4, 1 , "(ExtClkSource)");
    while(1) {
        OLED_ShowSignedNum(1, 10 , Get_CountSensorCnt(),3);
        OLED_ShowNum(2, 11 , Get_TimerCnt(),3);
        OLED_ShowNum(3, 11 , Get_TimerCnt2(),3);
    }
}
