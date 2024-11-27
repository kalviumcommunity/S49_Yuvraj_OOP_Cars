#include <iostream>
#include <string>
using namespace std;

// Abstract base class Vehicle (Open for extension)
class Vehicle {
    public:
        virtual void start() const = 0;  // Pure virtual functions to ensure extensibility
        virtual void stop() const = 0;
        virtual void drive() const = 0;
        virtual ~Vehicle() {}
};

// Car class inheriting from Vehicle (Extension of functionality)
class Car : public Vehicle {
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

        void stop() const override {
            cout << color << " " << make << " " << model << " is stopping." << endl;
        }

        void drive() const override {
            cout << color << " " << make << " " << model << " is driving." << endl;
        }
};

// Bike class inheriting from Vehicle (Extension of functionality)
class Bike : public Vehicle {
    private:
        string brand;
        string type;

    public:
        Bike(string b = "Unknown", string t = "Unknown") : brand(b), type(t) {}

        void start() const override {
            cout << brand << " " << type << " bike is starting." << endl;
        }

        void stop() const override {
            cout << brand << " " << type << " bike is stopping." << endl;
        }

        void drive() const override {
            cout << brand << " " << type << " bike is driving." << endl;
        }
};

// CarController class handling vehicles without modification
class CarController {
    private:
        Vehicle* vehicle;

    public:
        CarController(Vehicle* v) : vehicle(v) {}

        void operateVehicle() const {
            vehicle->start();
            vehicle->drive();
            vehicle->stop();
        }
};

int main() {
    // Creating Car and Bike objects
    Car car1("Red", "Toyota", "Corolla");
    Bike bike1("Yamaha", "Sport");

    // Using CarController to operate different types of vehicles
    CarController carController(&car1);
    CarController bikeController(&bike1);

    cout << "Operating Car:" << endl;
    carController.operateVehicle();

    cout << "\nOperating Bike:" << endl;
    bikeController.operateVehicle();

    return 0;
}
