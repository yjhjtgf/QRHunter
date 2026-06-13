#pragma once

#include <string>
#include <cstdint>

#include <QMetaType>

struct QRCodeInfo
{
    std::string rawContent;
    std::string platform;
    std::string roomID;
    int64_t timestamp{};
};

Q_DECLARE_METATYPE(QRCodeInfo)
