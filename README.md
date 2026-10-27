# BSRS — Wearable Motion-Sensing Prototype

An early embedded project exploring wearable motion-data collection for a proposed child-behavior research application.

**Stack:** ESP32-S3 · Arduino · PlatformIO · MPU6050 · I²C · Serial CSV

**Status:** Motion capture prototype. The committed firmware streams raw accelerometer and gyroscope readings. No trained screening model, validated attention score, or clinical screening capability is implemented.

## What the code currently does

- Initializes an MPU6050 over I²C using GPIO 8 (SDA) and GPIO 9 (SCL).
- Reads six raw motion channels: `ax, ay, az, gx, gy, gz`.
- Sends one comma-separated sample per line over serial at 115200 baud.
- Uses a 50 ms loop delay for a nominal sampling rate near 20 Hz; this is not precision-timed acquisition.

## Repository layout

| Path | Purpose |
|---|---|
| [firmware/BSRS](firmware/BSRS) | PlatformIO firmware project |
| [firmware/BSRS/src/main.cpp](firmware/BSRS/src/main.cpp) | Motion acquisition and serial output |
| [firmware/BSRS/platformio.ini](firmware/BSRS/platformio.ini) | Board, framework, and serial settings |
| [ai-model/har70plus](ai-model/har70plus) | CSV data and an empty model-script placeholder |

## Firmware setup

1. Open `firmware/BSRS` as a PlatformIO project.
2. Check the board configuration: it currently targets `adafruit_feather_esp32s3` with the Arduino framework.
3. Configure an MPU6050 library compatible with the API used in `main.cpp`. The repository does not currently declare this dependency in `lib_deps`.
4. Update `upload_port` and `monitor_port` for your machine; both currently use `COM5`.
5. Verify the sensor wiring, then build and upload with PlatformIO.
6. Open the serial monitor at 115200 baud to inspect the six-column CSV stream.

## Next steps

- Declare and pin the MPU6050 dependency for reproducible builds.
- Check sensor connectivity and handle read failures.
- Add timestamps and a documented data-capture procedure.
- Document dataset sources, permitted use, and suitability before model development.
- Define and evaluate a research objective before making screening claims.

The repository name reflects the original project idea. The current implementation is a motion-data acquisition prototype, not a diagnostic or clinically validated screening tool.
