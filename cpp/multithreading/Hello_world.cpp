#include<iostream>
#include<thread>
using namespace std;

void hello(){
    cout<<"Concurrent hello world program\n";
    std::cout<<std::this_thread::get_id()<<"\n";
}

int main(){
    cout<<"Hello World\n";
    std::thread::id master_thread;
    unsigned long const hardware_threads=std::thread::hardware_concurrency();
    cout<<hardware_threads<<"\n";
    cout<<master_thread<<"\n";
    std::cout<<std::this_thread::get_id()<<"\n";
    thread t(hello);
    t.join();
}