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
#ifndef SQUAZIP_H
#define SQUAZIP_H

#include <QObject>

class SQuaZip : public QObject
{
    Q_OBJECT
public:
    explicit SQuaZip(QObject *parent = 0);

    void saveAsFile(const QString &path, const QString &zipfile);
    void loadFromFile(const QString &path, const QString &zipfile);
private:
    bool zipDir(const QString &path, const QString &zipfile);
    bool unzipDir(const QString &zipfile, const QString &path);
};

#endif // SQUAZIP_H
