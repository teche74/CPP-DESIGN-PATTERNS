#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
    float real;
    float complex;
    
    public:  
    Complex(){
        real = 1.0;
        complex = 1.0;
    }
    
    Complex(float real , float complex){
        this->real = real;
        this->complex = complex;
    }
    
    Complex * operator +(Complex & obj){
        return new Complex(this->real  + obj.real , this->complex + obj.complex);
    }
    
    Complex * operator -(Complex & obj){
        return new Complex(this->real - obj.real , this->complex  - obj.complex);
    }
    
    void Show(){
        cout<<"\n Data : "<<this->real<<" + "<<this->complex<<"j "<<endl;
    }
};


int main(){
    Complex * obj = new Complex();
    Complex * obj2 = new Complex(1,2);
    
    Complex * res  = *obj + *obj2;
    
    res->Show();
    
    return 0;
}
