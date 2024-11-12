#include<iostream>
#include <cstring>
using namespace std;

class MyString{

    private:
        char *str;
    public:
        MyString();
        MyString(char *val);
        MyString(const MyString &source);
        char *getStr();

};

MyString::MyString():str(nullptr){
    cout<<"default constructor\n";

    this->str=new char[1];
    this->str[0]='\0';
}

MyString::MyString(char *val){
    cout<<"single argument constructor is called\n";
    if(val==nullptr){
        this->str=new char[1];
        this->str[0]='\0';
    }
    else{
        this->str=new char[strlen(val)+1];
        strcpy(str,val);
        this->str[strlen(val)]='\0';
    }
}

MyString::MyString(const MyString &source){

    cout<<"Copy constructor is called\n";
    this->str= new char[strlen(source.str)+1];
    strcpy(this->str,source.str);
    this->str[strlen(source.str)]='\0';
}

char* MyString::getStr(){
    return this->str;
}
int main(){
    cout<<"Hello World\n";
    MyString s;
    char temp[] = "Hello";
    MyString s2(temp);
    char *temp2 =s2.getStr();

    cout<<strlen(temp2);

    MyString s3(s2);

    MyString s4="New string";
    char *temp3 =s4.getStr();
    cout<<strlen(temp3);
    return 0;
}