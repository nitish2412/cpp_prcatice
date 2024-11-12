#include<iostream>
using namespace std;

template<typename T>
class MyVector{
    private:
        T *arr;
        int vec_size;
        int vec_capcity;

        void resize(int new_capcity){

            T *buffer =new T[new_capcity];
            for(int i=0;i<vec_size;i++){
                buffer[i]=arr[i];
            }
            delete []arr;
            arr=buffer;
            vec_capcity=new_capcity;

        }
    public:
        MyVector():vec_size(0),vec_capcity{2}{
            cout<<"Empty vector initialise\n";
            this->arr = new T[vec_capcity]; 
        }
        ~MyVector(){
            delete []arr;
            cout<<"destructor is called\n";
        }
        int getSize(){
            return this->vec_size;
        }
        T& operator[](int index){
            if(index>=vec_size){
                throw out_of_range("Index out of range!");
            }

            return arr[index];
        }
        int getCapcity(){
            return this->vec_capcity;
        }
        void push_back(const T& value){
            
            if(vec_size==vec_capcity){
                cout<<"array is full\n";
                resize(vec_capcity*2);
            }
            arr[vec_size++] = value;

        }

        void pop_back(){
            if(vec_size<=0){
                throw out_of_range("no element present to remove\n");
            }
            vec_size--;
        }

        // Function to get the first element
        T& front() {
            if (vec_size == 0) {
                throw std::out_of_range("Vector is empty!");
            }
            return arr[0];  // Return the first element
        }

        // Function to get the last element
        T& back() {
            if (vec_size == 0) {
                throw std::out_of_range("Vector is empty!");
            }
            return arr[vec_size - 1];  // Return the last element
        }
};
int main(){
    cout<<"Hello world\n";

    MyVector<int> vec;
    cout<<vec.getSize()<<"\n";
    cout<<vec.getCapcity()<<"\n";
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    cout<<vec.getSize()<<"\n";
    cout<<vec.getCapcity()<<"\n";
    vec.pop_back();
    cout << "Vector size: " << vec.getSize() << std::endl;     // Output: 3
    cout << "Vector capacity: " << vec.getCapcity() << std::endl;  // Output: 4 (capacity grows as needed)
    cout<<vec[0]<<"\n";
    cout<<vec[4]<<"\n";
    vec.front()=100;
    cout<<vec.front()<<"\n";
    cout<<vec.back()<<"\n";
    return 0; 
}