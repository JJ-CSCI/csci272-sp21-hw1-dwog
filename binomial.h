#pragma once
#include <array>
#include <utility>






class Binomial
{
private:
    std::array<std::pair<float, int>, 2> expression;

public:
    int Add(Binomial const& Addend);
    float GetCoefficient(int index) const;
    int GetPower(int index) const;
    void Multiply(float number);
    void Multiply(float coefficient, int power);
    int SetPower(int index, int power);

    Binomial(
    float firstCoefficient = 1.0,
    int firstPower = 1,
    float secondCoefficient = 1.0,
    int secondPower = 1);

    };

