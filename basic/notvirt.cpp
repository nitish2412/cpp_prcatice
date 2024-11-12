#include<iostream>
using namespace std;

class Base{

    public:
        void show(){
            cout<<"Base class\n";
        }
};

class Derv1:public Base{

    public:
        void show(){
            cout<<"Derived 1 class\n";
        }
};

class Derv2:public Base{

    public:
        void show(){
            cout<<"Derived 2 class\n";
        }
};




int main(){

    Derv1 d1;
    Derv2 d2;
    Base *ptr;
    ptr =&d1;
    ptr->show();
    ptr=&d2;
    ptr->show();

    return 0;
}