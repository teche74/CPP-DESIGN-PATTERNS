#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
    int id, contact , roll_no;
    public:
    string name, address, stream, course;


    void SetName(string value){
        this->name = value;
    }

    string GetName(){
        return this->name;
    }


    void SetAddress(string address){
        this->address = address;
    }

    string GetAddress(){
        return this->address;
    }

    void SetStream(string stream){
        this->stream = stream;
    }

    string GetStream(){
        return this->stream;
    }

    void SetCourse(string course){
        this->course = course;
    }

    string GetCourse(){
        return this->course;
    }

    void SetId(int id){
        this->id = id;
    }

    int GetId(){
        return this->id;
    }

    void SetContact(int contact){
        return this->contact;
    }

    
}

int main(){
    return 0;
}