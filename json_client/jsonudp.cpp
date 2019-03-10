#include "jsonudp.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QObject>
JsonUdp::JsonUdp(QObject *parent) :
    QObject(parent)
{
scors_[0]=17;
scors_[1]=19;
scors_[2]=15;
    socket_ = new QUdpSocket(this);

    socket_->bind(QHostAddress::LocalHost, 2222);

    connect(socket_, SIGNAL(readyRead()), this, SLOT(receiveAverage()));

JsonUdp::sendJson();
}

void JsonUdp::receiveAverage(){


    Receive_Byte_.resize(socket_->pendingDatagramSize());


    socket_->readDatagram(Receive_Byte_.data(), Receive_Byte_.size(),&sender_, &senderPort_);
qDebug()<<"Average"<<Receive_Byte_.toHex().toInt(&ok_,16);



}

void JsonUdp::sendJson(){

    name_family_score_.insert("Family", QJsonValue("salami"));
    name_family_score_.insert("Name", QJsonValue("misaq"));
score_={scors_[0],scors_[1],scors_[2]};
    name_family_score_.insert("score",score_);

       QJsonDocument jsdoc(name_family_score_);

    send_data_.append(jsdoc.toJson());
qDebug(jsdoc.toJson());
socket_->writeDatagram(send_data_,QHostAddress::LocalHost, 1111);





}




