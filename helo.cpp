#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string color;   // Color is private to hide internal details
        string make;
        string model;

    protected:
        // Protected function to handle starting the engine, not accessible directly by users
        void startEngine() {
            cout << "Engine started." << endl;
        }

    public:
        // Static variable to keep track of the total number of cars
        static int totalCars;

        // Constructor
        Car(string c, string m, string mo) : color(c), make(m), model(mo) {
            totalCars++;
        }

        // Public interface methods
        void start() {
            startEngine();  // Start engine through the protected function
            cout << color << " " << make << " " << model << " started." << endl;
        }

        void stop() {
            cout << color << " " << make << " " << model << " stopped." << endl;
        }

        void accelerate() {
            cout << color << " " << make << " " << model << " accelerating." << endl;
        }

        // Accessor (getter) methods - abstraction by providing controlled access to private data
        string getColor() const { return color; }
        string getMake() const { return make; }
        string getModel() const { return model; }

        // Mutator (setter) methods
        void setColor(const string& c) { color = c; }
        void setMake(const string& m) { make = m; }
        void setModel(const string& mo) { model = mo; }

        // Static member function to get the total number of cars
        static int getTotalCars() {
            return totalCars;
        }
};

// Initialize the static variable for total cars
int Car::totalCars = 0;

class Driver {
    private:
        string name;  // Encapsulated data: the driver's name and age are hidden from direct access
        int age;

    protected:
        Car car;  // Protected car object for possible subclass use

    public:
        // Static variable to keep track of the total number of drivers
        static int totalDrivers;

        // Constructor
        Driver(string n, int a, Car c) : name(n), age(a), car(c) {
            totalDrivers++;
        }

        // Public method for driving - users don't need to know how it's implemented internally
        void drive() {
            cout << name << " is driving the " << car.getColor() << " " << car.getMake() << " " << car.getModel() << "." << endl;
            car.start();
            car.accelerate();
        }

        // Public method for parking
        void park() {
            cout << name << " is parking the " << car.getColor() << " " << car.getMake() << " " << car.getModel() << "." << endl;
            car.stop();
        }

        // Accessor (getter) methods for controlled access to private data
        string getName() const { return name; }
        int getAge() const { return age; }

        // Mutator (setter) methods for controlled modification of private data
        void setName(const string& n) { name = n; }
        void setAge(int a) { age = a; }

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

    // Display the total number of cars and drivers created using static member functions
    cout << "Total number of cars: " << Car::getTotalCars() << endl;
    cout << "Total number of drivers: " << Driver::getTotalDrivers() << endl;

    // Free the dynamically allocated memory
    delete[] cars;
    delete[] drivers;

    return 0;
}
