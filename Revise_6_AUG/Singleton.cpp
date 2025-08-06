#include<bits/stdc++.h>
#include<mutex>
using namespace std;


class Singleton{
    private:
    Singleton(){}
    
    static Singleton * instance;
    static mutex mtx;
    
    static Singleton * GetInstance(){
        if(instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr){
                instance = new Singleton();
            }
        }
        return instance;
    }
    
    public:
    friend void accessSingleton(const string&);
    Singleton(const Singleton &) = delete;
    Singleton * operator =(const Singleton &) = delete;
    
    void showMessage(const string& threadName) {
        cout << "Accessed by " << threadName << " | Address: " << this << endl;
    }
};

Singleton * Singleton :: instance = nullptr;
mutex Singleton::mtx;

void accessSingleton(const string& threadName) {
    Singleton* s = Singleton::GetInstance();
    s->showMessage(threadName);
}

int main() {
    thread t1(accessSingleton, "Thread 1");
    thread t2(accessSingleton, "Thread 2");
    thread t3(accessSingleton, "Thread 3");

    t1.join();
    t2.join();
    t3.join();

    return 0;
}


