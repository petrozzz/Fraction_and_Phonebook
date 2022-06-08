#include <iostream>
#include "phonebook.h"
#include "fraction.h"

using namespace std;

float addProcent(float price, float procent);
void testPhonebook();
void testFraction();

int main(){
    cout << endl;
    testPhonebook();
    cout << endl;
    testFraction();
    cout << endl;
    return 0;
}

float addProcent(float price, float procent){
    return price * (1.0f + procent/100.f);
}

void testPhonebook(){
    cout << "Start test Phonebook" << endl;
    PhoneBook * phonebook = new PhoneBook();
    FullName name;

    name.create("Goncharov Petr Petrovich");
    phonebook->add(Subscriber(name, "+79508414265", "This is me"));
    name.create("Goncharova Svetlana Ivanovna");
    phonebook->add(Subscriber(name, "+79515370472", "This is not me"));
    name.create("Yarovoy Stepan Antonovich");
    phonebook->add(Subscriber(name, "+79612827422", "John Doe"));
    name.create("Nagorny Alan Muhtarovich");
    phonebook->add(Subscriber(name, "+79182342121", "Fiction"));
    name.create("Nagornaya Alina Muhtarovna");
    phonebook->add(Subscriber(name, "+79182342221"));

    cout << "All subscribers in phonebook: " << endl;
    phonebook->show(phonebook->getIds());

    cout << "The subscribers with phone number  \"+79612827422\" :" << endl;
    int *id_number = phonebook->getIds();
    phonebook->findPhoneNumber(string("+79612827422"), id_number);

    phonebook->show(id_number);
    delete phonebook;
    cout << "End test Phonebook" << endl;
}

void testFraction(){
    cout << "Start test Fraction" << endl;
    Fraction val1(1,2);
    Fraction val2(1,3);

    cout << val1.show() << " + " << val2.show() << " = " << (val1 + val2).show() << endl;
    cout << val1.show() << " - " << val2.show() << " = " << (val1 - val2).show() << endl;
    cout << val1.show() << " * " << val2.show() << " = " << (val1 * val2).show() << endl;
    cout << val1.show() << " : " << val2.show() << " = " << (val1 / val2).show() << endl;
    cout << "Integer part of 13/3 = " << Fraction(13, 3).getIntegerPart() << endl;
    cout << "End test Fraction" << endl;
}
