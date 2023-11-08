#include "Calculate.h"
#include <iostream>
using namespace std;

double Calculate::getValue() const
{
    return m_value;
}
void Calculate::addToHistory(char op, double value)
{
    if (m_index == 5) {
        for (int i = 0; i < 4; ++i) {
            m_histop[i] = m_histop[i + 1];
            m_histvalue[i] = m_histvalue[i + 1];
        }
        m_index = 4;
    }
    m_histop[m_index] = op;
    m_histvalue[m_index] = value;
    m_index++;
}

double Calculate::add(double value)
{
    addToHistory('+', value);
    return m_value += value;
}

double Calculate::substract(double value)
{
    addToHistory('-', value);
    return m_value -= value;
}

double Calculate::multiply(double value)
{
    addToHistory('*', value);
    return m_value *= value;
}

double Calculate::divide(double value)
{
    addToHistory('/', value);
    return m_value /= value;
}

bool Calculate::lastOperation(char& op, double& value)
{
    if (m_index == 0)
        return false;
    op = m_histop[m_index - 1];
    value = m_histvalue[m_index - 1];
    return true;
}

void Calculate::undo()
{
    m_index--;
    switch (m_histop[m_index]) {
    case '+':
        m_value -= m_histvalue[m_index];
        break;
    case '-':
        m_value += m_histvalue[m_index];
        break;
    case '*':
        m_value /= m_histvalue[m_index];
        break;
    case '/':
        m_value *= m_histvalue[m_index];
        break;
    }
}