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
#include "squazip.h"
#include "../quazip/JlCompress.h"
#include <QtConcurrent/QtConcurrent>

SQuaZip::SQuaZip(QObject *parent) : QObject(parent)
{
}

void SQuaZip::saveAsFile(const QString &path, const QString &zipfile)
{
    QtConcurrent::run(this, &SQuaZip::zipDir, path, zipfile);
}

void SQuaZip::loadFromFile(const QString &path, const QString &zipfile)
{
    QtConcurrent::run(this, &SQuaZip::unzipDir, zipfile, path);
}

/**
 * @brief SQuaZip::zipDir
 * @param path 待压缩目录
 * @param zipfile 压缩后的文件
 * @return
 */
bool SQuaZip::zipDir(const QString &path, const QString &zipfile)
{
    bool bok = JlCompress::compressDir(zipfile, path, true);
    return bok;
}

/**
 * @brief SQuaZip::unzipDir
 * @param zipfile 待解压缩的文件
 * @param path 解压缩存放的目录
 * @return
 */
bool SQuaZip::unzipDir(const QString &zipfile, const QString &path)
{
    bool bok = !JlCompress::extractDir(zipfile, path).isEmpty();
    qDebug() << "??::" << bok;
    return bok;
}
