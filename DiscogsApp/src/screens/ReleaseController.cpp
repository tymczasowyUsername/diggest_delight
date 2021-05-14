#include "ReleaseController.h"

ReleaseController::ReleaseController(QObject *parent)
    : m_releaseManager(new ReleaseManager(this))
    , m_wantlistModel(new WantlistModel(this))
{

}

void ReleaseController::addToWantlist(int index)
{
//    m_wantlistModel->removeRow(index);
//    m_collectionModel->addRow()
}

void ReleaseController::addToCollection(int index)
{
//    m_collectionModel->
}

void ReleaseController::removeFromWantlist(int index)
{

}

void ReleaseController::removeFromCollection(int index)
{

}
