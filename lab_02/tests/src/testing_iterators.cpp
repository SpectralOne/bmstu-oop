#include "utils.h"

TEST(ListIteratorsSuite, OutOfRangeAccess) {
  flexlist::List<int> a{1, 2};
  flexlist::ListIterator<int>it(a);

  ASSERT_THROW(it += 3, flexlist::ListOutOfBounds);
}

TEST(ListIteratorSuite, AssignIterator) {
  flexlist::List<int> l{1, 2, 3};
  ASSERT_NO_THROW(flexlist::ListIterator<int> it(l));
}

TEST(ListIteratorsSuite, IteratorInsertAfter) {
  flexlist::List<int> l{1, 2, 3};
  const ListData<int> ld{1, 2, 3, 4};
  flexlist::ListIterator<int> it(l);
  
  it += 2;
  ASSERT_NO_THROW(l.insertAfter(it, 4));
  ASSERT_EQ(l, ld);
}

TEST(ListIteratorsSuite, IteratorInsertBefore) {
  flexlist::List<int> l{1, 2, 3};
  const ListData<int> ld{1, 2, 4, 3};
  flexlist::ListIterator<int> it(l);
  
  it += 2;
  ASSERT_NO_THROW(l.insertBefore(it, 4));
  ASSERT_EQ(l, ld);
}

TEST(ListIteratorsSuite, IteratorInequality) {
  flexlist::List<int> l1{1, 2, 3};
  flexlist::List<int> l2{1, 2, 3};
  flexlist::ListIterator<int> it1(l1);
  flexlist::ListIterator<int> it2(l2);

  ASSERT_THROW(it1 > it2, flexlist::IteratorCompareError);  
  ASSERT_THROW(it1 >= it2, flexlist::IteratorCompareError);  
  ASSERT_THROW(it1 < it2, flexlist::IteratorCompareError);  
  ASSERT_THROW(it1 <= it2, flexlist::IteratorCompareError); 
  ASSERT_THROW(it1 == it2, flexlist::IteratorCompareError);  
  ASSERT_THROW(it1 != it2, flexlist::IteratorCompareError);   
}