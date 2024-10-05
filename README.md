Soil Moisture Monitoring System with NodeMCU ESP8266 and ThingSpeak

This project is designed to monitor soil moisture levels using two soil moisture sensors connected to a NodeMCU ESP8266 microcontroller. The system is capable of measuring the moisture content in the soil and sending real-time data to a cloud-based platform (ThingSpeak) for remote monitoring and analysis. This project is ideal for applications such as automated plant watering systems, smart agriculture, and soil health monitoring.
Key Features:

    Dual Soil Moisture Sensors: The system utilizes two soil moisture sensors, each capable of providing analog readings that represent the soil's moisture content. This allows for monitoring different areas of a garden or farm simultaneously.

    WiFi Connectivity: The NodeMCU ESP8266 connects to the internet via WiFi, allowing data to be uploaded to the cloud for remote access.

    ThingSpeak Integration: The soil moisture data is sent to ThingSpeak, a cloud-based IoT analytics platform, where users can visualize data trends, set alerts, and analyze historical data through a web interface.

    Real-time Data Logging: The system continuously monitors the soil moisture levels and sends data to ThingSpeak every 15 seconds, making it suitable for real-time monitoring of soil conditions.

    Power-Efficient Design: By leveraging the NodeMCU ESP8266, the system is compact, energy-efficient, and easy to deploy in various locations.

Components Used:

    NodeMCU ESP8266: The microcontroller that powers the system, handles WiFi connectivity, and sends data to ThingSpeak.
    Soil Moisture Sensors: Two analog sensors used to measure the moisture content of the soil.
    ThingSpeak API: The cloud platform where the data is uploaded and visualized in real-time.

Pin Configuration:
Component	NodeMCU Pin	Description
Soil Moisture Sensor 1	AO	Analog pin for sensor 1 (connected to A0)
DO	Digital output for sensor 1 (connected to D1)
Soil Moisture Sensor 2	AO	Analog pin for sensor 2 (connected to A0 using selection logic or multiplexer)
DO	Digital output for sensor 2 (connected to D2)
Power (VCC)	3.3V/5V	Power supply for both sensors
Ground (GND)	GND	Ground connection for all components
How It Works:

    Sensor Readings: The NodeMCU reads analog voltage values from each soil moisture sensor. These values are converted into percentage moisture levels (0% for completely dry and 100% for fully wet).

    Data Processing: The analog reading is processed into a percentage value that represents the soil moisture content. This calculation is performed for both sensors.

    WiFi Connection: The NodeMCU connects to a local WiFi network using the SSID and password provided in the code.

    Data Upload: Every 15 seconds, the moisture percentages from both sensors are uploaded to ThingSpeak using the Write API key.

    ThingSpeak Visualization: The data is visualized on the ThingSpeak dashboard, allowing users to monitor soil conditions remotely via a web browser or mobile device.

Project Workflow:

    Connect the soil moisture sensors to the NodeMCU following the specified pinout.
    Write and upload the code to the NodeMCU, setting up WiFi and ThingSpeak credentials.
    Power the NodeMCU and monitor soil moisture data on the ThingSpeak channel.

Applications:

    Smart Irrigation: Automatically water plants when the soil moisture drops below a certain threshold.
    Precision Agriculture: Monitor the moisture levels of different soil sections to optimize water usage in farming.
    Home Gardening: Use it to keep track of your garden’s soil moisture to ensure proper hydration of plants.

Future Improvements:

    Integrate an automated pump system to water the plants when moisture levels are low.
    Add more sensors to monitor additional zones.
    Include notifications (via email or SMS) when the moisture level drops below a specific threshold
