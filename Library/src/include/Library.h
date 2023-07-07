#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H

#include "Borrower.h"

class Library {
 public:

   void AddBook(const std::string& title, const std::string& author,
      const int publishing_year);

   void BorrowBook(const std::string& title, const std::string& borrower_name);

   void DisplayBooks() const;

   void AddBorrower(const std::string& name, int age);

   void ReturnBook(const std::string& title, const std::string& name);

   void BorrowedBooks(const std::string& name) const;

 private:
   std::vector<Book> books_;
   std::vector<Borrower> borrowers_;
};

#endif