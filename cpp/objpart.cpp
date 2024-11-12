#include<iostream>
using namespace std;

class Part{

    private:
        int modelnumber;
        int partnumber;
        float cost;
    public:
        void setPart(int mn, int pn, float cost){
            this->modelnumber = mn;
            this->partnumber =pn;
            this->cost = cost;
        }
        void showPart(){
            cout<<"Model Number:"<<this->modelnumber<<" Part Number:"<<this->partnumber<<" Cost $:"<<this->cost<<"\n";
        }
};
int main(){

    Part p1;
    p1.setPart(7668, 7383,654.3F);
    p1.showPart();

    return 0;
}