#include <RTClib.h>
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC kehilangan daya, segera atur waktu!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    Serial.println("waktu RTC telah diatur!");
  }
}

void loop() {
}
