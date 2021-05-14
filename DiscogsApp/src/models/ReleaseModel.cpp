#include "ReleaseModel.h"
#include <QDebug>

WantlistModel::WantlistModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int WantlistModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return m_wantlist.size();
}

int WantlistModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return 1;
}

QVariant WantlistModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    size_t row = index.row();

    if (row < m_wantlist.size())
    {
        switch (role)
        {
            case ArtistRole:
            {
                return m_wantlist.at(row).m_artist;
            }

            case TitleRole:
            {
                return m_wantlist.at(row).m_title;
            }

            case WantmeterRole:
            {
                return QVariant();
              //  return m_wantlist.at(row).m_wantmeter;
            }

            case YearRole:
            {
                return m_wantlist.at(row).m_year;
            }

            case RatingRole:
            {
                return QVariant();
//                return m_wantlist.at(row).m_rating;
            }

            case LabelRole:
            {
                return m_wantlist.at(row).m_label;
            }

            default:
            {
                break;
            }
        }
    }

    return QVariant();
}

void WantlistModel::setModel(std::vector<WantlistItem> model)
{
    m_wantlist = std::move(model);

    for (auto x : m_wantlist)
    {
        qDebug() << x.m_title;
    }
}

QHash<int, QByteArray> WantlistModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[ArtistRole] = "authorRole";
    roleNames[TitleRole]  = "titleRole";
    roleNames[WantmeterRole] = "wantmeterRole";
    roleNames[YearRole] = "yearRole";
    roleNames[RatingRole] = "ratingRole";
    roleNames[LabelRole] = "labelRole";
    return roleNames;
}
