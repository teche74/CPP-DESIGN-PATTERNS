#include<bits./stdc++.h>
using namespace std;

// class is a template or blueprint design for specific group. 
class Student{
    private: // private access specifier helps give access limit to data members and members function. private means these values are only accessed via class getter/setter only 
    
    // data members
    int student_id , enrollment_number; 
    string contact_number, name, address;
    bool ispresent;

    public: // public access specifier allows to access these value from object creation or anyone can access it.

    // member functions
    // setter functions are the member functions to manipulate data values of data member.

    void SetStudentId(int id){
        this->student_id = id; // this operator is used to get refrence of current object;
    }

    void SetEnrollNnumber(int enroll_num){
        this->enrollment_number = enroll_num;
    }

    void SetContact(string contact){
        this->contact_number = contact;
    }

    void SetName(string firstname , string middle_name = ""  , string last_name = ""){
        this->name = firstname + (middle_name.empty() ? "" : middle_name) + (last_name.empty() ? "" : last_name);
    }

    void SetAddress(string address){
        this->address = address;
    }

    void SetCurrentlyPresent(bool value){
        this->ispresent = value;
    }


    // getter functions are used to extract values of data members.
    
    int GetStudentId(){
        return this->student_id;
    }

    int GetEnrollment(){
        return this->enrollment_number;
    }

    string GetContact(){
        return this->contact_number;
    }

    string GetName(){
        return this->name;
    }

    string GetAddress(){
        return this->address;
    }


    bool IsPresent(){
        return this->ispresent;
    }


    void GetDetails(){
        cout<<"Name : "<<this->GetName()<<endl;
        cout<<"Address : "<<this->GetAddress()<<endl;
        cout<<"StudentId : "<<this->GetStudentId()<<endl;
        cout<<"Contact : "<<this->GetContact()<<endl;
        cout<<"Enroll Id : "<<this->GetEnrollment()<<endl;
        cout<<"Present Today : "<<(this->IsPresent()  == true ? "Yes" : "No")<<endl;

        cout<<endl;
    }

}; // It states the end of scope of class;

int main(){


    // we can create objects in 2 different ways
    
    // 1 : direct object creation is a way in which we do not use new operator and memory is allocated to stack, and automatically managed when gets out of scope
    
    Student s1;
    s1.SetName("Virat");
    s1.SetAddress("Delhi Sector 204 , near XYZ mall");
    s1.SetStudentId(24);
    s1.SetContact("32993728499");
    s1.SetEnrollNnumber(219998973);
    s1.SetCurrentlyPresent(true);


    s1.GetDetails();



    // 2: Dynamic memory allocation using new operator this time memory allocated in heap, and we have to manually free memory using delete operator.

    Student * s2 = new Student();
    s2->SetName("Raman");
    s2->SetAddress("Delhi Sector 102 , near XYZ station ");
    s2->SetStudentId(21);
    s2->SetContact("32993728321");
    s2->SetEnrollNnumber(218594782);
    s2->SetCurrentlyPresent(false);


    s2->GetDetails();
    
    delete s2;  // free up the memory allocated.
    
    return 0;
}
