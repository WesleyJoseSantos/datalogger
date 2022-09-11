/**
 * @file packet.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __PACKET__H__
#define __PACKET__H__

#include <inttypes.h>

#define PACKET_SIZE_IN_BYTES 128                        ///!< Total packet size in bytes
#define PACKET_U8_SIZE PACKET_SIZE_IN_BYTES             ///!< Size of packet as uint8_t array
#define PACKET_U16_SIZE (PACKET_SIZE_IN_BYTES / 2)      ///!< Size of packet as uint16_t array
#define PACKET_U32_SIZE (PACKET_SIZE_IN_BYTES / 4)      ///!< Size of packet as uint32_t array
#define PACKET_U64_SIZE (PACKET_SIZE_IN_BYTES / 8)      ///!< Size of packet as uint64_t array
#define PACKET_I8_SIZE PACKET_SIZE_IN_BYTES             ///!< Size of packet as int8_t array
#define PACKET_I16_SIZE (PACKET_SIZE_IN_BYTES / 2)      ///!< Size of packet as int16_t array
#define PACKET_I32_SIZE (PACKET_SIZE_IN_BYTES / 4)      ///!< Size of packet as int32_t array
#define PACKET_I64_SIZE (PACKET_SIZE_IN_BYTES / 8)      ///!< Size of packet as int64_t array
#define PACKET_FLOAT_SIZE (PACKET_SIZE_IN_BYTES / 4)    ///!< Size of packet as float array
#define PACKET_DOUBLE_SIZE (PACKET_SIZE_IN_BYTES / 8)   ///!< Size of packet as double array

/**
 * @brief Packet of data
 * 
 */
typedef union packet
{
    uint8_t as_uint8[PACKET_U8_SIZE];       ///!< Invoke packet as uint8_t array
    uint16_t as_uint16[PACKET_U16_SIZE];    ///!< Invoke packet as uint16_t array
    uint32_t as_uint32[PACKET_U32_SIZE];    ///!< Invoke packet as uint32_t array
    uint64_t as_uint64[PACKET_U64_SIZE];    ///!< Invoke packet as uint64_t array
    int8_t as_int8[PACKET_I8_SIZE];         ///!< Invoke packet as int8_t array
    int16_t as_int16[PACKET_I16_SIZE];      ///!< Invoke packet as int16_t array
    int32_t as_int32[PACKET_I32_SIZE];      ///!< Invoke packet as int32_t array
    int64_t as_int64[PACKET_I64_SIZE];      ///!< Invoke packet as int64_t array
    float as_float[PACKET_FLOAT_SIZE];      ///!< Invoke packet as float array
    double as_double[PACKET_DOUBLE_SIZE];   ///!< Invoke packet as double array
} packet_t;

#endif  //!__PACKET__H__