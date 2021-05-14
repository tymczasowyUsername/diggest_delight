#include "ReplyParser.h"

ReplyParser::ReplyParser(QObject *parent)
{}

void ReplyParser::parseGetReleaseVersionsReply(const QJsonDocument &reply) {}

std::vector<WantlistItem> ReplyParser::parseGetWantlistReply()
{
    const QJsonObject& json = m_wantlistJson.object();

    QString artists;
    QString title;
    QString labels;
    int year;
    int rating;
    std::vector<WantlistItem> wantlist;

    if (json.contains("wants") && json["wants"].isArray())
    {
        QJsonArray wants = json["wants"].toArray();

        for (int index = 0; index < wants.size(); ++index)
        {
            QJsonObject wantItem = wants[index].toObject();

            if (wantItem.contains("rating"))
                rating = wantItem["rating"].toInt();

            if (wantItem.contains("basic_information")
                    && wantItem["basic_information"].isObject())
            {
                QJsonObject info = wantItem["basic_information"].toObject();

                if (info.contains("title") && info["title"].isString())
                    title = info["title"].toString();

                if (info.contains("year"))
                    year = info["year"].toInt();

                if (info.contains("artists") && info["artists"].isArray())
                {
                    QJsonArray artistsList = info["artists"].toArray();

                    for (int artistIndex = 0; artistIndex < artistsList.size(); ++artistIndex)
                    {
                        QJsonObject artistItem = artistsList[index].toObject();

                        if (artistItem.contains("name") && artistItem["name"].isString())
                            artists += artistItem["name"].toString();

                        if (artistIndex > 0)
                            artists += ",";
                    }
                }

                if (info.contains("labels") && info["labels"].isArray())
                {
                    QJsonArray labelsList = info["labels"].toArray();

                    for (int labelIndex = 0; labelIndex < labelsList.size(); ++labelIndex)
                    {
                        QJsonObject labelItem = labelsList[index].toObject();

                        if (labelItem.contains("name") && labelItem["name"].isString())
                            labels += labelItem["name"].toString();

                        if (labelIndex > 0)
                            labels += ",";
                    }
                }
            }

            wantlist.push_back( WantlistItem{ artists,
                                              title,
                                              static_cast<Wantmeter>(1),
                                              year,
                                              static_cast<ReleaseRating>(rating),
                                              labels });

            qDebug() << wantlist.size();
        }
    }

    return wantlist;
}

QJsonDocument ReplyParser::writeToJson(const QByteArray& reply) const
{
    return QJsonDocument::fromJson(reply);
}

RequestType ReplyParser::getRequestType(const QJsonDocument &doc) const
{
    //qDebug() << doc;

    if (doc.isObject())
    {
        auto root = doc.object();


        if (root.contains("wants"))
            return RequestType::GetWantlist;
        else if (root.contains("collection"))
            return RequestType::GetCollection;
        else
            return RequestType::Unknown;
    }
    else
    {
        qCritical() << "Invalid JSON response";
        return RequestType::Unknown;
    }
}

void ReplyParser::handleValidReply(const QByteArray& reply)
{
    QJsonDocument jsonReply = writeToJson(reply);
    auto requestType = getRequestType(jsonReply);
    //                )
    switch (requestType)
    {
        case RequestType::Search:
        {
            // parseSearchReply(jsonReply);
            break;
        }

        case RequestType::GetReleaseVersions:
        {
            break;
        }

        case RequestType::GetWantlist:
        {
            m_wantlistJson = std::move(jsonReply);
            break;
        }

        case RequestType::GetCollection:
        {
            m_collectionJson = std::move(jsonReply);
            break;
        }

        case RequestType::Unknown:
        default:
        {
            qDebug() << "Unknown request type";
            // handleError();
            break;
        }
    }
}
