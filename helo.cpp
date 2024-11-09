#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle (Single inheritance)
class Vehicle {
    private:
        int wheels;

    public:
        Vehicle(int w = 4) : wheels(w) {}

        int getWheels() const { return wheels; }

        // Function overloading for polymorphism
        void displayVehicle() const {
            cout << "Vehicle with " << wheels << " wheels." << endl;
        }

        void displayVehicle(const string& message) const {  // Overloaded version
            cout << message << " - Vehicle with " << wheels << " wheels." << endl;
        }
};

// Derived class Car (Single inheritance from Vehicle)
class Car : public Vehicle {
    private:
        string color;   // Color is private to hide internal details
        string make;
        string model;

    protected:
        void startEngine() {
            cout << "Engine started." << endl;
        }

    public:
        static int totalCars;

        // Constructor Overloading
        Car() : Vehicle(), color("Unknown"), make("Unknown"), model("Unknown") {
            totalCars++;
        }

        Car(string c, string m, string mo) : Vehicle(4), color(c), make(m), model(mo) {
            totalCars++;
        }

        void start() {
            startEngine();
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

        void setColor(const string& c) { color = c; }
        void setMake(const string& m) { make = m; }
        void setModel(const string& mo) { model = mo; }

        static int getTotalCars() {
            return totalCars;
        }
};

int Car::totalCars = 0;

// Derived class Driver (Multilevel inheritance: Driver -> Car -> Vehicle)
class Driver : public Car {
    private:
        string name;
        int age;

    public:
        static int totalDrivers;

        Driver() : name("Unknown"), age(0), Car() {
            totalDrivers++;
        }

        Driver(string n, int a, const Car& c) : name(n), age(a), Car(c.getColor(), c.getMake(), c.getModel()) {
            totalDrivers++;
        }

        void drive() {
            cout << name << " is driving the " << getColor() << " " << getMake() << " " << getModel() << "." << endl;
            start();
            accelerate();
        }

        void park() {
            cout << name << " is parking the " << getColor() << " " << getMake() << " " << getModel() << "." << endl;
            stop();
        }

        string getName() const { return name; }
        int getAge() const { return age; }

        void setName(const string& n) { name = n; }
        void setAge(int a) { age = a; }

        static int getTotalDrivers() {
            return totalDrivers;
        }
};

int Driver::totalDrivers = 0;

int main() {
    const int numCars = 3;

    // Creating Car objects
    Car* cars = new Car[numCars] {
        Car("Red", "Toyota", "Corolla"),    // Parameterized constructor
        Car(),                             // Default constructor
        Car("Green", "Ford", "Focus")      // Parameterized constructor
    };

    // Creating Driver objects using multilevel inheritance
    Driver* drivers = new Driver[numCars] {
        Driver("Alice", 30, cars[0]),      // Parameterized constructor
        Driver(),                          // Default constructor
        Driver("Charlie", 35, cars[2])     // Parameterized constructor
    };

    for (int i = 0; i < numCars; ++i) {
        drivers[i].drive();
        drivers[i].park();
    }

    // Display information about the vehicle with overloaded functions
    Vehicle generalVehicle;
    generalVehicle.displayVehicle();                        // Calls displayVehicle without message
    generalVehicle.displayVehicle("Special Edition");       // Calls overloaded displayVehicle with message

    // Display the total number of cars and drivers
    cout << "Total number of cars: " << Car::getTotalCars() << endl;
    cout << "Total number of drivers: " << Driver::getTotalDrivers() << endl;

    // Free allocated memory
    delete[] cars;
    delete[] drivers;

    return 0;
}
