// ============================================================
//  TEST : Raw Digital Read — AGV Guide Sensor AMR-MNS8B-V1
//  Output Type : NPN Open-Collector  (LOW = line detected)
//  External power for sensor : 9-28 V
//  Board : ESP32 (Node32s)
// ============================================================
//
//  Wiring (sensor side → ESP32 GPIO)
//  S1  →  GPIO 13      S5  →  GPIO 26
//  S2  →  GPIO 12      S6  →  GPIO 25
//  S3  →  GPIO 14      S7  →  GPIO 33
//  S4  →  GPIO 27      S8  →  GPIO 32
//  GND (sensor) must share GND with ESP32
// ============================================================

// ---- Pin mapping (S1 = leftmost, S8 = rightmost) ----------
const int PIN_S1 = 13;
const int PIN_S2 = 12;
const int PIN_S3 = 14;
const int PIN_S4 = 27;
const int PIN_S5 = 26;
const int PIN_S6 = 25;
const int PIN_S7 = 33;
const int PIN_S8 = 32;

// ===========================================================
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\n=== RAW Digital Read Test ===");
  Serial.println("NPN-OC: LOW(0) = line detected | HIGH(1) = no line");
  Serial.println("Inverted: [1] = line detected  | [0] = no line\n");

  pinMode(PIN_S1, INPUT_PULLUP);
  pinMode(PIN_S2, INPUT_PULLUP);
  pinMode(PIN_S3, INPUT_PULLUP);
  pinMode(PIN_S4, INPUT_PULLUP);
  pinMode(PIN_S5, INPUT_PULLUP);
  pinMode(PIN_S6, INPUT_PULLUP);
  pinMode(PIN_S7, INPUT_PULLUP);
  pinMode(PIN_S8, INPUT_PULLUP);
}

// ===========================================================
void loop() {
  // อ่านค่าดิบ: LOW = เจอเส้น, HIGH = ไม่เจอเส้น
  int raw_S1 = digitalRead(PIN_S1);
  int raw_S2 = digitalRead(PIN_S2);
  int raw_S3 = digitalRead(PIN_S3);
  int raw_S4 = digitalRead(PIN_S4);
  int raw_S5 = digitalRead(PIN_S5);
  int raw_S6 = digitalRead(PIN_S6);
  int raw_S7 = digitalRead(PIN_S7);
  int raw_S8 = digitalRead(PIN_S8);

  // แปลงค่า: 1 = เจอเส้น, 0 = ไม่เจอเส้น (invert เพราะ NPN-OC)
  int s1 = (raw_S1 == LOW) ? 1 : 0;
  int s2 = (raw_S2 == LOW) ? 1 : 0;
  int s3 = (raw_S3 == LOW) ? 1 : 0;
  int s4 = (raw_S4 == LOW) ? 1 : 0;
  int s5 = (raw_S5 == LOW) ? 1 : 0;
  int s6 = (raw_S6 == LOW) ? 1 : 0;
  int s7 = (raw_S7 == LOW) ? 1 : 0;
  int s8 = (raw_S8 == LOW) ? 1 : 0;

  // แสดงผลตัวเลข
  Serial.println("S1  S2  S3  S4  S5  S6  S7  S8");
  Serial.println("--------------------------------");
  Serial.print(" "); Serial.print(s1);
  Serial.print("   "); Serial.print(s2);
  Serial.print("   "); Serial.print(s3);
  Serial.print("   "); Serial.print(s4);
  Serial.print("   "); Serial.print(s5);
  Serial.print("   "); Serial.print(s6);
  Serial.print("   "); Serial.print(s7);
  Serial.print("   "); Serial.println(s8);

  // แสดงผล Bar chart  (X = เจอเส้น, . = ไม่เจอเส้น)
  Serial.print("[ ");
  Serial.print(s1 ? "X " : ". ");
  Serial.print(s2 ? "X " : ". ");
  Serial.print(s3 ? "X " : ". ");
  Serial.print(s4 ? "X " : ". ");
  Serial.print(s5 ? "X " : ". ");
  Serial.print(s6 ? "X " : ". ");
  Serial.print(s7 ? "X " : ". ");
  Serial.print(s8 ? "X " : ". ");
  Serial.println("]");
  Serial.println();

  delay(300);
}
