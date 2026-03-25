# AMR-MNS16B-V1-N2540

**AGV Line Guide Sensor — 16 Channel | NPN Open-Collector | RS-232**

---

## 📦 Product Overview

| Item | Detail |
|------|--------|
| Model | AMR-MNS16B-V1-N2540 |
| Channels | 16 |
| Polarity | S or N |
| Supply Voltage | DC 9–28 V |
| Output Type | NPN Open-Collector / RS-232 |
| Manufacturer | All Mobile Robotics Co., Ltd. |
| Product Page | [🔗 allmobilerobotics.com](https://www.allmobilerobotics.com/product/11000838100000060) |

---

## ⚡ Wiring (NPN-OC mode → ESP32)

| Sensor Pin | ESP32 GPIO | Note |
|-----------|-----------|------|
| S1 | GPIO 13 | Leftmost |
| S2 | GPIO 12 | |
| S3 | GPIO 14 | |
| S4 | GPIO 27 | |
| S5 | GPIO 26 | |
| S6 | GPIO 25 | |
| S7 | GPIO 33 | |
| S8 | GPIO 32 | |
| S9 | GPIO 23 | |
| S10 | GPIO 22 | |
| S11 | GPIO 21 | |
| S12 | GPIO 19 | |
| S13 | GPIO 18 | |
| S14 | GPIO 5  | |
| S15 | GPIO 4  | |
| S16 | GPIO 2  | Rightmost |
| GND | GND | Shared with ESP32 |
| VCC | 9–28 V | External supply |

> **NPN Open-Collector:** LOW = line detected → use `INPUT_PULLUP` on ESP32

---

## 🖥️ Example Code (Arduino / PlatformIO)

```cpp
// NPN-OC: LOW = line detected → invert so 1 = detected
int s1 = (digitalRead(13) == LOW) ? 1 : 0;
int s2 = (digitalRead(12) == LOW) ? 1 : 0;
// ... repeat for all 16 channels
```

See full example: [`esp_sensorguide.ino`](esp_sensorguide.ino)

---

## 📄 License

Copyright © 2026 **All Mobile Robotics Co., Ltd.**  
All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED.

---

## 🏢 About

**บริษัท ออล โมบายล์ โรโบติกส์ จำกัด**  
**All Mobile Robotics Co., Ltd.**  
*System Integration | Mobile Robotics | Industrial Automation*

📍 83/9 หมู่ 3 ตำบลกระแชง อำเภอสามโคก จังหวัดปทุมธานี 12160  
🧾 เลขประจำตัวผู้เสียภาษี: 0135564009117  
📞 099-615-6938 | 084-164-9535  
🌐 [www.AllMobileRobotics.com](https://www.AllMobileRobotics.com)  
✉️ contact@AllMobileRobotics.com  
💬 LINE Official: @AllMobileRobotics  
