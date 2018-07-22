#include "gtest/gtest.h"
#include "gmock/gmock.h"


#include "A.h"

TEST(A, twice) // NOLINT
{
  A a;
  EXPECT_EQ(12, a.twice(6));
  EXPECT_EQ(-12, a.twice(-6));
}
