#include <cmath>
#include "Capacitor.h"

using namespace std;

const double PI = 4.0 * atan(1.0);

    // normalize the value of a capacitor: 0.0000047 becomes 4.7 uF (object remains unchanged)
    // flatten value of a capacitor: 4.7 uF becomes 0.0000047 (updates object)

    // must scale: aValue < 1.0
bool Capacitor::mustScale(double aValue) const
{
    return (aValue < 1.0);
}

    // scaling multiplier: 1000.0
const double Capacitor::getMultiplier() const
{
    return 1000.0;
}

    // major unit: "F"
const std::string Capacitor::getMajorUnit() const
{
    return "F";
}

    // minor units: "Fmunp"
const std::string Capacitor::getMinorUnits() const
{
    return "Fmunp";
}

Capacitor::Capacitor(double aBaseValue) : PassiveResistor(aBaseValue) {}

    // returns frequency-dependent capacitive reactance value
double Capacitor::getValue(double aFrequency) const
{
    return 1.0/(2 * PI * aFrequency * getBaseValue());
}