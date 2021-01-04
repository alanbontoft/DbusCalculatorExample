#include "calc.h"

#include <QDebug>

Calc::Calc(QObject *parent)
    : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

Calc::~Calc() {}

double Calc::multiply(double factor0, double factor1)
{
    qDebug() << __PRETTY_FUNCTION__ << factor0 << factor1;
    double product = factor0 * factor1;
    emit newProduct(product);
    return product;
}

double Calc::divide(double dividend, double divisor)
{
    qDebug() << __PRETTY_FUNCTION__ << dividend << divisor;
    double quotient = dividend / divisor;
    emit newQuotient(quotient);
    return quotient;
}

double Calc::add(double a, double b)
{
    qDebug() << __PRETTY_FUNCTION__ << a << b;
    double result = a + b;
    emit newSum(result);
    return result;
}

double Calc::subtract(double a, double b)
{
    qDebug() << __PRETTY_FUNCTION__ << a << b;
    double result = a - b;
    emit newDifference(result);
    return result;
}
