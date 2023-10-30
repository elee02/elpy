#ifndef _CALCULATE_H_
#define _CALCULATE_H_

class Calculate
{
    double m_value;
public:
    Calculate(double value = 0) : m_value{value} {};
    double getValue() const;
    double add(double value);
    double substract(double value);
    double multiply(double value);
    double divide(double value);
};

#endif // _CALCULATE_H_ 