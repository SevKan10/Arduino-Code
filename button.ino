int button = 2;
int led = 13;
int sta = 0;
void setup() {
  pinMode(button, INPUT_PULLUP);  //Cài đặt chân D11 ở trạng thái đọc dữ liệu
  pinMode(led,OUTPUT);
  Serial.begin(9600); // giao tiếp qua cổng
}

void loop() {
  int sta = digitalRead(button);  
  Serial.println(sta);
  if (sta == 0) { // Nếu mà button bị nhấn
    digitalWrite(led,HIGH); // Đèn led sáng
  } else { // ngược lại
    digitalWrite(led,LOW);
  }
}