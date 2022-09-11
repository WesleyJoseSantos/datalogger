/**
 * @file datalogger.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __DATALOGGER__H__
#define __DATALOGGER__H__

#include <stdio.h>
#include <inttypes.h>
#include "datalogger_config.h"
#include "datatype.h"
#include "message.h"

/**
 * @brief Datalogger err codes
 *
 */
typedef enum datalogger_err
{
    DATALOGGER_ERR_OK,                ///!< No error
    DATALOGGER_ERR_OPEN_CFG_FILE,     ///!< Error on open datalogger cfg file
    DATALOGGER_ERR_OPEN_SENSORS_FILE, ///!< Error on open sensors file
    DATALOGGER_ERR_OPEN_DAT_FILE,     ///!< Error on open dat file
} datalogger_err_t;

/**
 * @brief Sensor configuration
 *
 */
typedef struct sensor_cfg
{
    uint16_t id;          ///!< Sensor id
    uint16_t sample_rate; ///!< Aquisition sample rate
    datatype_t datatype;  ///!< Data type
} sensor_cfg_t;

/**
 * @brief Datalogger sensors list
 *
 */
typedef struct datalogger_sensors_list
{
    uint16_t count;    ///!< Datalogger sensors count
    sensor_cfg_t *cfg; ///!< Datalogger sensors configuration list
} datalogger_sensors_list_t;

/**
 * @brief Datalogger configuration
 *
 */
typedef struct datalogger_cfg
{
    uint8_t packet_size; ///!< Datalogger packet size
    uint32_t file_id;    ///!< Id of current datalogger file
} datalogger_cfg_t;

/**
 * @brief Datalogger file handle
 *
 */
typedef struct datalogger_dat_file
{
    FILE *ptr;     ///!< File pointer
    uint16_t size; ///!< File size
} datalogger_dat_file_t;

/**
 * @brief Datalogger sensors files
 *
 */
typedef struct datalogger_sensors_file
{
    FILE *ptr;                      ///!< File pointer
    datalogger_sensors_list_t data; ///!< File data
} datalogger_sensors_file_t;

/**
 * @brief Datalogger configuration file
 *
 */
typedef struct datalogger_cfg_file
{
    FILE *ptr;             ///!< File pointer
    datalogger_cfg_t data; ///!< File data
} datalogger_cfg_file_t;

/**
 * @brief Datalogger files
 *
 */
typedef struct datalogger_files
{
    datalogger_dat_file_t dat;         ///!< File with logged data
    datalogger_sensors_file_t sensors; ///!< File with sensors configurations
    datalogger_cfg_file_t cfg;         ///!< File with datalogger configration
} datalogger_files_t;

/**
 * @brief Datalogger
 *
 */
typedef struct datalogger
{
    datalogger_files_t files; ///!< Datalogger files
} datalogger_t;

/**
 * @brief Initialize datalogger
 *
 * @return datalogger_err err code
 */
uint16_t datalogger_init(void);

/**
 * @brief Add sensor to datalogger configuration
 *
 * @note Datalogger will add sensor to sensors list, and give an id to sensor.
 *
 * @param sensor Sensor to be added. Datalogger will update sensor id field.
 * @return datalogger_err err code
 */
uint16_t datalogger_add_sensor(sensor_cfg_t *sensor);

/**
 * @brief Add message to datalogger
 *
 * @param message Message to be added
 * @return uint16_t file size
 */
uint16_t datalogger_add_message(message_t *message);

/**
 * @brief Stop datalogger and close current datalogger file
 * 
 */
void datalogger_stop(void);

/**
 * @brief Resume datalogger after datalogger stop call
 * 
 */
void datalogger_resume(void);

#endif //!__DATALOGGER__H__