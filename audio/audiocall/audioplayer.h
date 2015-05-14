#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H


#include <QObject>
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioInput>
#include <QtMultimedia/QAudioFormat>
#include <QUdpSocket>

class audioPlayer : public QObject
{
    Q_OBJECT
public:
    explicit audioPlayer(QObject *parent = 0);
    void closeAudioOutput();

private slots:
    void playData();

public slots:
    void onAudioCall();

private:
    QUdpSocket *socket;
    QIODevice *device;
    QAudioOutput *output;
};
#endif // AUDIOPLAYER_H
