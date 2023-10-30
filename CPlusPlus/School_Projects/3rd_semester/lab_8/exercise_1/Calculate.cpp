#include "Calculate.h"
#include <iostream>
using namespace std;

double Calculate::getValue() const
{
    return m_value;
}

double Calculate::add(double value)
{
    m_value += value;
    return m_value;
}

double Calculate::substract(double value)
{
    m_value -= value;
    return m_value;
}

double Calculate::multiply(double value)
{
    m_value *= value;
    return m_value;
}

double Calculate::divide(double value)
{
    m_value /= value;
    return m_value;
}