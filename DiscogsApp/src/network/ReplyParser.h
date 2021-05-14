#pragma once

#include "UrlQueryCreator.h"
#include "RequestData.h"
#include "WantlistItem.h"
#include "CollectionItem.h"
#include "ReleaseModel.h"

#include <vector>

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>

class ReplyParser : public QObject
{
    Q_OBJECT

  public:
    ReplyParser(QObject* parent = nullptr);

  public slots:
    void handleValidReply(const QByteArray &reply);
    void parseGetReleaseVersionsReply(const QJsonDocument& reply);
    std::vector<WantlistItem> parseGetWantlistReply();
//    std::vector<CollectionItem> parseGetCollectionReply();

  private:
    QJsonDocument writeToJson(const QByteArray &reply) const;
    RequestType getRequestType(const QJsonDocument& doc) const;

//    std::vector<CollectionModel> m_parsedCollection;
    QJsonDocument m_collectionJson;
    QJsonDocument m_wantlistJson;
};
