/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2017-10-11
# UpdateTime: 2019-12-27
# Info: Qt用QuaZip实现压缩/解压的小Demo
# Url:https://shazhenyu.blog.csdn.net/article/details/78206650
# Github:https://github.com/ShaShiDiZhuanLan/Demo_QuaZip_Qt
#
#-------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QFileDialog>
#include <QDebug>
#include <QTimer>

#define IS_NULL_PATH isCorrectPath();if(m_correctPath == "")return;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::isCorrectPath()
{
    QString pathTMP = ui->lE_openPath->text();
    if(pathTMP.isEmpty() || pathTMP.split(":").count() == 0 || pathTMP.split("\\").count() == 0) {
        m_correctPath = "";
    } else {
        m_correctPath = pathTMP;
    }
}

void MainWindow::deleteDir(const QString &d)
{
    QDir dir(d);
    foreach (QFileInfo inf, dir.entryInfoList(QDir::Dirs|QDir::Files)) {
        if(inf.isFile()) {
            dir.remove(inf.absoluteFilePath());
        } else if(inf.isDir() && inf.fileName() != "." && inf.fileName() != "..") {
            deleteDir(inf.absolutePath()+"/"+inf.fileName());
        }
    }
    dir.rmdir(dir.absolutePath());
}

void MainWindow::on_pB_compress_clicked()
{
    IS_NULL_PATH

    QString name = m_correctPath.split("/").last();
    if(name == "") {
        name = m_correctPath.split("/").at(m_correctPath.count()-2);
    }
    QString tmpPath = m_correctPath.split(name).first();
    m_quaZip.saveAsFile(m_correctPath, tmpPath + name.append(".zip"));
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pB_unCompress_clicked()
{
    IS_NULL_PATH

    QString name = m_correctPath.split("/").last();
    QString fileFormat = name.split(".").last();
    QString fileNameFormat = name.split(fileFormat).first();
    QString fileName = fileNameFormat.mid(0, fileNameFormat.count() - 1);
    QString tmpPath = m_correctPath.split(name).first();
    QString filePath = tmpPath + fileName;
    m_quaZip.loadFromFile(filePath, m_correctPath);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pB_open_clicked()
{
    QString deskTopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), deskTopPath);
    ui->lE_openPath->setText(fileName);
}

void MainWindow::on_pB_delete_clicked()
{
    IS_NULL_PATH

    QFileInfo fileInfo(m_correctPath);
    if(fileInfo.isDir()){
        deleteDir(m_correctPath);
    } else {
        QFile::remove(m_correctPath);
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pB_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pB_openFiles_clicked()
{
    QString deskTopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), deskTopPath);
    ui->lE_openPath->setText(directory);
}
