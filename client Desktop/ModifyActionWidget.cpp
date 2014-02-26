#include "ModifyActionWidget.h"

/**
 * @brief ModActionWidget::ModActionWidget
 * @param events
 */
ModActionWidget::ModActionWidget(QStringList events) : QWidget()
{
    principalLayout = new QVBoxLayout;
        eventsBox = new QComboBox;

        for(int i = 0; i < events.count(); ++i)
            eventsBox->addItem(events.at(i));

        roriSay = new QLineEdit(tr("What rori will say"));
        rorifFile = new QLineEdit(tr(".rorif file to execute"));
        btnMod = new QPushButton(tr("Validate"));
    principalLayout->addWidget(eventsBox);
    principalLayout->addWidget(roriSay);
    principalLayout->addWidget(rorifFile);
    principalLayout->addWidget(btnMod);
    this->setLayout(principalLayout);
}
