#include "utils.h"

TEST(ListNegSuite, CreationFromFile) {
  for (auto& entry : fs::directory_iterator(glob_test_dir / "list_creation_neg")) {
    std::cout << entry.path() << std::endl;

    std::ifstream list_stream(entry.path());
    ASSERT_THROW(List<int>l(list_stream), InvalidListStream);
  }
}
