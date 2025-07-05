#include<bits/stdc++.h>
#include<memory>
using namespace std;

class Pizza{
    public:
    virtual void Eat() = 0;
    virtual ~Pizza(){};
};

class VegPizza : public Pizza{
    public:
    void Eat() override{
        cout<<"Eating Veg - Pizza"<<endl;
    }
};

class NonVegPizza : public Pizza{
    public:
    void Eat() override{
        cout<<"Eating NonVeg - Pizza"<<endl;
    }
};


class Burger{
    public:
    virtual void Eat() = 0;
    virtual ~Burger(){}; 
};

class VegBurger : public Burger{
    public:
    void Eat() override{
        cout<<"Eating Veg - Burger"<<endl;
    }
};

class NonVegBurger : public Burger{
    public:
    void Eat() override{
        cout<<"Eating NonVeg - Burger"<<endl;
    }
};


class Chef{
    public:
    virtual  unique_ptr<Burger> OrderBurger()= 0;
    virtual  unique_ptr<Pizza> OrderPizza()= 0;

    virtual ~ Chef(){}; 
};

class VegChef : public Chef{
    public:
    unique_ptr<Burger> OrderBurger(){
        return make_unique<VegBurger>(); 
    }

    unique_ptr<Pizza> OrderPizza(){
        return make_unique<VegPizza>();
    } 
};

class NonVegChef : public Chef{
    public:
    unique_ptr<Burger> OrderBurger(){
        return make_unique<NonVegBurger>(); 
    }

    unique_ptr<Pizza> OrderPizza(){
        return make_unique<NonVegPizza>();
    } 
};

int main(){

    string pref = "";

    cout<<"Order Preference : (Veg / NonVeg)";

    cin>>pref;

    transform(pref.begin(), pref.end() , pref.begin() , [&](char ch){
        return tolower(ch);
    });

    unique_ptr<Chef> chef;
    
    if(pref == "veg"){
        chef = make_unique<VegChef>();
    }
    else{
        chef = make_unique<NonVegChef>();
    }

    unique_ptr<Burger> my_burger = chef->OrderBurger();
    unique_ptr<Pizza> my_pizza = chef->OrderPizza();

    my_burger->Eat();
    my_pizza->Eat();
    return 0;
}