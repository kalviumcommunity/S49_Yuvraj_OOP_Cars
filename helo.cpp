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
            cout << color << " " << make << " " << model << " started." << endl;
        }

        void stop() {
            cout << color << " " << make << " " << model << " stopped." << endl;
        }

        void accelerate() {
            cout << color << " " << make << " " << model << " accelerating." << endl;
        }

        string getColor() const { return color; }
        string getMake() const { return make; }
        string getModel() const { return model; }
};

class Driver {
    private:
        string name;
        int age;
        Car car;
    
    public:
        Driver(string n, int a, Car c) : name(n), age(a), car(c) {}

        void drive() {
            cout << name << " is driving the " << car.getColor() << " " << car.getMake() << " " << car.getModel() << "." << endl;
            car.start();
            car.accelerate();
        }

        void park() {
            cout << name << " is parking the " << car.getColor() << " " << car.getMake() << " " << car.getModel() << "." << endl;
            car.stop();
        }

        string getName() const { return name; }
        int getAge() const { return age; }
};

int main() {
    Car myCar("Red", "Toyota", "Corolla");
    Driver driver("xyz", 30, myCar);
    driver.drive();
    driver.park();
    return 0;
}
