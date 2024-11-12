#include<iostream>
using namespace std;

class Base{

    public:
        virtual void show()=0;
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

    //Base b1;
    Derv1 d1;
    Derv2 d2;
    Base *arr[2];
    arr[0] =&d1;
    arr[0]->show();
    arr[1]=&d2;
    arr[1]->show();

    return 0;
}