#include<bits/stdc++.h>

using namespace std;

class Static{
    public:
    static int object_count;

    static int GetObjectCount(){
        return object_count;
    }

    Static(){
        cout<<"Object created"<<endl;
        object_count++;
    }

    ~Static(){
        cout<<"Object Destroyed"<<endl;
        object_count--;
    }

};


int Static::object_count = 0;

int main(){
    Static * s1 = new Static();
    Static s2;

    cout<<"Total Object Created : "<<Static::object_count<<endl;
    Static::GetObjectCount();


    delete s1;
    cout<<"Total Object Created : "<<Static::object_count<<endl;
    return 0;
}