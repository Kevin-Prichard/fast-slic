#include <gtest/gtest.h>
#include <cca.h>

TEST(ConnectivityEnforcer, preserves_connected_regions) {
    cca::label_no_t labels[] {
        1, 1, 2,
        1, 3, 2,
    };

    cca::ConnectivityEnforcer enforcer(labels, 2, 3, 10, 0);
    enforcer.execute(labels);

    EXPECT_EQ(labels[0], 0);
    EXPECT_EQ(labels[1], 0);
    EXPECT_EQ(labels[2], 1);
    EXPECT_EQ(labels[3], 0);
    EXPECT_EQ(labels[4], 2);
    EXPECT_EQ(labels[5], 1);
}
