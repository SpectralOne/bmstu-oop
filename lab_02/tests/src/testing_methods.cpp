#include "utils.h"

TEST(ListMethodsSuite, IsEmpty) {
  List<int> l;
  ASSERT_TRUE(l.isEmpty());

  List<int> l2{1, 2, 3};
  ASSERT_FALSE(l2.isEmpty());
}

TEST(ListMethodsSuite, Length) {
  List<int> l{1, 2};
  ASSERT_EQ(l.length(), 2);
}

TEST(ListMethodsSuite, Size) {
  List<int> l{1, 2};
  const size_t sz = 2 * sizeof(ListNode<int>);
  ASSERT_EQ(l.size(), sz);
}

TEST(ListMethodsSuite, UniqueNoThrow) {
  List<int> l{1, 2, 1, 1};
  ListData<int> ld{1, 2};
  
  ASSERT_NO_THROW(l.unique());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, UniqueEmptyList) {
  List<int> l;
  ASSERT_THROW(l.unique(), EmptyList);
}

TEST(ListMethodsSuite, UniqueNotEnoughNodes) {
  List<int> l{1};
  ASSERT_THROW(l.unique(), NotEnoughNodes);
}

TEST(ListMethodsSuite, Clear) {
  List<int> l{1, 3};
  const ListData<int> ld{0, 0};

  ASSERT_NO_THROW(l.clear());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, Flush) {
  List<int> l{1, 3};
  ASSERT_NO_THROW(l.flush());

  ASSERT_TRUE(l.isEmpty());
}

TEST(ListMethodsSuite, FlushEmptyList) {
  List<int> l;
  ASSERT_THROW(l.flush(), EmptyList);
}

TEST(ListMethodsSuite, AscendingSort) {
  List<int> l{4, 3, 2, 1};
  const ListData<int> ld{1, 2, 3, 4};

  ASSERT_NO_THROW(l.sort());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, DescendingSort) {
  List<int> l{1, 2, 3};
  const ListData<int> ld{3, 2, 1};

  ASSERT_NO_THROW(l.sort(false));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, EmptyListSort) {
  List<int> l;
  ASSERT_THROW(l.sort(), EmptyList);
}

TEST(ListMethodsSuite, OneNodeSort) {
  List<int> l{1};
  ASSERT_THROW(l.sort(), NotEnoughNodes);
}

TEST(ListMethodsSuite, ListReverse) {
  List<int> l{1, 2, 3, 4};
  const ListData<int> ld{4, 3, 2, 1};

  ASSERT_NO_THROW(l.reverse());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, AppendNode) {
  List<int> l;
  const ListData<int> ld{3};

  ASSERT_NO_THROW(l.append(3));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, AppendList) {
  List<int> l1{0, 1};
  List<int> l2{3, 4};
  const ListData<int> ld{0, 1, 3, 4};

  ASSERT_NO_THROW(l1.append(l2));
  ASSERT_EQ(l1, ld);
}

TEST(ListMethodsSuite, PopBackArg) {
  List<int> l{1, 2, 3};
  ListData<int> ld{1, 2};
  int arg;

  ASSERT_NO_THROW(arg = l.popBackArg());
  ASSERT_EQ(arg, 3);
  ASSERT_EQ(l.length(), 2);
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopBackArgThrow) {
  List<int> l;
  ASSERT_THROW(l.popBackArg(), EmptyList);
}

TEST(ListMethodsSuite, PopBack) {
  List<int> l{1, 2, 3};
  ListData<int> ld{1, 2};

  ASSERT_NO_THROW(l.popBack());
  ASSERT_EQ(l.length(), 2);
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopBackThrow) {
  List<int> l;
  ASSERT_THROW(l.popBack(), EmptyList);
}

TEST(ListMethodsSuite, PopFrontArgThrow) {
  List<int> l;
  ASSERT_THROW(l.popFrontArg(), EmptyList);
}

TEST(ListMethodsSuite, PopFront) {
  List<int> l{1, 2, 3};
  ListData<int> ld{2, 3};

  ASSERT_NO_THROW(l.popFrontArg());
  ASSERT_EQ(l.length(), 2);
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopFrontThrow) {
  List<int> l;
  ASSERT_THROW(l.popFrontArg(), EmptyList);
}

TEST(ListMethodsSuite, InsertFront) {
  List<int> l{1, 3};
  ListData<int> ld{0, 4, 1, 3};
  
  ASSERT_NO_THROW(l.insertFront(4));
  ASSERT_NO_THROW(l.insertFront(0));

  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, SuccsessfulFind) {
  List<int> l{1, 3};
  Shared<ListNode<int>> ptr;

  ASSERT_NO_THROW(ptr = l.find(1));
  ASSERT_EQ(ptr->getData(), 1);
}

TEST(ListMethodsSuite, UnSuccsessfulFind) {
  List<int> l{1, 3};
  Shared<ListNode<int>> ptr;

  ASSERT_NO_THROW(ptr = l.find(4));
  ASSERT_EQ(ptr, nullptr);
}