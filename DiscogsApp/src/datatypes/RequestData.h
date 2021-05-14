#pragma once

#include <cstdint>

enum class RequestType : uint8_t
{
    Search,
    GetReleaseVersions,
    GetWantlist,
    GetCollection,
    Unknown
};
