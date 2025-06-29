#include<bits/stdc++.h>
using namespace std;

class Base{
    private:
    int val1;
    string str1;

    protected:
    int val2;
    string str2;

    public:
    friend class FriendClass;
    int val3;
    string str3;


    int GetProtected(){
        cout<<"Protected Values : "<<val2 <<" : "<< str2<<endl;
    }

    int GetPrivate(){
        cout<<"Protected Values : "<<val1 <<" : "<<val2<<endl;
    }


    Base(int x, int y , int z , string s1 , string s2, string s3){
        this->val1 = x;
        this->val2 = y;
        this->val3 = z;
        this->str1 = s1;
        this->str2 = s2;
        this->str3 = s3;
    }
};

class FriendClass{
    public:

    void show(Base & obj){
        cout<<"Accessing private and protected member using FriendClass : "<<endl;
        
        cout<<"Private String : "<<obj.str1<<endl;
        cout<<"Protected String : "<<obj.str2<<endl;
    }

};

int main(){

    Base * bs = new Base(2, 3, 4, "temp1",  "temp2", "temp3");

    FriendClass * fc = new FriendClass();

    fc->show(*bs);
    return 0;
}