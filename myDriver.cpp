#include "distance.h"

using namespace std;

int main () {
    //testing general output, input, reduction, and getters/setter
    Distance d(1), c(2, 1), h(1, 2), e, f(1, 1), g(0, 1), i(4, 25), j(4, -13), k(-4, 10), p(-2, -1);
    cout << "Testing general output, input, reduction, and getters/setters: " << endl;
    cout << d << endl;
    cout << c << endl;
    cout << h << endl;
    cout << e << endl;
    cout << f << endl;
    cout << g << endl;
    cout << i << endl;
    cout << j << endl;
    cout << p << endl;
    cout << k << endl;
    Distance n;
    cout << "Enter values for distance n, feet, then inches: " << endl;
    cin >> n;
    cout << n << endl;
    cout << "Changing values for n using setter methods: " << endl;
    n.putFeet(0);
    n.putInch(-1);
    n.putFeet(4);
    cout << n << endl << endl;

    //testing arithmetic operators
    cout << "Testing overloaded addition operator: " << endl;
    Distance x;
    x = c + h;
    cout << c << " + " << h << " = " << x << endl;
    Distance y;
    y = x + k;
    cout << x << " + " << k << " = " << y << endl;
    cout << "Testing overloaded subtraction operator: " << endl;
    Distance t(-1, 1);
    cout << "t = " << t << " & -t = " << -t << endl;
    Distance z(2, 2);
    Distance s;
    s = z - x - t;
    cout << z << " - " << x << " - " << t << " = " << s << endl;
    cout << "Testing overloaded multiplication operator: " << endl;
    Distance d1(-5, 30), d2(5, -31);
    cout << (double(d1.getFeet()) + double(d1.getInch())/12) << " * " << (double(d2.getFeet()) + double(d2.getInch())/12) << endl;
    cout << "Sqfeet (" << d1 << " * " << d2 << ") = " << (d1 * d2) << endl;
    cout << "Testing overloaded division operator: " << endl;
    cout << (double(d1.getFeet()) + double(d1.getInch())/12) << " / " << (double(d2.getFeet()) + double(d2.getInch())/12) << endl;
    cout << "Ratio (" << d1 << " / " << d2 << ") = " << (d1 / d2) << endl << endl;

    //testing comparison operators 
    Distance d3(-2, -6);
    cout << "Testing operator>: " << endl;
    cout << d1 << " is" << ((d1 > d2) ? " > " : " not > ") << d2 << " according to operator>." <<  endl;
    cout << d2 << " is" << ((d2 > d1) ? " > " : " not > ") << d1 << " according to operator>." <<  endl;
    cout << "Testing operator<: " << endl;
    cout << d1 << " is" << ((d1 < d2) ? " < " : " not < ") << d2 << " according to operator<." <<  endl;
    cout << d2 << " is" << ((d2 < d1) ? " < " : " not < ") << d1 << " according to operator<." <<  endl;
    cout << "Testing operator>=: " << endl;
    cout << d1 << " is" << ((d1 >= d2) ? " >= " : " not >= ") << d2 << " according to operator>=." <<  endl;
    cout << d2 << " is" << ((d2 >= d1) ? " >= " : " not >= ") << d1 << " according to operator>=." <<  endl;
    cout << d1 << " is" << ((d1 >= d3) ? " >= " : " not >= ") << d3 << " according to operator>=." <<  endl;
    cout << "Testing operator<=: " << endl;
    cout << d1 << " is" << ((d1 <= d2) ? " <= " : " not <= ") << d2 << " according to operator<=." <<  endl;
    cout << d2 << " is" << ((d2 <= d1) ? " <= " : " not <= ") << d1 << " according to operator<=." <<  endl;
    cout << d1 << " is" << ((d1 <= d3) ? " <= " : " not <= ") << d3 << " according to operator<=." <<  endl;
    cout << "Testing operator==: " << endl;
    cout << d1 << " is" << ((d1 == d3) ? " == " : " not == ") << d3 << " according to operator==." <<  endl;
    cout << d1 << " is" << ((d1 == d2) ? " == " : " not == ") << d2 << " according to operator==." <<  endl;
    cout << "Testing operator!=: " << endl;
    cout << d1 << " is" << ((d1 != d3) ? " != " : " not != ") << d3 << " according to operator!=." <<  endl;
    cout << d1 << " is" << ((d1 != d2) ? " != " : " not != ") << d2 << " according to operator!=." <<  endl << endl;

    //testing assignment operators
    Distance d4(2, 3), d5(0, 7);
    cout << "Testing assignment operator+=: " << endl;
    cout << d4 << " + " << d5;
    d4 += d5;
    cout << " = the now changed " << d4 << endl;
    cout << "Testing assignment operator-=: " << endl;
    cout << d4 << " - " << d5;
    d4 -= d5;
    cout << " = the now changed " << d4 << endl << endl;

    //extra tests
    Distance d6(1), d7;
    cout << d6 << " is" << ((d6 > d7) ? " > " : " not > ") << d7 << " according to operator>." <<  endl;
    cout << d6 << " is" << ((d6 < d7) ? " < " : " not < ") << d7 << " according to operator<." <<  endl;

    return 0;
}