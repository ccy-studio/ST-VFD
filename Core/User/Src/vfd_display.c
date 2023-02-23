//
// Created by 83503 on 2023/2/23.
//
#include "vfd_display.h"

/**
 * 数据写入 八位
 * @param w_data
 */
void write_6302(unsigned char w_data) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        CLK_L;
        if ((w_data & 0x01) == 0x01) {
            DIN_H;
        } else {
            DIN_L;
        }
        w_data >>= 1;
        DELAY_US(2);
        CLK_H;
        DELAY_US(2);
    }
}

/**
 * 重置为初始化
 */
void VFD_REST() {
    RST_L;
    HAL_Delay(300);
    RST_H;
}


void VFD_SetCharacter(uint8_t index, char character) {
    CS_L;
    DELAY_US(2);
    //起始点位数
    write_6302(0x10 + index);
    DELAY_US(2);
    write_6302(character);
    CS_H;
}

/**
 * 清空显示内容
 */
void VFD_Clear(int start, int end) {
    CS_L;
    DELAY_US(2);
    for (int i = start; i <= end; i++) {
        write_6302(0x10 + i);
        DELAY_US(2);
        write_6302(0x00);
    }
    CS_H;
}

/**
 * 设置亮度
 * @param value
 */
void VFD_SetDisplayLight(uint8_t value) {
    //检查边界值
    if (value > DISPLAY_DUTY_MAX) {
        value = DISPLAY_DUTY_MAX;
    } else if (value < DISPLAY_DUTY_MIN) {
        value = DISPLAY_DUTY_MIN;
    }
    CS_L;
    DELAY_US(2);
    write_6302(value);
    CS_H;
}

/**
 * 设置灯光的开关
 * @param value
 */
void VFD_SetDisplayOnOff(uint8_t value) {
    CS_L;
    DELAY_US(2);
    write_6302(value);
    CS_H;
}

/**
 * 设置 P1和 P2引脚控制输出高低电平，实现LED指示灯的熄和亮
 * @param value
 */
void VFD_SetGeneralPinState(uint8_t value){
    CS_L;
    DELAY_US(2);
    write_6302(value);
    CS_H;
}