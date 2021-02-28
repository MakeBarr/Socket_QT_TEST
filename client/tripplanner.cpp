#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

#include "tripplanner.h"

const int STR_EQUAL=0;

char Report1[]  = "Report1___1 ____           ____   ___.";
char Report2[]  = "          _________           __   __ ";
char Report3[]  = "Report3___WRT____           ____   __.";
char Report4[]  = "Report4___WRT_______           _   __.";
char Report5[]  = "Report5___________           __   ___.";
char Report6[]  = "Report6____________              ____.";

char State_str[72];
int Commande;

char G_buffer[72];


TripPlanner::TripPlanner(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    searchButton = buttonBox->addButton(tr("&Send"),     QDialogButtonBox::ActionRole);
    stopButton = buttonBox->addButton(tr("S&top"),         QDialogButtonBox::ActionRole);
    stopButton = buttonBox->addButton(tr("Save"),         QDialogButtonBox::ActionRole);
    stopButton->setEnabled(false);
    buttonBox->button(QDialogButtonBox::Close)->setText(tr("&Quit"));

    QDateTime dateTime = QDateTime::currentDateTime();
    dateEdit->setDate(dateTime.date());
    timeEdit->setTime(QTime(dateTime.time().hour(), 0));

    progressBar->hide();
    progressBar->setSizePolicy(QSizePolicy::Preferred,     QSizePolicy::Ignored);

    tableWidget->verticalHeader()->hide();
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(searchButton, SIGNAL(clicked()),   this, SLOT(connectToServer()));
    connect(stopButton, SIGNAL(clicked()),     this, SLOT(stopSearch()));
    connect(buttonBox, SIGNAL(rejected()),     this, SLOT(reject()));

    connect(&tcpSocket, SIGNAL(connected()),     this, SLOT(sendRequest()));
    connect(&tcpSocket, SIGNAL(disconnected()),  this, SLOT(connectionClosedByServer()));
    connect(&tcpSocket, SIGNAL(readyRead()),     this, SLOT(updateTableWidget()));
    connect(&tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),  this, SLOT(error()));
}

void TripPlanner::connectToServer()
{
//#if 1
    tcpSocket.connectToHost(QHostAddress::LocalHost, 5001);
//#else
//    tcpSocket.connectToHost("tripserver.zugbahn.de", 6178);
//#endif

    tableWidget->setRowCount(0);
    searchButton->setEnabled(false);
    stopButton->setEnabled(true);
    statusLabel->setText(tr("Connecting to server..."));
    progressBar->show();

    nextBlockSize = 0;
}

void TripPlanner::sendRequest()
{
    int numRead = 0, numReadTotal = 0;
    char buffer[50];
    char Wbuffer[72];
    char Wbuffer1[72];
    char Wbuffer2[72];
       QString qstr("test__                                 _____")  ;
    QString qstr1("test__                                 _____")  ;
    QString qstr2("test__                                 _____")  ;

    QString c_start   = "start_measure";
    QString c_set     = "set_range";
    QString c_stop    = "stop_measure";
    QString c_get_s   = "get_status";
    QString c_get_res = "get_result";

    float pGOOD,SizO,SizI;


//    QByteArray block;

    QByteArray block("test");
    block.prepend("Neo ");         //
    block.append(" N1");          //
    block.replace(5, 3, "&");       //

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);


    qstr = fromComboBox->currentText();
    qstr1 = toComboBox->currentText();
    qstr2 = rangecomboBox->currentText();
    strncpy(Wbuffer, qPrintable(qstr), 16);
    strncpy(Wbuffer1, qPrintable(qstr1), 16);
    strncpy(Wbuffer2, qPrintable(qstr2), 16);


    sprintf (Report1, "%s %s %c              ", Wbuffer, Wbuffer1 , ' ');
    sprintf (Report3, "%s %d %c",    "P3     ", 22 , ' ');
    sprintf (Report4, "%s %7.4f %c", "___  _  ",SizO , ' ');
    sprintf (Report5, "%s %7.4f %c", "       ",SizI , ' ');
    sprintf (Report6, "%s %7.4f %s", "   ", pGOOD , "    ");

    Commande = 0;
 if (QString::compare(qstr, c_get_res) == STR_EQUAL) {
    Commande = 5;
 };
     tcpSocket.write(Report1);

    statusLabel->setText(tr("Sending request..."));

    statusLabel->setText(tr("READ from server"));



}

void TripPlanner::updateTableWidget()
{
    float Res0,Res1,Res2,Res3;
    QDataStream in(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_3);

    statusLabel->setText(tr("Table Works"));

        int row = tableWidget->rowCount();



        QDate date;
        QTime departureTime;
        QTime arrivalTime;
        quint16 duration;
        quint8 changes;
        QString trainType;
        QString trainType1;
        QString trainType2;
        QString trainType3;

        tcpSocket.read(G_buffer, 42);


          for(quint32 i = 0; i < 71; i++)
          {
              if(G_buffer[i] == ',') break;

              if(G_buffer[i] != '\0')
              {
               trainType.append(G_buffer[i]);
              };

          };

            Res0=0;Res1=0;
            if ( Commande == 5){
                sscanf (G_buffer,"%4s%f%f",State_str, &Res0, &Res1 );
            }; Commande == 0;

        tableWidget->setRowCount(row + 1);

        QStringList fields;
        fields << trainType
               << QString::number(Res0)
               << QString::number(Res1)
               << tr("%1 hr %2 min").arg(duration / 60)
                                    .arg(duration % 60)
               << QString::number(Commande)
               << trainType;

        for (int i = 0; i < fields.count(); ++i)
            tableWidget->setItem(row, i,
                                 new QTableWidgetItem(fields[i]));
        nextBlockSize = 0;

        statusLabel->setText(tr(G_buffer));

}

void TripPlanner::stopSearch()
{
//    statusLabel->setText(tr("Search stopped"));
    closeConnection();
}

void TripPlanner::connectionClosedByServer()
{
    if (nextBlockSize != 0xFFFF)
//       statusLabel->setText(tr("Error: Connection closed by server"));
    closeConnection();
}

void TripPlanner::error()
{
//    statusLabel->setText(tcpSocket.errorString());
    closeConnection();
}

void TripPlanner::closeConnection()
{
    tcpSocket.close();
    searchButton->setEnabled(true);
    stopButton->setEnabled(false);
    progressBar->hide();
}
