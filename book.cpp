#include <sstream>
#include "book.h"

using namespace std;

Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerId("") {}

Book::Book(const string& title, const string& author, const string& isbn)
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerId("") {}

// Les setters

void Book::setTitle(const string& title) { this->title = title; }
void Book::setAuthor(const string& author) { this->author = author; }
void Book::setISBN(const string& isbn) { this->isbn = isbn; }
void Book::setAvailability(bool available) { this->isAvailable = available; }
void Book::setBorrowerId(const string& id) { this->borrowerId = id; }

// Les getters

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }
string Book::getBorrowerId() const { return borrowerId; }

// Les méthodes

void Book::checkOut(const string& borrowerId) {
    this->isAvailable = false;
    this->borrowerId = borrowerId;
}

void Book::returnBook() {
    isAvailable = true;
    borrowerId = "";
}

string Book::toString() const {
    string availability;

    if (isAvailable) {
        availability = "Disponible";
    } else {
        availability = "Emprunteur: " + borrowerId;
    }

    return "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nStatut: " + availability;
}

string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerId;
}

void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availability;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availability, '|');
    getline(ss, borrowerId);
    isAvailable = (availability == "1");
}
