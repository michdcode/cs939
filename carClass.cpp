// Car Class - Question 4

#include <iostream>
#include <string>
using namespace std;

//Car Class declaration
class Car
{   private:
        int year;
        string make;
        int speed;
    
    public:
        // constructor
        Car(double vehicleYear, string vehicleMake)
        {
            year = vehicleYear;
            speed = 0.0;
            make = vehicleMake;
        } 

        Car(); // default constructor
        
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

// Client Program 
int main()
{
    Car myCar(2016, "Volvo");
    int count = 0;
    // Accelerate, get speed, show speed - repeat 5 times
    while (count < 5)
    {
        cout << "The current speed is: ";
        myCar.setAccelerate();
        cout << myCar.getSpeed(); 
        cout << endl;  
        count ++;
    }
    cout << "Whoa - slow down!\n";    
    // Brake, get speed, show speed - repeat 5 times
    while (count != 0)
    {
        cout << "The current speed is: "; 
        myCar.setBrake();
        cout << myCar.getSpeed();
        cout << endl;
        count --;
    }
    return 0; 
}

