#include<iostream>
using namespace std;

enum Suit {clubs, diamonds, hearts, spades};
const int jack =11;
const int queen =12;
const int king =13;
const int ace =14;

class Card{

    private:
        int number;
        Suit suit;
    public:
        Card()
        {}
        Card(int n, Suit s): number(n), suit(s)
        {}
        void display();
        bool isEqual(Card c);
};
void Card::display()
{
}


int main(){

    return 0;
}

