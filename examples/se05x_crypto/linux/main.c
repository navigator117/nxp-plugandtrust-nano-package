/** @file main.c
 *  @brief .
 *
 * Copyright 2021,2022,2024 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

/* ********************** Include files ********************** */
#include <stdio.h>

/* ********************** Extern functions ********************** */
extern int ex_se05x_crypto();

void main(void)
{
    printf("Se05x crypto Example !\n");
    if (ex_se05x_crypto() != 0) {
        printf("SE05x crypto Example Failed !\n");
    }
    else {
        printf("SE05x crypto Example Success ! \n");
    }
    return;
}