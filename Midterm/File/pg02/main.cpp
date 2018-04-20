#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Date
{
public:
    Date()  {
        year = 1900;
        month = 1;
        day = 1;
    }
    void print() {
        cout << year << "/" << month << "/" << day;
    }
    void setDate(string dateStr) {
        int dateNum = stoi(dateStr);
        day = dateNum % 100;
        dateNum /= 100;
        month = dateNum % 100;
        dateNum /= 100;
        year = dateNum;
    }
    int getYear() {
        return year;
    }
    
private:
    int month;
    int day;
    int year;
};

class Profile
{
public:
    Profile() {
        firstName = "John";
        lastName = "Doe";
        gender = 'M';
    }
    Profile(string fN, string lN, char g) {
        firstName = fN;
        lastName = lN;
        gender = g;
    }
    Profile(string fN, string lN, char g, string DOB) {
        firstName = fN;
        lastName = lN;
        gender = g;
        birthday.setDate(DOB);
    }
    void setAge() {
        time_t seconds = time(NULL);
        struct tm* t = localtime(&seconds);
        int currentYear = t->tm_year + 1900;
        age = currentYear - birthday.getYear();
    }
    void setID() {
        if(gender == 'M')
            id = (rand() % 1000000) + 1000000;
        else
            id = (rand() % 1000000) + 2000000;
    }
    void print() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Gender: " << gender << endl;
        cout << "Birthday: ";
        birthday.print();
        cout << endl;
        setAge();
        cout << "Age: " << age << endl;
        setID();
        cout << "ID: " << id << endl;
    }
private:
    string   firstName;
    string   lastName;
    char    gender;
    Date    birthday;
    int     age;
    int     id;
};

int main()
{
    
    srand(time(NULL));
    
    Profile person1;
    person1.print();
    
    Profile person2("Charles", "Wen", 'M');
    person2.print();
    
    Profile person3("Shohei", "Ohtani", 'M', "19940705");
    person3.print();
    
    Profile person4("Aragaki", "Yui", 'F', "19880611");
    person4.print();
    
    Profile person5("Ashida", "Mana", 'F', "20040623");
    person5.print();
    
    return 0;
}