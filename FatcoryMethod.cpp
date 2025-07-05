#include<bits/stdc++.h>
using namespace std;

class Burger{ 
    public:
    virtual void Eat() = 0;

    virtual ~Burger(){}
};

class VegBurger : public Burger{
    public:
    void Eat() override{
        cout<<"Eating Veg-Burger"<<endl;
    }
};

class Non_VegBurger : public Burger{
    public:
    void Eat() override{
        cout<<"Eating NonVeg-Burger "<<endl;
    }
};


class Pizza{ 
    public:
    virtual void Eat() = 0;
    virtual ~Pizza(){};
};

class VegPizza : public Pizza{
    public:
    void Eat() override{
        cout<<"Eating Veg-Pizza"<<endl;
    }
};

class Non_VegPizza : public Pizza{
    public:
    void Eat() override{
        cout<<"Eating NonVeg-Pizza "<<endl;
    }
};


class Chef{
    public:
    virtual Burger * OrderBurger() = 0;
    virtual ~Chef(){};
};

class VegChef : public Chef{
    public:
    Burger * OrderBurger() override{
        return new VegBurger();
    }
};

class NonVegChef : public Chef{
    public:
    Burger * OrderBurger() override{
        return new Non_VegBurger();
    }
};


int main(){
    string choice;
    Chef * chef = nullptr;

    cout<<"Enter Prefernce : ";
    cin>>choice;

    transform(choice.begin() , choice.end() , choice.begin() , [](char ch){
        return tolower(ch);
    });

    if( choice == "veg"){
        chef = new VegChef();
    }
    else{
        chef = new NonVegChef();
    }

    Burger * burger = chef->OrderBurger();

    burger->Eat();

    delete burger;
    delete chef;

    return 0;
}

