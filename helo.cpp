#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string color;
        string make;
        string model;
    
    public:
        // Static variable to keep track of the total number of cars
        static int totalCars;

        Car(string c, string m, string mo) : color(c), make(m), model(mo) {
            // Increment the total car count whenever a car object is created
            totalCars++;
        }

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

// Initialize the static variable for total cars
int Car::totalCars = 0;

class Driver {
    private:
        string name;
        int age;
        Car car;

    public:
        // Static variable to keep track of the total number of drivers
        static int totalDrivers;

        Driver(string n, int a, Car c) : name(n), age(a), car(c) {
            // Increment the total driver count whenever a driver object is created
            totalDrivers++;
        }

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

// Initialize the static variable for total drivers
int Driver::totalDrivers = 0;

int main() {
    const int numCars = 3; // Define the size of the array

    // Dynamically allocate memory for cars array
    Car* cars = new Car[numCars] {
        Car("Red", "Toyota", "Corolla"),
        Car("Blue", "Honda", "Civic"),
        Car("Green", "Ford", "Focus")
    };

    // Dynamically allocate memory for drivers array
    Driver* drivers = new Driver[numCars] {
        Driver("Alice", 30, cars[0]),
        Driver("Bob", 25, cars[1]),
        Driver("Charlie", 35, cars[2])
    };

    for (int i = 0; i < numCars; ++i) {
        drivers[i].drive();
        drivers[i].park();
    }

    // Display the total number of cars and drivers created
    cout << "Total number of cars: " << Car::totalCars << endl;
    cout << "Total number of drivers: " << Driver::totalDrivers << endl;

    // Free the dynamically allocated memory
    delete[] cars;
    delete[] drivers;

    return 0;
}
