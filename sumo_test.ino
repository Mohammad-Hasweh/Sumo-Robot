const int top_left_a = NULL;
const int top_left_b = NULL;
const int top_left_e = NULL;

const int top_right_a = NULL;
const int top_right_b = NULL;
const int top_right_e = NULL;

const int bottom_left_a = NULL;
const int bottom_left_b = NULL;
const int bottom_left_e = NULL;

const int bottom_right_a = NULL;
const int bottom_right_b = NULL;
const int bottom_right_e = NULL;

const int ir1_pin = NULL; // front left
const int ir2_pin = NULL; // front between
const int ir3_pin = NULL; // front right
const int ir4_pin = NULL; // left
const int ir5_pin = NULL; // right
const int ir6_pin = NULL; // back

const int edge1_pin = NULL; // top left
const int edge2_pin = NULL; // top right
const int edge3_pin = NULL; // bottom left
const int edge4_pin = NULL; // bottom right

int defult_speed = 128;
int max_speed = 255;
int defult_delay = 250;

void setup() {
    pinMode(top_left_a, OUTPUT);
    pinMode(top_left_b, OUTPUT);
    pinMode(top_left_e, OUTPUT);

    pinMode(top_right_a, OUTPUT);
    pinMode(top_right_b, OUTPUT);
    pinMode(top_right_e, OUTPUT);
  
    pinMode(bottom_left_a, OUTPUT);
    pinMode(bottom_left_b, OUTPUT);
    pinMode(bottom_left_e, OUTPUT);

    pinMode(bottom_right_a, OUTPUT);
    pinMode(bottom_right_b, OUTPUT);
    pinMode(bottom_right_e, OUTPUT);

    pinMode(ir1_pin, INPUT);
    pinMode(ir2_pin, INPUT);
    pinMode(ir3_pin, INPUT);
    pinMode(ir4_pin, INPUT);
    pinMode(ir5_pin, INPUT);
    pinMode(ir6_pin, INPUT);

    pinMode(edge1_pin, INPUT);
    pinMode(edge2_pin, INPUT);
    pinMode(edge3_pin, INPUT);
    pinMode(edge4_pin, INPUT);
}

void loop() {
    tornado_search();
    detectEdge();
    trackOpponent();
}

void move_forward(int speed) {
    analogWrite(top_left_e, speed);
    analogWrite(top_right_e, speed);
    analogWrite(bottom_left_e, speed);
    analogWrite(bottom_right_e, speed);

    digitalWrite(top_left_a, HIGH);
    digitalWrite(top_left_b, LOW);

    digitalWrite(top_right_a, HIGH);
    digitalWrite(top_right_b, LOW);

    digitalWrite(bottom_left_a, HIGH);
    digitalWrite(bottom_left_b, LOW);

    digitalWrite(bottom_right_a, HIGH);
    digitalWrite(bottom_right_b, LOW);
}

void move_backward(int speed) {
    analogWrite(top_left_e, speed);
    analogWrite(top_right_e, speed);
    analogWrite(bottom_left_e, speed);
    analogWrite(bottom_right_e, speed);

    digitalWrite(top_left_a, LOW);
    digitalWrite(top_left_b, HIGH);

    digitalWrite(top_right_a, LOW);
    digitalWrite(top_right_b, HIGH);

    digitalWrite(bottom_left_a, LOW);
    digitalWrite(bottom_left_b, HIGH);

    digitalWrite(bottom_right_a, LOW);
    digitalWrite(bottom_right_b, HIGH);
}

void move_left(int speed) {
    analogWrite(top_left_e, speed);
    analogWrite(top_right_e, speed);
    analogWrite(bottom_left_e, speed);
    analogWrite(bottom_right_e, speed);

    digitalWrite(top_left_a, LOW);
    digitalWrite(top_left_b, HIGH);
    
    digitalWrite(top_right_a, HIGH);
    digitalWrite(top_right_b, LOW);

    digitalWrite(bottom_left_a, HIGH);
    digitalWrite(bottom_left_b, LOW);
    
    digitalWrite(bottom_right_a, LOW);
    digitalWrite(bottom_right_b, HIGH);
}

void move_right(int speed) {
    analogWrite(top_left_e, speed);
    analogWrite(top_right_e, speed);
    analogWrite(bottom_left_e, speed);
    analogWrite(bottom_right_e, speed);

    digitalWrite(top_left_a, HIGH);
    digitalWrite(top_left_b, LOW);
    
    digitalWrite(top_right_a, LOW);
    digitalWrite(top_right_b, HIGH);

    digitalWrite(bottom_left_a, LOW);
    digitalWrite(bottom_left_b, HIGH);
    
    digitalWrite(bottom_right_a, HIGH);
    digitalWrite(bottom_right_b, LOW);
}

void stop() {
    digitalWrite(top_left_a, LOW);
    digitalWrite(top_left_b, LOW);
    
    digitalWrite(top_right_a, LOW);
    digitalWrite(top_right_b, LOW);

    digitalWrite(bottom_left_a, LOW);
    digitalWrite(bottom_left_b, LOW);
    
    digitalWrite(bottom_right_a, LOW);
    digitalWrite(bottom_right_b, LOW);
}

void slightly_right(int speed = 255, int d = 150) {
    move_right(speed);
    delay(d);
}

void slightly_left(int speed = 255, int d = 150) {
    move_left(speed);
    delay(d);
}

void attack() {
    while (digitalRead(ir2_pin)) {
        move_forward(100);
    }
}

void trackOpponent() {
    int ir1_read = digitalRead(ir1_pin);
    int ir2_read = digitalRead(ir2_pin);
    int ir3_read = digitalRead(ir3_pin);
    int ir4_read = digitalRead(ir4_pin);
    int ir5_read = digitalRead(ir5_pin);
    int ir6_read = digitalRead(ir6_pin);

    if (ir2_read) {
        attack();
    } else if (ir1_read || ir4_read) {
        move_left(max_speed);
    } else if (ir3_read || ir5_read) {
        move_right(max_speed);
    } else if (ir6_read) {
        int randDirection = random(0, 2);
        if (randDirection == 0) {
            move_left(max_speed);
        } else {
            move_right(max_speed);
        }
    }
}

void detectEdge() {
    int edge1_read = digitalRead(edge1_pin);
    int edge2_read = digitalRead(edge2_pin);
    int edge3_read = digitalRead(edge3_pin);
    int edge4_read = digitalRead(edge4_pin);

    if (edge1_read && edge2_read) {
        stop();
        move_backward(max_speed);
        delay(defult_delay);
        move_right(max_speed);
        delay(defult_delay);
    } else if (edge1_read) {
        stop();
        move_backward(max_speed);
        delay(defult_delay);
        slightly_right();
    } else if (edge2_read) {
        stop();
        move_backward(max_speed);
        delay(defult_delay);
        slightly_left();
    } else if (edge3_read && edge4_read) {
        move_forward(max_speed);
    } else if (edge4_read) {
        move_forward(max_speed);
        delay(defult_delay);
        slightly_left();
    } else if (edge3_read) {
        move_forward(max_speed);
        delay(defult_delay);
        slightly_right();
    }
}

void tornado_search() {
    move_right(255);
}

void zigzag_search() {
    move_forward(255);
}
