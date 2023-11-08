/* MIT License - Copyright (c) 2019-2022 Francis Van Roie
   For full license information read the LICENSE file in the project folder */

// USAGE: - Copy this file and rename it to my_custom.cpp
//        - Change false to true on line 9

#include "hasplib.h"
//#include <lvgl.h>

#if defined(HASP_USE_CUSTOM) && true // <-- set this to true in your code

#include "hasp_debug.h"
#include "custom/my_custom.h"


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

//extern lv_obj_t* battery_bar;  // Declare the battery bar variable
//lv_obj_t* battery_bar;  // Declare the battery bar variable

// Implement heartbeat led
const int fadeTime = 1000; 
unsigned long lastMillis = 0;
int brightness = 0;
int fadeDirection = 1;  // 1 for fading in, -1 for fading out

//Voltage read
const int MAX_ANALOG_VAL = 4095;
const float MAX_BATTERY_VOLTAGE = 4.2; // Max LiPoly voltage of a 3.7 battery is 4.2
const float minVoltage = 3.3;  // Minimum voltage (0% charge)
const float maxVoltage = 4.2;  // Maximum voltage (100% charge)

//deep sleep timer
const int sleepTimeSeconds = 10;  // Set the sleep time in seconds

void custom_setup()
{
    // Initialization code here
    last_blink = millis();
    pinMode(voltage_read, INPUT);
    pinMode(illum_read, INPUT);
    //uncomment if LEDS are ON at start, then comment back
    /*
    pinMode(LED_BUILTIN1, OUTPUT);
    analogWrite(LED_BUILTIN1, 255);
    pinMode(LED_BUILTIN2, OUTPUT);
    analogWrite(LED_BUILTIN2, 255);
    pinMode(LED_BUILTIN3, OUTPUT);
    analogWrite(LED_BUILTIN3, 255);
    */
    randomSeed(millis());

    //lv_init();
    //lv_disp_drv_t disp_drv;
    //lv_disp_drv_init(&disp_drv);
}

void custom_loop()
{
    // read voltage every 10 seconds
    if(blink_speed && (millis() - last_blink > blink_speed)) {

        currentVoltage = analogRead(voltage_read) * (maxVoltage / 4095.0);
        // Calculate the percentage of charge
        batteryFraction = map(constrain(currentVoltage, minVoltage, maxVoltage) * 1000, minVoltage * 1000, maxVoltage * 1000, 0, 100);
        illum = analogRead(illum_read);
        last_blink = millis();
        updateBatteryDisplay(11, 2, batteryFraction);
        updateBatteryDisplay(9, 9, batteryFraction);
        updateBatteryDisplay(0, 7, batteryFraction);
        //updateVoltageDisplay(9,10,currentVoltage);
        String voltageString = String(currentVoltage, 2);  // Converts the float to a String with 2 decimal places
        voltageString += "V";  // Concatenates "V" at the end
        updateTextDisplay(9, 10, voltageString.c_str());
        String fractionString = String(batteryFraction, 2);  // Converts the float to a String with 2 decimal places
        fractionString += "%";  // Concatenates "%" at the end 
        updateTextDisplay(9, 11, fractionString.c_str());              
    }
    if (batteryFraction <= 35) {
            low_bat_alert(LED_BUILTIN1, fadeTime);
            low_bat_alert(LED_BUILTIN1, fadeTime);
    }
    else if (batteryFraction <= 25) {
            low_bat_alert(LED_BUILTIN1, fadeTime);
            analogWrite(LED_BUILTIN2, 255);
    }
    else if (batteryFraction <= 15) {
            analogWrite(LED_BUILTIN1, 255);
            analogWrite(LED_BUILTIN2, 255);
            analogWrite(LED_BUILTIN3, 255);          
            esp_deep_sleep(1000000LL * sleepTimeSeconds);
    } 
    else{
          analogWrite(LED_BUILTIN1, 255);
    }

}

void updateBatteryDisplay(uint8_t page, uint8_t id, float adata) {
    lv_obj_t* widget = hasp_find_obj_from_page_id(page, id);
    if (!widget) return; // object doesn't exist
    lv_bar_set_value(widget, adata, LV_ANIM_OFF);
}

void updateTextDisplay(uint8_t page, uint8_t id, const char* text) {
    lv_obj_t* widget = hasp_find_obj_from_page_id(page, id);
    if (!widget) return; // object doesn't exist
    lv_label_set_text(widget, text);
}

// Function to update the LED brightness for a heartbeat effect
void low_bat_alert(int pin, int duration) {
    unsigned long currentMillis = millis();

    // Check if it's time to update the LED brightness
    if (currentMillis - lastMillis >= duration / 255) {
        lastMillis = currentMillis;

        // Update brightness based on the fade direction
        brightness += fadeDirection;

        // Ensure brightness stays within the valid range
        brightness = constrain(brightness, 0, 255);

        // Change direction if reaching maximum or minimum brightness
        if (brightness >= 255 || brightness <= 0) {
            fadeDirection *= -1;
        }

        // Check if we are in the double-beat range (e.g., 50-100 or 150-200)
        if ((brightness >= 50 && brightness <= 100) || (brightness >= 150 && brightness <= 200)) {
            // Create a second beat by slightly modifying the brightness
            int secondBeat = map(brightness, 50, 200, 0, 255);
            analogWrite(pin, secondBeat);
        } else {
            // Otherwise, use the regular brightness
            analogWrite(pin, brightness);
        }
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