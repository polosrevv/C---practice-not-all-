#include <iostream>
#include <string>
#include <vector>

class Book{
    private:
        std::string title;
        std::string author;
        int year;
        bool isAvailable;
    public:
        Book(std::string title, std::string author, int year, bool isAvailable) : title(title), author(author), year(year), isAvailable(isAvailable){

        }
        std::string getTitle(){
            return title;
        }
        std::string getAuthor(){
            return author;
        }
        int getYear(){
            return year;
        }
        bool checkAvailability(){
            return isAvailable;
        }
        void borrow(){
            isAvailable = false;
        }
        void returnBook(){
            isAvailable = true;
        }
};

class BorrowedBook{
    private:
        Book* book;
        int days;
    public:
        BorrowedBook(Book* book, int days) : book(book), days(days){

        }
        Book* getBook(){
            return book;
        }
        int getDays(){
            return days;
        }
};

class User{
    private:
        std::string name;
        std::vector<BorrowedBook> books;
    public:
        User(std::string name) : name(name){

        }
        void BorrowBook(Book* book, int days){
            
            if(book->checkAvailability()){
                books.push_back(BorrowedBook(book, days));
                book->borrow();
            }
            else{
                std::cerr << "Book is not available";
            }
        }
        void returnBook(Book* book){
            if (!(book->checkAvailability())){
                for(auto it = books.begin();it != books.end(); it++){
                    if((*it).getBook() == book){
                        it = books.erase(it);
                        break;
                    }
                }
                book->returnBook();
            }
        }

};
class Library{
    std::vector<User> users;
    std::vector<Book> booksInShelf;
};
int main(){
    Book book1("1984", "George Orwell", 1949, true);
    Book book2("The Hobbit", "J.R.R. Tolkien", 1937, true);
    User user1("Steven");

    user1.BorrowBook(&book1, 14);

}