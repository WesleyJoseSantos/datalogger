/**
 * @file message.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MESSAGE__H__
#define __MESSAGE__H__

#include "time.h"
#include "packet.h"

/**
 * @brief Message
 */
typedef struct message
{
    time_t timestamp;       ///!< Timestamp of message
    uint16_t sensor_id;     ///!< Id of sensor that sended the message
    packet_t packet;        ///!< Message packet
} message_t;

#endif  //!__MESSAGE__H__