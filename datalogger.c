/**
 * @file datalogger.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "datalogger.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

datalogger_t this;

uint16_t datalogger_init(void)
{
    char dat_filename[32];
    struct stat st = {0};

    if (stat(DATALOGGER_DIR, &st) == -1)
    {
        mkdir(DATALOGGER_DIR, 0700);
    }

    this.files.cfg.ptr = fopen(DATALOGGER_CFG_FILE, "a+");
    this.files.sensors.ptr = fopen(DATALOGGER_SENSORS_FILE, "a+");

    if (this.files.cfg.ptr != NULL)
    {
        fread(
            &this.files.cfg.data,
            sizeof(this.files.cfg.data),
            1,
            this.files.cfg.ptr);
        fclose(this.files.cfg.ptr);
    }
    else
    {
        printf("Error on open datalogger cfg file\n");
        return DATALOGGER_ERR_OPEN_CFG_FILE;
    }

    if (this.files.sensors.ptr != NULL)
    {
        fread(
            &this.files.sensors.data.count,
            sizeof(this.files.sensors.data.count),
            1,
            this.files.sensors.ptr);
        fclose(this.files.sensors.ptr);
    }
    else
    {
        printf("Error on open sensors file\n");
        return DATALOGGER_ERR_OPEN_SENSORS_FILE;
    }

    sprintf(dat_filename, DATALOGGER_DATA_FILE, this.files.cfg.data.file_id);
    this.files.dat.ptr = fopen(dat_filename, "a+");
    fseek(this.files.dat.ptr, 0, SEEK_END);
    this.files.dat.size = ftell(this.files.dat.ptr);

    return DATALOGGER_ERR_OK;
}

uint16_t datalogger_add_sensor(sensor_cfg_t *sensor)
{
    this.files.sensors.ptr = fopen(DATALOGGER_SENSORS_FILE, "rb+");

    sensor->id = this.files.sensors.data.count;
    this.files.sensors.data.count++;

    if (this.files.sensors.ptr == NULL)
    {
        printf("Error on open sensors file\n");
        return DATALOGGER_ERR_OPEN_SENSORS_FILE;
    }

    fwrite(
        &this.files.sensors.data.count,
        sizeof(this.files.sensors.data.count),
        1,
        this.files.sensors.ptr
    );
    fseek(this.files.sensors.ptr, 0, SEEK_END);
    fwrite(
        sensor,
        sizeof(*sensor),
        1,
        this.files.sensors.ptr
    );
    fclose(this.files.sensors.ptr);

    return DATALOGGER_ERR_OK;
}

uint16_t datalogger_add_message(message_t *message)
{
    this.files.dat.size += fwrite(
        message,
        sizeof(*message),
        1,
        this.files.dat.ptr
    ) * sizeof(*message);

    if (this.files.dat.size >= DATALOGGER_FILE_MAX_SIZE)
    {
        char dat_filename[32];
        this.files.cfg.data.file_id++;
        sprintf(dat_filename, DATALOGGER_DATA_FILE, this.files.cfg.data.file_id);

        fclose(this.files.dat.ptr);
        this.files.dat.ptr = fopen(dat_filename, "a+");
        this.files.dat.size = ftell(this.files.dat.ptr);
    }

    return this.files.dat.size;
}

void datalogger_stop(void)
{
    fclose(this.files.dat.ptr);
}

void datalogger_resume(void)
{
    char dat_filename[32];
    sprintf(dat_filename, DATALOGGER_DATA_FILE, this.files.cfg.data.file_id);
    this.files.dat.ptr = fopen(dat_filename, "a+");
}