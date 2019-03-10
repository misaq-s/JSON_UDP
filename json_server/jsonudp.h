#ifndef JSONUDP_H
#define JSONUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>


class JsonUdp : public QObject
{
    Q_OBJECT
public:
    explicit JsonUdp(QObject *parent = 0);
  //  void Send_Ave();
 void sendAverage(int ave);
signals:

public slots:

void receiveJson();
 // void readPendingDatagram();

private:
int sum_of_scors_,cont_of_scors_;
QByteArray Receive_Byte_;
 QByteArray send_data_;
QHostAddress sender_;
quint16 senderPort_;



QJsonValue json_val_;


QJsonDocument json_doc_;
QJsonParseError error_;

    QUdpSocket *socket;

};


#endif // JSONUDP_H

