#pragma once

#include "RequestData.h"
#include "ReplyParser.h"

#include <QString>
#include <QFile>
#include <QJsonDocument>

class IDiscogsWrapper
{
  public:
    virtual ~IDiscogsWrapper() {}

    virtual void getInitUserData() = 0;
};

class DiscogsWrapperStub : public IDiscogsWrapper
{
  public:
    DiscogsWrapperStub(ReplyParser* parser, QObject* parent = nullptr)
        : m_replyParser(parser)
    {}

    void getInitUserData() override
    {
        m_replyParser->handleValidReply(readFile(QStringLiteral(":/testdata/wantlist.json")));
//      m_replyParser->handleValidReply(readFile(QStringLiteral("qrc:")));
    }

  private:
    QByteArray readFile(const QString& path) const
    {
       // qDebug() << path;
        QFile file("C:/Users/TOm.DESKTOP-ANR5M81.001/Desktop/DiscogsApp/testdata/wantlist.json");
        file.open(QIODevice::ReadOnly);
        return file.readAll();
    }

    ReplyParser* m_replyParser;
};
