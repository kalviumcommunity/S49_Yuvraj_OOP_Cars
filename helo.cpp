#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string color;
        string make;
        string model;
    
    public:
        Car(string c, string m, string mo) : color(c), make(m), model(mo) {}

        void start() {
            cout << this->color << " " << this->make << " " << this->model << " started." << endl;
        }

        void stop() {
            cout << this->color << " " << this->make << " " << this->model << " stopped." << endl;
        }

        void accelerate() {
            cout << this->color << " " << this->make << " " << this->model << " accelerating." << endl;
        }

        string getColor() const { return this->color; }
        string getMake() const { return this->make; }
        string getModel() const { return this->model; }
};

class Driver {
    private:
        string name;
        int age;
        Car car;
    
    public:
        Driver(string n, int a, Car c) : name(n), age(a), car(c) {}

        void drive() {
            cout << this->name << " is driving the " << this->car.getColor() << " " << this->car.getMake() << " " << this->car.getModel() << "." << endl;
            this->car.start();
            this->car.accelerate();
        }

        void park() {
            cout << this->name << " is parking the " << this->car.getColor() << " " << this->car.getMake() << " " << this->car.getModel() << "." << endl;
            this->car.stop();
        }

        string getName() const { return this->name; }
        int getAge() const { return this->age; }
};

int main() {
    Car myCar("Red", "Toyota", "Corolla");
    Driver driver("xyz", 30, myCar);
    driver.drive();
    driver.park();
    return 0;
}
