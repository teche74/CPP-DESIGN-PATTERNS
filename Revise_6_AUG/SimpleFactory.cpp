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


class BurgerFactory{
    private:
    unique_ptr<Burger> order = nullptr;
    public:
    
    BurgerFactory(){
        cout<<"Welcome Sir, Can u please give Order"<<endl;
    }
    
    static unique_ptr<Burger> Order(string preference){
        if(preference == "non_veg"){
            return make_unique<NonVegBurger>();
        }
        else if(preference == "cheese"){
            return make_unique<CheeseBurger>();
        }
        
        return make_unique<VegBurger>();
    }
};

int main(){
    int input;
    while(true){
        unique_ptr<BurgerFactory> chef =  make_unique<BurgerFactory>();
        cout<<"\n Order Menu : \n 1 : VegBurger \n 2 : Cheese \n 3 : Non-Veg Burger\n Please Enter number you want to Order : "<<endl;
        cin >> input;
        unique_ptr<Burger> user_order = nullptr;
        
        switch(input){
            case 1:
                user_order = chef->Order("veg");
                break;
            case 2:
                user_order = chef->Order("cheese");
                break;
            default:
                user_order = chef->Order("non_veg");
        }
        
        user_order->eat();
        cout<<endl;
    }
    return 0;
}
