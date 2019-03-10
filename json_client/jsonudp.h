#ifndef JSONUDP_H
#define JSONUDP_H

#include <QObject>
#include <QUdpSocket>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
class JsonUdp : public QObject
{
    Q_OBJECT
public:
    explicit JsonUdp(QObject *parent = 0);
   // void Send_UDP();
    void sendJson();
signals:

public slots:
    void receiveAverage();
 // void readPendingDatagram();

private:

    QHostAddress sender_;
    quint16 senderPort_;


    int scors_[3];

        QJsonArray score_;

    bool ok_;
    QByteArray send_data_;
    QJsonObject name_family_score_;


    QByteArray Receive_Byte_;
    QUdpSocket *socket_;

};


#endif // JSONUDP_H























