void setRtc() {
  rtc.begin();
  rtc.setTime(hours, minutes, seconds);
  rtc.setDate(days, months, years);

  rtc.setAlarmTime(0, 0, 0);
  rtc.enableAlarm(rtc.MATCH_SS);
  rtc.attachInterrupt(alarmMatch);
}

void alarmMatch()
{
  //  applicationLog("alarm matched");
  //  if (debug) {
  //    Serial.println("alarm triggered");
  //  }
  sleep = false;
  //
}
