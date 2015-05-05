#include "udpplayer.h"

UDPPlayer::UDPPlayer(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket();
    socket->bind(1002);
    QAudioFormat format;
    format.setSampleRate(128000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format))
        format = info.nearestFormat(format);

    output = new QAudioOutput(format);
    device = output->start();
    connect(socket, SIGNAL(readyRead()), this, SLOT(playData()));
}

void UDPPlayer::playData()
{
    //You need to read datagrams from the udp socket
    while (socket->hasPendingDatagrams())
    {
        QByteArray data;
        data.resize(socket->pendingDatagramSize());
        socket->readDatagram(data.data(), data.size());
        device->write(data.data(), data.size());
    }
}
