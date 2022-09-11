/**
 * @file sensors_mocks.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __SENSORS_MOCKS__H__
#define __SENSORS_MOCKS__H__

#define SENSOR0_MOCK()           \
{                                \
    .id = 0,                     \
    .sample_rate = 500,          \
    .datatype = DATATYPE_DOUBLE, \
}

#define SENSOR1_MOCK()           \
{                                \
    .id = 1,                     \
    .sample_rate = 1000,         \
    .datatype = DATATYPE_DOUBLE, \
}

#endif //!__SENSORS_MOCKS__H__