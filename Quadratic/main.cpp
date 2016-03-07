//
//  main.cpp
//  Quadratic
//
//  Created by Alex Dickinson on 06.03.16.
//  Copyright © 2016 Alex Dickinson. All rights reserved.
//
// This program takes A, B, and C values from the user to calculate the critical numbers for an equation of
// the form Ax^2 + Bx + C. It reports whether the returned value is real or imaginary, and whether there are
// multiple solutions. Users may use this program to calculate multiple quadratic equations. A user may
// terminate the program by pressing return.

#include <iostream>
#include <fstream>
#include <math.h>
using std::cout;
using std::cin;
using std::string;

double doubleValidator(string inputMsg);

int main() {
    double aVal;
    double bVal;
    double cVal;
    double discriminant;
    double solution;//calculated twice in when there are multiple solutions.
    
    cout << "==============================================================" << std::endl;
    cout << "Payroll System" << std::endl;
    cout << "Long Beach City College" << std::endl;
    cout << "Author: Alex Dickinson" << std::endl;
    cout << "March 5, 2016" << std::endl;
    cout << "==============================================================" << std::endl;
    cout << std::endl;
    cout << "This program evaluates equations of the form Ax^2 + Bx + C." << std::endl;
    
    while(true){
        //initialize variables here since they have to be initialized after looping anyway
        aVal = double();
        bVal = double();
        cVal = double();
        discriminant = double();
        solution = double();

        cout << "Please type in the values for A, B, and C." << std::endl;
        cout << "Press RETURN at any time to terminate the program." << std::endl;
        cout << std::endl;
        
        //these get coefficient values
        aVal = doubleValidator("A");
        bVal = doubleValidator("B");
        cVal = doubleValidator("C");
        discriminant = (pow(bVal, 2) - (4 * aVal * cVal));
        solution = -bVal / (2 * aVal);
        if (discriminant == 0){//single solution
            cout << "The only solution for the equation " << aVal << "x^2 + " << bVal << "x + " << cVal << "C is " << solution << "." << std::endl;
        }
        else if (discriminant < 0){//multiple imaginary solutions
            discriminant = (sqrt(-discriminant)) / (2 * aVal);
            cout << "The following are imaginary solutions for the equation " << aVal << "x^2 + " << bVal << "x + " << cVal << ":" << std::endl;
            cout << solution << " + " << discriminant << " * i" << std::endl;
            cout << solution << " + " << discriminant << " * i" << std::endl;
        }
        else{//multiple real solutions
            discriminant = (sqrt(discriminant) / (2 * aVal));
            cout << "The following are real solutions for the equation " << aVal << "x^2 + " << bVal << "x + " << cVal << ":" << std::endl;
            cout << solution + discriminant << std::endl;
            cout << solution - discriminant << std::endl;
        }
    }
    
    return 0;
}

/*
 This takes a string and makes sure it is a numerical value.
 */
double doubleValidator(string inputMsg){
    string input;
    double inputMath;
    bool isNeg = false;//tells whether number is negative or positive
    
    while (true) { //input validation loop
        //Tells the user that they need to input a certain value.
        cout << "Please enter your desired value for " << inputMsg << ":" << std::endl;
        getline(std::cin, input);
        if (input.empty()){
            cout << "Thanks for playing!" << std::endl;
            exit(0);
        }
        if (input.at(0) == '-'){
            input.erase(0, 1);
            isNeg = true;
        }
        if (input.find_first_not_of("1234567890.") == string::npos) {
            if (inputMsg == "A" && input.find_first_not_of("0") == string::npos){
                cout << "A cannot be zero!" << std::endl;
                continue;
            }
            else{
                inputMath = stod(input);
                if (isNeg){
                    inputMath = -inputMath;
                }
                return inputMath;
            }
        }
        else{
            cout << "The entered value for " << inputMsg << " is invalid." << std::endl;
            continue;
        }
    }
}