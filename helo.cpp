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

        // Accessor (getter) methods
        string getColor() const { return color; }
        string getMake() const { return make; }
        string getModel() const { return model; }

        // Mutator (setter) methods
        void setColor(const string& c) { color = c; }
        void setMake(const string& m) { make = m; }
        void setModel(const string& mo) { model = mo; }

        void start() {
            cout << color << " " << make << " " << model << " started." << endl;
        }

        void stop() {
            cout << color << " " << make << " " << model << " stopped." << endl;
        }

        void accelerate() {
            cout << color << " " << make << " " << model << " accelerating." << endl;
        }

        // Static member function to get the total number of cars
        static int getTotalCars() {
            return totalCars;
        }
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

        // Accessor (getter) methods
        string getName() const { return name; }
        int getAge() const { return age; }
        Car getCar() const { return car; }

        // Mutator (setter) methods
        void setName(const string& n) { name = n; }
        void setAge(int a) { age = a; }
        void setCar(const Car& c) { car = c; }

        void drive() {
            cout << name << " is driving the " << car.getColor() << " " << car.getMake() << " " << car.getModel() << "." << endl;
            car.start();
            car.accelerate();
        }

        void park() {
            cout << name << " is parking the " << car.getColor() << " " << car.getMake() << " " << car.getModel() << "." << endl;
            car.stop();
        }

        // Static member function to get the total number of drivers
        static int getTotalDrivers() {
            return totalDrivers;
        }
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

    // Example of using the mutator methods to modify car and driver details
    drivers[0].setName("Alicia");
    drivers[0].setAge(31);
    drivers[0].getCar().setColor("Pink");

    cout << drivers[0].getName() << " is now driving a " << drivers[0].getCar().getColor() << " car." << endl;

    // Display the total number of cars and drivers created using static member functions
    cout << "Total number of cars: " << Car::getTotalCars() << endl;
    cout << "Total number of drivers: " << Driver::getTotalDrivers() << endl;

    // Free the dynamically allocated memory
    delete[] cars;
    delete[] drivers;

    return 0;
}
