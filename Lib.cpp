#include <cctype>   // для функции tolower (приведение символа к нижнему регистру)
#include <string>   // для работы со строками std::string
#include <iostream> // для ввода/вывода (cin, cout)
using namespace std;

// Структура, описывающая одну книгу
struct Book {
    string name;   // название книги
    string author; // автор
    int year;      // год издания
    double price;  // цена в рублях
};

// Структура, представляющая библиотеку (массив книг + счётчик)
struct Library {
    Book b[10];          // массив максимум на 10 книг
    int bookCount = 0;   // сколько книг реально добавлено в библиотеку

    // Добавить книгу в библиотеку
    void addBook(string name, string author, int year, double price);

    // Вывести список всех книг
    void printAllBooks();

    // Найти книги по автору
    void findByAuthor(string answer);

    // Найти книги по году издания
    void findByYear(int year);
};


// Реализация метода добавления книги
void Library::addBook(string name, string author, int year, double price) {
    if (bookCount < 10) {
        // Если есть место — записываем книгу в массив и увеличиваем счётчик
        b[bookCount] = {name, author, year, price};
        bookCount++;
    }
    else
        // Иначе сообщаем, что мест больше нет
        cout << "Library is full!" << endl;
}


// Реализация метода вывода всех книг
void Library::printAllBooks() {
    // Проходим по всем реально добавленным книгам (от 0 до bookCount-1)
    for (int i = 0; i < bookCount; ++i) {
        cout << '"' << b[i].name << '"' << ", " << b[i].author << ", "
             << b[i].year << ", " << b[i].price << " rub." << endl;
    }
}


// Вспомогательная функция: обрабатывает ответ пользователя "да/нет"
// Возвращает true, если ответ "yes", иначе false
bool answerFunction(string answer) {
    // Приводим все символы строки к нижнему регистру (чтобы "Yes", "YES", "yEs" считались одинаковыми)
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
        // Если ответ не распознан — считаем, что пользователь отказался
        cout << "Im not understand answer" << endl;
        return false;
    }
}


// Реализация поиска книг по автору
void Library::findByAuthor(string answer) {
    bool found = false; // флаг: нашли ли хотя бы одну книгу

    for (int i = 0; i < bookCount; ++i) {
        // Сравниваем автора книги с введённой строкой (по умолчанию — с учётом регистра)
        if (b[i].author == answer) {
            cout << "His book(s): " << '"' << b[i].name << '"' << endl;
            found = true;
        }
    }
    // Если ничего не нашли — сообщаем об этом
    if (!found) cout << "I dont know this author :(" << endl;
}


// Реализация поиска книг по году издания
void Library::findByYear(int year) {
    bool found = false;

    for (int i = 0; i < bookCount; ++i) {
        if (b[i].year == year) {
            cout << "Book(s) this year: " << '"' << b[i].name << '"'
                 << ". " << "Author: " << b[i].author << endl;
            found = true;
        }
    }

    if (!found) cout << "Book of this year has not found in our library :(" << endl;
}


int main() {
    // Переменные для ввода пользователя
    string answer;  // ответ на вопросы "да/нет" и строка поиска по автору
    string name;    // название новой книги
    string author;  // автор новой книги
    int year;       // год (для добавления или поиска)
    double price;   // цена новой книги

    // Инициализация библиотеки: 6 предзаполненных книг и счётчик = 6
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


    // ---- Шаг 1: предложение добавить книгу ----
    cout << "Do you want to add the book to the library? (Yes or No): ";
    cin >> answer;
    cin.ignore(); // очищаем буфер ввода после cin >> answer, чтобы getline работал корректно

    if (answerFunction(answer)) {
        // Если пользователь согласился — считываем данные новой книги
        cout << "Enter a name Book: " << endl;
        getline(cin, name);

        cout << "Enter a author: " << endl;
        getline(cin, author);

        cout << "Enter a year: " << endl;
        cin >> year;

        cout << "Enter a price: " << endl;
        cin >> price;

        lib.addBook(name, author, year, price);
    }
    else
        return 0; // пользователь отказался — выходим из программы

    cout << endl;


    // ---- Шаг 2: вывести все книги ----
    cout << "Our books: " << endl;
    lib.printAllBooks();

    cout << endl;


    // ---- Шаг 3: поиск по автору ----
    cout << "You want find book or books? (Yes or No): ";
    cin >> answer;
    cin.ignore();

    if (answerFunction(answer)) {
        cout << "Which authors book would you like to take a look at?: ";
        getline(cin, answer); // здесь answer используется как строка-автор

        lib.findByAuthor(answer);
    }
    else
        return 0;

    cout << endl;


    // ---- Шаг 4: поиск по году ----
    cout << "Do you want to find a book from a specific year? (Yes/No): ";
    cin >> answer;
    cin.ignore();

    if (answerFunction(answer)) {
        cout << "Enter a specific year: ";
        cin >> year;

        lib.findByYear(year);
    }
    else
        return 0;
}
