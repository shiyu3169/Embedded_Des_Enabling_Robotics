#include <cstddef>
#include "petSystem.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>  //for std::vector
using namespace std;

/**************Pet functions********************/
Pet *Pet::createPet(string name, string breed, char gender, string birthday) {
  Pet *neo = new Pet();
  neo->name = name;
  neo->breed = breed;
  neo->gender = gender;
  neo->birthday = birthday;
  return neo;
}

string Pet::getInfo() {
  return "Name: " + name + ", Breed: " + breed + ", Gender: " + gender + ", Birthday: " + birthday;
}

string Pet::getName() {
  return name;
}

/**************Owner functions******************/
Owner *Owner::createOwner(string firstName, string lastName, string phoneNumber, string email, std::vector<Pet*> pets) {
  Owner *neo = new Owner();
  neo->firstName = firstName;
  neo->lastName = lastName;
  neo->phoneNumber = phoneNumber;
  neo->email = email;
  neo->pets = pets;
  return neo;
}

string Owner::getOwnerInfo() {
  return "First Name: " + firstName + ", Last Name: " + lastName + ", Phone Number: " + phoneNumber + ", Email: " + email;
}

string Owner::getName() {
  return firstName + lastName;
}

void Owner::readPets() {
  unsigned int i;
  for(i=0;i<pets.size();i++) {
    Pet *p1 = pets[i];
    string s1 = p1->getInfo();
    cout<<"  " + s1 << endl;
  }
}

void Owner::getPetsByName(string name) {
  unsigned int i;
  for(i=0;i<pets.size();i++) {
    Pet *p1 = pets[i];
    if(p1->getName() == name) {
      cout<<"  " + p1->getInfo() << endl;
    }
  }
}

void Owner::addPet(Pet *pet) {
  pets.push_back(pet);
}

void Owner::updateContact(string nphoneNumber, string nemail) {
  if (nphoneNumber != "N/A") {
    this->phoneNumber = nphoneNumber;
  }
  if (nemail != "N/A") {
    this->email = nemail;
  }
}

void Owner::deletePet(string name) {
  unsigned int i;
  for(i=0;i<pets.size();i++) {
    Pet *p1 = pets[i];
    if(p1->getName() == name) {
      pets.erase(pets.begin() + i);
      cout<<"pet is removed from list" << endl;
    }
  }
  cout<< endl;
  cout<<"pet is not found for this owner" << endl;
}

/**************System functions*****************/
void PetSystem::operation_select(){
        printf("\n\n***********************************\n");
        printf("select your operation\n");
        printf("1- Read all owner\n");
        printf("2- Read all pets\n");
        printf("3- Find pets by name\n");
        printf("4- Find Pets by Owner\n");
        printf("5- Add a new pet\n");
        printf("6- Add a new owner\n");
        printf("7- Update a owner\n");
        printf("8- Delete a pet\n");
        printf("9- Exit\n");
        printf("Which operation? ");
}

void PetSystem::init() {
  //Pet init
  Pet *pet = NULL;
  Pet *rengar = pet->createPet("Rengar", "cat", 'M', "07/11/2012");
  Pet *anivia = pet->createPet("Anivia", "bird", 'F', "08/13/2014");
  Pet *twitch = pet->createPet("Twitch", "hamsters", 'M', "09/22/2014");
  Pet *ahri = pet->createPet("Ahri", "dog", 'F', "10/02/2015");
  Pet *aurelion = pet->createPet("Aurelion", "lizard", 'M', "12/21/2011");
  Pet *azir = pet->createPet("Azir", "bird", 'M', "12/21/2001");
  Pet *cassiopeia = pet->createPet("Cassiopeia", "lizard,", 'F', "05/21/2011");
  Pet *elise = pet->createPet("Elise", "spider", 'F', "03/11/2007");
  Pet *nasus = pet->createPet("Nasus", "dog", 'M', "05/21/2010");
  Pet *katarina = pet->createPet("Katarina", "cat", 'F', "01/21/2010");

  //empty pet list;
  std::vector<Pet*> stevePets;
  std::vector<Pet*> cliffPets;
  std::vector<Pet*>shiyuPets;

  //assign pets to right owners
  stevePets.push_back(rengar);
  stevePets.push_back(anivia);
  stevePets.push_back(twitch);

  cliffPets.push_back(ahri);
  cliffPets.push_back(aurelion);
  cliffPets.push_back(azir);

  shiyuPets.push_back(cassiopeia);
  shiyuPets.push_back(elise);
  shiyuPets.push_back(nasus);
  shiyuPets.push_back(katarina);

  //Owner init
  Owner *owner = NULL;
  Owner *steve = owner->createOwner("Steve", "Constructor", "123-321-1234", "steve123@gmail.com", stevePets);
  Owner *cliff = owner->createOwner("Cliff", "Eece", "888-888-8888", "Aplease@gmail.com", cliffPets);
  Owner *shiyu = owner->createOwner("Shiyu", "Wang", "233-223-2333", "maxgrade@gmail.com", shiyuPets);

  //petSystem init
  owners.push_back(steve);
  owners.push_back(cliff);
  owners.push_back(shiyu);
}

void PetSystem::readOwners() {
  unsigned int i;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    string s1 = o1->getOwnerInfo();
    cout<< s1 << endl;
  }
}

void PetSystem::readAllPets() {
  unsigned int i;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    o1->readPets();
  }
}

void PetSystem::getPetsByName(string name) {
  unsigned int i;
  cout<< "Searching Result:" << endl;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    o1->getPetsByName(name);
  }
  cout<< endl;
  cout<< "All results are listed above" << endl;
}

void PetSystem::getPetsByOwner(string firstName, string lastName) {
  unsigned int i;
  string name = firstName + lastName;
  cout<< "Searching Result:" << endl;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    string on = o1->getName();
    if(on == name) {
      cout<<"Result is found:" << endl;
      o1->readPets();
      return;
    }
  }
  cout<< endl;
  cout<< "Not found" << endl;
}

void PetSystem::addPet(string name, string breed, char gender, string birthday, string firstName, string lastName) {
  Pet *pet = NULL;
  Pet *tmp = pet->createPet(name, breed, gender, birthday);
  unsigned int i;
  string n = firstName + lastName;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    string on = o1->getName();
    if(on == n) {
      o1->addPet(tmp);
      cout<<"Pet is added" << endl;
      return;
    }
  }
  cout<< endl;
  cout<<"owner is not found" << endl;
}

void PetSystem::addOwner(string firstName, string lastName, string phoneNumber, string email) {
  std::vector<Pet*> empty;
  Owner *owner = NULL;
  Owner *no = owner->createOwner(firstName, lastName, phoneNumber, email, empty);
  owners.push_back(no);
}

void PetSystem::updateContact(string firstName, string lastName, string phoneNumber, string email) {
  string name = firstName + lastName;
  unsigned int i;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    string on = o1->getName();
    if(on == name) {
      o1->updateContact(phoneNumber, email);
      cout<<"contact information is updated" << endl;
      return;
    }
  }
  cout<< endl;
  cout<<"owner is not found" << endl;
}

void PetSystem::deletePet(string firstName, string lastName, string petName) {
  string name = firstName + lastName;
  unsigned int i;
  for(i=0;i<owners.size();i++) {
    Owner *o1 = owners[i];
    string on = o1->getName();
    if(on == name) {
      o1->deletePet(petName);
      return;
    }
  }
  cout<< endl;
  cout<<"pet is not found for this owner" << endl;
}