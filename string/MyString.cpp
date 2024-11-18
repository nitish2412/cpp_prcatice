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

        // Equality Operator implemented
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

        //string concatination with +
        MyString operator+(const MyString &other) const{

            cout<<"String concatination called!!!!\n";
            MyString result;
            result.len=this->len+other.len;
            result.res=new char[result.len+1];
            strcpy(result.res,res);
            strcat(result.res,other.res);

            return result;
        }


        //string concatination with +=
        MyString& operator+=(const MyString &other){
            
            cout<<"string concatination with +=!!!!!!!!!!!!!!\n";
            len+=other.len;
            char* newdata=new char[len+1];
            strcpy(newdata,res);
            strcat(newdata,other.res);
            delete []res;
            res=newdata;

            return *this;
        }

        //indexing operator with modifiable
        char & operator[](size_t index){
            cout<<"Non const version of index operator is called\n";
            return res[index];
        }

        //indexing operator with readonly
        const char & operator[](size_t index) const{
             cout<<"Const version of index operator is called\n";
            return res[index];
        }
        //Stream Insertion Operator (<<)

        ostream& operator<<(std::ostream& os) {
            os << this->res;  // Access data via getter
            return os;
        }
        const char* getdata() const{
            return res;
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
    MyString str11("Hello, ");
    MyString str12("World!");
    MyString str13;
    str13=str11+str12;
    str13.display();

    str13+=str11;
    str13.display();

    MyString str_index("nitish");
    str_index[0]='m';
    str_index.display();

    const MyString str_const_index("World");
    char a=str_const_index[0];
    //str_const_index[0]='t';
    str_const_index.display();
    //cout<<str_const_index;

    return 0;
}