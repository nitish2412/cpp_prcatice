#include<iostream>
#include<cstring>

using namespace std;

class MyString{
    private:
        char *res;
        size_t len;
    public:
        MyString():res{nullptr},len{0}{
            cout<<"default constructor is called \n";
        }

        //parameterized constructor
        MyString(const char* data){

            cout<<"parameterized constructor is called \n";
            if(data==nullptr){
                len=0;
                res=new char[1];
                res[0]='\0';
            }
            else{
                len=strlen(data);
                res= new char[len+1];
                strcpy(res,data);
            }
        }

        //copy constructor
        MyString(const MyString &source){

            len=source.len;
            res=new char[len+1];
            strcpy(res,source.res);
            cout<<"copy constructor is called\n";
        }

        // Equality Operator
        bool operator==(const MyString& other) const {
            cout<<"equality opearator is called\n";
            return len == other.len && std::strcmp(res, other.res) == 0;
        }

        // Copy assignment operator
        MyString &operator=(const MyString &source){
            if(*this== source){
                return *this;
            }
            delete [] res;
            len=source.len;
            res=new char[len+1];
            strcpy(res,source.res);
            return *this;
        }

        //move constructor
        MyString(MyString &&other):res(other.res), len(other.len){
            other.res=nullptr;
            other.len=0;
            cout << "Moved constructor is called"<<std::endl;
        }

        // Move assignment operator
        MyString& operator=(MyString&& other){
            if(this==&other){
                return *this;
            }
            delete []res;
            res=other.res;
            len=other.len;
            other.res=nullptr;
            other.len=0;
            cout<<"move assignment operator is called.\n";
            return *this;
        }
        ~MyString(){
            delete []res;
            //cout<<"destructor is called\n";
        }
        void display() const{
            cout<<res<<"\n";
        }

};

int main(){
    cout<<"hello world!!\n";

    MyString str1;
    MyString str2("Hello");
    MyString str3="World";
    MyString str4(str3);
    MyString str5=str4;
    MyString str6=move(str3);
    str5.display();
    str5=move(str2);
    str5.display();

    //str2.display();

    return 0;
}