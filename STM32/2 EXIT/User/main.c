#include "stm32f10x.h"
#include "delay.h"
#include "OLED.h"
#include "CountSensor.h"

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
    OLED_ShowString(1, 1 , "Count:");
    OLED_ShowNum(1, 10 , 0,3);

    OLED_ShowString(2, 1 , "Count2:");
    OLED_ShowNum(2, 10 , 0,3);
    while(1) {
        OLED_ShowNum(1, 10 , Get_CountSensorCnt(),3);
        OLED_ShowSignedNum(2, 9 , Get_CountSensorCnt2(),3);
    }
}
