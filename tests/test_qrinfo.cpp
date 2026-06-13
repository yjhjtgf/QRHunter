#include <gtest/gtest.h>
#include "QRCodeInfo.hpp"

static QRCodeInfo buildInfo(const std::string& content, const std::string& platform, const std::string& roomID)
{
    QRCodeInfo info;
    info.rawContent = content;
    info.platform = platform;
    info.roomID = roomID;
    info.timestamp = 1718000000000;
    return info;
}

TEST(QRCodeInfo, NormalContent)
{
    auto info = buildInfo("https://example.com/some-qrcode-content-here", "Douyin", "12345");
    EXPECT_EQ(info.rawContent, "https://example.com/some-qrcode-content-here");
    EXPECT_EQ(info.platform, "Douyin");
    EXPECT_EQ(info.roomID, "12345");
    EXPECT_EQ(info.timestamp, 1718000000000);
}

TEST(QRCodeInfo, EmptyContent)
{
    auto info = buildInfo("", "Douyin", "12345");
    EXPECT_TRUE(info.rawContent.empty());
    EXPECT_EQ(info.platform, "Douyin");
}

TEST(QRCodeInfo, BilibiliPlatform)
{
    auto info = buildInfo("https://example.com/content", "Bilibili", "999");
    EXPECT_EQ(info.platform, "Bilibili");
    EXPECT_EQ(info.roomID, "999");
}
