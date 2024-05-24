/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#include "pedaling_mgt.h"

#include "time_mgt.h"

/**** Defines ****/

#define MAGNET_NBR 12 /// Number of magnets on pedaling sensor (no unit)
#define US_IN_A_MINUTE 60000000.f /// number of microseconds in one minute (us)

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
    float average_pedaling_speed = 0.0;
    /// average_pedaling_speed = 1min / (actualTimestamp - oldestTimestamp)
    average_pedaling_speed = US_IN_A_MINUTE / (magnet_timestamp_array[index] - magnet_timestamp_array[(index + 1) % MAGNET_NBR]);

    return average_pedaling_speed;
}

void new_magnet_cb(void)
{
    index = (index + 1) % MAGNET_NBR;
    magnet_timestamp_array[index] = get_timestamp();
}
