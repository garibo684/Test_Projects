#include <iostream>
#include <vector>
#include <string>

class Book {
 public:
  Book(const std::string& author, const std::string title) :
      author_(author), title_(title), borrowed_(false) {}

  const std::string& GetAuthor() const {
    return author_;
  }
  const std::string& GetTitle() const {
    return title_;
  }
  bool IsBorrowed() const {
    return borrowed_;
  }
  void SetBorrowed(bool borrowed) {
    borrowed_ = borrowed;
  }

 private:
  std::string author_;
  std::string title_;
  bool borrowed_;
};

class Borrower {
 public:
  explicit Borrower(const std::string name) : name_(name) {}

  const std::string& GetName() const {
    return name_;
  }
  void AddBorrowedBook(const Book& book) {
    borrowed_books_.emplace_back(book);
  }
  void DisplayBorrowedBooks() const {
    for (auto book : borrowed_books_) {
      std::cout << "Title: " << book.GetTitle()<< " Author: " <<
          book.GetAuthor() << std::endl;
    }
  }
  int GetCountBB() const {
    return borrowed_books_.size();
  }

 private:
  std::string name_;
  std::vector<Book> borrowed_books_;
};

class Library {
 public:
  void AddBook(const std::string& title, const std::string& author) {
    books_.emplace_back(author, title);
  }
  void AddBorrower(const std::string& name) {
    borrowers_.emplace_back(name);
  }
  void DisplayBooks() const {
    for (auto& book : books_) {
      std::cout << "Title: " << book.GetTitle()<< " Author: " <<
          book.GetAuthor();
      if (!book.IsBorrowed()) {
       std::cout << " [Available]" << std::endl;
      } else {
          std::cout << " [Not Available]" << std::endl;
      }
    }
  }
  bool IsAvailable(const std::string& title) const {
    for (auto& book : books_) {
      if (book.GetTitle() == title) {
        return !book.IsBorrowed();
      }
    }
    std::cout << "\nBook '" << title << "' not in library.\n" << std::endl;
    return false;
  }
  int GetBookCount() const {
    return books_.size();
  }
  int GetBorrowerCount() const {
    return borrowers_.size();
  }
  void ReturnBook(const std::string& title, const std::string& name) {
    for (auto& book : books_) {
      if (book.GetTitle() == title) {
        for (auto& borrower : borrowers_) {
          if (borrower.GetName() == name) {
            book.SetBorrowed(false);
            std::cout << "\nBook '" << book.GetTitle() <<
                "' is successfully returned by '" << borrower.GetName()
                << "'.\n" << std::endl;
            return;
            }
          }
        }
      }
    std::cout << "\nBook '" << title << "' not in library.\n" << std::endl;
  }
  void BorrowBook(const std::string& title, const std::string& name) {
    for (auto& book : books_) {
      if (book.GetTitle() == title) {
        if (!book.IsBorrowed()) {
          book.SetBorrowed(true);
          for (auto& borrower : borrowers_) {
            if (borrower.GetName() == name) {
              borrower.AddBorrowedBook(book);
              std::cout << "\nBook '" << book.GetTitle() << "' borrowed by '"
                  << borrower.GetName() << "'.\n" << std::endl;
              return;
            }
          }
          borrowers_.emplace_back(name);
          std::cout << "\nBorrower '" << borrowers_.back().GetName() <<
              "' added to the database.\n" << std::endl;
          borrowers_.back().AddBorrowedBook(book);
          std::cout << "Book '" << book.GetTitle() << "' successfully borrowedby '"
              << borrowers_.back().GetName() << "'.\n" << std::endl;
          return;
        } else {
          std::cout << "\nBook '" << book.GetTitle() << "' is already borrowed.\n";
          return;
       }
      }
    }
    std::cout << "\nBook '" << title << "' not in library.\n" << std::endl;
  }

 private:
  std::vector<Book> books_;
  std::vector<Borrower> borrowers_;
};

int main_process() {
  Library library;

  library.AddBorrower("Ahmetmet");

  library.AddBook("Count of Monte Kristo", "Alexandre Dumas");
  library.AddBook("Foundation", "Asimov");
  library.AddBook("Animal Farm", "George Orwell");
  library.DisplayBooks();

  library.BorrowBook("Foundation", "Mahmut Palamut");
  library.DisplayBooks();

  library.BorrowBook("Count of Monte Kristo", "Ahmetmet");
  library.DisplayBooks();

  library.ReturnBook("Foundation", "Mahmut Palamut");
  library.DisplayBooks();

  library.ReturnBook("Count of Monte Kristo", "Ahmetmet");
  library.DisplayBooks();

  return 0;
}
