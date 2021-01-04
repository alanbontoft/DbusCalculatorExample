#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "calculator_interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

struct Params
{
    double a;
    double b;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnAdd_clicked();

    void on_btnSub_clicked();

    void on_btnMult_clicked();

    void on_btnDiv_clicked();

    Params getParams();

    void showResult(QDBusReply<double> reply);

private:
    Ui::Dialog *ui;
    com::deathstar::Calculator *calc;
};
#endif // DIALOG_H
