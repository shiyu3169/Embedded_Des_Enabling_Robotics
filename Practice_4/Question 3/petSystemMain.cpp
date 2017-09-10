#include "petSystem.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>  //for std::vector

int main() {
	//initialize a pet system
	PetSystem *system = new PetSystem();
	system->init();

    int operation;
    string name, firstName, lastName, petName, breed, birthday, phoneNumber, email;
    char gender;

    do {
        system->operation_select();
        scanf("%d",&operation);

        switch (operation) {
          case 1: system->readOwners();
                  break;
          case 2: system->readAllPets();
                  break;
          case 3: printf("\nName: ");
                  std::cin >> name;
                  system->getPetsByName(name);
                  break;
	      case 4: printf("\nFirst Name: ");
                  std::cin >> firstName;
                  printf("\nLast Name: ");
                  std::cin >> lastName;
                  system->getPetsByOwner(firstName, lastName);
                  break;
          case 5: printf("\nEnter the owner of the new pet");
          		  printf("\nFirst Name: ");
                  std::cin >> firstName;
                  printf("\nLast Name: ");
                  std::cin >> lastName;
                  printf("\nEnter the new pet info");
                  printf("\nPet Name: ");
                  std::cin >> petName;
                  printf("\nBreed: ");
                  std::cin >> breed;
                  printf("\ngender: ");
                  std::cin >> gender;
                  printf("\nBirthday: ");
                  std::cin >> birthday;
                  system->addPet(petName, breed, gender, birthday, firstName, lastName);
                  break;
          case 6: printf("\nEnter the information of the new owner");
          		  printf("\nFirst Name: ");
                  std::cin >> firstName;
                  printf("\nLast Name: ");
                  std::cin >> lastName;
                  printf("\nPhone Number: ");
                  std::cin >> phoneNumber;
                  printf("\nEmail: ");
                  std::cin >> email;
                  system->addOwner(firstName, lastName, phoneNumber, email);
                  break;
          case 7: printf("\nEnter the name of the owner");
          		  printf("\nFirst Name: ");
                  std::cin >> firstName;
                  printf("\nLast Name: ");
                  std::cin >> lastName;
                  printf("\nEnter the new contact information");
                  printf("\nEnter 'N/A' if no update for current infomation");
                  printf("\nPhone Number: ");
                  std::cin >> phoneNumber;
                  printf("\nEmail: ");
                  std::cin >> email;
                  system->updateContact(firstName, lastName, phoneNumber, email);
                  break;
          case 8: printf("\nEnter the name of the owner");
          		  printf("\nFirst Name: ");
                  std::cin >> firstName;
                  printf("\nLast Name: ");
                  std::cin >> lastName;
                  printf("\nEnter the pet name");
                  printf("\nPet Name: ");
                  std::cin >> petName;
                  system->deletePet(firstName, lastName, petName);
                  break;
          case 9:
                  break;
          default: printf("undefined input\n");
        }
    } while(operation!= 9);
  	return 0;
}