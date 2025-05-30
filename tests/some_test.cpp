#include <gtest/gtest.h>
#include "../types.h"
#include "../pagesim.h"
#include "../address_splitting.h"
#include "../tests.h"

// Copy actual variables over from pagesim.c since they are declared in pagesim.h
uint8_t *mem;                // start of our simulated memory
uint8_t replacement = 0;     // page replacment policy
pfn_t last_evicted = 0;      // last evicted page frame

TEST(testsim, blank_test)
{
  GTEST_ASSERT_TRUE(1);
}

TEST(testsim, get_vaddr_vpn)
{
  GTEST_ASSERT_EQ(0xFF, get_vaddr_vpn((vaddr_t)((0xFF<<OFFSET_LEN) + 0x2032)));
}

TEST(testsim, get_vaddr_offset)
{
  GTEST_ASSERT_EQ(0x2032, get_vaddr_offset((vaddr_t)((0xFF<<OFFSET_LEN) + 0x2032)));
}

TEST(provided_tests, test_get_vaddr_vpn)
{
  try
  {
    test_get_vaddr_vpn();    
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    GTEST_ASSERT_TRUE(0);
  }
  
  GTEST_ASSERT_TRUE(1);
}

int main(int argc, char* argv[]) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}