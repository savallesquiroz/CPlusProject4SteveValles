//Make sure header is not repeated
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

class Money
{
public:
    //Operator overloadings
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1);
    friend bool operator ==(const Money& amount1, const Money& amount2);

    //input and output operators
    friend std::istream& operator >>(std::istream& ins, Money& amount);
    friend std::ostream& operator <<(std::ostream& outs, const Money& amount);

    // Constructors
    Money(long dollars, int cents);
    Money(long dollars);
    Money();

    //Getter function to get value
    double getValue() const;

    // Percentage function declaration
    Money percent(int percentFigure) const;

    //digitToInt
    static int digitToInt(char c);

private:
    long allCents;
};

#endif
