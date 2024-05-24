/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#include "pedaling_mgt.h"

#include "time_mgt.h"

/**** Defines ****/

#define MAGNET_NBR 12 /// Number of magnets on pedaling sensor (no unit)

/**** Private variables ****/

static uint8_t index = 0;
static uint32_t magnet_timestamp_array[MAGNET_NBR] = {0};

/**** Public API ****/

float get_pedaling_speed(void)
{
    // WRITE YOUR CODE HERE
    return 0.f;
}

float get_average_pedaling_speed(void)
{
    // WRITE YOUR CODE HERE
    return 0.f;
}

void new_magnet_cb(void)
{
    index = (index + 1) % MAGNET_NBR;
    magnet_timestamp_array[index] = get_timestamp();
}
