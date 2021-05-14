#pragma once

#include "UrlQueryCreator.h"
#include "IDiscogsWrapper.h"
#include "RequestData.h"
#include "ReleaseModel.h"

#include <QObject>
#include <QtNetwork>
#include <QtNetworkAuth>
#include <QJsonDocument>

class DiscogsWrapper : public QOAuth1, public IDiscogsWrapper
{
    Q_OBJECT

  public:
    DiscogsWrapper(ReplyParser* parser, QObject* parent = nullptr);

    void searchDatabase(const QString& searchString) const;
    void getWantlist() const;
    void getCollection() const;

  private:
    void init();
    void getInitUserData() override;
    void handleReply(QNetworkReply* reply);
    void handleReplyError(QNetworkReply::NetworkError error, const QString& errorString) const;

    QNetworkAccessManager* m_networkAccessManager;
    QOAuthHttpServerReplyHandler* m_replyHandler;
    bool m_granted;
    bool m_usePersonalAccessToken;
    UrlQueryCreator m_urlQueryCreator;
    ReplyParser* m_parser;
};


