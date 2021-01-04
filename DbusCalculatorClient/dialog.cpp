#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    calc = new com::deathstar::Calculator("com.deathstar.CalcService", "/Calculator",
                           QDBusConnection::sessionBus(), this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnAdd_clicked()
{
    ui->lblOperator->setText("+");

    Params params = getParams();

    showResult(calc->add(params.a, params.b));
}


void Dialog::on_btnSub_clicked()
{
    ui->lblOperator->setText("-");

    Params params = getParams();

    showResult(calc->subtract(params.a, params.b));
}

void Dialog::on_btnMult_clicked()
{
    ui->lblOperator->setText("*");

    Params params = getParams();

    showResult(calc->multiply(params.a, params.b));
}

void Dialog::on_btnDiv_clicked()
{
    ui->lblOperator->setText("/");

    Params params = getParams();

    showResult(calc->divide(params.a, params.b));
}

Params Dialog::getParams()
{
    Params result;
    bool ok;
    double value;



    value = ui->edtParamA->text().toDouble(&ok);

    if (!ok)
    {
        result.a = 0.0;
        result.b = 0.0;
        return result;
    }

    result.a = value;

    value = ui->edtParamB->text().toDouble(&ok);

    if (!ok)
    {
        result.a = 0.0;
        result.b = 0.0;
        return result;
    }

    result.b = value;

    return  result;
}

void Dialog::showResult(QDBusReply<double> reply)
{
    if (reply.isValid())
    {
        ui->lblResult->setText(QString("%1").arg(reply.value()));
    }
    else
    {
        ui->lblResult->setText(reply.error().name());
    }
}
