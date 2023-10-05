#include <LiquidCrystal.h>

int seconds = 0;
int soilMoisturePin = A0; // دبوس حساس التربة
int trigPin = 7; // دبوس Trig لمستشعر Ultrasonic
int echoPin = 6; // دبوس Echo لمستشعر Ultrasonic

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
  lcd_1.begin(16, 2); // تهيئة عدد الأعمدة والصفوف على الشاشة.
  pinMode(soilMoisturePin, INPUT); // تحديد دبوس حساس التربة كمدخل.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // عرض رسالة على الشاشة.
  lcd_1.setCursor(0, 0);
  lcd_1.print("Soil Moisture:");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Distance:");
}

void loop() {
  // قراءة قيمة رطوبة التربة من حساس التربة (0 إلى 1023).
  int soilMoistureValue = analogRead(soilMoisturePin);

  // قياس المسافة باستخدام مستشعر Ultrasonic Sensor.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; // حساب المسافة بالسنتيمتر.

  // عرض قيم رطوبة التربة والمسافة على الشاشة.
  lcd_1.setCursor(14, 0);
  lcd_1.print("      "); // مسح القيمة القديمة.
  lcd_1.setCursor(14, 0);
  lcd_1.print(soilMoistureValue);

  lcd_1.setCursor(9, 1);
  lcd_1.print("     "); // مسح القيمة القديمة.
  lcd_1.setCursor(9, 1);
  lcd_1.print(distance);
  lcd_1.print(" cm");

  delay(1000); // انتظار ثانية واحدة قبل قياس القيم مرة أخرى.
}