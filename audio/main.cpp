#include <QApplication>
#include <QIODevice>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioFormat>
#include <QUdpSocket>
#include "udpplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new UDPPlayer();

    QAudioFormat format;
    format.setSampleRate(128000);
    format.setChannelCount(1);
    format.setSampleSize(16);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    //If format isn't supported find the nearest supported
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultInputDevice());
    if (!info.isFormatSupported(format))
        format = info.nearestFormat(format);

    QAudioInput* input = new QAudioInput(format);
    QUdpSocket* socket = new QUdpSocket();
    socket->connectToHost("127.0.0.1", 1002);
    input->start(socket);

    return a.exec();
}
