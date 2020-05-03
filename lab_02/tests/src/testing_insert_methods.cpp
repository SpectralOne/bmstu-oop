#include "utils.h"

TEST(ListMethodsSuite, InsertFrontData) {
  List<int> l{1, 3};
  ListData<int> ld{0, 4, 1, 3};
  
  ASSERT_NO_THROW(l.insertFront(4));
  ASSERT_NO_THROW(l.insertFront(0));

  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, InsertFrontList) {
  List<int>l1{3, 4};
  List<int>l2{1, 2};
  const ListData<int> ld{1, 2, 3, 4};

  ASSERT_NO_THROW(l1.insertFront(l2));
  ASSERT_EQ(l1, ld);
}

TEST(ListMethodsSuite, InsertFrontNode) {
  List<int> l{1, 3};
  ListData<int> ld{0, 1, 3};
  Shared<ListNode<int>> node = std::make_shared<ListNode<int>>(0);
  
  ASSERT_NO_THROW(l.insertFront(node));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, InsertAfterData) {
  List<int> l{1, 3};
  ListData<int> ld{1, 2, 3};
  Shared<ListNode<int>> node = std::make_shared<ListNode<int>>(1);

  ASSERT_NO_THROW(l.insertAfter(node, 2));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, InsertAfterList) {
  List<int> l{1, 3};
  List<int> ins{1, 2};
  ListData<int> ld{1, 1, 2, 3};
  Shared<ListNode<int>> node = std::make_shared<ListNode<int>>(1);

  ASSERT_NO_THROW(l.insertAfter(node, ins));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, InsertBeforeData) {
  List<int> l{1, 3};
  ListData<int> ld{1, 2, 3};
  Shared<ListNode<int>> node = std::make_shared<ListNode<int>>(3);

  ASSERT_NO_THROW(l.insertBefore(node, 2));
  ASSERT_EQ(l, ld);
}
TEST(ListMethodsSuite, InsertBeforeList) {
  List<int> l{1, 3};
  List<int> ins{1, 2};
  ListData<int> ld{1, 1, 2, 3};
  Shared<ListNode<int>> node = std::make_shared<ListNode<int>>(3);

  ASSERT_NO_THROW(l.insertBefore(node, ins));
  ASSERT_EQ(l, ld);
}
