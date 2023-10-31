#ifndef _CALCULATE_H_
#define _CALCULATE_H_

class Calculate
{
    int m_index{ 0 };
    char m_histop[5];
    double m_histvalue[5];
    double m_value{ 0.0 };
    void addToHistory(char op, double value);
public:
    Calculate() = default;
    Calculate(Calculate& cc) {
        m_value = cc.m_value;
    }
    double getValue() const;
    double add(double value);
    double substract(double value);
    double multiply(double value);
    double divide(double value);
    bool lastOperation(char& op, double& value);
    void undo();
};

#endif // _CALCULATE_H_ 