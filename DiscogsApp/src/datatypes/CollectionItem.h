#pragma once

#include "ReleaseRating.h"

#include <QString>

#include <cstdint>

enum class Condition : uint8_t
{
    Poor,
    Fair,
    Good,
    VeryGood,
    Mint
};

struct CollectionItem
{
    CollectionItem(const QString& artist, const QString& title, Condition condition,
                 int year, ReleaseRating rating, const QString& label)
        : m_artist(artist)
        , m_title(title)
        , m_year(year)
        , m_rating(rating)
        , m_conditionRating(condition)
        , m_label(label)
    {}

    QString m_artist;
    QString m_title;
    int m_year;
    ReleaseRating m_rating;
    Condition m_conditionRating;
    QString m_label;
//        QFile image;
};
