#include<bits/stdc++.h>
using namespace std;


class Burger{
    public:
    virtual ~Burger(){};
    virtual void eat() = 0;
};

class VegBurger : public  Burger{
    public:
    virtual ~VegBurger(){};
    void eat() override{
        cout<<"Eating Veg Burger"<<endl;
    }
};

class NonVegBurger : public Burger{
    public:
    virtual ~NonVegBurger(){};
    void eat() override{
        cout<<"Eating NonVeg Burger"<<endl;
    }
};

class CheeseBurger : public Burger{
    public:
    virtual ~CheeseBurger(){};
    void eat() override{
        cout<<"Eating Cheese Burger"<<endl;
    }
};


class Chef{
    public:
    virtual ~ Chef(){};
    virtual unique_ptr<Burger>Cook() = 0;
};


class VegChef : public Chef{
    public:
    virtual ~VegChef(){};
    unique_ptr<Burger> Cook() override{
        return make_unique<VegBurger>(); 
    }
};

class NonVegChef : public Chef{
    public:
    virtual ~NonVegChef(){};
    unique_ptr<Burger> Cook() override{
        return make_unique<NonVegBurger>();
    }
};

class CheeseChef : public Chef{
    public:
    virtual ~CheeseChef(){};
    unique_ptr<Burger> Cook() override{
        return make_unique<CheeseBurger>();
    }
};

int main(){
    int input;
    while(true){
        cout<<"\n Order Menu : \n 1 : VegBurger \n 2 : Cheese \n 3 : Non-Veg Burger\n Please Enter number you want to Order : "<<endl;
        cin >> input;
        unique_ptr<Chef> chef =  nullptr;
        unique_ptr<Burger> user_order = nullptr;
        
        switch(input){
            case 1:
                chef = make_unique<VegChef>();
                user_order = chef->Cook();
                break;
            case 2:
                chef = make_unique<CheeseChef>(); 
                user_order = chef->Cook();
                break;
            default:
                chef = make_unique<NonVegChef>(); 
                user_order = chef->Cook();
        }
        
        user_order->eat();
        cout<<endl;
    }
    return 0;
}




