/**
 * @file messages_mocks.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MESSAGES_MOCKS__H__
#define __MESSAGES_MOCKS__H__

#define MESSAGE1_MOCK() {                                                                                                       \
    .sensor_id = 0,                                                                                                             \
    .packet = {                                                                                                                 \
        .as_double = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 0.10, 0.11, 0.12, 0.13, 0.14, 0.15 }                   \
    }                                                                                                                           \
}

#define MESSAGE2_MOCK() {                                                                                                       \
    .sensor_id = 1,                                                                                                             \
    .packet = {                                                                                                                 \
        .as_double = { 0.17, 0.18, 0.19, 0.20, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.30, 0.31, 0.32 }         \
    }                                                                                                                           \
}

#endif  //!__MESSAGES_MOCKS__H__