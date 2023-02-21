//
// Created by 83503 on 2023/2/21.
//
#include "index.h"
#include "main.h"
#include "ws2812b.h"

void Run_Service(void) {
    HAL_Delay(1000);
    RGB_SetColor(RGB_CONST_RED);
    HAL_Delay(1000);
    RGB_SetColor(RGB_CONST_BLACK);
    HAL_Delay(1000);
    RGB_SetColor(RGB_CONST_ORANGE);
    HAL_Delay(1000);
    RGB_SetColor(RGB_CONST_WHITE);
    HAL_Delay(1000);
    RGB_SetColor(RGB_CONST_YELLOW);
    HAL_Delay(1000);
}

void Error_Service_Handler(void) {
    printf("--->>ERROR\n");
    HAL_Delay(1000);
}