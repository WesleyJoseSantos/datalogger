/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "datalogger.h"

sensor_cfg_t sensor1 = {
    .datatype = DATATYPE_DOUBLE,
    .sample_rate = 100
};

message_t message1 = {
    .sensor_id = 0,
    .packet = {
        .as_double = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15 }
    }
};

message_t message2 = {
    .sensor_id = 1,
    .packet = {
        .as_double = { 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.30, 0.31, 0.32 }
    }
};

message_t message3 = {
    .sensor_id = 2,
    .packet = {
        .as_double = { 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.40, 0.41, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47, 0.48 }
    }
};

int main(void)
{
    datalogger_init();
    datalogger_add_sensor(&sensor1);

    message1.timestamp = time(NULL);
    datalogger_add_message(&message1);

    message2.timestamp = time(NULL);
    datalogger_add_message(&message2);

    message3.timestamp = time(NULL);
    datalogger_add_message(&message3);
    return 0;
}