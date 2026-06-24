# LiveQRHunter

直播二维码实时监控工具。从抖音/B站直播间实时捕获二维码，重新生成干净的二维码图像并显示，方便手机扫码。

## 功能

- 支持抖音、B站直播流
- 实时检测直播间画面中的二维码
- 检测到后重新生成干净的白底黑码二维码（比直播画面更清晰）
- 二维码消失后立即清除显示
- 二维码历史记录（最多100条，支持删除和回看）
- 房间号历史记录
- 置顶显示
- 配置自动保存

## 下载

从 [Releases](../../releases) 页面下载最新版本的 ZIP 文件，解压后运行 `LiveQRHunter.exe`。

## 使用方法

1. 运行 `LiveQRHunter.exe`
2. 选择平台（抖音/B站）
3. 输入直播间房间号
4. 点击 ▶ 开始监控
5. 直播间出现二维码时，窗口会自动显示干净的二维码
6. 用手机对着窗口扫码即可

## 从源码构建

### 环境要求

- Visual Studio 2022 (MSVC)
- CMake 3.26+
- Qt 6.8
- vcpkg

### 构建步骤

```powershell
# 配置
cmake -B build -DCMAKE_BUILD_TYPE=Release `
  -DCMAKE_TOOLCHAIN_FILE="$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" `
  -DVCPKG_TARGET_TRIPLET=x64-windows-static-md

# 构建
cmake --build build --config Release --parallel

# 复制模型文件
Copy-Item -Recurse -Force ScanModel build\Release\ScanModel
```

### 依赖

通过 vcpkg 管理：
- cpr (HTTP 客户端)
- opencv (二维码检测)

通过 FetchContent 获取：
- nlohmann/json
- FFmpeg (预编译二进制)
- QR-Code-generator (源码在 3rdparty/)

## 许可证

MIT License
