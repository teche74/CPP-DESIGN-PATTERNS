#include<bits/stdc++.h>
using namespace std;


class AccessSpecifier{
    
    private:
    friend class FriendClass;
    int pri_member1;
    string pri_member2;
    bool pri_member3;
    
    protected:
    int pro_member1;
    string pro_member2;
    bool pro_member3;
    
    
    public:
    int pub_member1;
    string pub_member2;
    bool pub_member3;
    
    void GetprivateMember(){
        cout<<"value 1 : "<<this->pri_member1<<endl<<"value2 : "<<this->pri_member2<<endl<<"value3 : "<<this->pri_member3<<endl;
    }
    
    void GetPublicMember(){
        cout<<"value 1 : "<<this->pub_member1<<endl<<"value2 : "<<this->pub_member2<<endl<<"value3 : "<<this->pub_member3<<endl;
    }
    void GetProtectedMember(){
        cout<<"value 1 : "<<this->pro_member1<<endl<<"value2 : "<<this->pro_member2<<endl<<"value3 : "<<this->pro_member3<<endl;
    }
    
    void SetprivateMember(int value1 , string value2, bool value3){
        this->pri_member1 =value1;
        this->pri_member2 = value2;
        this->pri_member3 = value3;
    }
    
    
    void SetProtectedMemeber(int value1, string value2 , bool value3){
        this->pro_member1 =value1;
        this->pro_member2 = value2;
        this->pro_member3 = value3;
    }

    
    friend void SetValue(AccessSpecifier & obj , int value1 , string value2 , bool value3);
};


void SetValue(AccessSpecifier & obj , int val1 , string val2 , bool val3){
    obj.pri_member1 = val1;
    obj.pri_member2 = val2;
    obj.pri_member3 = val3;
}


class FriendClass{
    public:
    void ChangePrivateMemberOfAccessSpecifier(AccessSpecifier & e){
        e.pri_member1 = 10;
        e.pri_member2 = "xxeoew";
        e.pri_member3 = true;
    }
};


class Derived : public AccessSpecifier{
    public: 
    void SetNewValues(){
        pro_member1 = 10;
        pro_member2 = "derived_class";
        pro_member3 = true;
    }
};

int main(){
    AccessSpecifier * temp = new AccessSpecifier();

    // public access means it can accessed from outside or inside of class with no restrictions, it is used to expose data and functionality.
    temp->pub_member1 = 1;
    temp->pub_member2 = "value1";
    temp->pub_member3 = false;
    cout<<"Accessing Public Members"<<endl;
    temp->GetPublicMember();




    
    // private members is accessed via Getter/Setter functions of the object.
    cout<<"Accessing Private Members"<<endl;
    temp->SetprivateMember(2, "value2" , true);
    temp->GetprivateMember();
    
    // private members can only be accessed directly  via (friend function or friend class);

    // friend function
    cout<<"Friend Function Manipulate values"<<endl;
    SetValue(*temp , 3, "value3" , false);
    temp->GetprivateMember();

    // friend class
    cout<<"Friend class Manipulate values"<<endl;
    FriendClass fc;
    fc.ChangePrivateMemberOfAccessSpecifier(*temp);
    temp->GetprivateMember();




    // protected members can be access via Getter / Setter.
    cout<<"Accessed Protected Members"<<endl;
    temp->SetProtectedMemeber(3,"value none" , false);
    temp->GetProtectedMember();

    // protected Members can be accessed directly in derived class
    cout<<"Accessed Via Derived class internally"<<endl;
    Derived * temp2 = new Derived();
    temp2->SetNewValues();
    temp2->GetProtectedMember();



    delete temp;
    delete temp2;

    return 0;
}
