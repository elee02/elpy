#ifndef _CALCULATE_H_
#define _CALCULATE_H_

class Calculate
{
    double m_value;
public:
    double getValue() const;
    double add(double value);
    double substract(double value);
    double multiply(double value);
    double divide(double value);
};

#endif // _CALCULATE_H_ 