#include <iostream>
#include <string>
using namespace std;

// Segregated interfaces
class Startable {
    public:
        virtual void start() const = 0;
        virtual ~Startable() {}
};

class Drivable {
    public:
        virtual void drive() const = 0;
        virtual ~Drivable() {}
};

class Stoppable {
    public:
        virtual void stop() const = 0;
        virtual ~Stoppable() {}
};

// Car class implementing all interfaces
class Car : public Startable, public Drivable, public Stoppable {
    private:
        string color;
        string make;
        string model;

    public:
        Car(string c = "Unknown", string m = "Unknown", string mo = "Unknown") 
            : color(c), make(m), model(mo) {}

        void start() const override {
            cout << color << " " << make << " " << model << " is starting." << endl;
        }

        void drive() const override {
            cout << color << " " << make << " " << model << " is driving." << endl;
        }

        void stop() const override {
            cout << color << " " << make << " " << model << " is stopping." << endl;
        }
};

// Bicycle class implementing only Drivable and Stoppable interfaces
class Bicycle : public Drivable, public Stoppable {
    private:
        string brand;
        string type;

    public:
        Bicycle(string b = "Unknown", string t = "Unknown") 
            : brand(b), type(t) {}

        void drive() const override {
            cout << brand << " " << type << " bicycle is being pedaled." << endl;
        }

        void stop() const override {
            cout << brand << " " << type << " bicycle is stopping." << endl;
        }
};

// Controller class working with different segregated interfaces
class VehicleController {
    public:
        void operate(Startable* startable, Drivable* drivable, Stoppable* stoppable) const {
            if (startable) startable->start();
            if (drivable) drivable->drive();
            if (stoppable) stoppable->stop();
        }
};

int main() {
    // Creating Car and Bicycle objects
    Car car1("Red", "Toyota", "Corolla");
    Bicycle bike1("Yamaha", "Sport");

    // Creating controller
    VehicleController controller;

    cout << "Operating Car:" << endl;
    controller.operate(&car1, &car1, &car1);  // Car implements all three interfaces

    cout << "\nOperating Bicycle:" << endl;
    controller.operate(nullptr, &bike1, &bike1);  // Bicycle implements only Drivable and Stoppable

    return 0;
}
