#include<bits/stdc++.h>
using namespace std;

class Mother {
private:
    int weight, height;
    int face_length, face_bredth, nose_length, ear_length;
    string skin_color, eye_color;

public:
    Mother(int weight = 60, int height = 158, int face_length = 16, int face_bredth = 10, int nose_length = 5, int ear_length = 5, string skin_color = "clear yellowish", string eye_color = "black") {
        this->weight = weight;
        this->height = height;
        this->face_length = face_length;
        this->face_bredth = face_bredth;
        this->nose_length = nose_length;
        this->ear_length = ear_length;
        this->skin_color = skin_color;
        this->eye_color = eye_color;
    }

protected:
    int GetWeight() { return weight; }
    int GetHeight() { return height; }
    int GetFaceLength() { return face_length; }
    int GetFaceBredth() { return face_bredth; }
    int GetNoseLength() { return nose_length; }
    int GetEarLength() { return ear_length; }
    string GetSkinColor() { return skin_color; }
    string GetEyeColor() { return eye_color; }
};

class Father {
private:
    int weight, height;
    int face_length, face_bredth, nose_length, ear_length;
    string skin_color, eye_color;

public:
    Father(int weight = 68, int height = 162, int face_length = 18, int face_bredth = 7, int nose_length = 7, int ear_length = 7, string skin_color = "clear yellowish", string eye_color = "black") {
        this->weight = weight;
        this->height = height;
        this->face_length = face_length;
        this->face_bredth = face_bredth;
        this->nose_length = nose_length;
        this->ear_length = ear_length;
        this->skin_color = skin_color;
        this->eye_color = eye_color;
    }

protected:
    int GetWeight() { return weight; }
    int GetHeight() { return height; }
    int GetFaceLength() { return face_length; }
    int GetFaceBredth() { return face_bredth; }
    int GetNoseLength() { return nose_length; }
    int GetEarLength() { return ear_length; }
    string GetSkinColor() { return skin_color; }
    string GetEyeColor() { return eye_color; }
};

class Child : protected Mother, protected Father {
private:
    int weight, height;
    int face_length, face_bredth, nose_length, ear_length;
    string skin_color, eye_color;

public:
    Child(int weight = 52, int height = 148, int face_length = 10, int face_bredth = 5, int nose_length = 5, int ear_length = 5, string skin_color = "clear yellowish", string eye_color = "black") {
        this->weight = weight;
        this->height = height;
        this->face_length = face_length;
        this->face_bredth = face_bredth;
        this->nose_length = nose_length;
        this->ear_length = ear_length;
        this->skin_color = skin_color;
        this->eye_color = eye_color;
    }

    void GetChildAttributeDetails() {
        cout << "------ Child's Own Attributes ------" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Face (LxB): " << face_length << " x " << face_bredth << " cm" << endl;
        cout << "Nose Length: " << nose_length << " cm" << endl;
        cout << "Ear Length: " << ear_length << " cm" << endl;
        cout << "Skin Color: " << skin_color << endl;
        cout << "Eye Color: " << eye_color << endl;

        cout << "\n------ Inherited Attributes ------" << endl;
        cout << "[From Mother]" << endl;
        cout << "Eye Color: " << Mother::GetEyeColor() << endl;
        cout << "Skin Color: " << Mother::GetSkinColor() << endl;

        cout << "[From Father]" << endl;
        cout << "Nose Length: " << Father::GetNoseLength() << " cm" << endl;
        cout << "Height: " << Father::GetHeight() << " cm" << endl;
    }
};

int main() {
    Child c;
    c.GetChildAttributeDetails();  
    return 0;
}
