/**
 * @file main.cpp
 * @author Viacheslav (slava.k@ks2corp.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright KS2 Copyright (c) 2022
 *
 */
#include <iostream>
#include <string.h>

#include "chunking.h"

int main()
{
    static const uint32_t TEST_DATA_SIZE = 83;
    uint8_t data[327];
    // Init buff
    memset(data, 0xff, sizeof(data));
    reading_by_chunk(0, data, sizeof(data));
    memset(data, 0xff, sizeof(data));
    for (int i = 0; i < 3; i++)
        writing_by_chunk(i * TEST_DATA_SIZE, &data[i * TEST_DATA_SIZE], TEST_DATA_SIZE);
}