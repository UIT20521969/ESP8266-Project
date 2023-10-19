#define relay D2 //led chân ngắn GND, chân dài D2
#define dat A0
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  int analog = analogRead(dat);
  int cov = map(analog, 1023, 0, 0, 100);  // gán các giá trị của cảm biến qua phần trăm
  int pt = 100 - cov;
  Serial.println("Analog: " + String(analog) + " ~ " + String(pt));
  Serial.println("Độ Ẩm: " + String(pt) + "%");
  if (pt <= 40) {
    digitalWrite(relay, HIGH);  //độ ẩm dưới 40% thì bật máy bơm
  } else {
    digitalWrite(relay, LOW);  //độ ẩm trên 40% thì tắt máy bơm
  }
  delay(1500);
}