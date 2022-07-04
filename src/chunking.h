
#ifndef CHUNKING_H
#define CHUNKING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void reading_by_chunk(uint8_t addr, uint8_t *buff, uint32_t size);

void writing_by_chunk(uint8_t addr, uint8_t *buff, uint32_t size);


#ifdef __cplusplus
}
#endif

#endif // CHUNKING_H