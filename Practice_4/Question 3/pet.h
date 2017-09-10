#include <iostream>
#include <stdio.h>
using namespace std;

class Pet {
private:
    string name;
    string breed;
    char gender;
    string birthday;
public:
    Pet(){ }
    ~Pet(){ }           

    Pet *createPet(string name, string breed, char gender, string birthday); //create new pet         
    string getInfo(); //get pet info
    string getName(); //get pet name
};