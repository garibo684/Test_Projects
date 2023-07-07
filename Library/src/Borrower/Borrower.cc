#include "Borrower.h"
#include <iostream>

Borrower::Borrower(const std::string& name, int age) :
    name_(name), age_(age) {}

const std::string& Borrower::GetName() const {
  return name_;
}

const int Borrower::GetAge() const {
  return age_;
}

bool Borrower::IsStudent() const {
  return is_student_;
}

bool Borrower::IsElderly() const {
  return is_elderly_;
}

void Borrower::GetBorrowedBooks() const {
  
  int count = 1;

  for (auto& book : borrowed_books_) {
    std::cout << count << "- Title: '" << book.GetTitle() << "'\nAuthor: '" <<  
        book.GetAuthor() << "'\n [" << book.GetAvailablity() << "]\n" << std::endl;
    count++;
  }
  std::cout << "_________________________________________\n" << std::endl;
}

bool Borrower::GetClearence() const {
  return clearence_;
}

void Borrower::SetClearence(bool clearence) {
  clearence_ = clearence;
}

void Borrower::AddBook(const Book& book) {
  borrowed_books_.emplace_back(book);
}

void Borrower::RemoveBook(const Book& book) {

  int count = 0;
  
  for (auto& borrowed_book : borrowed_books_) {
    if (book.GetTitle() == borrowed_book.GetTitle()) {
      borrowed_books_.erase(borrowed_books_.begin() + count);
    }
    count++;
  }
}
