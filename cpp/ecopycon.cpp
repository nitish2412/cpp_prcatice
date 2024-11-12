#include<iostream>

using namespace std;

class Distance{

    private:
        int feet;
        float inches;
    public:
        Distance():feet(0),inches(0.0)
        {
            cout<<"constructor called:\n";
        }

        Distance(int ft, float in): feet(ft), inches(in)
        {}
        void getDistance(){

            cout<<"\nEnter Feet: ";
            cin>>feet;
            cout<<"Enter inches: ";
            cin>>inches;
        }

        void showDistance(){

            cout<<"Feet:"<<this->feet<<" Inches: "<<this->inches<<"\n";
        }

};

int main(){

    Distance d1(11,6.25);
    Distance d2(d1);
    Distance d3=d1;


    cout<<"D1 distance: ";
    d1.showDistance();

    cout<<"D2 distance: ";
    d2.showDistance();

    cout<<"D3 distance: ";
    d3.showDistance();


    return 0;
}