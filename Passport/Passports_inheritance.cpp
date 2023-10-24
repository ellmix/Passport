#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Passport {
protected:
    char* name;
    char* surname;
    int age;
    char* date_of_receipt;
    char* gender;

public:
    //constructor
    Passport()
        :name(nullptr), surname(nullptr), date_of_receipt(nullptr), gender(nullptr), age(0) { }

    Passport(const char* n, const char* s, const char* d, const char* g, int a) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        surname = new char[strlen(s) + 1];
        strcpy(surname, s);

        date_of_receipt = new char[strlen(d) + 1];
        strcpy(date_of_receipt, d);

        gender = new char[strlen(g) + 1];
        strcpy(gender, g);
    }

    //destructor
    ~Passport() {
        delete[] name;
        delete[] surname;
        delete[] date_of_receipt;
        delete[] gender;
    }

    //show
    void displayPassport() {
        cout << "\n--------------\n";
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Date of receipt: " << date_of_receipt << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
    }
};

class Foreign : public Passport {
private:
    char* Visa;
    int validity_year;

public:
    //constructor
    Foreign() : Visa(nullptr), validity_year(0) {}

    Foreign(const char* visa, int y, const char* n, const char* s, const char* d, const char* g, int a) : Passport(n, s, d, g, a), validity_year(y) {
        Visa = new char[strlen(visa) + 1];
        strcpy(Visa, visa);
    }

    //destructor
    ~Foreign() {
        delete[] Visa;
    }
    
    //show
    void displayVisa() {
        cout << "Visa: " << Visa << endl;
        cout << "Validity_year: " << validity_year << endl;
        cout << "\n--------------\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");


    Passport regular_passport("Artem", "Kotov", "01.01.2000", "M", 30);
    regular_passport.displayPassport();

    Foreign foreign_passport("VISA Tourist", 2025, "Albert", "Sokolov", "05.15.1995", "M", 23);
    foreign_passport.displayPassport();
    foreign_passport.displayVisa();
}