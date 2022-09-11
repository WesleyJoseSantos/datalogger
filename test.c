/**
 * @file tests_datalogger.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Unity/src/unity.h"
#include "mocks/sensors_mocks.h"
#include "mocks/messages_mocks.h"
#include "datalogger.h"

#define DATALOGGER_DATA1_FILE DATALOGGER_DIR "/dat1.dat"

void setUp(void) {}

void tearDown(void) {}

static void datalogger_init_should_create_files(void)
{
    struct stat st = {0};

    if (stat(DATALOGGER_DIR, &st) != -1)
    {
        remove(DATALOGGER_CFG_FILE);
        remove(DATALOGGER_DATA0_FILE);
        remove(DATALOGGER_DATA1_FILE);
        remove(DATALOGGER_SENSORS_FILE);
        rmdir(DATALOGGER_DIR);
    }

    datalogger_init();
    TEST_ASSERT_NOT_EQUAL(fopen(DATALOGGER_CFG_FILE, "r"), NULL);
    TEST_ASSERT_NOT_EQUAL(fopen(DATALOGGER_DATA0_FILE, "r"), NULL);
    TEST_ASSERT_NOT_EQUAL(fopen(DATALOGGER_SENSORS_FILE, "r"), NULL);
}

static void datalogger_add_sensor_should_add_sensor_to_file(void)
{
    sensor_cfg_t sensor0_mock = SENSOR0_MOCK();
    sensor_cfg_t sensor1_mock = SENSOR1_MOCK();

    datalogger_add_sensor(&sensor0_mock);
    datalogger_add_sensor(&sensor1_mock);

    FILE *sensors_file = fopen(DATALOGGER_SENSORS_FILE, "r");
    uint16_t sensors_count;
    sensor_cfg_t sensors[2];

    TEST_ASSERT_NOT_EQUAL(sensors_file, NULL);

    fread(&sensors_count, sizeof(sensors_count), 1, sensors_file);
    fread(&sensors, sizeof(sensor_cfg_t), sensors_count, sensors_file);
    fclose(sensors_file);

    TEST_ASSERT_EQUAL(2, sensors_count);
    TEST_ASSERT_EQUAL_MEMORY(&sensor0_mock, &sensors[0], sizeof(sensor_cfg_t));
    TEST_ASSERT_EQUAL_MEMORY(&sensor1_mock, &sensors[1], sizeof(sensor_cfg_t));
}

static void datalogger_add_message_should_add_message_to_file(void)
{
    message_t message1 = MESSAGE1_MOCK();
    message_t message2 = MESSAGE2_MOCK();
    message_t messages[2];

    datalogger_add_message(&message1);
    datalogger_add_message(&message2);
    datalogger_stop();

    FILE *data_file = fopen(DATALOGGER_DATA0_FILE, "r");

    TEST_ASSERT_NOT_EQUAL(data_file, NULL);

    fread(&messages, sizeof(message_t), 2, data_file);
    fclose(data_file);

    TEST_ASSERT_EQUAL_MEMORY(&message1, &messages[0], sizeof(message_t));
    TEST_ASSERT_EQUAL_MEMORY(&message2, &messages[1], sizeof(message_t));
}

static void datalogger_add_message_should_create_new_file_if_size_higher_than_limit(void)
{
    size_t current_size = sizeof(message_t) * 2;
    message_t message = MESSAGE1_MOCK();
    message_t message_read;

    datalogger_resume();

    while (current_size < DATALOGGER_FILE_MAX_SIZE)
    {
        current_size += sizeof(message_t);
        datalogger_add_message(&message);
    }

    datalogger_add_message(&message);
    datalogger_stop();

    FILE *data1_file = fopen(DATALOGGER_DATA1_FILE, "r");
    TEST_ASSERT_NOT_EQUAL(data1_file, NULL);

    fread(&message_read, sizeof(message_t), 1, data1_file);
    TEST_ASSERT_EQUAL_MEMORY(&message, &message_read, sizeof(message_t));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(datalogger_init_should_create_files);
    RUN_TEST(datalogger_add_sensor_should_add_sensor_to_file);
    RUN_TEST(datalogger_add_message_should_add_message_to_file);
    RUN_TEST(datalogger_add_message_should_create_new_file_if_size_higher_than_limit);

    return UNITY_END();
}
