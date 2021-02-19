#include "binomial.h"








int Binomial::Add(Binomial const& Addend)
{
    int value{0};
 
    if ((Addend.GetPower(1) == this->expression.at(0).second) && (Addend.GetPower(2) == this->expression.at(1).second))
    {
        this->expression.at(0).first = this->expression.at(0).first + Addend.GetCoefficient(1);
        this->expression.at(1).first = this->expression.at(1).first + Addend.GetCoefficient(2);
    }
    else
    {
        value = -1;
    }

    return value;
}

float Binomial::GetCoefficient(int index) const
{
    float value = ((index < 1) || (index > 2)) ? -1.0 : this->expression.at((index - 1)).first;
    return value;
}

int Binomial::GetPower(int index) const
{
    int value = ((index < 1) || (index > 2)) ? -1 : this->expression.at((index - 1)).second;
    return value;
}

void Binomial::Multiply(float number)
{

    for (auto& expression : this->expression)
    {
        expression.first = expression.first * number;
    }

}

void Binomial::Multiply(float coefficient, int power)
{

    for (auto& expression : this->expression)
    {
        expression.first = expression.first * coefficient;
        expression.second = expression.second + power;
    }

}

int Binomial::SetPower(int index, int power)
{
    int value{0};

    if ((index > 0) && (index < 3))
    {
        this->expression.at((index - 1)).second = (power > 0) ? power : 1;
    }
    else
    {
        value = -1;
    }

    return value;
}

Binomial::Binomial(float firstCoefficient, int firstPower, float secondCoefficient, int secondPower)
{
    this->expression.at(0).first = firstCoefficient;
    this->expression.at(0).second = (firstPower > 0) ? firstPower : 1;

    this->expression.at(1).first = secondCoefficient;
    this->expression.at(1).second = (secondPower > 0) ? secondPower : 1;
}
