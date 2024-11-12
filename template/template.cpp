#include<iostream>

using namespace std;

//Function Template with single Parameters
template<typename T>
T add(T a, T b){
    return a+b;
}

//Function Template with Multiple Parameters
template <typename T1, typename T2>
T1 multiply(T1 a, T2 b) {
    return a * b;
}

template <typename T>
void swapValues(T& a, T& b) {  // Passing by reference
    T temp = a;
    a = b;
    b = temp;
}


int main(){
    cout<<"Hello World\n";
    float res=add(4.0,6.6);
    cout<<res<<"\n";
    cout << add(3, 4) << endl;        // Output: 7 (int)
    cout << add(2.5, 3.0) << endl; 
    cout << add<int>(5, 6) << endl;  // Output: 11

    cout << multiply(3, 4) << endl;        // Output: 7 (int)
    cout << multiply(2.5, 3.0) << endl; 
    cout << multiply<int>(5, 6) << endl;  // Output: 11

     int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);  // Swap by reference
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}