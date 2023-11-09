#include <string>
#include <iostream>
using namespace std;

class EbookLibrary;
class Book {
public:
    Book(const string& title, const string& ISBN, double price)
        : title(title), ISBN(ISBN), price(price) {}

    void ShowBookInfo() const {
        cout << "Title: " << title << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: " << price << endl;
    }

protected:
    string title;
    string ISBN;
    double price;
    friend class EbookLibrary;
};

class EBook : public Book {
public:
    EBook(const string& title, const string& ISBN, double price, const string& DRMKey, const string& format = "Kindle")
        : Book(title, ISBN, price), DRMKey(DRMKey), format(format) {}

    void ShowEBookInfo() const { 
        cout << "Title: " << title << endl
             << "ISBN: " << ISBN << endl
             << "Price: " << price << endl
             << "Format: " << format << endl;
    }

private:
    string DRMKey;
    string format;
    friend class EbookLibrary;
};

const int MAX_BOOK = 100;
class EBookLibrary {
private:
    EBook* m_books[MAX_BOOK];
    int m_cnt{0};

public:
    EBookLibrary() = default;
    ~EBookLibrary() {
        for (int i = 0; i < m_cnt; ++i) {
            delete m_books[i];
        }
    }
    void AddBook(EBook* book) {
        m_books[m_cnt] = book;
        m_cnt++;
    };
    void ShowAllBooks() {
        for (int i = 0; i < m_cnt; i++) {
            m_books[i]->ShowEBookInfo();
            cout << endl;
        }
    };
};

int main() {
    EBookLibrary elib;
    elib.AddBook(new EBook{ "Book1", "1234567890", 10.99, "AAAAAA", "ePub" });
    elib.AddBook(new EBook{ "Book2", "2345678901", 20.99, "BBBBBB" });
    elib.AddBook(new EBook{ "Book3", "3456789012", 30.99, "CCCCCC", "ePub"});
    elib.AddBook(new EBook{ "Book4", "4567890123", 40.99, "DDDDDD" });
    elib.ShowAllBooks();

    return 0;
}
