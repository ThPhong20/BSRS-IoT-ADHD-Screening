#include <Arduino.h>
#include <MPU6050.h>
#include <Wire.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9);
  mpu.initialize();

  // (tuỳ chọn) chờ Serial sẵn sàng trên một số board
  // while (!Serial) { delay(10); }
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // IMPORTANT: chỉ số, CSV, mỗi dòng 1 sample
  Serial.print(ax); Serial.print(',');
  Serial.print(ay); Serial.print(',');
  Serial.print(az); Serial.print(',');
  Serial.print(gx); Serial.print(',');
  Serial.print(gy); Serial.print(',');
  Serial.println(gz);

  delay(50); // 20 Hz (>2Hz) OK cho auto-detect
}
