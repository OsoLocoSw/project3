#include <gtest/gtest.h>
#include "../pagesim.h"

uint8_t replacement = 0;     // page replacment policy

TEST(testsim, blank_test)
{
  GTEST_ASSERT_TRUE(1);
}

int main(int argc, char* argv[]) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}