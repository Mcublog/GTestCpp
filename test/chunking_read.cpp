#include <gtest/gtest.h>

#include "chunking.h"

TEST(chunking, read) {
    static const uint32_t TEST_DATA_SIZE = 83;
    uint8_t data[327];
    // Init buff
    memset(data, 0xff, sizeof(data));
    reading_by_chunk(0, data, sizeof(data));
  // double res;
  // res = add_numbers(1.0, 2.0);
  // ASSERT_NEAR(res, 3.0, 1.0e-11);
}
