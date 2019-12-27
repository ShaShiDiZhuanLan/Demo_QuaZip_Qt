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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "squazip.h"

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
    SQuaZip m_quaZip;
    QString m_correctPath;
private:
    void isCorrectPath();
    void deleteDir(const QString &d);
private slots:
    void on_pB_compress_clicked();
    void on_pB_unCompress_clicked();
    void on_pB_open_clicked();
    void on_pB_delete_clicked();
    void on_pB_back_clicked();
    void on_pB_openFiles_clicked();
};

#endif // MAINWINDOW_H
