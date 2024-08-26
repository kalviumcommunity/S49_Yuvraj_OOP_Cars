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
    const int numCars = 3; // Define the size of the array
    Car cars[numCars] = {
        Car("Red", "Toyota", "Corolla"),
        Car("Blue", "Honda", "Civic"),
        Car("Green", "Ford", "Focus")
    };

    const int numDrivers = 3;
    Driver drivers[numDrivers] = {
        Driver("Alice", 30, cars[0]),
        Driver("Bob", 25, cars[1]),
        Driver("Charlie", 35, cars[2])
    };

    for (int i = 0; i < numDrivers; ++i) {
        drivers[i].drive();
        drivers[i].park();
    }

    return 0;
}
