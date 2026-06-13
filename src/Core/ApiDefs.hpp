#pragma once

#include "compile_string.hpp"

namespace api::live::bili
{
constexpr compile_string base{ "https://api.live.bilibili.com" };
constexpr auto room_init = base + compile_string{ "/room/v1/Room/room_init" };
constexpr auto v2_play_info = base + compile_string{ "/xlive/web-room/v2/index/getRoomPlayInfo" };
}

namespace api::live::douyin
{
constexpr compile_string base{ "https://live.douyin.com" };
constexpr auto room = base + compile_string{ "/webcast/room/web/enter/?" };
}
