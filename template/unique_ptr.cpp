#include<iostream>
using namespace std;




template<typename T>
class MyUniquePtr{

    private:
        T *ptr;

    public:
        MyUniquePtr():ptr(nullptr){
            cout<<"default constructor is called\n";
        }
        MyUniquePtr(T* resource):ptr(resource){
            cout<<"Parameterized constructor is called\n";
            //cout<<*ptr<<"\n";
        }
        //copy constructor not allowed
        MyUniquePtr(MyUniquePtr & unq_pt) =delete;
        //copy assignment not allowed
        MyUniquePtr& operator=(const MyUniquePtr& unq_ptr) =delete;

        //move constructor
        MyUniquePtr(MyUniquePtr &&unq_ptr):ptr(unq_ptr.ptr){
            cout<<"Move constructor is called\n";
            //ptr=unq_ptr.ptr;
            unq_ptr.ptr=nullptr;
        }
        //move assignment
        MyUniquePtr& operator=(MyUniquePtr && unq_ptr){
            cout<<"move assignment operator is called\n";
            if(this == &unq_ptr){
                return *this;
            }
            delete ptr;
            ptr=unq_ptr.ptr;
            unq_ptr.ptr=nullptr;
            return *this;
        }
        // overload dereference
        T& operator *() const{

            return *ptr;
        }
        // overload -> operator

        T* operator->() const{
            return ptr;
        }
        void display(){
            if(ptr){
                cout<<*ptr<<"\n";
            }
            else{
                cout<<"ptr is null pointer\n";
            }
        }
        ~MyUniquePtr(){
            cout<<"destructor is called\n";
            delete ptr;
        }

};
class Example {
public:
    Example() {
        std::cout << "Example created\n";
    }

    ~Example() {
        std::cout << "Example destroyed\n";
    }

    void display() {
        std::cout << "Display method called\n";
    }
    
};

int main(){ 
    cout<<"Hello world\n";
    MyUniquePtr<int> ptr1;
    MyUniquePtr<int> ptr2(new int(10));
    MyUniquePtr<char> ptr3(new char('c'));
    //MyUniquePtr<int> ptr4(ptr2);  // compiler error copy not allowed
    //ptr1= ptr2;
    MyUniquePtr<int> ptr4=move(ptr2);
    ptr2=move(ptr4);
    cout << "Value: " << *ptr3 << '\n';
    //ptr3->display();
    //ptr2->disply();
    
    //class object
    MyUniquePtr<Example> ptr_1(new Example());

    // Access the managed resource
    ptr_1->display();
    (*ptr_1).display();
    return 0;
}