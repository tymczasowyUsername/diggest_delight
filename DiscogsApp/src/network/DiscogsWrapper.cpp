#include "DiscogsWrapper.h"

#include <QDesktopServices>
#include <QDebug>
#include <QSslError>
#include <QSslSocket>

namespace
{
const QString REQUEST_TOKEN_URL = QStringLiteral("https://api.discogs.com/oauth/request_token");
const QString AUTHORIZE_URL     = QStringLiteral("https://www.discogs.com/oauth/authorize");
const QString ACCESS_TOKEN_URL  = QStringLiteral("https://api.discogs.com/oauth/access_token");

const QString SEARCH_URL        = QStringLiteral("https://api.discogs.com/database/search?");
//const QString REQUEST_SUFFIX    = QStringLiteral("&per_page=3&page=1");

const QString CONSUMER_KEY      = QStringLiteral("eADaUjeLAxLxcwIXRnpT");
const QString CONSUMER_SECRET   = QStringLiteral("RdoebAPGzoobzzrMDDRlFycvOVvISiJM");
}

DiscogsWrapper::DiscogsWrapper(ReplyParser* parser, QObject* parent)
    : QOAuth1(CONSUMER_KEY, CONSUMER_SECRET, nullptr, parent)
    , m_networkAccessManager(new QNetworkAccessManager(parent))
    , m_replyHandler(new QOAuthHttpServerReplyHandler(1337, this))
    , m_granted(false)
    , m_usePersonalAccessToken(true)
    , m_urlQueryCreator(m_usePersonalAccessToken)
    , m_parser(parser)
{
    setNetworkAccessManager(m_networkAccessManager);

    connect(this, &QOAuth1::authorizeWithBrowser, [&] (const QUrl& url) {
        QDesktopServices::openUrl(url);
    });

    connect(m_networkAccessManager, &QNetworkAccessManager::finished, [this] (QNetworkReply* reply)  {       emit authorizeWithBrowser(AUTHORIZE_URL);
        if (m_granted)
        {
            emit handleReply(reply);
        }
    });

    connect(this, &QOAuth1::granted, [this] () {
        m_granted = true;
    });

    init();
}

void DiscogsWrapper::init()
{
    setReplyHandler(m_replyHandler);

    setTemporaryCredentialsUrl(QUrl(REQUEST_TOKEN_URL));
    setAuthorizationUrl(QUrl(AUTHORIZE_URL));
    setTokenCredentialsUrl(QUrl(ACCESS_TOKEN_URL));

    grant();
}

void DiscogsWrapper::getInitUserData()
{
    getCollection();
    getWantlist();
}

void DiscogsWrapper::handleReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
        handleReplyError(reply->error(), reply->errorString());

    m_parser->handleValidReply(reply->readAll());
}

void DiscogsWrapper::handleReplyError(QNetworkReply::NetworkError error, const QString &errorString) const
{
    Q_UNUSED(error);
    qDebug() << errorString;
}

void DiscogsWrapper::searchDatabase(const QString &searchString) const
{
//    get(QUrl(SEARCH_URL + "&release_title=" + title + "&artist=" + artist + "&type=master" + REQUEST_SUFFIX));
}

void DiscogsWrapper::getCollection() const
{
//    get(m_urlQueryCreator.getCollectionUrl());
}
void DiscogsWrapper::getWantlist() const
{
//    get(m_urlQueryCreator.getWantlistUrl());
}
