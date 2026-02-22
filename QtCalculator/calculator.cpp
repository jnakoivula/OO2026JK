#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    //start inputs for number1
    state = 1;

    //list of all buttons
    QList<QPushButton*> digitButtons = {ui->N0, ui->N1, ui->N2, ui->N3, ui->N4, ui->N5, ui->N6, ui->N7, ui->N8, ui->N9};

    //all digits connected to the same handler
    for (QPushButton *button : digitButtons) {
        connect(button, &QPushButton::clicked, this, &Calculator::numberClickedHandler);
    }

    //same thing for operand buttons
    QList<QPushButton*> operandButtons = {ui->add, ui->sub, ui->mul, ui->div};
    for (QPushButton *button : operandButtons) {
        connect(button, &QPushButton::clicked, this, &Calculator::addSubMulDivClickHandler);
    }
    //same thing for clear and Enter
    QList<QPushButton*> clearEnterButtons = {ui->clear, ui->enter};
    for (QPushButton *button : clearEnterButtons) {
        connect(button, &QPushButton::clicked, this, &Calculator::clearAndEnterClickHandler);
    }
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::numberClickedHandler()
{
    //return the qobject that sent the signal -> convert it to a QPushButton pointer
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    //Get the name of the button that was pressed
    QString name = button->objectName();
    qDebug() << "Button name: " << name;

    //Used to extract the digit from the object name i.e. "N1" = 1, "N9" = 9
    QString digit = name.last(1);

    //sets pressed number in its corresponding box
    if (state == 1) {
        number1 += digit;
        ui->num1->setText(number1);
    } else {
        number2 += digit;
        ui->num2->setText(number2);
    }
}

void Calculator::clearAndEnterClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    QString name = button ->objectName();
    qDebug() << "Button name: " << name;

        //Clear resets the calculator
    if (name == "clear") {
        state = 1;
        number1.clear();
        number2.clear();
        resetLineEdits();
        //Enter performs the calculation
    } else if (name == "enter") {

        //convert QString to float
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();

        qDebug() <<"Number 1 = " << n1 << " and number 2 = " << n2 << Qt::endl;
        //operations for selected operand
        switch (operand) {
        case 0:
            result = n1+n2;
            break;
        case 1:
            result = n1-n2;
            break;
        case 2:
            result = n1*n2;
            break;
        case 3:
            //Can't divide by 0
            if (n2 == 0) {
                ui->result->setText("Error");
                return;
            }
            result = n1/n2;
            break;
        }
        //result in result box, converted back to QString
        ui->result->setText(QString::number(result));
        //if you want to keep adding operands to the result
        number1 = QString::number(result);
        number2.clear();
        state = 2;
    }
}

void Calculator::addSubMulDivClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    QString name = button ->objectName();
    qDebug() << "Button name: " << name;

    //determines which operand is being used, stored as an int for switch(operand)
    if (name == "add")
        operand = 0;
    else if (name == "sub")
        operand = 1;
    else if (name == "mul")
        operand = 2;
    else if (name == "div")
        operand = 3;
    //start inputs for number2
    state = 2;
}

void Calculator::resetLineEdits()
{
    //resets the UI elements
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
}
