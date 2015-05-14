#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audiocall/audioplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAudioInput* input;
    QUdpSocket* socket;
    audioPlayer* myAudioPlayer;
    bool OnLive;

private slots:
    void startAudioCall();
    void endAudioCall();
};

#endif // MAINWINDOW_H
