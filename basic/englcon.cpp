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

        void add_distance(Distance,Distance);
};

void Distance::add_distance(Distance d1, Distance d2){

    inches=d1.inches+d2.inches;
    feet=0;
    if(inches>=12){
        inches-=12;
        feet++;
    }

    feet+=d1.feet + d2.feet;
}

int main(){

    Distance d1, d3;
    Distance d2(11, 6.25);

    d1.getDistance();
    d3.add_distance(d1,d2);

    cout<<"D1 distance: ";
    d1.showDistance();

    cout<<"D2 distance: ";
    d2.showDistance();

    cout<<"D3 distance: ";
    d3.showDistance();


    return 0;
}