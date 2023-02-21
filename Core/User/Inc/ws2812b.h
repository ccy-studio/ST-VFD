//
// Created by 83503 on 2023/2/21.
//

#ifndef ST_VFD_WS2812B_H
#define ST_VFD_WS2812B_H

#include "main.h"
/**
参考： https://blog.csdn.net/qq_49519820/article/details/127930074

0码PWM占空比：

（0码高电平时间）/（周期）--->  0.4 / 1.25 = 0.32

用占空比乘以定时器重装值加一就是0码的CCR值（代表PWM高电平计数个数）--->

0.32 * （79+1） = 25.6

1码PWM占空比：

同理计算：（1码高电平时间）/ （周期）---> 0.8 / 1.25 = 0.64

（占空比）*（重置值+1）= CCR ---> 0.64  * （79+1） = 51
*/

//定义0和1的高电平占空比
#define CODE_1  51
#define CODE_0  25

/*建立一个定义单个LED三原色值大小的结构体*/
typedef struct {
    uint8_t R;
    uint8_t G;
    uint8_t B;
} RGB_Color_TypeDef;

/*Some Static Colors------------------------------*/
const RGB_Color_TypeDef RGB_CONST_RED = {255, 0, 0};   //显示红色RGB数据
const RGB_Color_TypeDef RGB_CONST_GREEN = {0, 255, 0};
const RGB_Color_TypeDef RGB_CONST_BLUE = {0, 0, 255};
const RGB_Color_TypeDef RGB_CONST_SKY = {0, 255, 255};
const RGB_Color_TypeDef RGB_CONST_MAGENTA = {255, 0, 220};
const RGB_Color_TypeDef RGB_CONST_YELLOW = {127, 216, 0};
const RGB_Color_TypeDef RGB_CONST_ORANGE = {127, 106, 0};
const RGB_Color_TypeDef RGB_CONST_BLACK = {0, 0, 0};
const RGB_Color_TypeDef RGB_CONST_WHITE = {255, 255, 255};

void RGB_SetColor(RGB_Color_TypeDef color);


#endif //ST_VFD_WS2812B_H
