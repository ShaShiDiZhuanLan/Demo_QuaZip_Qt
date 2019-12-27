#ifndef CZIP_H
#define CZIP_H


#include <direct.h>

#include <QString>
#include <QFileInfo>
#include <QDir>

#ifdef CZIPLIB_DLL
#define CZIPLIB_API __declspec(dllexport)
#pragma warning (disable: 4251)
#else
#define CZIPLIB_API __declspec(dllimport)
#pragma warning (disable: 4251)
#endif
#define  MAXPATH    260



typedef unsigned long long int ZPOS64_T;
//将文件添加到zip文件中，注意如果源文件srcFile为空则添加空目录
//fileNameInZip: 在zip文件中的文件名，包含相对路径
void CZIPLIB_API AddFileToZip(void* zf, const char* fileNameInZip, const char* srcFile);
//递归添加子目录到zip文件
void CZIPLIB_API CollectFilesInDirToZip(void* zf, const QString& strPath, const QString& parentDir);
//最终接口：从某个目录创建zip文件
bool CZIPLIB_API ZipFromDir(const char* dirName, const char* zipFileName);
//创建目录
void CZIPLIB_API mkdirFile(QString dirName);
//解压文件
void CZIPLIB_API AddUNZipToFile(void* unZipFile, const char* filename_unzip,ZPOS64_T file_size,QString dirName);
//最终接口：解压zipFileName文件到dirName目录
bool CZIPLIB_API UNZipFromDir(const char* dirName, const char* zipFileName);


#endif // CZIP_H
