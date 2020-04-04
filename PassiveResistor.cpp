#include "PassiveResistor.h"

#include <stdexcept>
#include <iostream>

using namespace std;

PassiveResistor::PassiveResistor(double aBaseValue)
{
    setBaseValue(aBaseValue);
}

const string PassiveResistor::getMajorUnit() const
{
    return "Ohm";
}

const string PassiveResistor::getMinorUnits() const
{
    return "OkM";
}

void PassiveResistor::setBaseValue(double aBaseValue)
{
    fBaseValue = aBaseValue;
}

double PassiveResistor::getBaseValue() const
{
    return fBaseValue;
}

bool PassiveResistor::mustScale(double aValue) const
{
    return (aValue >= 1000.0);
}

const double PassiveResistor::getMultiplier() const
{
    return 0.001;
}

double PassiveResistor::getValue(double aFrequency) const
{
    return getBaseValue();
}

double PassiveResistor::getPotential(double aCurrent, double aFrequency) const
{   // V = I * R
    return this->getValue(aFrequency) * aCurrent;
}

double PassiveResistor::getCurrent(double aVoltage, double aFrequency) const
{   // I = V / R
    return aVoltage / this->getValue(aFrequency);
}

istream& operator>> (std::istream& aIStream, PassiveResistor& aObject)
{
    double lValue;    
    string lUnit;    
    aIStream >> lValue >> lUnit;    
    aObject.flatten(lValue, lUnit);    
    return aIStream;
}

ostream& operator<< (std::ostream& aOStream, const PassiveResistor& aObject)
{
    double lValue;    
    string lUnit;    
    aObject.normalize(lValue, lUnit);    
    aOStream << lValue << lUnit;    
    return aOStream;
}