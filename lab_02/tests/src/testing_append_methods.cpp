#include "utils.h"

TEST(ListMethodsSuite, Append) {
  flexlist::List<int> l;
  const ListData<int> ld{3};

  ASSERT_NO_THROW(l.append(3));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, AppendNode) {
  flexlist::List<int> l;
  const ListData<int> ld{3};

  Shared<flexlist::ListNode<int>> node = std::make_shared<flexlist::ListNode<int>>(3);

  ASSERT_NO_THROW(l.append(node));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, AppendList) {
  flexlist::List<int> l1{0, 1};
  flexlist::List<int> l2{3, 4};
  const ListData<int> ld{0, 1, 3, 4};

  ASSERT_NO_THROW(l1.append(l2));
  ASSERT_EQ(l1, ld);
}