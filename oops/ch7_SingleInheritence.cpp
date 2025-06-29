#include<bits/stdc++.h>
using namespace std;


class Base{
    private:
    int pri_val;

    protected:
    int pro_val;
    
    public:
    int pub_val;

    Base(int x, int y , int z){
        this->pub_val = x;
        this->pri_val = y;
        this->pro_val = z;
    }
    
    int GetPrivate(){
        return this->pri_val;
    }

    void SetPrivate(int val){
        this->pri_val = val;
    }

    void SetProtected(int val){
        this->pro_val = val;
    }

    int GetProtected(){
        return pro_val;
    }
};

class Derived : public Base{
    // when inherited only public and (protected of Direct Parent (only accessed direclty inside class)) can be accessed , private member can be accessed via getter/setter only;  
    public:

    Derived(int x , int y, int z) : Base(x,y,z) {};

};

int main(){
    Derived * dv = new Derived(1,2,3);
    // public value and protected value can be directly accessed;
    cout<<dv->pub_val<<endl;
    cout<<dv->GetProtected()<<endl;
    cout<<dv->GetPrivate();
    return 0;
}