#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(OpenImg()));
}

void MainWindow::OpenImg()
{
    QString OpenFile, OpenFilePath;
    QImage image;
    //打开文件夹中的图片文件
    OpenFile = QFileDialog::getOpenFileName(this,
                                              "Please choose an image file",
                                              "",
                                              "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
    if( OpenFile != "" )
    {
        if( image.load(OpenFile) )
        {
            ui->label_2->setPixmap(QPixmap::fromImage(image));
        }
    }

    //显示所示图片的路径
    QFileInfo OpenFileInfo;
    OpenFileInfo = QFileInfo(OpenFile);
    OpenFilePath = OpenFileInfo.filePath();
    ui->lineEdit->setText(OpenFilePath);
}

MainWindow::~MainWindow()
{
    delete ui;
}
