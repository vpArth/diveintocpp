#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Collection.hpp"

int sum(int a, int b) { return a + b; }
bool isOdd(int el) { return el % 2 != 0; }

TEST(Collection, reduce) { // NOLINT
  std::vector<int> a{1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
  EXPECT_EQ(55, (Collection::reduce(a, sum, 0)));
  EXPECT_EQ(55, (Collection::reduce(a, sum)));
  EXPECT_EQ(55, (Collection::reduce<int>(a, [](int a, int b) { return a + b; })));
  EXPECT_EQ(55, (Collection::reduce<int>(a, [](int a, int b) { return a + b; }, 0)));
  EXPECT_EQ(55, (Collection::reduce<int, int>(a, [](int a, int b) { return a + b; }, 0)));
}

TEST(Collection, filter) { // NOLINT
  std::vector<int> a{1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
  auto odd = Collection::filter(a, isOdd);
  EXPECT_EQ(5, odd.size());
  EXPECT_EQ(1, odd[0]);
  EXPECT_EQ(3, odd[1]);
  EXPECT_EQ(5, odd[2]);
  EXPECT_EQ(9, odd[3]);
  EXPECT_EQ(7, odd[4]);
}
