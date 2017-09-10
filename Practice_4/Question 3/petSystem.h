#include <iostream>
#include <stdio.h>
#include "owner.h"
#include <vector>  //for std::vector

class PetSystem {
private:
    std::vector<Owner*> owners;
public:
    PetSystem(){ }
    ~PetSystem(){ }

    void operation_select(); 
    void init();       //initialize the system data
    void readOwners(); //read all existing owners 
    void readAllPets(); //read all existing pets
    void getPetsByName(string name); //get pets by given pets name
    void getPetsByOwner(string firstName, string lastName); //get pets by owner name
    void addPet(string name, string breed, char gender, string birthday, string firstName, string lastName); //add new pet
    void addOwner(string firstName, string lastName, string phoneNumber, string email); //add new owner
    void updateContact(string firstName, string	lastName, string phoneNumber, string email); //update contact information
    void deletePet(string firstName, string lastName, string petName); //delete a pet by name from given owner
};