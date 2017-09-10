#include <iostream>
#include <stdio.h>
#include "pet.h"
#include <vector>  //for std::vector
using namespace std;

class Owner {
private:
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    std::vector<Pet*> pets;
public:
    Owner(){ }
    ~Owner(){ }
    Owner *createOwner(string firstName, string lastName, string phoneNumber, string email, std::vector<Pet*> pets); //create new owner
    string getOwnerInfo(); //get owner Info
    void readPets(); //read all pets of this owner
    void getPetsByName(string name); //get pets info by given name
    string getName(); //get owner name
    void addPet(Pet *pet); //add a new pet
    void updateContact(string phoneNumber, string email); //update contact information
    void deletePet(string name); //delete pet by given name
};