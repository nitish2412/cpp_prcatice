#include<iostream>
using namespace std;



class Foo{
    
    private:
        static int count;
    public:
        Foo(){
            this->count++;
        }
        int getCount(){
            return this->count;
        }

   
};

int Foo::count =0;


int main(){

    Foo f1;
    //create three objects
    cout << "count is " << f1.getCount() << endl;
    Foo f2,f3;
    cout << "count is " << f2.getCount() << endl;
    cout << "count is " << f3.getCount() << endl;
   
    return 0;
}

