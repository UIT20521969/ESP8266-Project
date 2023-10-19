#include "DHT.h"            
#define DHTPIN D1       //Đọc dữ liệu từ DHT11
#define DHTTYPE DHT11  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();         // Khởi động cảm biến
}
void loop() {
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
  Serial.println("Nhiet do: " + String(t));           //Xuất nhiệt độ
  Serial.println("Do am: " + String(h));              //Xuất độ ẩm
  delay(2000);                     //Đợi 2 giây
}