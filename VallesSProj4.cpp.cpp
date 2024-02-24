//2023F_CSCI221_VB Computer Science II
//Steve Valles Quiroz
//Project 4

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
//Include ADT
#include "Money.h"

int main()
{
  //Acess external files
    Money amount;
    std::ifstream instream;
    std::ofstream outstream;
    //Test if it opens correctly
    instream.open("infile.dat");
    if (instream.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
    outstream.open("outfile.dat");
    if (outstream.fail())
    {
        std::cout << "Output file opening failed.\n";
        exit(1);
    }
    //Input from infile.dat file
    instream >> amount;
    //Send output to outfile.dat
    outstream << amount << " copied from the file infile.dat.\n";
    std::cout << amount << " copied from the file infile.dat.\n";
    //Calculate percentage
    std::cout << amount.percent(10);
    //Close files after use
    instream.close();
    outstream.close();

    return 0;
}
