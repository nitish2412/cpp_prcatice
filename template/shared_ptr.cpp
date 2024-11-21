#include<iostream>
using namespace std;

template<typename T>
class SharedPtr{

    private:
        T* ptr;
        int *refcount;

        void release(){
            cout<<"Checking resource to release\n";
            if(refcount){
                --(*refcount);
                if(*refcount==0){
                    cout<<"Successfully released resource\n";
                    delete ptr;
                    delete refcount;
                }
            }
        }
    public:
        SharedPtr():ptr(nullptr), refcount(nullptr){
            cout<<"Default constructor is called\n";
        }
        
        SharedPtr(T* resource):ptr(resource), refcount(new int(1)){
            cout<<"Parameterized constructor is called\n";
        }
        // copy constructor
        SharedPtr(const SharedPtr<T> &other): ptr(other.ptr), refcount(other.refcount){
            cout<<"copy constructor is called\n";
            if(refcount){
                ++(*refcount);
            }
        }
        //copy assignment
        SharedPtr& operator=(const SharedPtr &other){
            cout<<"Copy assignment operator overloading is called\n";
            if(this!=&other){
            release();
            ptr=other.ptr;
            refcount=other.refcount;
            if(refcount){
                    ++(*refcount);
            }
            }
            return *this;
            
        }
        //move constructor;
        SharedPtr(SharedPtr<T> &&other):ptr(other.ptr), refcount(other.refcount){
            cout<<"Move constructor is called\n";
            other.ptr=nullptr;
            other.refcount=nullptr;
        }
        // move assignment 
        SharedPtr& operator=(SharedPtr<T> &&other){
            cout<<"Move assignment is called\n";
            if(this!=&other){
                release();
                ptr=other.ptr;
                refcount=other.refcount;
                other.ptr=nullptr;
                other.refcount=nullptr;
            }
            return *this;
        }
        void display(){
            cout<<*ptr<<" "<<*refcount<<"\n";
        }
        ~SharedPtr(){
            cout<<"Destructor is called for releasing resource\n";
            release();
        }
        //* operator overloading
        T& operator*() const{
            cout<<"* operator overloading\n";
            return *ptr;
        }

        // -> operator overloading
        T* operator->() const{
            return ptr;
        }

        //get raw pointer
        T* get() const{
            cout<<"get raw pointer\n";
            return ptr;
        }
        
        // check valid resource or not
        bool isValid() const{
            return ptr!=nullptr;
        }
        //get count of resource obj
        int getCount() const{
            if(refcount){
                return *refcount;
            }
            return 0;
        }



};

int main(){
    cout<<"Hello world\n";
    SharedPtr<int> ptr1;
    SharedPtr<int> ptr2(new int(10));
    SharedPtr<int> ptr3=new int(20); // if we make explicit SharedPtr(T* resource) function definition then it will give compiler error.
    SharedPtr<int> ptr4(ptr3);
    SharedPtr<int> ptr5(move(ptr2));
    ptr2=move(ptr3);
    //ptr3.display();
    ptr4.display();
    ptr2.display();
    //ptr3.display();
    cout<<*ptr2<<"\n";

    return 0;
}