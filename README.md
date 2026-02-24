# test_hello_world_esp32_s3_devkit

ESP32-S3 DevKit を使ったサンプルプロジェクト集です。  
PlatformIO + Arduino フレームワークを使用しています。

## 対象ボード

- **RYMCU ESP32-S3 DevKitC-1**
- フレームワーク: Arduino
- アップロード速度: 115200 bps
- シリアルモニター速度: 115200 bps
- 接続ポート: COM10

---

## プロジェクト一覧

### 1. hello_wrold_serial_esp32s3

**概要**  
ESP32-S3 でシリアル通信を使った Hello World サンプルです。

**動作内容**  
- 起動時にシリアル通信（115200 bps）を初期化します。
- 1秒ごとにシリアルモニターへ `Hello, World!` を送信し続けます。

**ソースコード抜粋 (`src/main.cpp`)**

```cpp
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Hello, World!");
  delay(1000);
}
```

**確認方法**  
PlatformIO のシリアルモニター（115200 bps）を開くと、1秒ごとに `Hello, World!` が表示されます。

---

### 2. test_esp32s3_led_chika

**概要**  
ESP32-S3 DevKit 内蔵の NeoPixel（RGB LED）を制御する LED チカチカサンプルです。

**動作内容**  
- GPIO 48 に接続された NeoPixel LED を制御します。
- 以下の順番で色を1秒ごとに切り替えます。
  1. **白 (White)** : RGB(127, 127, 127)
  2. **消灯 (Off)** : RGB(0, 0, 0)
  3. **赤 (Red)** : RGB(127, 0, 0)
  4. **緑 (Green)** : RGB(0, 127, 0)
  5. **青 (Blue)** : RGB(0, 0, 127)
- 各状態はシリアルモニターにも出力されます。

**ソースコード抜粋 (`src/main.cpp`)**

```cpp
#include <Arduino.h>

#define LED_PIN 48

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Serial.println("led on");
  neopixelWrite(LED_PIN, 127, 127, 127); // White
  delay(1000);
  Serial.println("led off");
  neopixelWrite(LED_PIN, 0, 0, 0); // Off
  delay(1000);
  Serial.println("red");
  neopixelWrite(LED_PIN, 127, 0, 0); // Red
  delay(1000);
  Serial.println("green");
  neopixelWrite(LED_PIN, 0, 127, 0); // Green
  delay(1000);
  Serial.println("blue");
  neopixelWrite(LED_PIN, 0, 0, 127); // Blue
  delay(1000);
}
```

**確認方法**  
書き込み後、ボード上の RGB LED が白→消灯→赤→緑→青の順に1秒ごとに点灯・変化します。  
PlatformIO のシリアルモニター（115200 bps）でも各状態のログを確認できます。

---

## 開発環境

| 項目 | 内容 |
|------|------|
| IDE | [PlatformIO](https://platformio.org/) (VSCode拡張) |
| フレームワーク | Arduino |
| プラットフォーム | espressif32 |
| ボード | rymcu-esp32-s3-devkitc-1 |
