#include<bits/stdc++.h>

using namespace std;

// SRP (Single Responsibility Principle): a class should follow a single responsibility with best practices.
class Rectangle{
    private:
    double length, breadth;

    public:
    Rectangle(double l, double b) : length(l), breadth(b) {}
    double GetLength() const {
        return this->length;
    }

    double GetBreadth() const {
        return this->breadth;
    }

    double GetArea() const {
        return this->length * this->breadth;
    }
};


// OCP (Open/Closed Principle): a class can be extended using inheritance, interface or abstract class, but we cannot modify the existing code.

class Shape{
    public:
    virtual double GetArea() const = 0;
    virtual ~Shape() {};
};

class RectangleShape : public Shape{
    Rectangle rect;
    public:
    RectangleShape(double w, double h) : rect(w, h) {}
    
    double GetArea() const override {
        return rect.GetArea();
    }
};

// ISP (Interface Segregation Principle): a class should not be forced to implement interfaces it does not use. Instead, we should have smaller, more specific interfaces.
class Printable {
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

class PrintableRectangle : public RectangleShape, public Printable {
public:
    PrintableRectangle(double w, double h) : RectangleShape(w, h) {}
    void print() const override {
        cout << "Rectangle area: " << GetArea() << endl;
    }
};

// DIP (Dependency Inversion Principle) : high level and low level shares common interface for loose coupling ans easy change behaviour.
class AreaPrinter {
public:
    void printArea(const Printable& shape) {
        shape.print();
    }
};

int main(){
    // LSP (Liskov Substitution Principle): a derived class should be substitutable for its base class without affecting the correctness of the program.
    Shape* shape = new RectangleShape(5, 10);
    cout << "Area of Rectangle: " << shape->GetArea() << endl;
    delete shape;

    PrintableRectangle pr(3, 7);
    AreaPrinter printer;
    printer.printArea(pr);

    return 0;
}