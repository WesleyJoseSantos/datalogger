/**
 * @file datatype.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DATATYPE__H__
#define __DATATYPE__H__

/**
 * @brief Type of data
 *
 */
typedef enum datatype
{
    DATATYPE_U8,     //!< uint8_t data type
    DATATYPE_U16,    //!< uint16_t data type
    DATATYPE_U32,    //!< uint32_t data type
    DATATYPE_U64,    //!< uint64_t data type
    DATATYPE_I8,     //!< int8_t data type
    DATATYPE_I16,    //!< int16_t data type
    DATATYPE_I32,    //!< int32_t data type
    DATATYPE_I64,    //!< int64_t data type
    DATATYPE_FLOAT,  //!< float data type
    DATATYPE_DOUBLE, //!< double data type
} datatype_t;

#endif  //!__DATATYPE__H__