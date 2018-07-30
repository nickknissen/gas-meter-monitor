/*
 * This is a sample configuration file.
 *
 * Change the settings below and save the file as "config.h"
 */

// WiFi
#define CONFIG_WIFI_SSID "{WIFI-SSID}"
#define CONFIG_WIFI_PASS "{WIFI-PASSWORD}"

// MQTT
#define CONFIG_MQTT_HOST "{MQTT-SERVER}"
#define CONFIG_MQTT_USER "{MQTT-USERNAME}"
#define CONFIG_MQTT_PASS "{MQTT-PASSWORD}"

#define CONFIG_MQTT_CLIENT_ID "gas_meter"

#define CONFIG_MQTT_TOPIC "garage/gas-pulse"

#define CONFIG_REED_PIN D2