/**
 * @file datalogger_config.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __DATALOGGER_CONFIG__H__
#define __DATALOGGER_CONFIG__H__

#ifndef DATALOGGER_CUSTOM_CONFIG

#define DATALOGGER_DIR "data"                                 ///!< Directory of datalogger files
#define DATALOGGER_CFG_FILE DATALOGGER_DIR "/cfg.dat"         ///!< Datalogger configuration file
#define DATALOGGER_SENSORS_FILE DATALOGGER_DIR "/sensors.dat" ///!< Datalogger sensors file
#define DATALOGGER_DATA_FILE DATALOGGER_DIR "/dat%d.dat"      ///!< Datalogger data file
#define DATALOGGER_DATA0_FILE DATALOGGER_DIR "/dat0.dat"      ///!< First data file created by datalogger
#define DATALOGGER_FILE_MAX_SIZE 8192                         ///!< Datalogger file max file

#endif

#endif //!__DATALOGGER_CONFIG__H__