#include<iostream>
using namespace std;


class Counter{

    private:
        unsigned int count;
    public:
        Counter():count(0){
            cout<<"Initialize constructor\n";
        }
        void inc_count(){
            //cout<<"incrementin counter value\n";
            this->count++;
        }
        int get_count(){
            //cout<<"return counter value\n";
            return this->count;
        }

};
int main(){

    Counter c1,c2;

    cout<<"C1:"<<c1.get_count()<<"\n";
    cout<<"C2:"<<c2.get_count()<<"\n";

    c1.inc_count();
    c2.inc_count();
    c2.inc_count();
    cout<<"C1:"<<c1.get_count()<<"\n";
    cout<<"C2:"<<c2.get_count()<<"\n";



    return 0;
}