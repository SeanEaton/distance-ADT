#ifndef RAT_H
#define RAT_H
#include <iostream>
using namespace std;

class Distance {
   
    //--------------------- overloaded IO functions -------------------------
    //assumes parameter is a distance object
    friend ostream& operator<<(ostream& output, const Distance &);
    friend istream& operator>>(istream& input, Distance &);

public:
    //-------------------------- constructor --------------------------------
    Distance (int = 0, int = 0);

    //--------------------- arithmetic operators ----------------------------
    //overloading operators + - * /
    Distance operator+(const Distance &) const;
    //two '-' operators, one for subtraction, one for turning adjacent distance negative
    Distance operator-(const Distance &) const;
    Distance operator-();
    double operator*(const Distance &) const;
    double operator/(const Distance &) const;

    //--------------------- comparison operators ----------------------------
    //overloading operators > < >= <= == !=
    bool operator>(const Distance &) const; 
    bool operator<(const Distance &) const; 
    bool operator>=(const Distance &) const;
    bool operator<=(const Distance &) const;
    bool operator==(const Distance &) const;
    bool operator!=(const Distance &) const;

    //--------------------- assignment operators ----------------------------
    //overloading operators += -=
    Distance& operator+=(const Distance &); 
    Distance& operator-=(const Distance &); 

    //----------------------- getter methods --------------------------------
    int getFeet(); 
    int getInch();
    //----------------------- setter methods --------------------------------
    void putFeet(int);
    void putInch(int);
private:
    //----------------------- variable fields -------------------------------
    int feet;
    int inch;

    //------------------------------ reduce ---------------------------------
    // will adjust for negative values then fit inches into feet, etc
    void reduce();
};

#endif