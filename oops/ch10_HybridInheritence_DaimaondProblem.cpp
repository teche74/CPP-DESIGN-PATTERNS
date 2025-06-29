#include<bits/stdc++.h>

using namespace std;

class A{
    public:
    void func(){
        cout<<"function from Class A"<<endl;
    }

};

class B : public virtual A{
    public:
};


class C : public virtual A{
    public:
};


class D : public B,  public C{
    public:
};

int main(){
    D * obj = new D();
    obj->func(); // avoid ambiguity using virtual Inheritence.

    return 0;
}

