#include "audioplayer.h"

audioPlayer::audioPlayer(QUdpSocket* senderSocket)
{
    socket = new QUdpSocket();
    socket->bind(42069);
    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (!info.isFormatSupported(format)) {
        qDebug() << "Default format not supported - trying to use nearest";
        format = info.nearestFormat(format);
    }

    output = new QAudioOutput(format);
    device = output->start();
    connect(socket, SIGNAL(readyRead()), this, SLOT(playData()));

    if (socket->state() == QUdpSocket::ConnectedState)
        qDebug() << "Connected";
    else
        qDebug() << "Not Connected";
}

void audioPlayer::playData()
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

audioPlayer::~audioPlayer()
{
    delete socket;
    delete output;
    delete device;
}
