# IOT_DISTANCE_AND_TEMPERATURE_MONITORING_VIA_WHATSAPP
MONITORING DISTANCE AND TEMPERATURE VIA IOT AND WHATSAPP

This IoT project uses the ESP8266 microcontroller and sensors, specifically the DHT11 and ULTRASONIC sensors. It's a simple project that connects to WhatsApp using the [callmebot](https://www.callmebot.com//) API, which is free and easy to use.

Here are the general steps to write the code:

1. **Hardware Setup**:
   - Make sure you have an ESP8266 device connected to DHT11 and ULTRASONIC (HC-SR04) sensors.
   - Connect the wires from the sensors to the appropriate pins on the ESP8266, ensuring that the positive, negative, and signal wires are correctly connected.

2. **Library Installation**:
   - Ensure you have installed the necessary libraries. In your code, you're using libraries like `ESP8266WiFi`, `ESP8266HTTPClient`, `WiFiClient`, and others. Make sure these libraries are installed in the Arduino IDE. You can install them through the "Sketch" -> "Include Library" -> "Manage Libraries" menu by searching for the appropriate library names.

3. **WiFi Configuration**:
   - Change the values of `ssid` and `password` to match your WiFi network information.

4. **WhatsApp Number and API Key Configuration**:
   - Replace the value of `phoneNumber` with the WhatsApp phone number that will receive messages.
   - Replace the value of `apiKey` with the API key you obtain from "callmebot.com."

5. **Sensor Initialization**:
   - Specify the pins used to connect the DHT11 and ULTRASONIC (HC-SR04) sensors to the ESP8266. Set these pins correctly in the pin definitions.

6. **Setup() Function**:
   - In the `setup()`, initialize serial communication with `Serial.begin(115200)`.
   - Start the WiFi connection using `WiFi.begin(ssid, password)`.
   - Wait until the device is connected to the WiFi network with a `while(WiFi.status() != WL_CONNECTED)` loop.
   - After a successful WiFi connection, initialize the DHT11 sensor and set the pin mode for the ultrasonic sensor.

7. **Loop() Function**:
   - In `loop()`, use a loop to periodically read the sensors and send WhatsApp messages.
   - Use variables like `interval` and `previousMillis` to control the message sending frequency.
   - In each iteration, read the temperature and humidity from the DHT11 sensor, and read the distance from the ultrasonic sensor.
   - Create a message with the measured data.
   - Use the `sendMessage()` function to send the message to the specified WhatsApp number.

8. **measureDistance() Function**:
   - This function is used to measure distance with the ultrasonic sensor and should be called from `loop()`.
   - The function sets the ultrasonic signal, measures the bounce-back time, and calculates the distance.

9. **sendMessage() Function**:
   - This function is used to send a WhatsApp message with the measured data.
   - It constructs a URL containing the phone number, API key, and the message to be sent.
   - Using `HTTPClient`, it establishes an HTTP connection to the "callmebot.com" service and sends the message.

10. **Test the Code**: After writing the code, save and compile it in the Arduino IDE. Ensure there are no syntax errors or compilation issues.

11. **Upload the Code**: Upload the code to your ESP8266 device.

12. **Monitor Serial Output**: Use the serial monitor in the Arduino IDE to view the device's output. This will help you check if the device successfully connects to WiFi and sends WhatsApp messages correctly.

13. **Monitor the Results**: Make sure your device functions as expected. Also, verify that WhatsApp messages are sent to the specified number.

14. **Debug and Enhance**: If needed, you can debug or modify the code to meet your specific requirements or add additional features.

This code allows you to monitor temperature and distance using IoT and send the data via WhatsApp, which can be handy for various applications.
