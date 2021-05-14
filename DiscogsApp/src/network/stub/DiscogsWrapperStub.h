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

    virtual void searchDatabase(const QString& searchString) const = 0;
    virtual void getWantlist() const = 0;
    virtual void getCollection() const = 0;
};

class DiscogsWrapperStub : public IDiscogsWrapper
{
  public:
    DiscogsWrapperStub(QObject* parent = nullptr) {}

    void getWantlist() const override
    {
      //  m_replyParser.parseGetWantlistReply(readJson(QStringLiteral(":/testdata/wantlist.json")));
    }

    void getCollection() const override
    {
       // m_replyParser.parseGetCollectionReply(readJson(QStringLiteral(":/testdata/collection.json")));
    }

    void searchDatabase(const QString& str) const override
    {
        Q_UNUSED(str)
        return;
    }

  private:
    QJsonDocument readJson(const QString& path) const
    {
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        auto content = file.readAll();

        return QJsonDocument::fromJson(content);
    }

   // ReplyParser m_replyParser;
};
