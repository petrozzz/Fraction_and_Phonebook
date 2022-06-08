#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

using namespace std;

struct FullName{
    void create(string fullname);
    string name;
    string patronymic;
    string surname;
};

class Subscriber{
public:
    Subscriber();
    Subscriber(FullName fullname, string phoneNumber, string comment = "");
    void show(int regime = 0);

    string getPhoneNumber(){
        return phoneNumber;
    }
    FullName getFullName(){
        return fullname;
    }

private:
    FullName fullname;
    string phoneNumber;
    string comment;
};

class PhoneBook
{
private:
    Subscriber* subscribers = nullptr;
    int size = 0;
    int *ids = nullptr;
    void updete_ids();

public:
    PhoneBook();
    ~PhoneBook();

    void add(Subscriber &subscriber);
    void remove(int id = 0);
    void remove(int *ids);

    void findSurname(string surname, int*& ids);
    void findName(string name, int*& ids);
    void findPhoneNumber(string phoneNumber, int *&ids);

    int* getIds();
    void show(int *ids){
        int size = int(_msize(ids)) / sizeof(ids[0]);
        for(int k = 0; k < size; k++)
            subscribers[ids[k]].show(1);
    }
};

#endif // PHONEBOOK_H
