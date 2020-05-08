#include "utils.h"


TEST(ListBaseSuite, CreationFromFile) {
  for (auto& entry : fs::directory_iterator(glob_test_dir / "list_creation")) {
    std::cout << entry.path() << std::endl;

    std::ifstream list_stream(entry.path());
    ASSERT_NO_THROW(flexlist::List<int>l(list_stream));

    list_stream.clear();
    list_stream.seekg(0);
    flexlist::List<int> list(list_stream);

    list_stream.clear();
    list_stream.seekg(0);
    ListData<int> expectedcurrentList = createListData<int>(list_stream);

    ASSERT_EQ(expectedcurrentList, list);
  }
}

TEST(ListBaseSuite, CreationFromIstream) {
  for (auto& entry : fs::directory_iterator(glob_test_dir / "list_creation")) {
    std::cout << entry.path() << std::endl;
    flexlist::List<int> l;
    std::ifstream list_stream(entry.path());
    ASSERT_NO_THROW(list_stream >> l);

    list_stream.clear();
    list_stream.seekg(0);
    flexlist::List<int> list;
    list_stream >> list;

    list_stream.clear();
    list_stream.seekg(0);
    ListData<int> expectedcurrentList = createListData<int>(list_stream);

    ASSERT_EQ(expectedcurrentList, list);
  }
}

TEST(ListBaseSuite, CreationFromInitializerList) {
  ASSERT_NO_THROW(flexlist::List<int>{1});

  flexlist::List<int> list{1, 2, 3};
  ListData<int> list_data{1, 2, 3};
  
  ASSERT_EQ(list.size(), list_data.size());
  ASSERT_EQ(list, list_data);
}

TEST(ListBaseSuite, CreationFromArray) {
  int array[5] = {1, 2, 3, 4, 5};
  ASSERT_NO_THROW(flexlist::List<int>(array, 5));

  ListData<int> list_data{1, 2, 3, 4, 5};
  flexlist::List<int> list(array, 5);

  ASSERT_EQ(list.size(), list_data.size());
  ASSERT_EQ(list, list_data);
}

TEST(ListBaseSuite, CopyAssign) {
  flexlist::List<int> l1(2, 2);
  ASSERT_NO_THROW(flexlist::List<int>{l1});

  const flexlist::List<int> l2(l1);
  ASSERT_EQ(l1, l2);

  flexlist::List<int>l3;
  ASSERT_NO_THROW(l3 = l1); 
  ASSERT_EQ(l1, l3);
}

TEST(ListBaseSuite, DefaultConstrucor) {
  flexlist::List<int> l;
  ASSERT_TRUE(l.isEmpty());
}
