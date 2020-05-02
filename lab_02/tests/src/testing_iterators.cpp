#include "utils.h"

TEST(ListIteratorsSuite, OutOfRangeAccess) {
  List<int> a{1, 2};
  ListIterator<int>it(a);

  ASSERT_THROW(it += 3, ListOutOfBounds);
}

TEST(ListIteratorSuite, AssignIterator) {
  List<int> l{1, 2, 3};
  ASSERT_NO_THROW(ListIterator<int> it(l));
}

TEST(ListIteratorsSuite, IteratorInsertAfter) {
  List<int> l{1, 2, 3};
  const ListData<int> ld{1, 2, 3, 4};
  ListIterator<int> it(l);
  
  it += 2;
  ASSERT_NO_THROW(l.insertAfter(it, 4));
  ASSERT_EQ(l, ld);
}

TEST(ListIteratorsSuite, IteratorInsertBefore) {
  List<int> l{1, 2, 3};
  const ListData<int> ld{1, 2, 4, 3};
  ListIterator<int> it(l);
  
  it += 2;
  ASSERT_NO_THROW(l.insertBefore(it, 4));
  ASSERT_EQ(l, ld);
}

TEST(ListIteratorsSuite, IteratorInequality) {
  List<int> l1{1, 2, 3};
  List<int> l2{1, 2, 3};
  ListIterator<int> it1(l1);
  ListIterator<int> it2(l2);

  ASSERT_THROW(it1 > it2, IteratorCompareError);  
  ASSERT_THROW(it1 >= it2, IteratorCompareError);  
  ASSERT_THROW(it1 < it2, IteratorCompareError);  
  ASSERT_THROW(it1 <= it2, IteratorCompareError); 
  ASSERT_THROW(it1 == it2, IteratorCompareError);  
  ASSERT_THROW(it1 != it2, IteratorCompareError);   
}