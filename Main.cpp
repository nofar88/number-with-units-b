#include "NumberWithUnits.hpp"
using ariel::NumberWithUnits;

#include <iostream>
#include <stdexcept>
using namespace std;



int main() {
//"km and m case"
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{1000, "mm"};

    NumberWithUnits aAddb = a + b;
    cout << aAddb << endl;// print "3km"
//    NumberWithUnits bAdda = b+a;
//    cout << bAdda <<  endl;// print "3000m"
//    NumberWithUnits aMb = a - b;
//    cout << aMb << endl;// print "1km"
//    NumberWithUnits bMa = b-a;
//    cout << bMa << endl;// print "-1000m"
//    NumberWithUnits bMadouble =3*bMa;
//    cout << bMadouble  << endl;// print "-3000m"
//    NumberWithUnits aMbdouble =3*aMb;
//    cout << aMbdouble  << endl;// print "3km"
//    NumberWithUnits doubleaMb =aMb*3;
//    cout << doubleaMb << endl;// print "3km"
//    NumberWithUnits bMadouble1 =(-3)*bMa;
//    cout << bMadouble1  << endl;// print "3000m"
//
//    cout<< (a!=b)<<endl;//print true/1
//    cout<< (b<a)<<endl;//print true/1
//    cout<< (b<=a)<<endl;//print true/1
//    cout<< (a>b)<<endl;//print true/1
//    cout<< (a>=b)<<endl;//print true/1
//    cout<< (aMbdouble!=bMadouble)<<endl;//print true/1
//    cout<< (aMbdouble==bMadouble1)<<endl;//print true/1
//    cout << a << endl;// Prints "2km". Note that a has changed.
//    cout << b << endl;// Prints "1000m". Note that a has changed.
//    cout << (-a) << endl;// Prints "-2km".
//    cout << (-b) << endl;// Prints "-1000m".
//    cout << (a++) << endl;// Prints "2km".
//    cout << (b++) << endl;// Prints "1000m".
//    cout << (++a) << endl;// Prints "4km".
//    cout << (++b) << endl;// Prints "1002m".
//    cout << (a+=a) << endl;// Prints "8km".
//    cout << (a+=b) << endl;// Prints "9.002km".
//    cout << (b-=a) << endl;// Prints "-8000m".
//
//    cout <<"_____________________________________________________" << endl;
//
//    //"m and cm case"
//
//    NumberWithUnits a1{20, "cm"};
//    NumberWithUnits b1{5, "m"};
//
//    NumberWithUnits a1Addb1 = a1 + b1;
//    cout << a1Addb1 << endl;// print "520cm"
//    NumberWithUnits b1Adda1 = b1+a1;
//    cout << b1Adda1  << endl;// print "5.2m"
//    NumberWithUnits a1Mb1 = a1 - b1;
//    cout << a1Mb1 << endl;// print "-480cm"
//    NumberWithUnits b1Ma1 = b1-a1;
//    cout << b1Ma1 << endl;// print "4.8m"
//    NumberWithUnits b1Ma1double =-3*b1Ma1;
//    cout << b1Ma1double << endl;// print "-14.4m"
//    NumberWithUnits a1Mb1double =-3*a1Mb1;
//    cout << a1Mb1double  << endl;// print "1440cm"
//    NumberWithUnits doublea1Mb1 =a1Mb1*(-3);
//    cout << doublea1Mb1<< endl;// print "1440cm"
//    NumberWithUnits b1Ma1double1 =(-3)*b1Ma1;
//    cout << b1Ma1double1  << endl;// print "-14.4m"
//
//    cout<< (a1!=b1)<<endl;//print true/1
//    cout<< (b1>a1)<<endl;//print true/1
//    cout<< (b1>=a1)<<endl;//print true/1
//    cout<< (a1 > b1Ma1double)<<endl;//print true/1
//    cout<< (a1Mb1double != b1Ma1double)<<endl;//print true/1
//    cout << a1 << endl;// Prints "20cm". Note that a has changed.
//    cout << b1 << endl;// Prints "5m". Note that a has changed.
//    cout << (-a1) << endl;// Prints "-20cm".
//    cout << (-b1) << endl;// Prints "-5m".
//    cout << (a1++) << endl;// Prints "20cm".
//    cout << (b1++) << endl;// Prints "5m".
//    cout << (++a1) << endl;// Prints "22cm".
//    cout << (++b1) << endl;// Prints "7m".
//    cout << (a1+=a1) << endl;// Prints "44cm".
//    cout << (a1+=b1) << endl;// Prints "744cm".
//    cout << (b1-=a1) << endl;// Prints "-0.44m".
//
//    cout <<"_____________________________________________________" << endl;
//
//
//    //"km and cm case"
//
//    NumberWithUnits a2{16, "km"};
//    NumberWithUnits b2{10, "cm"};
//
//    NumberWithUnits a2Addb2= a2 + b2;
//    cout << a2Addb2 << endl;// print "16.0001km"
//    NumberWithUnits b2Adda2 = b2+a2;
//    cout << b2Adda2  << endl;// print "1600010cm"
//    NumberWithUnits a2Mb2 = a2 - b2;
//    cout << a2Mb2 << endl;// print "15.9999km"
//    NumberWithUnits b2Ma2 = b2-a2;
//    cout << b2Ma2 << endl;// print "-1599990cm"
//    NumberWithUnits b2Ma2double =-3*b2Ma2;
//    cout << b2Ma2double << endl;// print "4799970cm"
//    NumberWithUnits a2Mb2double =-3*a2Mb2;
//    cout << a2Mb2double  << endl;// print "-47.9997km"
//
//
//    cout<< (a2!=b2)<<endl;//print true/1
//    cout<< (b2<a2)<<endl;//print true/1
//    cout<< (b2<=a2)<<endl;//print true/1
//    cout<< (a2 < b2Ma2double)<<endl;//print true/1
//    cout<< (a2Mb2double != b2Ma2double)<<endl;//print true/1
//    cout << a2 << endl;// Prints "16km". Note that a has changed.
//    cout << b2 << endl;// Prints "10cm". Note that a has changed.
//    cout << (-a2) << endl;// Prints "-16km".
//    cout << (-b2) << endl;// Prints "-10cm".
//    cout << (a2++) << endl;// Prints "16km".
//    cout << (b2++) << endl;// Prints "10cm".





}

