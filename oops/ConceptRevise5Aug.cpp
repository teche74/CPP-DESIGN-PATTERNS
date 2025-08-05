#include<bits/stdc++.h>
using namespace std;


class ClassElements{
    // private access specifier
    private:
    // private datta members
    int private_member1;
    string private_member2;
    
    // protected access specifier 
    protected:
    // protected data members
    int protected_member1;
    string protected_member2;
    
    // public access specifier 
    public:
    // public data member
    int public_member1;
    string public_member2;
    
    // static data member
    static int count_instance;

    
    // Setter member functions
    void set_private(int value1 , string value2){
        this->private_member1 = value1;
        this->private_member2 = value2;
    }
    
    void set_public(int value1 , string value2){
        this->public_member1 = value1;
        this->public_member2 = value2;
    }
    
    void set_protected(int value1 , string value2){
        this->protected_member1 = value1;
        this->protected_member2 = value2;
    }
    
    // Getter member functions
    void GetInfo()
    {
        cout<<"\n data \n"<<endl;
        cout<<"public members : "<<this->public_member1<<" "<<this->public_member2<<endl;
        cout<<"private members : "<<this->private_member1<<" "<<this->private_member2<<endl;
        cout<<"protected members : "<<this->protected_member1<<" "<<this->protected_member2<<endl;
    }
    
    // static member function
    static int GetInstanceCount(){
        return count_instance;
    }
    
    // friend function 
    friend void friend_function(ClassElements & obj);
    
    // friend class 
    friend class FriendClass;
    
    
    // constructors
    
    // default constructor
    ClassElements(){
        ClassElements::count_instance++;
        cout<<"Default Constructor called"<<endl;
    }
    
    // parameterized constructor or Overloaded constructor
    ClassElements(int val1 , int val2, int val3 , string str1, string str2, string str3){
        ClassElements::count_instance++;
        this->private_member1 = val1;
        this->private_member2 = str1;
        
        
        this->public_member1 = val2;
        this->public_member2 = str2;
        
        this->protected_member1 = val3;
        this->protected_member2 = str3;
    }
    
    // Inline Constructor
    ClassElements(int val1, int val2, int val3) : private_member1(val1) , public_member1(val2) , protected_member1(val3) {this->count_instance++;}
    
    // Copy Constructor
    ClassElements(ClassElements & obj){
        ClassElements::count_instance++;
        this->private_member1 = obj.private_member1;
        this->private_member2 = obj.private_member2;
        
        
        this->public_member1 = obj.public_member1;
        this->public_member2 = obj.public_member2;
        
        this->protected_member1 = obj.protected_member1;
        this->protected_member2 = obj.protected_member2; 
    }
    
    // Destructor
    ~ClassElements(){
        ClassElements::count_instance--;
        cout<<"Default Destructor Called"<<endl;
    }

};


void friend_function(ClassElements & obj){
    cout<<"\n Friend Function Access \n"<<endl;
    cout<<"public members : "<<obj.public_member1<<" "<<obj.public_member2<<endl;
    cout<<"private members : "<<obj.private_member1<<" "<<obj.private_member2<<endl;
    cout<<"protected members : "<<obj.protected_member1<<" "<<obj.protected_member2<<endl;
}


class FriendClass{
    public:
    
    void GetData(ClassElements & obj){
        cout<<"\n Friend Class Accessinf \n"<<endl;
        cout<<"public members : "<<obj.public_member1<<" "<<obj.public_member2<<endl;
        cout<<"private members : "<<obj.private_member1<<" "<<obj.private_member2<<endl;
        cout<<"protected members : "<<obj.protected_member1<<" "<<obj.protected_member2<<endl;
    }
};


// intializing static members
int ClassElements :: count_instance = 0;


int main(){
    // Object Instantiation : Dynamic (Heap Memory Allocation)
    ClassElements * obj = new ClassElements();
    
    // Object Instantiation : Static (Stack Memory Allocation)
    ClassElements obj2;
    
    
    // using Getter/Setter
    obj->set_public(1,"Public data");
    obj->GetInfo();
    
    obj2.set_private(3,"private data");
    obj2.GetInfo();
    
    
    // static member function call
    cout<<"Instance Created with reference to object1 : "<<ClassElements::GetInstanceCount()<<endl;
    
    // frined function access
    friend_function(obj2);
    
    // friend class access 
    FriendClass * fc = new FriendClass();
    fc->GetData(*obj);

    
    
    delete obj;
    delete fc;
    return 0;
}
