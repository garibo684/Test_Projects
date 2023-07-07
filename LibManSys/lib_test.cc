#include <gtest/gtest.h>
#include "lib_man_sys.cc"

TEST(LibraryTest, AddBook_GetBook) {
  Library library;

  library.AddBook("Count of Monte Kristo", "Alexandre Dumas");
  library.AddBook("Foundation", "Asimov");
  library.AddBook("Animal Farm", "George Orwell");
  EXPECT_EQ(library.GetBookCount(), 3);

  library.AddBook("Second Foundation", "Asimov");
  EXPECT_EQ(library.GetBookCount(), 4);
}

TEST(LibraryTest, AddBorrower) {
  Library library;

  library.AddBorrower("Ahmetmet");
  EXPECT_EQ(library.GetBorrowerCount(), 1);

  library.AddBorrower("Mahmut Palamut");
  EXPECT_EQ(library.GetBorrowerCount(), 2);
}

TEST(LibraryTest, BorrowBook_ReturnBook) {
  Library library;

  library.AddBorrower("Ahmetmet");
  library.AddBook("Count of Monte Kristo", "Alexandre Dumas");
  library.AddBook("Foundation", "Asimov");

  library.BorrowBook("Foundation", "Ahmetmet");
  EXPECT_FALSE(library.IsAvailable("Foundation"));
  
  library.BorrowBook("Count of Monte Kristo", "Ahmetmet");
  EXPECT_FALSE(library.IsAvailable("Count of Monte Kristo"));

  library.ReturnBook("Foundation", "Ahmetmet");
  EXPECT_TRUE(library.IsAvailable("Foundation"));
}
int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}