/*
 * Macros.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Mohamed
 */

#ifndef COMMONS_MACROS_H_
#define COMMONS_MACROS_H_

#define GET_BIT(REG,BIT) ((REG>>BIT)&1)
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)

enum {
	E_OK, E_NOT_OK
};


#endif /* COMMONS_MACROS_H_ */
