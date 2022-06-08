#include "phonebook.h"

#include <QString>

void PhoneBook::updete_ids(){
    ids = new int[size];
    for(int k =0; k < size; k++)
        ids[k] = k;
}

PhoneBook::~PhoneBook(){
    delete [] subscribers;
}

PhoneBook::PhoneBook(){
    subscribers = nullptr;
}

void PhoneBook::add(Subscriber &subscriber){
    Subscriber * buffer = new Subscriber[size + 1];
    for(int k = 0; k < size; k++)
        buffer[k] = subscribers[k];
    buffer[size] = subscriber;
    delete [] subscribers;
    subscribers = buffer;
    size++;
    updete_ids();
}

void PhoneBook::remove(int id){
    if(size > 0 && size > id){
        Subscriber * buffer = new Subscriber[size - 1];
        for(int k = 0; k < id; k++)
            buffer[k] = subscribers[k];
        for(int k = id + 1; k < size; k++)
            buffer[k-1] = subscribers[k];
        delete [] subscribers;
        subscribers = buffer;
        size--;
    } else {
        cout << " The size < 0 or id > size" << endl;
    }
    updete_ids();
}

void PhoneBook::remove(int *ids){
    int countremoved = int(_msize(ids)) / sizeof(ids[0]);
    Subscriber * buffer = new Subscriber[size - countremoved];
    int n = 0;
    bool flag;
    for(int k = 0; k< size; k++){
        flag = true;
        for(int m =0; m < countremoved; m++)
            if(ids[m] == this->ids[k]){
                flag = false;
                break;
            }
        if(flag)
            buffer[n++] = subscribers[k];
    }
    size -= countremoved;
    delete  [] subscribers;
    updete_ids();
}

void PhoneBook::findSurname(string surname, int *&ids){
    int size = int(_msize(ids)) / sizeof(ids[0]);
    int count = 0;
    for(int k = 0; k < size; k++){
        if(subscribers[ids[k]].getFullName().surname == surname)
            count++;
    }
    int* buffer = new int[count];
    count = 0;
    for(int k = 0; k < size; k++){
        if(subscribers[ids[k]].getFullName().surname == surname)
            buffer[count++] = ids[k];
    }
    delete[] ids;
    ids = buffer;
}

void PhoneBook::findName(string name, int*& ids){
    int size = int(_msize(ids)) / sizeof(ids[0]);
    int count = 0;
    for(int k = 0; k < size; k++){
        if(subscribers[ids[k]].getFullName().name == name)
            count++;
    }
    int* buffer = new int[count];
    count = 0;
    for(int k = 0; k < size; k++){
        if(subscribers[ids[k]].getFullName().name == name)
            buffer[count++] = ids[k];
    }
    delete[] ids;
    ids = buffer;
}

    void PhoneBook::findPhoneNumber(string phoneNumber, int*& ids){
    //int size = int(_msize(ids)) / sizeof(ids[0]);
    int count = 0;
    for(int k = 0; k < size; k++){
        if(subscribers[ids[k]].getPhoneNumber() == phoneNumber)
            count++;
    }
    int* buffer = new int[count];
    count = 0;
    for(int k = 0; k < size; k++){
        if(subscribers[ids[k]].getPhoneNumber() == phoneNumber)
            buffer[count++] = ids[k];
    }
    /*
    for(int k = 0; k < count; k++){
        cout << buffer[k] << " ";
    }
    cout << endl;
    */
    delete [] ids;
    ids = buffer;
    /*
    for(int k = 0; k < count; k++){
        cout << ids[k] << " ";
    }
    cout << endl;
    */
}

int *PhoneBook::getIds(){
    return ids;
}

Subscriber::Subscriber(){

}

Subscriber::Subscriber(FullName fullname, string phoneNumber, string comment){
    this->fullname= fullname;
    this->phoneNumber = phoneNumber;
    this->comment = comment;
}

void Subscriber::show(int regime){
    switch (regime) {
    case 0:
        cout << fullname.surname << " " << fullname.name << " "
             << fullname.patronymic << " " << phoneNumber;
        break;
    default:
        cout << fullname.surname << " " << fullname.name[0] << ". "
             << fullname.patronymic[0] << ". " << phoneNumber;
        break;
        break;
    }
    if(comment.size()) cout << " " << comment;
    cout << endl;
}

void FullName::create(string fullname){
    int pos1 = (int)fullname.find(' ') + 1;
    this->surname = fullname.substr(0, pos1);
    int pos2 = (int)fullname.find(' ', pos1) + 1;
    this->name = fullname.substr(pos1, pos2-pos1);
    this->patronymic = fullname.substr(pos2, fullname.size());
}
