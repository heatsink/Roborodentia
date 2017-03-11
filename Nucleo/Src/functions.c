#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "functions.h"

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

extern uint16_t oldDutyCycle;
extern uint16_t newDutyCycle;
extern TIM_HandleTypeDef * motorTimer;


/*
 * Checks for a valid memory allocation before returning allocation
 */
void *checked_malloc(size_t size) {
    void *p = malloc(size);
    if (p == NULL){ 
        //perror("broken allocation\n");
        exit(-1);
    }
    return p;
}

/*
 * Checks for a valid memory reallocation before returning allocation
 */
void *checked_realloc(void *pointer, size_t size) {
    void *p = realloc(pointer, size);
    if (p == NULL){ 
        //perror("broken reallocation\n");
        exit(-1);
    }
    return p;
}

void initLineDataStruct(struct lineData *lineData) {
    for (int i = 0; i < LSENSOR_COUNT; i++) {
        lineData->pName[i] = NULL;
        lineData->status[i] = 0;
        lineData->status[i] = false;
    }
}

void initLineSensor(struct lineData *lineData, 
       GPIO_TypeDef *pName1, uint16_t pNum1,
       GPIO_TypeDef *pName2, uint16_t pNum2,
       GPIO_TypeDef *pName3, uint16_t pNum3,
       GPIO_TypeDef *pName4, uint16_t pNum4,
       GPIO_TypeDef *pName5, uint16_t pNum5,
       GPIO_TypeDef *pName6, uint16_t pNum6,
       GPIO_TypeDef *pName7, uint16_t pNum7,
       GPIO_TypeDef *pName8, uint16_t pNum8
        ) {
    initLineDataStruct(lineData);
    lineData->pName[0] = pName1;
    lineData->pName[1] = pName2;
    lineData->pName[2] = pName3;
    lineData->pName[3] = pName4;
    lineData->pName[4] = pName5;
    lineData->pName[5] = pName6;
    lineData->pName[6] = pName7;
    lineData->pName[7] = pName8;
    lineData->pNum[0] = pNum1;
    lineData->pNum[1] = pNum2;
    lineData->pNum[2] = pNum3;
    lineData->pNum[3] = pNum4;
    lineData->pNum[4] = pNum5;
    lineData->pNum[5] = pNum6;
    lineData->pNum[6] = pNum7;
    lineData->pNum[7] = pNum8;
}

void updateLineData(struct lineData *lineData) {
    for (int i = 0; i < LSENSOR_COUNT; i++) {
        if (HAL_GPIO_ReadPin(lineData->pName[i], (uint16_t) lineData->pNum[i]) == GPIO_PIN_SET) {
            lineData->status[i] = true;
            continue;
        }
        lineData->status[i] = false;
    }
}

int lineOnCount(struct lineData *lineData) {
    int onCount = 0;
    for (int i = 0; i < LSENSOR_COUNT; i++) {
        if (lineData->status[i] == true) {
            onCount++;
        }
    }
    return onCount;
}

void driveForward(uint16_t speed){
//---Example for using Timer 13---------------------------
    // oldDutyCycle = __HAL_TIM_GET_AUTORELOAD(&htim13);         // Gets the Period set for PWm
    // oldDutyCycle = __HAL_TIM_GET_COMPARE(&htim13, TIM_CHANNEL_1); // Get reading for Timer 13
    // oldDutyCycle = TIM13 -> CCR1;                             // Set Capture Compare register directly

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);         // DIR Pin 1 for Motor Driver
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);         // DIR Pin 2 for Motor Driver

    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_1, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_2, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_3, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_4, speed); // Set new Pulse to Channel
}

void driveLeft(uint16_t speed){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
            
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_1, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_2, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_3, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_4, speed); // Set new Pulse to Channel
}

void driveShallow(uint16_t speedL, uint16_t speedR){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
            
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_1, speedL); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_2, speedR); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_3, speedR); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_4, speedL); // Set new Pulse to Channel
}

void driveShallowBack(uint16_t speedL, uint16_t speedR){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
            
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_1, speedR); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_2, speedL); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_3, speedL); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_4, speedR); // Set new Pulse to Channel
}


void driveRight(uint16_t speed){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
            
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_1, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_2, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_3, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_4, speed); // Set new Pulse to Channel
}

void driveBack(uint16_t speed){
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
            
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_1, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_2, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_3, speed); // Set new Pulse to Channel
    __HAL_TIM_SET_COMPARE(motorTimer, TIM_CHANNEL_4, speed); // Set new Pulse to Channel
}
/*
void initialize_ADC(ADC_HandleTypeDef hadc) {
    HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, 100);
}

bool lineDetected(ADC_HandleTypeDef hadc, uint16_t logicLevel) {
    initialize_ADC(hadc);
    //if (HAL_ADC_GetValue(&hadc) > logicLevel) {
    if (HAL_ADC_GetValue(&hadc) < logicLevel) {
        return true;
    }
    return false;
}

void lineFollowerCallback(ADC_HandleTypeDef hadc1, ADC_HandleTypeDef hadc2, uint16_t logicLevel) {
    if (lineDetected(hadc1, LINE_LOGIC_LEVEL) && lineDetected(hadc2, LINE_LOGIC_LEVEL)) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // LED On
        Drive_Forward(DEFAULT_SPEED);
    }
    else if (lineDetected(hadc1, LINE_LOGIC_LEVEL)) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // LED On
        Drive_Left(DEFAULT_SPEED);
    }
    else if (lineDetected(hadc2, LINE_LOGIC_LEVEL)) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // LED On
        Drive_Right(DEFAULT_SPEED);
    }
    else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // LED Off
        Drive_Forward(0);
    }

}
*/
