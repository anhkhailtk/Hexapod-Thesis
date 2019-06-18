#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#ifndef __OPERATIONMODE_H
#define __OPERATIONMODE_H
#ifdef __cplusplus
 extern "C" {
#endif

#define IDLE										0
#define TESTING 								1
#define HOMESCAN 								2
#define INVERSEKINEMATIC		 		3
#define DEMO								 		4
#define CIRCLE									5
#define RESET										6

#define PI 										3.1416f
extern uint8_t Mode;
extern bool isDemoMode;
extern bool isCircleMode;

extern bool reset_flag;

void CircleMode(void);
void DemoMode(void);
void TestingMode(void);	 
void HomeScanMode(void);
void InverseKinematicMode(bool isInvereKinematicMode);
void IdleMode(void);
#ifdef __cplusplus
}
#endif

#endif 
