#include "Library.h"

int main() {
  Library library;
  
  library.AddBook("1984", "George Orwell", 1960);
  library.AddBook("Count of Monte Cristo", "Alexandre Dumas", 1880);
  library.AddBook("Animal Farm", "George Orwell", 1975);
  library.AddBorrower("Mahmut", 24);
  library.AddBorrower("Necdettin", 65);
  library.DisplayBooks();

  library.BorrowBook("1984", "Mahmut");
  library.BorrowBook("Animal Farm", "Necdettin");
  library.DisplayBooks();

  library.BorrowBook("Count of Monte Cristo", "Mahmut");
  library.BorrowedBooks("Mahmut");

  library.ReturnBook("1984", "Mahmut");
  library.BorrowedBooks("Mahmut");
  library.DisplayBooks();

  return 0;
}