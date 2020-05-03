#include "utils.h"

TEST(ListOperatorsSuite, EqualityInequality) {
  List<int> l1{1, 2, 3, 4};
  List<int> l2{1, 2, 3, 4};
  List<int> l3{1, 1, 1, 1};

  ASSERT_TRUE(l1 == l2);
  ASSERT_FALSE(l2 == l3);
  ASSERT_TRUE(l2 != l3);
  ASSERT_FALSE(l1 != l2);
}

TEST(ListOperatorsSuite, PlusOperators) {
  List<int> l1{1, 2, 3};
  ListData<int> ld1{1, 2, 3, 4};

  ASSERT_NO_THROW(l1 += 4);
  ASSERT_EQ(l1, ld1);

  List<int> l2{1, 2, 3, 4};
  List<int> l3{1, 1};
  ListData<int> ld2{1, 2, 3, 4, 1, 1};

  ASSERT_NO_THROW(l2 += l3);
  ASSERT_EQ(l2, ld2);

  List<int> l4{1, 2, 3, 4};
  ListData<int> ld4{1, 2, 3, 4, 5};
  Shared<ListNode<int>> node = std::make_shared<ListNode<int>>(5);

  ASSERT_NO_THROW(l4 += node);
  ASSERT_EQ(l4, ld4);
}

TEST(ListOperatorsSuite, AccessibilityBracketOperator) {
  const List<int> l1{1, 2, 3};
  ASSERT_NO_THROW(l1[1]);
  ASSERT_EQ(l1[1], 2);

  const List<int> l2{1, 2, 3, 4};
  ASSERT_THROW(l2[100], ListOutOfBounds);

  const List<int> l3;
  ASSERT_THROW(l3[0], EmptyList);
}

TEST(ListOperatorsSuite, AssignBracketOperator) {
  List<int> l1{1, 2, 3};
  const ListData<int> ld{1, 1, 3};

  ASSERT_NO_THROW(l1[1] = 1);
  ASSERT_EQ(l1, ld);
}