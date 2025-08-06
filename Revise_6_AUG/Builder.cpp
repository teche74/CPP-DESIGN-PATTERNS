#include <iostream>
#include <string>
using namespace std;

class Phone {
public:
    int phone_id, model_number;
    string company, model;
    int ram, camera, battery_cap;

    void GetInfo() {
        cout << "Phone ID: " << phone_id << endl;
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Model Number: " << model_number << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Camera: " << camera << " MP" << endl;
        cout << "Battery: " << battery_cap << " mAh" << endl;
    }
};

class PhoneBuilder {
private:
    Phone phone;
public:
    PhoneBuilder& SetPhoneId(int id) {
        phone.phone_id = id;
        return *this;
    }

    PhoneBuilder& SetCompany(string company) {
        phone.company = company;
        return *this;
    }

    PhoneBuilder& SetModel(string model) {
        phone.model = model;
        return *this;
    }

    PhoneBuilder& SetModelNumber(int num) {
        phone.model_number = num;
        return *this;
    }

    PhoneBuilder& SetRam(int ram) {
        phone.ram = ram;
        return *this;
    }

    PhoneBuilder& SetCamera(int cam) {
        phone.camera = cam;
        return *this;
    }

    PhoneBuilder& SetBatteryCap(int cap) {
        phone.battery_cap = cap;
        return *this;
    }

    Phone Build() {
        return phone;
    }
};

int main() {
    Phone phone = PhoneBuilder()
                    .SetPhoneId(101)
                    .SetCompany("Samsung")
                    .SetModel("Galaxy M51")
                    .SetModelNumber(2025)
                    .SetRam(8)
                    .SetCamera(64)
                    .SetBatteryCap(7000)
                    .Build();

    phone.GetInfo();
    return 0;
}
