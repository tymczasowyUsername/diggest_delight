#include "ReleaseManager.h"

ReleaseManager::ReleaseManager(QObject *parent)
    : QObject(parent)
    , m_wantlistModel(new WantlistModel(this))
    , m_parser(new ReplyParser(this))
    , m_discogsWrapper(new DiscogsWrapperStub(m_parser, this))
{
    m_discogsWrapper->getInitUserData();

    init();
}

void ReleaseManager::init()
{
    m_wantlistModel->setModel(m_parser->parseGetWantlistReply());
    // m_collectionModel->setMoedl(m_parser->parseGetCollectionReply());
}
