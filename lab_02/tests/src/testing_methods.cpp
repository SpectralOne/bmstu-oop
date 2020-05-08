#include "utils.h"

TEST(ListMethodsSuite, IsEmpty) {
  flexlist::List<int> l;
  ASSERT_TRUE(l.isEmpty());

  flexlist::List<int> l2{1, 2, 3};
  ASSERT_FALSE(l2.isEmpty());
}

TEST(ListMethodsSuite, Size) {
  flexlist::List<int> l{1, 2};
  ASSERT_EQ(l.size(), 2);
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

TEST(ListMethodsSuite, ListReverse) {
  flexlist::List<int> l{1, 2, 3, 4};
  const ListData<int> ld{4, 3, 2, 1};

  ASSERT_NO_THROW(l.reverse());
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, PopFrontThrow) {
  flexlist::List<int> l;
  ASSERT_THROW(l.popFront(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, PopFront) {
  flexlist::List<int> l{1, 2, 3};
  ListData<int> ld{2, 3};

  ASSERT_NO_THROW(l.popFront());
  ASSERT_EQ(l.size(), 2);
  ASSERT_EQ(l, ld);
}


TEST(ListMethodsSuite, PopBackThrow) {
  flexlist::List<int> l;
  ASSERT_THROW(l.popBack(), flexlist::EmptyList);
}

TEST(ListMethodsSuite, PopBack) {
  flexlist::List<int> l{1, 2, 3};
  ListData<int> ld{1, 2};

  ASSERT_NO_THROW(l.popBack());
  ASSERT_EQ(l.size(), 2);
  ASSERT_EQ(l, ld);
}