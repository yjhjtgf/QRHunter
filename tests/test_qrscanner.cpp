#include <gtest/gtest.h>
#include "QRScanner.h"
#include <qrcodegen.hpp>
#include <opencv2/opencv.hpp>

// 用 QR-Code-generator 生成测试二维码图像
static cv::Mat generateTestQR(const std::string& content)
{
    const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(content.c_str(), qrcodegen::QrCode::Ecc::QUARTILE);
    const int size = qr.getSize();
    const int scale = 10;
    cv::Mat img(size * scale, size * scale, CV_8UC1, cv::Scalar(255));
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (qr.getModule(x, y))
            {
                cv::Rect roi(x * scale, y * scale, scale, scale);
                img(roi).setTo(0);
            }
        }
    }
    return img;
}

TEST(QRScanner, DecodeGeneratedQR)
{
    QRScanner scanner;
    std::string original = "https://example.com/test-qrcode-content-123456789";
    cv::Mat img = generateTestQR(original);
    ASSERT_FALSE(img.empty());
    std::string result;
    scanner.decodeSingle(img, result);
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result, original);
}

TEST(QRScanner, DecodeLongQR)
{
    QRScanner scanner;
    // 生成一个长内容的二维码 (模拟游戏登录二维码格式)
    std::string original = "https://hk4e.mihoyo.com/ys/download/port?game_biz=hk4e_cn&region=cn_gf01&uid=100000000&ticket=ABCDEFGH12345678ABCDEFGH";
    ASSERT_GE(original.size(), 85u);
    cv::Mat img = generateTestQR(original);
    std::string result;
    scanner.decodeSingle(img, result);
    EXPECT_FALSE(result.empty());
    EXPECT_EQ(result, original);
    EXPECT_GE(result.size(), 85u);
}

TEST(QRScanner, DecodeEmptyImage)
{
    QRScanner scanner;
    cv::Mat img = cv::Mat::zeros(100, 100, CV_8UC3);
    std::string result;
    scanner.decodeSingle(img, result);
    EXPECT_TRUE(result.empty());
}

TEST(QRScanner, DecodeNoQRImage)
{
    QRScanner scanner;
    cv::Mat img(100, 100, CV_8UC3, cv::Scalar(128, 128, 128));
    std::string result;
    scanner.decodeSingle(img, result);
    EXPECT_TRUE(result.empty());
}
