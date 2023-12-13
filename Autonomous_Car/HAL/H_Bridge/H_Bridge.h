/*
 * H_Bridge.h
 *
 *  Created on: Dec 9, 2023
 *      Author: Mohamed
 */

#ifndef HAL_H_BRIDGE_H_BRIDGE_H_
#define HAL_H_BRIDGE_H_BRIDGE_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/Timer 1/Timer1.h"

void HAL_void_H_BridgeInit();
void HAL_void_H_BridgeCW(u8);
void HAL_void_H_BridgeCCW(u8);
void HAL_void_H_BridgeStop(u8);
void HAL_void_H_BridgeFront(u8);
void HAL_void_H_BridgeBack(u8);

#endif /* HAL_H_BRIDGE_H_BRIDGE_H_ */
