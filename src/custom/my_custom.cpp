/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

// USAGE: - Copy this file and rename it to my_custom.cpp
//        - Change false to true on line 9

#include "hasplib.h"

#if defined(HASP_USE_CUSTOM) && true // <-- set this to true in your code

#include "hasp_debug.h"
#include "custom/my_custom.h"
//#include <esp_deep_sleep.h>

unsigned long last_blink = 0;
bool blink_state = LOW;

const int LED_BUILTIN1 = 4;  //red
const int LED_BUILTIN2 = 16; //green
const int LED_BUILTIN3 = 17; //blue
const int voltage_read = 35;
const int illum_read = 34;
const int blink_speed = 10000; //read every 10sec

float batteryFraction;
float currentVoltage;
int illum;

// Implement heartbeat led
const int fadeTime = 1000; 
unsigned long lastMillis = 0;
int brightness = 0;
int fadeDirection = 1;  // 1 for fading in, -1 for fading out

//Voltage read
const int MAX_ANALOG_VAL = 4095;
const float MAX_BATTERY_VOLTAGE = 4.2; // Max LiPoly voltage of a 3.7 battery is 4.2
const float minVoltage = 3.0;  // Minimum voltage (0% charge)
const float maxVoltage = 4.2;  // Maximum voltage (100% charge)

//deep sleep timer
const int sleepTimeSeconds = 10;  // Set the sleep time in seconds

void custom_setup()
{
    // Initialization code here
    last_blink = millis();
    //pinMode(LED_BUILTIN1, OUTPUT);
    //digitalWrite(LED_BUILTIN1, LOW);
    //pinMode(LED_BUILTIN2, OUTPUT);
    //digitalWrite(LED_BUILTIN2, LOW);
    //pinMode(LED_BUILTIN3, OUTPUT);
    //digitalWrite(LED_BUILTIN3, LOW);   
    pinMode(voltage_read, INPUT);
    pinMode(illum_read, INPUT);
    randomSeed(millis());
}

void custom_loop()
{
    // read voltage every 10 seconds
    if(blink_speed && (millis() - last_blink > blink_speed)) {

        currentVoltage = analogRead(voltage_read) * (maxVoltage / 4095.0);
        // Calculate the percentage of charge
        batteryFraction = map(constrain(currentVoltage, minVoltage, maxVoltage) * 1000, minVoltage * 1000, maxVoltage * 1000, 0, 100);

        illum = analogRead(illum_read);

        if (batteryFraction <= 15) {
            low_bat_alert(LED_BUILTIN1, fadeTime);
        }
        else if (batteryFraction <= 5) {
             // Avoid rapid transitions by adding a delay
            delay(1000);  // Adjust the delay as needed           
            esp_deep_sleep(1000000LL * sleepTimeSeconds);;
        } 
        last_blink = millis();
    }
}

// Function to update the LED brightness for a heartbeat effect
void low_bat_alert(int pin, int duration) {
  unsigned long currentMillis = millis();

  // Check if it's time to update the LED brightness
  if (currentMillis - lastMillis >= duration / 255) {
    lastMillis = currentMillis;

    // Update brightness based on the fade direction
    brightness += fadeDirection;

    // Change direction if reaching maximum or minimum brightness
    if (brightness >= 255 || brightness <= 0) {
      fadeDirection *= -1;
    }

    analogWrite(pin, brightness);
  }
}

void custom_every_second()
{
    Serial.print("#");
}

void custom_every_5seconds()
{
    LOG_VERBOSE(TAG_CUSTOM, "%d seconds have passsed...", 5);


    // Convert the integer to a string
    String vbatFraction = String(batteryFraction);
    String vbatLevel = String(currentVoltage);
    String illumLevel = String(illum);

    // Create the JSON string
    String jsonString = "{\"vbat_Fraction\":" + vbatFraction + "}";
    String jsonString2 = "{\"vbat_Level\":" + vbatLevel + "}";
    String jsonString3 = "{\"illum_Level\":" + illumLevel + "}";

    

    // Convert the JSON string to a const char* for your function
    const char* jsonChar = jsonString.c_str();
    const char* jsonChar2 = jsonString2.c_str();
    const char* jsonChar3 = jsonString3.c_str();

    // Call your function with the JSON string
    dispatch_state_subtopic("vbat_Fraction", jsonChar);
    dispatch_state_subtopic("vbat_Level", jsonChar2);  
    dispatch_state_subtopic("illum_Level", jsonChar3); 
    
    //Battery percentage
    String jsonString4 = "Battery"; //topic
    const char* jsonChar4 = jsonString4.c_str();
    dispatch_state_val(jsonChar4, (hasp_event_t) 1, batteryFraction); 

}


bool custom_pin_in_use(uint8_t pin)
{
    
    switch(pin) {
        case illum_read:  // Custom LED pin
        case 6:  // Custom Input pin
            return true;
        default:
            return false;
    }
    
}

void custom_get_sensors(JsonDocument& doc)
{
    JsonObject sensor = doc.createNestedObject(F("Battery"));  // Add Key
    sensor[F("Battery")] = batteryFraction;                        // Set Value

}

void custom_topic_payload(const char* topic, const char* payload, uint8_t source){
    // Not used
}

#endif // HASP_USE_CUSTOM