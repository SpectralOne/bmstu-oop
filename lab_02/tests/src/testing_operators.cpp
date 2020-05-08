#include "utils.h"

TEST(ListOperatorsSuite, EqualityInequality) {
  flexlist::List<int> l1{1, 2, 3, 4};
  flexlist::List<int> l2{1, 2, 3, 4};
  flexlist::List<int> l3{1, 1, 1, 1};

  ASSERT_TRUE(l1 == l2);
  ASSERT_FALSE(l2 == l3);
  ASSERT_TRUE(l2 != l3);
  ASSERT_FALSE(l1 != l2);
}

TEST(ListOperatorsSuite, PlusOperators) {
  flexlist::List<int> l1{1, 2, 3};
  ListData<int> ld1{1, 2, 3, 4};

  ASSERT_NO_THROW(l1 += 4);
  ASSERT_EQ(l1, ld1);

  flexlist::List<int> l2{1, 2, 3, 4};
  flexlist::List<int> l3{1, 1};
  ListData<int> ld2{1, 2, 3, 4, 1, 1};

  ASSERT_NO_THROW(l2 += l3);
  ASSERT_EQ(l2, ld2);
}

TEST(IteratorsOperatorsSuite, AccessibilityOperators) {
  flexlist::List<int> l{1, 2, 3};
  flexlist::Iterator<int> it(l);

  ASSERT_NO_THROW(*it);
  ASSERT_EQ(*it, 1);
}

TEST(IteratorsOperatorsSuite, PlusOperators) {
  flexlist::List<int> l{1, 2, 3};
  flexlist::Iterator<int> it(l);

  ASSERT_NO_THROW(it += 1);
  ASSERT_EQ(*it, 2);
}
