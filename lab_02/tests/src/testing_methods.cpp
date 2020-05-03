#include "utils.h"

TEST(ListMethodsSuite, IsEmpty) {
  flexlist::List<int> l;
  ASSERT_TRUE(l.isEmpty());

  flexlist::List<int> l2{1, 2, 3};
  ASSERT_FALSE(l2.isEmpty());
}

TEST(ListMethodsSuite, Length) {
  flexlist::List<int> l{1, 2};
  ASSERT_EQ(l.length(), 2);
}

TEST(ListMethodsSuite, Size) {
  flexlist::List<int> l{1, 2};
  const size_t sz = 2 * sizeof(flexlist::ListNode<int>);
  ASSERT_EQ(l.size(), sz);
}

TEST(ListMethodsSuite, UniqueNoThrow) {
  flexlist::List<int> l{1, 2, 1, 1};
  ListData<int> ld{1, 2};
  
  ASSERT_NO_THROW(l.unique());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, UniqueEmptyList) {
  flexlist::List<int> l;
  ASSERT_THROW(l.unique(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, UniqueNotEnoughNodes) {
  flexlist::List<int> l{1};
  ASSERT_THROW(l.unique(), flexlist::NotEnoughNodes);
}

TEST(ListMethodsSuite, Reset) {
  flexlist::List<int> l1{1, 3};
  const ListData<int> ld1{0, 0};

  ASSERT_NO_THROW(l1.reset());
  ASSERT_EQ(l1, ld1);

  flexlist::List<int> l2{0, 0};
  const ListData<int> ld2{1, 1};

  ASSERT_NO_THROW(l2.reset(1));
  ASSERT_EQ(l2, ld2);
}

TEST(ListMethodsSuite, Clear) {
  flexlist::List<int> l{1, 3};
  ASSERT_NO_THROW(l.clear());

  ASSERT_TRUE(l.isEmpty());
}

TEST(ListMethodsSuite, ClearEmptyList) {
  flexlist::List<int> l;
  ASSERT_THROW(l.clear(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, AscendingSort) {
  flexlist::List<int> l{4, 3, 2, 1};
  const ListData<int> ld{1, 2, 3, 4};

  ASSERT_NO_THROW(l.sort());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, DescendingSort) {
  flexlist::List<int> l{1, 2, 3};
  const ListData<int> ld{3, 2, 1};

  ASSERT_NO_THROW(l.sort(false));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, EmptyListSort) {
  flexlist::List<int> l;
  ASSERT_THROW(l.sort(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, OneNodeSort) {
  flexlist::List<int> l{1};
  ASSERT_THROW(l.sort(), flexlist::NotEnoughNodes);
}

TEST(ListMethodsSuite, ListReverse) {
  flexlist::List<int> l{1, 2, 3, 4};
  const ListData<int> ld{4, 3, 2, 1};

  ASSERT_NO_THROW(l.reverse());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopBackArg) {
  flexlist::List<int> l{1, 2, 3};
  ListData<int> ld{1, 2};
  int arg;

  ASSERT_NO_THROW(arg = l.popBackArg());
  ASSERT_EQ(arg, 3);
  ASSERT_EQ(l.length(), 2);
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopBackArgThrow) {
  flexlist::List<int> l;
  ASSERT_THROW(l.popBackArg(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, PopBack) {
  flexlist::List<int> l{1, 2, 3};
  ListData<int> ld{1, 2};

  ASSERT_NO_THROW(l.popBack());
  ASSERT_EQ(l.length(), 2);
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopBackThrow) {
  flexlist::List<int> l;
  ASSERT_THROW(l.popBack(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, PopFrontArgThrow) {
  flexlist::List<int> l;
  ASSERT_THROW(l.popFrontArg(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, PopFront) {
  flexlist::List<int> l{1, 2, 3};
  ListData<int> ld{2, 3};

  ASSERT_NO_THROW(l.popFrontArg());
  ASSERT_EQ(l.length(), 2);
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopFrontThrow) {
  flexlist::List<int> l;
  ASSERT_THROW(l.popFrontArg(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, SuccsessfulFind) {
  flexlist::List<int> l{1, 3};
  Shared<flexlist::ListNode<int>> ptr;

  ASSERT_NO_THROW(ptr = l.find(1));
  ASSERT_EQ(ptr->getData(), 1);
}

TEST(ListMethodsSuite, UnSuccsessfulFind) {
  flexlist::List<int> l{1, 3};
  Shared<flexlist::ListNode<int>> ptr;

  ASSERT_NO_THROW(ptr = l.find(4));
  ASSERT_EQ(ptr, nullptr);
}