//
// Created by 83503 on 2023/2/23.
//

#ifndef ST_VFD_VFD_DISPLAY_H
#define ST_VFD_VFD_DISPLAY_H

#include "main.h"
#include "tim.h"

#define RST_L HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET)
#define RST_H HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET)
#define CS_L HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET)
#define CS_H HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET)
#define CLK_L HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET)
#define CLK_H HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET)
#define DIN_L HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_RESET)
#define DIN_H HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,GPIO_PIN_SET)

#define DELAY_US(t) delay_us(t)

/**
 * 亮度最大和最小值
 */
#define DISPLAY_DUTY_MIN 50
#define DISPLAY_DUTY_MAX 87

/**
 * 显示灯光的开关
 */
#define DISPLAY_OFF 0x71 //关
#define DISPLAY_ON 0x73 //开

/**
 * P1 和 P2输出口的设置地址
 */
#define P1_P2_FB    0x40
#define P1_SET      0x01
#define P1_RESET    0x00
#define P2_SET      0x02
#define P2_RESET    0x00
#define P1_P2_SET   0x03
#define P1_P2_RESET 0x00

/**
 * 重置状态
 * 复位功能
    当RSTB引脚设置为“低”电平时，重置功能启用。所有函数都已初始化。的初始状态
    各种功能如下：
        1.每个RAM的地址：地址“00”H
        2.每个RAM的数据：所有内容均未定义。
        3.通用输出端口：所有通用输出端口均设置为“低”。
        4.显示位数：16位
        5.对比度调整：8/16
        6.所有显示灯：关闭模式
        7.段输出：所有段输出设置为“低”。
        8.AD输出：所有AD输出设置为“低”
 */
void VFD_REST();

/**
 * 清空
 */
void VFD_Clear(int start,int end);

/**
 * 设置亮度
 * @param value
 */
void VFD_SetDisplayLight(uint8_t value);

/**
 * 设置灯光的开关
 * @param value
 */
void VFD_SetDisplayOnOff(uint8_t value);

/**
 * 设置 P1和 P2引脚控制输出高低电平，实现LED指示灯的熄和亮
 * @param value
 */
void VFD_SetGeneralPinState(uint8_t value);

/**
 * 在指定位置显示指定的字符
 * @param index
 * @param character
 */
void VFD_SetCharacter(uint8_t index,char character);

#endif //ST_VFD_VFD_DISPLAY_H
