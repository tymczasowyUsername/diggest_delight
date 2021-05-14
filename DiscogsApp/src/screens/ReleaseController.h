#ifndef RELEASECONTROLLER_H
#define RELEASECONTROLLER_H

#include "ReleaseModel.h"
#include "ReleaseManager.h"

#include <QObject>

class ReleaseController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(WantlistModel* wantlist READ wantlist NOTIFY wantlistChanged)
//    Q_PROPERTY(CollectionModel* collection READ collection NOTIFY wantlistChanged)

  public:
    ReleaseController(QObject* parent = nullptr);

    Q_INVOKABLE void addToWantlist(int index);
    Q_INVOKABLE void addToCollection(int index);
    Q_INVOKABLE void removeFromWantlist(int index);
    Q_INVOKABLE void removeFromCollection(int index);

    WantlistModel* wantlist() { return m_wantlistModel; }

  signals:
    void wantlistChanged();
    void collectionChanged();

  private:

//    WantlistModel* wantlist;
    ReleaseManager* m_releaseManager;
    WantlistModel* m_wantlistModel;
//    CollectionModel* m_collectionModel;
};

#endif // RELEASECONTROLLER_H
