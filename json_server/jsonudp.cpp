#include "jsonudp.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QObject>
#include <QJsonParseError>
#include <QString>
JsonUdp::JsonUdp(QObject *parent) :
    QObject(parent)
{
sum_of_scors_=0;
cont_of_scors_=3;
    socket = new QUdpSocket(this);

    socket->bind(QHostAddress::LocalHost, 1111);

    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveJson()));



}

void JsonUdp::sendAverage(int ave){

qDebug()<<"Average"<<ave<<endl;
send_data_.append(ave);

socket->writeDatagram(send_data_,QHostAddress::LocalHost, 2222);


}

void JsonUdp::receiveJson(){
    Receive_Byte_.resize(socket->pendingDatagramSize());

    socket->readDatagram(Receive_Byte_.data(), Receive_Byte_.size(),&sender_, &senderPort_);


for (int i=0;i<cont_of_scors_;i++){

    json_val_=json_doc_.fromJson(Receive_Byte_, &error_).operator []("score")[i];

 sum_of_scors_+=json_val_.toDouble();
}

JsonUdp::sendAverage(sum_of_scors_/cont_of_scors_);
}




