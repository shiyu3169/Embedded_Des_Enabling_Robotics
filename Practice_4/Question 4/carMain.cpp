#include <string.h>
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

int main() {
   Car *empty = NULL;
   std::ifstream file("data.txt");
   std::string str; 
   std::vector<string> lines;
   while (std::getline(file, str))
   {
   		lines.push_back(str);
   }

   std::vector<Car*> cars;

  unsigned int i;
  for(i=0;i<lines.size();i++) {
  	string line = lines[i];
  	istringstream iss(line);
  	vector<string> tokens;
	copy(istream_iterator<string>(iss),
     	istream_iterator<string>(),
     	back_inserter(tokens));

  	string make = tokens[0];
  	string model = tokens[1];
  	string year = tokens[2];
  	string color = tokens[3];
  	Car *car = empty->create(make, model, year, color);
  	cars.push_back(car);
	}

	int operation;
	string base, order;

	 do {
        empty->operation_select();
        scanf("%d",&operation);

        switch (operation) {
          case 1: printf("\nEnter the sorting base, either 'model' or 'year'");
          		  printf("\nBase: ");
                  std::cin >> base;
                  printf("\nEnter the sorting order, either 'asc' or 'desc'");
                  printf("\nOrder: ");
                  std::cin >> order;
                  empty->bubble(cars, base, order);
                  break;
          case 2: empty->findDup(cars);
                  break;
          case 3:
                  break;
          default: printf("undefined input\n");
        }
    } while(operation!= 9);
   return 0;
}