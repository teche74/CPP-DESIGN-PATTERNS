#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    A() {cout<<"Constructor A called"<<endl;}
    void Call(){
        cout<<"function called"<<endl; 
    }
};

class B : public virtual A{
    public:
    B() : A() {cout<<"Constructor B called"<<endl;}
};

class C : public virtual A{
    public:
    C() : A() {cout<<"Constructor C called"<<endl;}
};

class D : public B, public C{
    public:
    D() : B() , C() {cout<<"Constructor D called"<<endl;}
};


int main(){
    D * obj = new D();
    
    // ambiguity faced by D because B and C both passing same function to D
    // obj->Call();
    
    // to solve this first option is specifically tells compiler which parent function we are calling 
    obj->B::Call();
    
    
    // second is to ensure that virtual inheritence of base class is done so that only single object is passed on to childs prevents conflict.
    obj->Call();
    return 0;
}
