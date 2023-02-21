//
// Created by 83503 on 2023/2/21.
//

/**
 * 每次给一个灯一个24位的数据，顺序是GRB-green red bule
 */

#include "ws2812b.h"

extern TIM_HandleTypeDef htim15;

/*二维数组存放最终PWM输出数组，每一行24个
数据代表一个LED，最后一行24个0代表RESET码*/
uint32_t rbg_buf[2][24];

/**
 *
 * @param color
 */
void RGB_SetColor(RGB_Color_TypeDef color) {
    //GRB的顺序发，24位高位先发（H xxx  L）
    for (int i = 0; i < 8; i++) {
        rbg_buf[0][i] = ((color.G & 0x80) ? CODE_1 : CODE_0);
        color.G <<= 1;
    }
    for (int i = 8; i < 16; i++) {
        rbg_buf[0][i] = ((color.R & 0x80) ? CODE_1 : CODE_0);
        color.R <<= 1;
    }
    for (int i = 16; i < 24; i++) {
        rbg_buf[0][i] = ((color.B & 0x80) ? CODE_1 : CODE_0);
        color.B <<= 1;
    }
    //最后一行装在24个0，输出24个周期占空比为0的PWM波
    // 作为最后reset延时，这里总时长为24*1.2=30us > 24us(要求大于24us)
    for (int i = 0; i < 24; i++) {
        rbg_buf[1][i] = 0;
    }
    //(&htim15)定时器1，(TIM_CHANNEL_1)通道1，((uint32_t *)Pixel_Buf)待发送数组，
    //			(Pixel_NUM+1)*24)发送个数，数组行列相乘
    HAL_TIM_PWM_Start_DMA(&htim15, TIM_CHANNEL_3, (uint32_t *) rbg_buf, 2 * 24);
}

