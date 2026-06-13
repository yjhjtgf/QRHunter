#include <gtest/gtest.h>
#include "LiveStreamLink.h"

TEST(LiveStreamLink, DouyinInvalidRoom)
{
    auto info = GetLiveInfo(LivePlatform::Douyin, "0000000000000000000");
    EXPECT_NE(info.status, LiveStreamStatus::Normal);
}

TEST(LiveStreamLink, BilibiliInvalidRoom)
{
    auto info = GetLiveInfo(LivePlatform::Bilibili, "9999999999999");
    EXPECT_NE(info.status, LiveStreamStatus::Normal);
}
