#include "calc.h"

#include <QDebug>

Calc::Calc(QObject *parent)
    : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

Calc::~Calc() {}

double Calc::multiply(double factor1, double factor2)
{
    qDebug() << __PRETTY_FUNCTION__ << factor1 << factor2;
    double result = factor1 * factor2;
    emit newProduct(result);
    return result;
}

double Calc::divide(double dividend, double divisor)
{
    qDebug() << __PRETTY_FUNCTION__ << dividend << divisor;


    if (divisor == 0.0)
    {
        sendErrorReply(QDBusError::NotSupported, QString("Division by zero not allowed"));
        return 0.0;
    }
    else
    {
        double result = dividend / divisor;
        emit newQuotient(result);
        return result;
    }
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
