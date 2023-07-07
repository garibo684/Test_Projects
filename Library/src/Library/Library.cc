#include "Library.h"
#include <iostream>

void Library::AddBook(const std::string& title, const std::string& author,
    const int publishing_year) {
  books_.emplace_back(title, author, publishing_year);
}

void Library::AddBorrower(const std::string& name, int age) {
  borrowers_.emplace_back(name, age);
}

void Library::BorrowBook(const std::string& title, const std::string& borrower_name) {
  for (auto& borrower : borrowers_) {
    if (borrower_name == borrower.GetName()) {

      for (auto& book : books_) {
        if (title == book.GetTitle()) {
          if(book.GetAvailablity() == true) {
            if (book.GetSecurity() == borrower.GetClearence()) {
              if (borrower.IsElderly() || borrower.IsStudent()) {

                
              }
              book.SetAvailablity(false);
              borrower.AddBook(book);
            }
          }
        }
      }
    }
  }
}
  

void Library::DisplayBooks() const {

  int count = 1;

  for (auto& book : books_) {
    std::cout << count << "- Title: '" << book.GetTitle() << "'\nAuthor: '" <<  
        book.GetAuthor() << "'\n [" << book.GetAvailablity() << "]\n" << std::endl;
    count++;
  }
  std::cout << "_________________________________________\n" << std::endl;
}

void Library::ReturnBook(const std::string& title, const std::string& name) {
  for (auto& borrower : borrowers_) {
    if (name == borrower.GetName()) {
      for (auto& book : books_) {
        if (title == book.GetTitle()) {
          book.SetAvailablity(true);
          borrower.RemoveBook(book);
        }
      }
    }
  }
}

void Library::BorrowedBooks(const std::string& name) const {
  for (auto& borrower : borrowers_) {
    if (name == borrower.GetName()) {
      borrower.GetBorrowedBooks();
    }
  }
}