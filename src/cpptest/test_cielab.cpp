#include <gtest/gtest.h>
#include <cielab.h>
#include <vector>

TEST(CIELABTest, rgb_to_cielab) {
    const uint8_t rgb[] {
        139, 91, 30,
        111, 197, 143,
        255, 255, 255,
        255, 255, 0,
        255, 0, 255,
        0, 255, 255,
        30, 57, 184,
    };
    simd_helper::AlignedArray<uint8_t> lab(1, 7 * 4);
    int shift = 0;
    rgb_to_cielab(rgb, 1, 7, lab, shift);

    EXPECT_EQ(shift, output_shift);
    const uint8_t expected[][3] {
        {85, 156, 210},
        {146, 51, 166},
        {200, 128, 128},
        {194, 84, 255},
        {120, 255, 6},
        {182, 31, 99},
        {61, 204, 0},
    };
    for (int i = 0; i < 7; ++i) {
        EXPECT_EQ(lab.get(0, 4 * i), expected[i][0]);
        EXPECT_EQ(lab.get(0, 4 * i + 1), expected[i][1]);
        EXPECT_EQ(lab.get(0, 4 * i + 2), expected[i][2]);
    }
}
