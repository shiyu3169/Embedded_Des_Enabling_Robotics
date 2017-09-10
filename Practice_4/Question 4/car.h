#include <iostream>
#include <vector> 
#include <stdio.h>
using namespace std;

class Car {
private:
  	string make;
    string model;
    string year;
    string color;
public:
    Car(){ }
    ~Car(){ }

    void operation_select(); 
    Car *create(string make, string model, string year, string color);
    string getData();
    void bubble(std::vector<Car*> items,string base, string order);
    void findDup(std::vector<Car*> cars);
};



