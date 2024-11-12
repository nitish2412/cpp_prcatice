
//This is simple program for creating a object and accessing method.
#include<iostream>
using namespace std;

class SmallObj{
    
    private:
        int somedata;
    public:
        void setData(int d){
            somedata=d;
        }
        void showData(){
            cout<<"Data:"<<somedata<<"\n";
        }

};

int main(){
    cout<<"hello world\n";
    SmallObj obj1, obj2;
    obj1.setData(100);
    obj2.setData(676);

    obj1.showData();
    obj2.showData();

    return 0;
}
