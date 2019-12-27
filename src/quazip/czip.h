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
//���ļ���ӵ�zip�ļ��У�ע�����Դ�ļ�srcFileΪ������ӿ�Ŀ¼
//fileNameInZip: ��zip�ļ��е��ļ������������·��
void CZIPLIB_API AddFileToZip(void* zf, const char* fileNameInZip, const char* srcFile);
//�ݹ������Ŀ¼��zip�ļ�
void CZIPLIB_API CollectFilesInDirToZip(void* zf, const QString& strPath, const QString& parentDir);
//���սӿڣ���ĳ��Ŀ¼����zip�ļ�
bool CZIPLIB_API ZipFromDir(const char* dirName, const char* zipFileName);
//����Ŀ¼
void CZIPLIB_API mkdirFile(QString dirName);
//��ѹ�ļ�
void CZIPLIB_API AddUNZipToFile(void* unZipFile, const char* filename_unzip,ZPOS64_T file_size,QString dirName);
//���սӿڣ���ѹzipFileName�ļ���dirNameĿ¼
bool CZIPLIB_API UNZipFromDir(const char* dirName, const char* zipFileName);


#endif // CZIP_H
