
#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

map<pair<string, string>, double> NumberWithUnits::unit;


NumberWithUnits::NumberWithUnits(double n, const string &str) {//I set it as const because I do not change the value, and I put & for the prevent copy by value
    if (checkUnit(str)) {
        num = n;
        s = str;
    } else {
        throw std::invalid_argument(str + " is invalid unit");
    }
}
//A function that checks if a particular unit exists
bool NumberWithUnits::checkUnit(const string &getunit) {
    return unit.count(pair<string, string>(getunit, getunit)) != 0;// Check if the unit itself already exists then returns true else false
}


void NumberWithUnits::read_units(ifstream &path) {
    double num1 = NAN;
    string unit1;
    double num2 = NAN;
    string unit2;

    string line;
    if (path.is_open()) {
        while (getline(path, line)) {//Read the next line into the line variable
            unsigned int i = 0;
            string temp;

            // read the first number and convert it to int
            while (('0' <= line[i] && line[i] <= '9') || line[i] == '.') {
                temp += line[i++];
            }
            num1 = stod(temp);//Saves the value into the variable

            // skip the ' ' until the first letter
            while (line[i] == ' ') {
                i++;
            }

            // read the first letter and convert it to int
            temp = "";
            while ('A' <= line[i] && line[i] <= 'z') {
                temp += line[i++];
            }
            unit1 = temp;//Saves the value into the variable

            // skip the ' ' and '=' until the first number
            while (line[i] == ' ' || line[i] == '=') {
                i++;
            }

            // read the second number and convert it to int
            temp = "";
            while (('0' <= line[i] && line[i] <= '9') || line[i] == '.') {
                temp += line[i++];
            }
            num2 = stod(temp);//Saves the value into the variable

            // skip the ' ' until the first letter
            while (line[i] == ' ') {
                i++;
            }

            // read the second letter and convert it to int
            temp = "";
            while ('A' <= line[i] && line[i] <= 'z') {
                temp += line[i++];
            }
            unit2 = temp;//Saves the value into the variable

//Calculation of conversions
            unit[pair<string, string>(unit1, unit2)] = num2 / num1;
            unit[pair<string, string>(unit2, unit1)] = num1 / num2;
        }
        path.close();//Close the read of the file

//For transcendence
        map < pair < string, string >, double > ::iterator it1;
        map < pair < string, string >, double > ::iterator it2;

        for (it1 = unit.begin(); it1 != unit.end(); it1++) {
            for (it2 = unit.begin(); it2 != unit.end(); it2++) {
                string from1 = it1->first.first;
                string to1 = it1->first.second;
                string from2 = it2->first.first;
                string to2 = it2->first.second;

                if (to1 == from2 && from1 != from2) {
                    unit[pair<string, string>(from1, to2)] = unit[it2->first] * unit[it1->first];
                    unit[pair<string, string>(to2, from1)] = 1 / (unit[it2->first] * unit[it1->first]);
                }
            }
        }
    }
}

//A converting function
double NumberWithUnits::convert(double num, const string &from, const string &to) {
    pair <string, string> units(from, to);
    if (unit.count(units) == 0) {
        throw std::invalid_argument("Units do not match - ["+from+"] cannot be converted to ["+to+"]");
    }
    double factor = unit[units];//If the unit exists, then go to the contents of the unit
    return num * factor;//Multiplier in conversion
}


NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &other) const {
    double numplus = convert(other.num, other.s, s);
    return NumberWithUnits(num + numplus, s);
}

NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &other) {
    double numplus = convert(other.num, other.s, s);
    num += numplus;
    return *this;//Changes the original and therefore returns the *this

}

NumberWithUnits NumberWithUnits::operator+() {
    return NumberWithUnits{num, s};
}

NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &other) const {
    double numplus = convert(other.num, other.s, s);
    return NumberWithUnits(num - numplus, s);

}

NumberWithUnits NumberWithUnits::operator-() {
    return NumberWithUnits{-num, s};
}


NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits &other) {
    double numplus = convert(other.num, other.s, s);
    num -= numplus;
    return *this;//Changes the original and therefore returns the *this

}


NumberWithUnits &NumberWithUnits::operator++() {
    ++num;
    return *this;//Immediately see the change
}

NumberWithUnits NumberWithUnits::operator++(int dummy) {
    NumberWithUnits temp{num, s};
    num++;
    return temp;//Immediately see the change only next time
}

NumberWithUnits &NumberWithUnits::operator--() {
    --num;
    return *this;

}

NumberWithUnits NumberWithUnits::operator--(int dummy) {
    NumberWithUnits temp{num, s};
    num--;
    return temp;

}

namespace ariel {
    const float TOLERANCE = 0.001;

    bool operator==(const NumberWithUnits &c1, const NumberWithUnits &c2) {
        double numeuals = NumberWithUnits::convert(c2.num, c2.s, c1.s);
        return abs(numeuals - c1.num) < TOLERANCE;
    }

    bool operator!=(const NumberWithUnits &c1, const NumberWithUnits &c2) {
        return !(c1 == c2);
    }

    bool operator>=(const NumberWithUnits &c1, const NumberWithUnits &c2) {
        return c1 == c2 || c1 > c2;
    }

    bool operator>(const NumberWithUnits &c1, const NumberWithUnits &c2) {
        double numeuals = NumberWithUnits::convert(c2.num, c2.s, c1.s);
        return (c1.num - numeuals) >= TOLERANCE;

    }

    bool operator<=(const NumberWithUnits &c1, const NumberWithUnits &c2) {
        return c1 == c2 || c1 < c2;
    }

    bool operator<(const NumberWithUnits &c1, const NumberWithUnits &c2) {
        double numeuals = NumberWithUnits::convert(c2.num, c2.s, c1.s);
        return (numeuals - c1.num) >= TOLERANCE;

    }

    NumberWithUnits operator*(const NumberWithUnits &c1, const double &c2) {
        return NumberWithUnits(c2 * c1.num, c1.s);
    }

    NumberWithUnits operator*(const double &c1, const NumberWithUnits &c2) {
        return NumberWithUnits(c1 * c2.num, c2.s);
    }

    ostream &operator<<(ostream &os, const NumberWithUnits &c) {
        return (os << c.num << '[' << c.s << ']');
    }

    istream &operator>>(istream &is, NumberWithUnits &c) {
        string str;
        getline(is, str, ']'); //Calls from IS to STR until he sees]

        string num;
        string unitIn;
        unsigned int i = 0;

        while (' ' == str[i]){
            i++;
        }

        while (('0' <= str[i] && str[i] <= '9') || '+' == str[i] || '-' == str[i] || '.' == str[i]){
            num += str[i++];
        }

        while (' ' == str[i] || str[i] == '['){
            i++;
        }

        while ('A' <= str[i] && str[i] <= 'z'){
            unitIn += str[i++];
        }

        if (!NumberWithUnits::checkUnit(unitIn)) {
            throw std::invalid_argument(unitIn + " is invalid unit");
        }
        c = NumberWithUnits(stod(num), unitIn);
        return is;
    }
}




