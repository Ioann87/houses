#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

vector<char*> names = {
    "Ivan",
    "Petr",
    "Viktor",
    "Stepan",
    "Josiph",
    "Vladimir",
    "Kiryll",
    "Anton",
    "Jury",
    "Boris"
};

vector<char*> surnames = {
    "Ivanov",
    "Petrov",
    "Viktorov",
    "Stepanov",
    "Josiphov",
    "Vladimirov",
    "Kiryllov",
    "Antonov",
    "Juryov",
    "Borisov"
};

class Person {
private:
    char* name;
    char* surname;
    int age;

public:
    Person();
    Person(char name);
    ~Person();
    void init_person(char* name, char* surname, int age);
    void show_info();
};

class Flat {
private:
    Person* flats;
    int size;

public:
    Flat();
    ~Flat();
    void init_flat();
    void show_flat();
};

class House {
private:
    Flat* flats_count;
    int size;

public:
    House();
    ~House();
    void show_house();
    void init_house();
};

int main()
{
    srand(time(NULL));

    House* houses = new House[5];

    for (int i = 0; i < 3; i++) {
        houses[i].init_house();
    }

    for (int i = 0; i < 3; i++) {
        houses[i].show_house();
    }

    delete[] houses;

    return 0;
}

Person::Person()
{
    this->name = nullptr;
    this->surname = nullptr;
    this->age = 0;
}

Person::~Person()
{
    delete name;
    delete surname;
}

void Person::init_person(char* name, char* surname, int age)
{
    this->name = new char[15];
    strcpy(this->name, name);
    this->surname = new char[15];
    strcpy(this->surname, surname);
    this->age = age;
    return;
}

void Person::show_info()
{
    cout << "Name: " << this->name << endl;
    cout << "Surname: " << this->surname << endl;
    cout << "Age: " << this->age << endl;
    cout << endl;
}

Flat::Flat()
{
    this->flats = nullptr;
    this->size = 0;
}

Flat::~Flat()
{
    delete[] flats;
}

void Flat::init_flat()
{
    this->size = rand() % 3 + 1;
    this->flats = new Person[this->size];
    for (int i = 0; i < size; i++) {
        flats[i].init_person(
            names[rand() % 10],
            surnames[rand() % 10],
            rand() % 50 + 20);
    }
    return;
}

void Flat::show_flat()
{

    for (int i = 0; i < this->size; i++) {
        cout << "Flat #" << i + 1 << endl;
        flats[i].show_info();
    }

    return;
}

House::House()
{
    this->flats_count = nullptr;
    this->size = 0;
}

House::~House()
{
    delete[] flats_count;
}

void House::init_house()
{
    this->size = rand() % 5 + 1;
    this->flats_count = new Flat[size];
    for (int i = 0; i < this->size; i++) {
        flats_count[i].init_flat();
    }
    return;
}

void House::show_house()
{
    for (int i = 0; i < this->size; i++) {
        cout << "House #" << i + 1 << endl;
        flats_count[i].show_flat();
    }
}
