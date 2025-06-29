#include<bits/stdc++.h>
using namespace std;


class ConsDes{
    int val;
    public:

    // Default Constructor
    ConsDes(){
        cout<<"this is default consturctor"<<endl;
    }

    // Parameterized Constructor
    ConsDes(int val){
        cout<<"This is Parameterized constructor with value : "<<val<<endl;
    }

    // Overloaded Constructor
    ConsDes(string val){
        cout<<"This is Overloaded Constructor with string value : "<<val<<endl;
    }

    // Deep Copy Constructor
    ConsDes(ConsDes & obj){
        this->val = obj.val;
    }

    // Inline Constructor
    ConsDes(int val) : val(val) {};


    // Destructor
    ~ConsDes(){
        cout<<"Destructor called"<<endl;
    }
};

int main(){
    return 0;
}