#include <QCoreApplication>
#include "calc.h"
#include "calculator_adaptor.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Calc *calc = new Calc(&app);

    new CalculatorAdaptor(calc);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/Calculator", calc);
    connection.registerService("com.deathstar.CalcService");

    return app.exec();
}
