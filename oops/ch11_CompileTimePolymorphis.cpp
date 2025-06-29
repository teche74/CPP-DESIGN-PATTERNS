#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int real , image;


    public:
    Complex(int real , int imag){
        this->real = real;
        this->image = imag;
    }


    void show(){
        cout<<"Value : "<<this->real<<" + i"<<this->image<<endl;
    }


    // function overloading

    void add(int real){
        this->real += real;
    }

    void add(int real, int image){
        this->real += real;
        this->image += image;
    }

    // operator overloading

    Complex operator +(Complex & obj){
        return Complex(this->real + obj.real , this->image + obj.image);
    } 


    Complex operator -(Complex & obj){
        return Complex(this->real - obj.real , this->image + obj.image);
    }


};


int main(){
    return 0;
}