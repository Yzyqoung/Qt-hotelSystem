#include "log.h"

QFile *gFileLog = NULL;

char *msgHead[]={
    "Debug   ",
    "Warning ",
    "Critical",
    "Fatal   ",
    "Info    "
};

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");

    if(gFileLog){
        QTextStream tWrite(gFileLog);

        QString msgText="%1 | 时间:%6 | %2:%3, %4 | 信息:%5\n";
        msgText = msgText.arg(msgHead[type]).arg(context.file).arg(context.line).arg(context.function).arg(localMsg.constData()).arg(current_date_time);
        //gFileLog->write(msgText.toLocal8Bit(), msgText.length());
        tWrite << msgText;
    }else{
        fprintf(stderr, "%s | 时间:%s | %s:%u, %s | 信息:%s\n", msgHead[type], current_date_time.toLocal8Bit().constData(), context.file, context.line, context.function, localMsg.constData());
    }
}

void logSysInit(QString filePath)
{
    gFileLog = new QFile(filePath);
    if (!gFileLog->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        return;
    }
    //初始化自定义日志处理函数myMessageOutput
    qInstallMessageHandler(myMessageOutput);

}
