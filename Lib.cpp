#include <cctype>
#include <string>
#include <iostream>
using namespace std;
struct Book {
    string name;
    string author;
    int year;
    double price;
};

struct Library {
    Book b[10];

    int bookCount = 0;

    void addBook(string name, string author, int year, double price);

    void printAllBooks();

    void findByAuthor(string answer);

    void findByYear(int year);

};


void Library::addBook(string name, string author, int year, double price) {
    if (bookCount < 10) {
        b[bookCount] = {name, author, year, price};
        bookCount++;
    }
    else
        cout << "Library is full!" << endl;
}


void Library::printAllBooks() {
    for (int i = 0; i < bookCount; ++i) {
        cout << '"' << b[i].name << '"' << ", " << b[i].author << ", " << b[i].year << ", " << b[i].price << " rub." << endl;
    }
}


bool answerFunction(string answer) {
    for (int i = 0; i < answer.size(); ++i) {
        answer[i] = tolower(answer[i]);

    }

    if (answer == "yes") {
        cout << "Great!" << endl;
        return true;
    }
    else if (answer == "no") {
        cout << "Bye!" << endl;
        return false;
    }
    else {
        cout << "Im not understand answer" << endl;
        return false;
    }

}


void Library::findByAuthor(string answer) {
    bool found = false;

    for (int i = 0; i < bookCount; ++i) {
        if (b[i].author == answer) {
            cout << "His book(s): " << '"' << b[i].name << '"' << endl;
            found = true;
        }
    }
    if (!found) cout << "I dont know this author :(" << endl;


}

void Library::findByYear(int year) {
    bool found = false;

    for (int i = 0; i < bookCount; ++i) {
        if (b[i].year == year) {
            cout << "Book(s) this year: " << '"' << b[i].name << '"' << ". " << "Author: " << b[i].author << endl;
            found = true;
        }
    }

    if (!found) cout << "Book of this year has not found in our library :(" << endl;
}

int main() {
    string answer;
    string name;
    string author;
    int year;
    double price;

    Library lib = {
        {
            {"The Captain's Daughter", "Alexander Pushkin", 1836, 380},
            {"War and Peace", "Leo Tolstoy", 1869, 950},
            {"Fathers and Sons", "Ivan Turgenev", 1862, 350},
            {"A Hero of Our Time", "Mikhail Lermontov", 1840, 320},
            {"Dead Souls", "Nikolai Gogol", 1842, 390},
            {"Eugene Onegin", "Alexander Pushkin", 1833, 420}
        }, {6}

    };


    cout << "Do you want to add the book to the library? (Yes or No): "; cin >> answer;
    cin.ignore();

    if (answerFunction(answer)) {
        cout << "Enter a name Book: " << endl;
        getline(cin, name);

        cout << "Enter a author: " << endl;
        getline(cin , author);

        cout << "Enter a year: " << endl;
        cin >> year;

        cout << "Enter a price: " << endl;
        cin >> price;

        lib.addBook(name, author, year, price);
    }
    else
        return 0;

    cout << endl;


    cout << "Our books: " << endl;
    lib.printAllBooks();

    cout << endl;

    cout << "You want find book or books? (Yes or No): "; cin >> answer;
    cin.ignore();

    if (answerFunction(answer)) {
        cout << "Which authors book would you like to take a look at?: "; getline(cin, answer);

        lib.findByAuthor(answer);
    }
    else
        return 0;

    cout << endl;

    cout << "Do you want to find a book from a specific year? (Yes/No): "; cin >> answer;
    cin.ignore();

    if (answerFunction(answer)) {
        cout << "Enter a specific year: "; cin >> year;

        lib.findByYear(year);
    }

    else
        return 0;

}
