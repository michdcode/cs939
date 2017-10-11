// Car Class - Question 4

#include <iostream>
#include <string>
using namespace std;

//Car Class declaration
class Car
{   private:
        int year, speed;
        string make;
    
    public:
        // function prototypes
        Car(int vehicleYear, string vehicleMake); 
        
        // Accessor functions -- inline because they are short
        int getYear()
        {   return year; }
        
        int getSpeed()
        {   return speed; }
        
        string getMake()
        {   return make; }        
        
        // Mutator functions
        void setAccelerate()
        {   speed = speed + 5; }

        void setBrake()
        {   speed = speed - 5; }
};

// Car Class member function implementation -- Constructor
Car::Car(int vehicleYear, string vehicleMake)
{
    year = vehicleYear;
    speed = 0.0;
    make = vehicleMake;
}

// Client Program 
int main()
{
    Car dadCar(2016, 'Volvo');
    int count = 0;
    // Accelerate, get speed, show speed - repeat 5 times
    while (count < 5)
    {
        cout << "The current speed is: " << dadCar.setAccelerate() << dadCar.getSpeed() << endl;
        count ++;
    }
    cout << "Whoa - slow down!";    
    // Brake, get speed, show speed - repeat 5 times
    while (count != 0)
    {
        cout << "The current speed is: " << dadCar.setBrake() << dadCar.getSpeed() << endl;
        count --;
    }
    return 0; 
}
