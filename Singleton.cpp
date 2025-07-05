#include<bits/stdc++.h>

using namespace std;

class Singleton{
    private:
    static Singleton * instance;
        
    Singleton(){};
    
    public:
    static Singleton * GetInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }

};

Singleton * Singleton :: instance = nullptr;

int main(){
    return 0;
}