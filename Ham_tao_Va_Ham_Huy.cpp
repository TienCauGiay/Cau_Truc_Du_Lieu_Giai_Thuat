#include <iostream>
#include <cstring>
using namespace std;

class Sinh_Vien{
    private:
        char Name[100];
        char ID[20];
        char Address[100];
        int Age;
        float Mark;
    public:

        //Ham tao
        Sinh_Vien();
        Sinh_Vien(char *);
        Sinh_Vien(char *, char *);
        Sinh_Vien(char *, char *, char *, int, float );

        void ShowInfo();

        //Ham thay doi thong tin
        void setID(char *);
        void setName(char *);
        void setAddress(char *);
        void setAge(int);
        void setMark(float);

        // Ham lay thong tin ra
        int getAge();
        float getMark();
        char* getID();
        char* getName();
        char* getAddress();

};

Sinh_Vien::Sinh_Vien(){
    this->Name[0] = '\0';
    this->ID[0] = '\0';
    this->Address[0] = '\0';
    this->Age = 0;
    this->Mark = 0;
}

Sinh_Vien::Sinh_Vien(char *Name){
    strcpy_s(this->Name, 99, Name);
    this->ID[0] = '\0';
    this->Address[0] = '\0';
    this->Age = 0;
    this->Mark = 0;
}
Sinh_Vien::Sinh_Vien(char * Name, char *ID){
    strcpy_s(this->Name, 99, Name);
    strcpy_s(this->ID, 19, ID);
    this->Address[0] = '\0';
    this->Age = 0;
    this->Mark = 0;
}

Sinh_Vien::Sinh_Vien(char * Name, char *ID, char *Address, int Age, float Mark){
    strcpy_s(this->Name, 99, Name);
    strcpy_s(this->ID, 19, ID);
    strcpy_s(this->Address, 99, Address);
    this->Age = Age;
    this->Mark = Mark;
}

void Sinh_Vien::ShowInfo(){
    cout << "========== Show Info ==========" << endl;
    cout << "Name: " << Name << endl;
    cout << "ID: " << ID << endl;
    cout << "Address: " << Address << endl;
    cout << "Age: " << Age << endl;
    cout << "Mark: " << Mark << endl;
    cout << "================================" << endl;
}

void Sinh_Vien::setID(char * id){
    strcpy_s(this->ID, 19, id);
}

void Sinh_Vien::setName(char * name){
    strcpy_s(this->Name, 99, name);
}

void Sinh_Vien::setAddress(char * Addr){
    strcpy_s(this->Address, 99, Addr);
}

void Sinh_Vien::setAge(int age){
    this->Age = age;
}

void Sinh_Vien::setMark(float mark){
    this->Mark = mark;
}

int Sinh_Vien::getAge(){
    return this->Age;
}

float Sinh_Vien::getMark(){
    return this->Mark;
}

char* Sinh_Vien::getID(){
    return this->ID;
}

char* Sinh_Vien::getName(){
    return this->Name;
}

char* Sinh_Vien::getAddress(){
    return this->Address;
}

int main(){
    char *Name = new char[100];
    strcpy_s(Name, 99, "Bui Ngoc Tien");
    char *ID = new char[20];
    strcpy_s(ID, 19, "TYL17051908");
    char *Address = new char[100];
    strcpy_s(Address, 99, "Cau Giay Ha Noi");
    Sinh_Vien a;
    // Sinh_Vien a1(Name);
    // Sinh_Vien a2(Name, ID);
    // Sinh_Vien a3(Name, ID, Address, 20, 9.5);

    // a.ShowInfo();
    // a1.ShowInfo();
    // a2.ShowInfo();
    // a3.ShowInfo();

    a.setName(Name);
    a.setAge(20);
    a.setAddress(Address);
    a.setID(ID);
    a.setMark(9.6);

    a.ShowInfo();

    return 0;
}