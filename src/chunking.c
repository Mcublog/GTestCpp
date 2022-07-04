/**
 * @file chunking.c
 * @author Viacheslav (slava.k@ks2corp.com)
 * @brief
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright KS2 Copyright (c) 2022
 *
 */
#include <string.h>
#include <stdio.h>

#include "chunking.h"

#define MAX_CHUNK_SIZE (100)

/**
 * @brief
 *
 * @param addr
 * @param buff
 * @param size
 */
void reading_by_chunk(uint8_t addr, uint8_t *buff, uint32_t size)
{
    (void)addr;
    uint32_t max_chunks = (size / MAX_CHUNK_SIZE);
    uint32_t remainder = max_chunks ? size % (max_chunks * MAX_CHUNK_SIZE) : 0;
    uint32_t chunk = 0;
    for (chunk; chunk < (size / MAX_CHUNK_SIZE); chunk++)
    {
        memset(&buff[chunk * MAX_CHUNK_SIZE], 0x00, (MAX_CHUNK_SIZE));
    }
    if (remainder)
        memset(&buff[chunk * MAX_CHUNK_SIZE], 0x00, remainder);
}

/**
 * @brief
 *
 * @param addr
 * @param buff
 * @param size
 */
void writing_by_chunk(uint8_t addr, uint8_t *buff, uint32_t size)
{
    int32_t page = (addr / MAX_CHUNK_SIZE);
    int32_t offset = addr % MAX_CHUNK_SIZE;
    int32_t remainder = (offset + size) - MAX_CHUNK_SIZE;
    if (remainder < 0)
        remainder = 0;

    printf("addr: %d size: %d => page: %d ofst: %d remainder: %d\r\n", addr, size, page, offset, remainder);
    if (remainder)
    {
        printf("write to: page %d size: %d ofst: %d\r\n", page, size - remainder, offset);
        page++;
        offset = 0;
    }
    else
        remainder = size;
    printf("write to: page %d size: %d ofst: %d\r\n", page, remainder, offset);
}