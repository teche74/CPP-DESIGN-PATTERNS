#include<bits/stdc++.h>
using namespace std;

class Car{
    private:
    int max_speed, torque, economy_range;
    string car_model, company;


    public:

    Car(int max_speed = 180, int torque = 200, int economy_range = 60, string car_model = "N/A" , string company = "Factory") : max_speed(max_speed), torque(torque), economy_range(economy_range), car_model(car_model), company(company){};

    int GetMaxSpeed(){
        return this->max_speed;
    }

    void SetMaxSpeed(int value = 120){
        this->max_speed = value;
    }

    int GetTorque(){
        return this->torque;
    }


    void SetTorque(int value){
        this->torque = value;
    }

    int GetEconomyRange(){
        return this->economy_range;
    }


    void SetEconomyRange(int value){
        this->economy_range = value;
    }

    string GetCarModel(){
        return this->car_model;
    }

    void SetCarModel(string model){
        this->car_model = model;
    }

    void SetCompany(string car_company){
        this->company = car_company;
    }

    string GetCarCompany(){
        return this->company;
    }

};


class MahindraXUV : protected Car{
    public:
    MahindraXUV(int max_speed = 120, int torque = 120, int economy_range = 60, string car_model = "XUV 700" , string company = "Mahindra") : Car(){
        this->SetMaxSpeed(max_speed);
        this->SetCarModel(car_model);
        this->SetEconomyRange(economy_range);
        this->SetTorque(torque);
        this->SetCompany(company);
    }

    void GetDetails(){
        cout<<"Car Details are listed below : "<<endl;
        cout<<"Company :"<<this->GetCarCompany()<<endl;
        cout<<"Car Model : "<<this->GetCarModel()<<endl; 
        cout<<"Max Speed : "<<this->GetMaxSpeed()<<endl;
        cout<<"Torque : "<<this->GetTorque()<<endl;
        cout<<"EconomyRange : "<<this->GetEconomyRange()<<endl;
    }
};



int main(){
    MahindraXUV * mx = new MahindraXUV();
    mx->GetDetails();


    delete mx;
    return 0;
}