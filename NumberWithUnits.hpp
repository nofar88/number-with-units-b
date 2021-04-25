
#ifndef UNTITLED5_NUMBERWITHUNITS_HPP
#define UNTITLED5_NUMBERWITHUNITS_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdexcept>


using namespace std;

namespace ariel {

    class NumberWithUnits {
    private:
        static map<pair<string, string>, double> unit;
        double num;
        string s;

    public:
        NumberWithUnits(double n, const string &str);

        static double convert(double num, const string &from, const string &to);//A function that is called from all sorts of places in the code, so we want it to be static

        static bool checkUnit(const string &getunit);//A function that is called from all sorts of places in the code, so we want it to be static

        static void read_units(ifstream &path);//A function that is called from all sorts of places in the code, so we want it to be static

        NumberWithUnits operator+(const NumberWithUnits &other) const;

        NumberWithUnits &operator+=(const NumberWithUnits &other);

        NumberWithUnits operator+();

        NumberWithUnits operator-(const NumberWithUnits &other) const;

        NumberWithUnits operator-();

        NumberWithUnits operator-=(const NumberWithUnits &other);

        friend bool operator==(const NumberWithUnits &c1, const NumberWithUnits &c2);

        friend bool operator!=(const NumberWithUnits &c1, const NumberWithUnits &c2);

        friend bool operator>=(const NumberWithUnits &c1, const NumberWithUnits &c2);

        friend bool operator>(const NumberWithUnits &c1, const NumberWithUnits &c2);

        friend bool operator<=(const NumberWithUnits &c1, const NumberWithUnits &c2);

        friend bool operator<(const NumberWithUnits &c1, const NumberWithUnits &c2);

        friend NumberWithUnits operator*(const NumberWithUnits &c1, const double &c2);

        friend NumberWithUnits operator*(const double &c1, const NumberWithUnits &c2);


        NumberWithUnits &operator++();

        NumberWithUnits operator++(int dummy);

        NumberWithUnits &operator--();

        NumberWithUnits operator--(int dummy);

        friend ostream &operator<<(ostream &os, const NumberWithUnits &c);

        friend istream &operator>>(istream &is, NumberWithUnits &c);


    };

}


#endif //UNTITLED5_NUMBERWITHUNITS_HPP
