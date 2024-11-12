#include <iostream>
using namespace std;
int main(){

    int number;
    cout << "Please enter an integer: ";
    cin >> number;
    cout << uppercase<< " octal \t decimal \t hexadecimal\n "<< oct << number << "\t "<< dec << number << "\t " << hex << number << endl;
    
    double x = 12.0;
    cout.precision(2);
    // Precision 2
    cout << " By default: " << x << endl;
    cout << " showpoint: " << showpoint << x << endl;
    cout << " fixed: " << fixed << x << endl;
    cout << " scientific: " << scientific << x << endl;

    int number = ' ';
    cout << "The white space code is as follows: " << number << endl;
    char ch;
    string prompt = "\nPlease enter a character followed by " " <return>: ";
    cout << prompt;
    cin >> ch;
    number = ch;
    // Read a character
    cout << "The character " << ch << " has code" << number << endl;
    //cout << uppercase << " octal decimal hexadecimal\n " << oct << setw(8) << number << dec << setw(8) << number << hex << setw(8) << number << endl;
    
    return 0;
}