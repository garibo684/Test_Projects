#ifndef LIBRARY_BORROWER_H
#define LIBRARY_BORROWER_H

#include "Book.h"
#include <vector>

class Borrower {
 public:
   Borrower(const std::string& name, int age);

   const std::string& GetName() const;

   const int GetAge() const;

   bool IsStudent() const;

   bool IsElderly() const;

   void GetBorrowedBooks() const;

   bool GetClearence() const;

   void SetClearence(bool clearence);

   void AddBook(const Book& book);

   void RemoveBook(const Book& book);

 private:
   std::string name_;
   int age_;
   bool is_student_;
   bool is_elderly_;
   bool clearence_;
   std::vector<Book> borrowed_books_;

};

#endif