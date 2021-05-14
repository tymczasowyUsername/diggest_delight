#pragma once

#include "DiscogsWrapper.h"
#include "ReleaseModel.h"
#include "ReplyParser.h"

#include <QObject>
#include <QStandardPaths>

class ReleaseManager : public QObject
{
    Q_OBJECT

  public:
    ReleaseManager(QObject* parent = nullptr);

  private:
    void init();

    WantlistModel* m_wantlistModel;
//  CollectionModel* m_collection;
    ReplyParser* m_parser;
    IDiscogsWrapper* m_discogsWrapper;
};
