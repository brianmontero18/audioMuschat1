#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H


#include <QObject>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioFormat>
#include <QUdpSocket>
#include <QAbstractSocket>

class audioPlayer : public QObject
{
    Q_OBJECT
public:
    audioPlayer(QUdpSocket* senderSocket);
    ~audioPlayer();

signals:
    void Fruta();

public slots:
    void playData();

private:
    QUdpSocket *socket;
    QIODevice *device;
    QAudioOutput *output;
};
#endif // AUDIOPLAYER_H
