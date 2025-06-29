#include<bits/stdc++.h>
using namespace std;

class Father{
    public:
    int pen;
    inline Father(int val ) : pen(val){};


    virtual int GetPenCount(){
        cout<<"Father has : "<<pen<<" Pen"<<endl;
        return this->pen;
    }

};


class Child : public Father{
    public:

    Child(int val) : Father(val) {}; 
    
    int GetPenCount() override{
        cout<<"Child has : "<<pen<<" Pen"<<endl;
        return this->pen;
    }
};


int main(){
    Father * obj = new Child(2);
    obj->GetPenCount();

    obj = new Father(3);
    obj->GetPenCount();


    return 0;
}