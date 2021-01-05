#ifndef CALC_H
#define CALC_H

#include <QObject>
#include <QDBusContext>
#include <QDBusError>


class Calc : public QObject, protected QDBusContext
{
    Q_OBJECT;
    Q_CLASSINFO("D-Bus Interface", "com.deathstar.Calculator");

public:
    Calc(QObject *parent);
    virtual ~Calc();

public slots:
    double multiply(double factor0, double factor2);
    double divide(double divident, double divisor);
    double add(double a, double b);
    double subtract(double a, double b);

signals:
    void newProduct(double product);
    void newQuotient(double quotient);
    void newSum(double result);
    void newDifference(double result);
};

#endif // CALC_H
