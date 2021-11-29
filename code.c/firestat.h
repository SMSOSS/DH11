/*
 * Copyright (c) 2021 rain2wood@SMSOSS
 *
 * File name: firestat.h
 *
 * Licensed under WTFPL
 *
 * Description: Header used for storing global value that will be used for the project "noFire"
 */

#ifndef _NOFIRE_FIRESTAT_H
#define _NOFIRE_FIRESTAT_H

#include <stdio.h>
#include <stdlib.h>

/* PIN definitions and debugMode */
#define dht_apin 11
#define flamePin 2
#define debugMode 0

/* external int defs */
extern int isFire;
extern int temp;
extern int flame;

#endif /*_NOFIRE_FIRESTAT_H*/
