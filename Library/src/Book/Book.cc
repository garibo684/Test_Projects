#include "Book.h"

Book::Book(const std::string& title, const std::string& author, const int publishing_year) :
    author_(author), title_(title), publishing_year_(publishing_year), avaiable_(true) {}   

const std::string& Book::GetAuthor() const {
  return author_;
}

const std::string& Book::GetTitle() const {
  return title_;
}

const int Book::GetYear() const {
  return publishing_year_;
}

const std::string& Book::GetBorrower() const {
  return borrower_;
}

bool Book::GetSecurity() const {
  return is_secured_;
}

void Book::SetSecurity(bool is_secured) {
  is_secured_ = is_secured;
} 

bool Book::GetAvailablity() const {
  return avaiable_;
}

void Book::SetAvailablity(bool availability) {
  avaiable_ = availability;
}