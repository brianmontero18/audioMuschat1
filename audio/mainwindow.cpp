#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audiocall/audioplayer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->ConnectButton, SIGNAL(clicked()), this, SLOT(startAudioCall()));
    connect(ui->DisconnectButton, SIGNAL(clicked()), this, SLOT(endAudioCall()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startAudioCall()
{
    myAudioPlayer = new audioPlayer();

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

    input = new QAudioInput(format);
    socket = new QUdpSocket();
    socket->connectToHost(ui->IpEdit->text(), 1002);
    input->start(socket);
    OnLive = true;
}

void MainWindow::endAudioCall()
{
    if(OnLive) {
        delete input;
        delete socket;
        myAudioPlayer->closeAudioOutput();
        delete myAudioPlayer;
        OnLive = false;
    }
}
