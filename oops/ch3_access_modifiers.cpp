#include <bits/stdc++.h>
using namespace std;

class AccessModifiers
{
private:
    int private_value;
    string private_string;

protected:
    int protected_value;
    string protected_string;

public:
    int public_value;
    string public_string;

    friend void friend_function(int, AccessModifiers &);

    void GetPublic()
    {
        cout << "Values are : " << public_value << ", " << public_string << endl;
    }

    void SetPublic(int int_value, string str_value)
    {
        this->public_value = int_value;
        this->public_string = str_value;
    }

    void GetPrivate()
    {
        cout << "Values are : " << private_value << ", " << private_string << endl;
    }

    void SetPrivate(int int_value, string str_value)
    {
        this->private_value = int_value;
        this->private_string = str_value;
    }

    void GetProtected()
    {
        cout << "Values are : " << protected_value << ", " << protected_string << endl;
    }

    void SetProtected(int int_value, string str_value)
    {
        this->protected_value = int_value;
        this->protected_string = str_value;
    }
};

class Child : public AccessModifiers
{
public:
};

void friend_function(int val, AccessModifiers &obj)
{
    cout << "I am friend function and I can access {"
         << (val == 0 ? "public" : val == 1 ? "private"
                                            : "protected")
         << "} members" << endl;

    switch (val)
    {
    case 0:
        cout << "int : " << obj.public_value << endl;
        cout << "string : " << obj.public_string << endl;
        break;
    case 1:
        cout << "int : " << obj.private_value << endl;
        cout << "string : " << obj.private_string << endl;
        break;
    default:
        cout << "int : " << obj.protected_value << endl;
        cout << "string : " << obj.protected_string << endl;
        break;
    }
}

int main()
{
    AccessModifiers *am = new AccessModifiers();
    Child *ch = new Child();

    am->SetPublic(1, "string");
    cout << "Values : " << am->public_value << ", " << am->public_string << endl;
    am->GetPublic();
    friend_function(0, *am);

    am->SetProtected(2, "string 2");
    am->GetProtected();
    friend_function(2, *am);
    ch->SetProtected(22, "child's protected");
    ch->GetProtected();

    am->SetPrivate(3, "string 3");
    am->GetPrivate();
    friend_function(1, *am);
    ch->SetPrivate(33, "child's private");
    ch->GetPrivate();

    delete am;
    delete ch;
    return 0;
}
