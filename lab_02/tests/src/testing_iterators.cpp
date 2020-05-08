#include "utils.h"

TEST(ListIteratorsSuite, OutOfRangeAccess) {
  flexlist::List<int> a{1, 2};
  flexlist::Iterator<int>it(a);

  ASSERT_THROW(it += 3, flexlist::ListOutOfBounds);
}

TEST(ListIteratorSuite, AssignIterator) {
  flexlist::List<int> l{1, 2, 3};
  ASSERT_NO_THROW(flexlist::Iterator<int> it(l));
}

TEST(ListIteratorSuite, Insert) {
  flexlist::List<int> l{1, 3};
  ListData<int> ld{1, 2, 3};
  flexlist::Iterator<int> it(l);

  ASSERT_NO_THROW(l.insert(it, 2));
  ASSERT_EQ(l, ld);
}
TEST(ListIteratorSuite, Remove) {
  flexlist::List<int> l{1, 2, 3};
  ListData<int> ld{1, 3};
  flexlist::Iterator<int> it(l);

  ASSERT_NO_THROW(l.remove(it));
  ASSERT_EQ(l, ld);
}