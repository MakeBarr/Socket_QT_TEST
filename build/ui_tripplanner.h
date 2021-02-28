/********************************************************************************
** Form generated from reading UI file 'tripplanner.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLANNER_H
#define UI_TRIPPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TripPlanner
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QHBoxLayout *hboxLayout;
    QLabel *statusLabel;
    QProgressBar *progressBar;
    QTableWidget *tableWidget;
    QGroupBox *tripInfoGroupBox;
    QGridLayout *gridLayout1;
    QLabel *timeLabel;
    QDateTimeEdit *dateEdit;
    QDateTimeEdit *timeEdit;
    QLabel *dateLabel;
    QLabel *toLabel;
    QHBoxLayout *hboxLayout1;
    QRadioButton *departureRadioButton;
    QRadioButton *arrivalRadioButton;
    QComboBox *fromComboBox;
    QComboBox *toComboBox;
    QLabel *fromLabel;
    QComboBox *rangecomboBox;
    QLabel *label;

    void setupUi(QDialog *TripPlanner)
    {
        if (TripPlanner->objectName().isEmpty())
            TripPlanner->setObjectName(QStringLiteral("TripPlanner"));
        TripPlanner->resize(849, 465);
        gridLayout = new QGridLayout(TripPlanner);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(TripPlanner);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 0, 1, 5, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        statusLabel = new QLabel(TripPlanner);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(statusLabel);

        progressBar = new QProgressBar(TripPlanner);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setOrientation(Qt::Horizontal);

        hboxLayout->addWidget(progressBar);


        gridLayout->addLayout(hboxLayout, 4, 0, 1, 1);

        tableWidget = new QTableWidget(TripPlanner);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(619, 0));
        tableWidget->setColumnCount(6);

        gridLayout->addWidget(tableWidget, 2, 0, 1, 1);

        tripInfoGroupBox = new QGroupBox(TripPlanner);
        tripInfoGroupBox->setObjectName(QStringLiteral("tripInfoGroupBox"));
        gridLayout1 = new QGridLayout(tripInfoGroupBox);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        timeLabel = new QLabel(tripInfoGroupBox);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout1->addWidget(timeLabel, 5, 0, 1, 1);

        dateEdit = new QDateTimeEdit(tripInfoGroupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        gridLayout1->addWidget(dateEdit, 4, 1, 1, 1);

        timeEdit = new QDateTimeEdit(tripInfoGroupBox);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        gridLayout1->addWidget(timeEdit, 5, 1, 1, 1);

        dateLabel = new QLabel(tripInfoGroupBox);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        gridLayout1->addWidget(dateLabel, 4, 0, 1, 1);

        toLabel = new QLabel(tripInfoGroupBox);
        toLabel->setObjectName(QStringLiteral("toLabel"));

        gridLayout1->addWidget(toLabel, 1, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        departureRadioButton = new QRadioButton(tripInfoGroupBox);
        departureRadioButton->setObjectName(QStringLiteral("departureRadioButton"));
        departureRadioButton->setChecked(true);

        hboxLayout1->addWidget(departureRadioButton);

        arrivalRadioButton = new QRadioButton(tripInfoGroupBox);
        arrivalRadioButton->setObjectName(QStringLiteral("arrivalRadioButton"));

        hboxLayout1->addWidget(arrivalRadioButton);


        gridLayout1->addLayout(hboxLayout1, 6, 0, 1, 2);

        fromComboBox = new QComboBox(tripInfoGroupBox);
        fromComboBox->setObjectName(QStringLiteral("fromComboBox"));

        gridLayout1->addWidget(fromComboBox, 0, 1, 1, 1);

        toComboBox = new QComboBox(tripInfoGroupBox);
        toComboBox->setObjectName(QStringLiteral("toComboBox"));

        gridLayout1->addWidget(toComboBox, 1, 1, 1, 1);

        fromLabel = new QLabel(tripInfoGroupBox);
        fromLabel->setObjectName(QStringLiteral("fromLabel"));

        gridLayout1->addWidget(fromLabel, 0, 0, 1, 1);

        rangecomboBox = new QComboBox(tripInfoGroupBox);
        rangecomboBox->setObjectName(QStringLiteral("rangecomboBox"));

        gridLayout1->addWidget(rangecomboBox, 3, 1, 1, 1);

        label = new QLabel(tripInfoGroupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout1->addWidget(label, 3, 0, 1, 1);


        gridLayout->addWidget(tripInfoGroupBox, 1, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        timeLabel->setBuddy(timeEdit);
        dateLabel->setBuddy(dateEdit);
        toLabel->setBuddy(toComboBox);
        fromLabel->setBuddy(fromComboBox);
#endif // QT_NO_SHORTCUT

        retranslateUi(TripPlanner);

        fromComboBox->setCurrentIndex(0);
        toComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TripPlanner);
    } // setupUi

    void retranslateUi(QDialog *TripPlanner)
    {
        TripPlanner->setWindowTitle(QApplication::translate("TripPlanner", "Trip Planner", 0));
        statusLabel->setText(QApplication::translate("TripPlanner", "Ready", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TripPlanner", "Time", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TripPlanner", "Data1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("TripPlanner", "Data2", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("TripPlanner", "Data3", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("TripPlanner", "Changes", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("TripPlanner", "Type", 0));
        tripInfoGroupBox->setTitle(QApplication::translate("TripPlanner", "Information", 0));
        timeLabel->setText(QApplication::translate("TripPlanner", "Signal Events AT", 0));
        dateEdit->setDisplayFormat(QApplication::translate("TripPlanner", "yyyy-MM-dd", 0));
        timeEdit->setDisplayFormat(QApplication::translate("TripPlanner", "hh:mm:ss", 0));
        dateLabel->setText(QApplication::translate("TripPlanner", "&Date:", 0));
        toLabel->setText(QApplication::translate("TripPlanner", "Channel", 0));
        departureRadioButton->setText(QApplication::translate("TripPlanner", "READ", 0));
        departureRadioButton->setShortcut(QApplication::translate("TripPlanner", "Alt+E", 0));
        arrivalRadioButton->setText(QApplication::translate("TripPlanner", "&WRITE", 0));
        arrivalRadioButton->setShortcut(QApplication::translate("TripPlanner", "Alt+A", 0));
        fromComboBox->clear();
        fromComboBox->insertItems(0, QStringList()
         << QApplication::translate("TripPlanner", "start_measure", 0)
         << QApplication::translate("TripPlanner", "set_range", 0)
         << QApplication::translate("TripPlanner", "stop_measure", 0)
         << QApplication::translate("TripPlanner", "get_status", 0)
         << QApplication::translate("TripPlanner", "get_result", 0)
         << QApplication::translate("TripPlanner", "new1", 0)
         << QApplication::translate("TripPlanner", "new2", 0)
         << QApplication::translate("TripPlanner", "new3", 0)
         << QString()
        );
        toComboBox->clear();
        toComboBox->insertItems(0, QStringList()
         << QApplication::translate("TripPlanner", "channel0", 0)
         << QApplication::translate("TripPlanner", "channel1", 0)
         << QApplication::translate("TripPlanner", "channel2", 0)
         << QApplication::translate("TripPlanner", "channel3", 0)
         << QApplication::translate("TripPlanner", "channel4", 0)
         << QApplication::translate("TripPlanner", "channel5", 0)
         << QApplication::translate("TripPlanner", "channel6", 0)
         << QApplication::translate("TripPlanner", "channel7", 0)
         << QApplication::translate("TripPlanner", "channel8", 0)
         << QApplication::translate("TripPlanner", "channel9", 0)
         << QApplication::translate("TripPlanner", "channel10", 0)
         << QApplication::translate("TripPlanner", "channel11", 0)
         << QApplication::translate("TripPlanner", "channel12", 0)
         << QApplication::translate("TripPlanner", "channel13", 0)
         << QApplication::translate("TripPlanner", "channel14", 0)
         << QApplication::translate("TripPlanner", "channel15", 0)
        );
        fromLabel->setText(QApplication::translate("TripPlanner", "Signal Set", 0));
        rangecomboBox->clear();
        rangecomboBox->insertItems(0, QStringList()
         << QApplication::translate("TripPlanner", "range0", 0)
         << QApplication::translate("TripPlanner", "range1", 0)
         << QApplication::translate("TripPlanner", "range2", 0)
         << QApplication::translate("TripPlanner", "range3", 0)
        );
        label->setText(QApplication::translate("TripPlanner", "Range", 0));
    } // retranslateUi

};

namespace Ui {
    class TripPlanner: public Ui_TripPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLANNER_H
