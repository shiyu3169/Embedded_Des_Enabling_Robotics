#include <iostream>
#include <stdio.h>
using namespace std;

//get the minimum value of the 3 inputs
template <class T> 
T minimum(T a, T b, T c) {
	T min = a;
	if (b < min) {
		min = b;
	}
	if (c < min) {
		min = c;
	}
	return min;
}

template <class T> 
void bubble(T *items,int count)
{
  T t;

  for(int a=1; a<count; a++)
    for(int b=count-1; b>=a; b--)
      if(items[b-1] > items[b]) {
        t = items[b-1];
        items[b-1] = items[b];
        items[b] = t;
      }
}

int main() {
//minumum value
	//int
	int a1 = 41241;
	int b1 = 41242;
	int c1 = 41222;
	cout<< "The minimum int value is: " << minimum( a1, b1, c1 ) << endl;

	//double
	double a2 = 41241.2;
	double b2 = 41241.3;
	double c2 = 41241.9;
	cout<< "The minimum double value is: " << minimum( a2, b2, c2 ) << endl;

	//string
	string a3 = "hello";
	string b3 = "eece";
	string c3 = "class";
	cout<< "The minimum string value is: " << minimum( a3, b3, c3 ) << endl;

//bubble sort
	//int
	int iarray[7] = {7, 5, 4, 3, 9, 8, 6};
	cout << "Unsorted integer array: ";
  	for(int i=0;  i<7; i++) {
    	cout << iarray[i] << ' ';
    }
    cout << endl;

    bubble(iarray, 7);

	cout << "Sorted integer array: ";
	for(int i=0;  i<7; i++) {
		cout << iarray[i] << ' ';
	}
    cout << endl;


	//double
  	double darray[5] = {4.3, 2.5, -0.9, 10.2, 3.0};
  	cout << "Unsorted double array: ";
  	for(int i=0;  i<5; i++) {
    	cout << darray[i] << ' ';
  	}
    cout << endl;

    bubble(darray, 5);

    cout << "Here is sorted double array: ";
    for(int i=0;  i<5; i++) {
    	cout << darray[i] << ' ';
    }
    cout << endl;
  	
  	//string
  	string sarray[5] = {"hello", "goodbye", "thanks", "welcome", "morning"};
  	cout << "Unsorted string array: ";
  	for(int i=0;  i<5; i++) {
    	cout << sarray[i] << ' ';
  	}
    cout << endl;

    bubble(sarray, 5);

    cout << "Sorted double array: ";
    for(int i=0;  i<5; i++) {
    	cout << sarray[i] << ' ';
    }
    cout << endl;
}