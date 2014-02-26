#include "AddActionWidget.h"

/**
 * @brief create an action into diary
 * @param date
 */
AddActionWidget::AddActionWidget(QString date) : QWidget()
{
    layoutPrincipal = new QFormLayout;
        roriSay = new QLineEdit;
        rorifFile = new QLineEdit;
        noneDate = new QCheckBox;
        dayln = new QLineEdit(date);
        dayln->setEnabled(false);
        hourChB = new QCheckBox;
        hour = new QSpinBox;
        hour->setMaximum(23);
        hour->setMinimum(0);
        btnOk = new QPushButton("Validate");

        layoutPrincipal->addRow(tr("What RORI will say :"), roriSay);
        layoutPrincipal->addRow(tr(".rorif file to execute :"), rorifFile);
        layoutPrincipal->addRow(tr("Check if date is not important :"), noneDate);
        layoutPrincipal->addRow(tr("Date"), dayln);
        layoutPrincipal->addRow(tr("Check if hour is not important :"), hourChB);
        layoutPrincipal->addRow(tr("Hour :"), hour);
        layoutPrincipal->addWidget(btnOk);
    this->setLayout(layoutPrincipal);
}

