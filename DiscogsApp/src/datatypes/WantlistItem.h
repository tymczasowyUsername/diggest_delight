#pragma once

#include "ReleaseRating.h"

#include <QString>

enum class Wantmeter : uint8_t
{
    MayHave,
    LikeToHave,
    MustHave
};

struct WantlistItem
{
    WantlistItem(const QString& artist, const QString& title, Wantmeter wantmeter,
                 int year, ReleaseRating rating, const QString& label)
        : m_artist(artist)
        , m_title(title)
        , m_wantmeter(wantmeter)
        , m_year(year)
        , m_rating(rating)
        , m_label(label)
    {}

    QString m_artist;
    QString m_title;
    Wantmeter m_wantmeter;
    int m_year;
    ReleaseRating m_rating;
    QString m_label;
//        QFile image;
};
