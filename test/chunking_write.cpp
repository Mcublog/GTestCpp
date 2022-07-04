#include <gtest/gtest.h>

#include "chunking.h"

TEST(chunking, write) {
    static const uint32_t TEST_DATA_SIZE = 83;
    uint8_t data[327];
    // Init buff
    memset(data, 0xff, sizeof(data));
    for (int i = 0; i < 3; i++)
        writing_by_chunk(i * TEST_DATA_SIZE, &data[i * TEST_DATA_SIZE], TEST_DATA_SIZE);
  // double res;
  // res = subtract_numbers(1.0, 2.0);
  // ASSERT_NEAR(res, -1.0, 1.0e-11);
}
