#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title, author;
    int copies;

    static int validate(int n) {
        if (n < 0)
            throw invalid_argument("Copies cannot be negative");
        return n;
    }

public:
    Book() : Book("Untitled", "Unknown", 0) {}

    explicit Book(const string& t)
        : Book(t, "Unknown", 1) {}

    Book(const string& t, const string& a, int n)
        : title(t), author(a), copies(validate(n)) {}

    void print() const {
        cout << "Title: " << title
             << ", Author: " << author
             << ", Copies: " << copies << '\n';
    }
};

int main() {
    try {
        Book b1;
        Book b2("The Alchemist");
        Book b3("Wings of Fire", "A.P.J. Abdul Kalam", 5);

        b1.print();
        b2.print();
        b3.print();

        Book b4("Invalid Book", "Unknown", -2);
        b4.print();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << '\n';
    }

    Book shelf[3];

    return 0;
}

<img width="364" height="92" alt="image" src="https://github.com/user-attachments/assets/3a335629-5185-40a5-a9b3-b12d5b30c5f7" />
