/***************************************************************
 *文件名称：日志系统
 *简要描述：在后台以txt方式记录的日志系统
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/4/28
 *说明：Email:578706463@qq.com
*****************************************************************/
#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QMessageLogger>
#include <qlogging.h>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

void logSysInit(QString filePath);
void logSysInit();

#endif // LOG_H
