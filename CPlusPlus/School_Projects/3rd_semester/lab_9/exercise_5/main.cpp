#include <string>
#include <iostream>
using namespace std;

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
};

int main() {
    Book book("Modern C++ Programming Cookbook", "1800208987", 49.99);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Modern C++ Programming Cookbook(ebook)", "1800208987", 34.99, "dkb34x!@*~");
    ebook.ShowEBookInfo();

    return 0;
}
