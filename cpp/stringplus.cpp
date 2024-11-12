#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class String{

    private:
        enum {SZ=80};

        char str[SZ];
    public:
        String(){
            strcpy(str,"");
        }

        String(char s[]){
            strcpy(str,s);
        }
        void display() const{
            cout<<str;
        }

        String operator+(String ss) const{

                String temp;
                if(strlen(str)+ strlen(ss.str) < SZ){
                    strcpy(temp.str,str);
                    strcat(temp.str,ss.str);
                }
                else{
                    cout<<"Overflow string\n";
                    exit(1);
                }
                return temp;

        }

        bool operator==(String ss) const{
            return ( strcmp(str, ss.str)==0 ) ? true : false;
        }



};

int main(){

    String s1 = "\nMerry Christmas! ";
    String s2 = "Happy new year!";
    String s3;
    String s4 = "Happy new year!";

    s1.display();
    s2.display();
    s3.display();
    s3 = s1 + s2;
    s3.display();
    cout << endl;
    if(s2==s4)
        cout<<"Equal string\n";
    return 0;
}
