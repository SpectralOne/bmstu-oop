#include "utils.h"

TEST(ListMethodsSuite, AppendData) {
  flexlist::List<int> l;
  const ListData<int> ld{3};

  ASSERT_NO_THROW(l.pushBack(3));
  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, AppendList) {
  flexlist::List<int> l1{0, 1};
  flexlist::List<int> l2{3, 4};
  const ListData<int> ld{0, 1, 3, 4};

  ASSERT_NO_THROW(l1.pushBack(l2));
  ASSERT_EQ(l1, ld);
}

TEST(ListMethodsSuite, InsertFrontData) {
  flexlist::List<int> l{1, 3};
  ListData<int> ld{0, 4, 1, 3};
  
  ASSERT_NO_THROW(l.pushFront(4));
  ASSERT_NO_THROW(l.pushFront(0));

  ASSERT_EQ(l, ld);
}

TEST(ListMethodsSuite, InsertFrontList) {
  flexlist::List<int>l1{3, 4};
  flexlist::List<int>l2{1, 2};
  const ListData<int> ld{1, 2, 3, 4};

  ASSERT_NO_THROW(l1.pushFront(l2));
  ASSERT_EQ(l1, ld);
}