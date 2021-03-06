/**
 *   @file: wages.cc
 * @author: Nasseef Abukamail (edited by KaraBeth Nemet)
 *   @date: January 24, 2022 (edited on January 31, 2022)
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes
const double MAX_HOURS = 70;

int main(int argc, char const *argv[]) {

    //0. variable decalarations
    double hours, rate, wages, overtimewages, overtimerate, overtimehours;
    //1. input the hours
    cout << "Enter the number of hours: ";
    cin >> hours;
    if (hours < 0 || hours > MAX_HOURS) //invalid?
    {
        cout << "Error: hours must be between 0 and 70" << endl;
        //return 0; //terminates the function
        exit(0);  //terminates the program
    }
    
    //2. input the rate
    cout << "Enter the hourly rate: ";
    cin >> rate;
    if (rate < 0 || rate > 20)
    {
       cout << "Error: rate must be between 0 and 20" << endl;
       exit(0);
    }
    cout << "Enter overtime hourly rate: ";
    cin >> overtimerate;
    
    //3. Calculations
    //calculate overtime pay
    if ( hours > 40 ){
        overtimehours = hours - 40;
        hours = hours - overtimehours;
        overtimewages = overtimehours * overtimerate;
    }
    else overtimewages = 0;

    wages = (hours * rate) + overtimewages;

    //4. Output
    cout << fixed << setprecision(2);
    cout << "Wages: $" << wages << endl;

    return 0;
} /// main