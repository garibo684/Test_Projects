#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>

class Book {
 public:
   Book(const std::string& author, const std::string& title, const int publishing_year);
    
  const std::string& GetAuthor() const;

  const std::string& GetTitle() const;

  const int GetYear() const;

  bool GetAvailablity() const;

  void SetAvailablity(bool availability); 

  const std::string& GetBorrower() const;

  void SetSecurity(bool is_secured);

  bool GetSecurity() const;

 private:
   std::string author_;
   std::string title_;
   int publishing_year_;
   bool avaiable_;
   std::string borrower_;
   bool is_secured_;
};

#endif