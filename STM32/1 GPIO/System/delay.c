#include "delay.h"

static uint32_t fac_us = 0;
static uint32_t fac_ms = 0;

void delay_init(void) {
    SystemCoreClockUpdate();                        // 读取 RCC 寄存器，获取真实时钟
    fac_us = SystemCoreClock / 1000000;
    fac_ms = SystemCoreClock / 1000;
}

void delay_ms(uint32_t ms) {
    SysTick->LOAD = fac_ms;
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk      // HCLK 不分频
                  | SysTick_CTRL_ENABLE_Msk;

    for (uint32_t i = 0; i < ms; i++) {
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
    }

    SysTick->CTRL = 0;
}

void delay_s(uint32_t s) {
    delay_ms(s * 1000);
}

void delay_us(uint32_t us) {
    SysTick->LOAD = fac_us * us;
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk
                  | SysTick_CTRL_ENABLE_Msk;

    while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));

    SysTick->CTRL = 0;
}
