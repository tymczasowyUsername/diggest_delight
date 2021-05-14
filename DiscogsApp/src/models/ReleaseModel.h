#ifndef RELEASEMODEL_H
#define RELEASEMODEL_H

#include "ReleaseRating.h"
#include "WantlistItem.h"

#include <vector>

#include <QAbstractListModel>
#include <QFile>
#include <QDate>

class WantlistModel : public QAbstractListModel
{
    Q_OBJECT

  public:
    explicit WantlistModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    void setModel(std::vector<WantlistItem> model);

  protected:
    QHash<int, QByteArray> roleNames() const override;

public:
    enum Roles
    {
        ArtistRole,
        TitleRole,
        WantmeterRole,
        YearRole,
        RatingRole,
        LabelRole
    };

    std::vector<WantlistItem> m_wantlist;
};

#endif // RELEASEMODEL_H
