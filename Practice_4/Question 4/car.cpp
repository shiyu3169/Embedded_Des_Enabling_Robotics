#include <string.h>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>  //for std::vector
#include "car.h"
using namespace std;
Car* Car::create(string make, string model, string year, string color) {
	Car *car = new Car();

	car->make = make;
	car->model = model;
	car->year = year;
	car->color = color;

	return car;
}

void Car::operation_select(){
        printf("\n\n***********************************\n");
        printf("select your operation\n");
        printf("1- Sort\n");
        printf("2- Identify repeated records\n");
        printf("3- Exit\n");
        printf("Which operation? ");
}

void Car::bubble(std::vector<Car*> items, string base, string order) {
  Car *t;
  int count = items.size();
  
  for(int a=1; a<count; a++) {
    for(int b=count-1; b>=a; b--) {
    	if(base == "model") {
	    	if (order == "asc") {
	      		if(items[b-1]->model > items[b]->model) {
	        		t = items[b-1];
	        		items[b-1] = items[b];
	        		items[b] = t;
	      		}
	  		}
	  		if(order == "desc") {
	  			if(items[b-1]->model < items[b]->model) {
	        		t = items[b-1];
	        		items[b-1] = items[b];
	        		items[b] = t;
	        	}
	  		}
	  	}
	  	if(base == "year") {
	    	if (order == "asc") {
	      		if(items[b-1]->year > items[b]->year) {
	        		t = items[b-1];
	        		items[b-1] = items[b];
	        		items[b] = t;
	      		}
	  		}
	  		if(order == "desc") {
	  			if(items[b-1]->year < items[b]->year) {
	        		t = items[b-1];
	        		items[b-1] = items[b];
	        		items[b] = t;
	        	}
	  		}
	  	}
  	}
  }
  cout << "Sorted list: " << endl;
  unsigned int j;
  	for(j=0;  j<items.size(); j++) {
		cout << items[j]->getData() << endl;
	}
}

string Car::getData() {
	return make + " " + model + " " + year + " " + color;
}

void Car::findDup(std::vector<Car*> cars) {
	std::vector<Car*> tmp;
	unsigned int i, k;

	for(i=0;i<cars.size();i++) {
		string data = cars[i]->getData();
		for(k=i+1;k<cars.size();k++) {
			string data2 = cars[k]->getData();
			if(data == data2) {
				tmp.push_back(cars[i]);
			}
		
		}
	}

	cout << endl;
	cout << "Duplicate car list: " << endl;
  	unsigned int j;
  	for(j=0;  j<tmp.size(); j++) {
		cout << tmp[j]->getData() << endl;
	}
}