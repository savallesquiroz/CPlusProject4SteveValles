#include "Money.h"

//OPERATORS
Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}

Money operator -(const Money& amount1) {
    Money temp;
    temp.allCents = -amount1.allCents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return amount1.allCents == amount2.allCents;
}

// Implementation of operator>> and operator<<
std::istream& operator >>(std::istream& ins, Money& amount)
{
    char oneChar, decimalPoint, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar;
    }
    else
        negative = false;

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if (oneChar != '$' || decimalPoint != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        std::cout << "Error: illegal format for money input\n";
        exit(1);
    }

    cents = Money::digitToInt(digit1) * 10 + Money::digitToInt(digit2);

    amount.allCents = dollars * 100 + cents;
    if (negative)
        amount.allCents = -amount.allCents;
    return ins;
}

std::ostream& operator <<(std::ostream& outs, const Money& amount)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (amount.allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << ".";

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

// Constructors
Money::Money(long dollars, int cents) {
    allCents = dollars * 100 + cents;
}

Money::Money(long dollars) {
    allCents = dollars * 100;
}

Money::Money() {
    allCents = 0;
}

//Percentage function
Money Money::percent(int percentFigure) const
{
    //Percentage calculatio 
    double percentage = static_cast<double>(percentFigure) / 100.0;
    long newCents = static_cast<long>(static_cast<double>(allCents) * percentage);

    //calculated value
    Money result;
    result.allCents = newCents;

    return result;
}
//digitToInt function
int Money::digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

//digitToInt function
int digitToInt(char c);