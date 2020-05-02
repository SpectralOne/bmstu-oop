#include "utils.h"


TEST(ListBaseSuite, CreationFromFile) {
  for (auto& entry : fs::directory_iterator(glob_test_dir / "list_creation")) {
    std::cout << entry.path() << std::endl;

    std::ifstream list_stream(entry.path());
    ASSERT_NO_THROW(List<int>l(list_stream));

    list_stream.clear();
    list_stream.seekg(0);
    List<int> list(list_stream);

    list_stream.clear();
    list_stream.seekg(0);
    ListData<int> expectedcurrentList = createListData<int>(list_stream);

    ASSERT_EQ(expectedcurrentList, list);
  }
}

TEST(ListBaseSuite, CreationFromInitializerList) {
  ASSERT_NO_THROW(List<int>{1});

  List<int> list{1, 2, 3};
  ListData<int> list_data{1, 2, 3};
  
  ASSERT_EQ(list.length(), list_data.size());
  ASSERT_EQ(list, list_data);
}

TEST(ListBaseSuite, CreationFromVector) {
  ASSERT_NO_THROW(List<int>(std::vector<int>(1)));

  ListData<int> list_data{1, 2, 3};
  List<int> list(list_data);

  ASSERT_EQ(list.length(), list_data.size());
  ASSERT_EQ(list, list_data);
}

TEST(ListBaseSuite, CopyAssign) {
  List<int> l1(2, 2);
  ASSERT_NO_THROW(List<int>{l1});

  const List<int> l2(l1);
  ASSERT_EQ(l1, l2);

  List<int>l3;
  ASSERT_NO_THROW(l3 = l1); 
  ASSERT_EQ(l1, l3);
}

TEST(ListBaseSuite, DefaultConstrucor) {
  List<int> l;
  ASSERT_TRUE(l.isEmpty());
}
