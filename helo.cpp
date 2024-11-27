#include <iostream>
#include <string>
using namespace std;

// Abstract base class with virtual function
class Drivable {
    public:
        virtual void drive() = 0; // Pure virtual function
};

// Base class Vehicle (Single inheritance) inheriting from Drivable
class Vehicle : public Drivable {
    private:
        int wheels;

    public:
        Vehicle(int w = 4) : wheels(w) {}

        int getWheels() const { return wheels; }

        // Virtual function from Drivable class must be defined
        void drive() override {
            cout << "Driving a generic vehicle with " << wheels << " wheels." << endl;
        }
};

// Derived class Car (Single inheritance from Vehicle)
class Car : public Vehicle {
    private:
        string color;   
        string make;
        string model;

    public:
        static int totalCars;

        Car(string c = "Unknown", string m = "Unknown", string mo = "Unknown") 
            : Vehicle(4), color(c), make(m), model(mo) {
            totalCars++;
        }

        string getColor() const { return color; }
        string getMake() const { return make; }
        string getModel() const { return model; }
        void displayCarInfo() const {
            cout << color << " " << make << " " << model << endl;
        }
};

int Car::totalCars = 0;

// Class responsible only for driver-related data
class Driver {
    private:
        string name;
        int age;

    public:
        Driver(string n = "Unknown", int a = 0) : name(n), age(a) {}

        string getName() const { return name; }
        int getAge() const { return age; }

        void setName(const string& n) { name = n; }
        void setAge(int a) { age = a; }

        void displayDriverInfo() const {
            cout << "Driver Name: " << name << ", Age: " << age << endl;
        }
};

// Class responsible for controlling the car (Single Responsibility)
class CarController : public Drivable {
    private:
        Car car;
        Driver driver;

    public:
        CarController(const Car& c, const Driver& d) : car(c), driver(d) {}

        void drive() override {
            cout << driver.getName() << " is driving the ";
            car.displayCarInfo();
        }

        void start() {
            cout << driver.getName() << " is starting the ";
            car.displayCarInfo();
        }

        void stop() {
            cout << driver.getName() << " is stopping the ";
            car.displayCarInfo();
        }
};

int main() {
    // Create Cars and Drivers
    Car car1("Red", "Toyota", "Corolla");
    Driver driver1("Alice", 30);

    Car car2("Green", "Ford", "Focus");
    Driver driver2("Bob", 40);

    // Create CarControllers for managing operations
    CarController controller1(car1, driver1);
    CarController controller2(car2, driver2);

    // Operations
    controller1.drive();
    controller2.start();
    controller1.stop();

    return 0;
}
