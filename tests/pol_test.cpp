#include <gtest/gtest.h>
#include "c_nn/Functions.hpp"

TEST(Functions, Identity)
{
    Function f = Pol();
    EXPECT_FLOAT_EQ(f.call(1), 1);
}