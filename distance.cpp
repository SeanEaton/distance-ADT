#include "distance.h"
#include <math.h>

using namespace std;

/*
------------------------------ I/O OPERATORS ---------------------------------
*/
//------------------------- operator<< overload ------------------------------
// overloaded <<: will print out the current object as "X feet Y inches"
ostream& operator<<(ostream& output, const Distance& d){
    if (d.feet != 0 && d.inch != 0){
        if ((d.feet > 1 || d.feet < -1) && (d.inch > 1 || d.inch < -1)){
            output << d.feet << " feet " << d.inch << " inches";
        }
        else if ((d.feet == 1 && d.inch == 1) || (d.feet == -1 && d.inch == -1)){
            output << d.feet << " foot " << d.inch << " inch";
        }
        else if (d.feet == 1 || d.feet == -1){
            output << d.feet << " foot " << d.inch << " inches";
        }
        else if (d.inch == 1 || d.inch == -1){
            output << d.feet << " feet " << d.inch << " inch";
        }
    }
    else if (d.feet == 0){
        if (d.inch >= -1 && d.inch <= 1){
            output << d.inch << " inch";
        }
        else {
            output << d.inch << " inches";
        }
    }
    else if (d.inch == 0){
        if (d.feet == 1 || d.feet == -1){
            output << d.feet << " foot";
        }
        else {
            output << d.feet << " feet";
        }
    }
    return output;
}

//------------------------- operator>> overload ------------------------------
// overloaded >>: take two inputs, feet and inches, and change parameter's values to input
istream& operator>>(istream& input, Distance& d){
    cout << "Feet: ";
    input >> d.feet;
    cout << "Inches: ";
    input >> d.inch;
    d.reduce();
    return input;
}


/*
------------------------------- CONSTRUCTOR ----------------------------------
*/
//------------------------------ Distance ------------------------------------
// default constructor:  parameters are feet and inch respectively
// will call reduce() to fix values
Distance::Distance(int f, int i){
    feet = f;
    inch = i;
    reduce();
}


/*
-------------------------- ARITHMETIC OPERATORS ------------------------------
*/
//--------------------------------- add --------------------------------------
// overloaded +: addition of 2 Distances, current object and parameter
Distance Distance::operator+(const Distance& d) const {
    Distance sum;
    sum.feet = (feet + d.feet);
    sum.inch = (inch + d.inch);
    sum.reduce();
    return sum;
}

//------------------------------- subtract -----------------------------------
//overloaded -: subtraction of 2 Distances, current object and parameter
Distance Distance::operator-(const Distance& d) const {
    Distance diff;
    diff.feet = (feet - d.feet);
    diff.inch = (inch - d.inch);
    diff.reduce();
    return diff;
}
//if no parameters, then turn whatever is adjacent to operator negative
Distance Distance::operator-() {
    Distance signswitch;
    signswitch.feet = -feet;
    signswitch.inch = -inch;
    reduce();
    return signswitch;
}

//--------------------------- multiplication ---------------------------------
//overloaded *: multiplication of 2 Distances, current object and parameter, returning a double representing sq. feet.
double Distance::operator*(const Distance& d) const {
    double sqfeet;
    sqfeet = (double(feet) + double(inch)/12) * (double(d.feet) + double(d.inch)/12);
    return sqfeet;
}

//------------------------------- division -----------------------------------
//overloaded /: division of 2 Distances, current object and parameter, returning a double representing ratio.
double Distance::operator/(const Distance& d) const {
    if (d.feet == 0 && d.inch == 0) {
        cout << "DIVIDE BY ZERO ERROR!!!" << endl;
        return 0.0;
    }
    double ratio;
    ratio = (double(feet) + double(inch)/12) / (double(d.feet) + double(d.inch)/12);
    return ratio;
}


/*
--------------------------- COMPARISON OPERATORS -----------------------------
*/
//-------------------------- operator> overload ------------------------------
// overloaded >: checks if current object is greater than parameter
bool Distance::operator>(const Distance& d) const{
    return (double(feet) + double(inch)/12) > (double(d.feet) + double(d.inch)/12);
}

//-------------------------- operator< overload ------------------------------
// overloaded <: checks if current object is less than parameter
bool Distance::operator<(const Distance& d) const{
    return (double(feet) + double(inch)/12) < (double(d.feet) + double(d.inch)/12);
}

//------------------------- operator>= overload ------------------------------
// overloaded >=: checks if current object is less than parameter
bool Distance::operator>=(const Distance& d) const{
    return (double(feet) + double(inch)/12) >= (double(d.feet) + double(d.inch)/12);
}

//------------------------- operator<= overload ------------------------------
// overloaded <=: checks if current object is less than parameter
bool Distance::operator<=(const Distance& d) const{
    return (double(feet) + double(inch)/12) <= (double(d.feet) + double(d.inch)/12);
}

//------------------------- operator== overload ------------------------------
// overloaded ==: checks if current object is less than parameter
bool Distance::operator==(const Distance& d) const{
    return (double(feet) + double(inch)/12) == (double(d.feet) + double(d.inch)/12);
}

//------------------------- operator!= overload ------------------------------
// overloaded !=: checks if current object is less than parameter
bool Distance::operator!=(const Distance& d) const{
    return (double(feet) + double(inch)/12) != (double(d.feet) + double(d.inch)/12);
}


/*
--------------------------- ASSIGNMENT OPERATORS -----------------------------
*/
//-------------------------- operator+= overload ------------------------------
// overloaded +=: adds parameter to current object, returning altered current object
Distance& Distance::operator+=(const Distance& d) {
    feet = (feet + d.feet);
    inch = (inch + d.inch);
    reduce();
    return *this;
}

//-------------------------- operator-= overload ------------------------------
// overloaded -=: adds parameter to current object, returning altered current object
Distance& Distance::operator-=(const Distance& d) {
    feet = (feet - d.feet);
    inch = (inch - d.inch);
    reduce();
    return *this;
}


/*
---------------------------- GETTERS & SETTERS -------------------------------
*/
//------------------------------ getFeet -------------------------------------
int Distance::getFeet(){
    return feet;
}

//------------------------------ getInch -------------------------------------
int Distance::getInch(){
    return inch;
}

//------------------------------ putFeet -------------------------------------
void Distance::putFeet(int f){
    feet = f;
    reduce();
}

//------------------------------ putInch -------------------------------------
void Distance::putInch(int i){
    inch = i;
    reduce();
}


//------------------------------ reduce --------------------------------------
// will adjust for negative values then fit inches into feet, etc
void Distance::reduce(){
    if (inch < 0 && feet > 0) {
        inch = ((feet * 12) + inch);
        feet = 0; 
    }
    else if (feet < 0 && inch > 0) {
        inch = ((feet * 12) + inch);
        feet = 0;
    }
    if (inch > 11 || inch < -11){
        feet += (inch/12);
        inch = inch % 12;  
    }
}
