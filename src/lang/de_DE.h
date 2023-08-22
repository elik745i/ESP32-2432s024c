#ifndef HASP_LANG_DE_DE_H
#define HASP_LANG_DE_DE_H

#define D_ISO_LANG_CODE "de-DE"

#define D_USERNAME "Benutzer:"
#define D_PASSWORD "Kennwort:"
#define D_SSID "Ssid:"
#define D_YES "Ja"
#define D_NO "Nein"

#define D_ERROR_OUT_OF_MEMORY "Nicht genug Speicher"
#define D_ERROR_UNKNOWN "Unbekannter Fehler"

#define D_CONFIG_NOT_CHANGED "Einstellungen nicht geändert"
#define D_CONFIG_CHANGED "Einstellungen geändert"
#define D_CONFIG_LOADED "Einstellungen geladen"

#define D_FILE_LOADING "Laden %s"
#define D_FILE_LOADED "Geladen %s"
#define D_FILE_LOAD_FAILED "Fehler beim Laden %s"
#define D_FILE_SAVING "Speichern %s"
#define D_FILE_SAVED "Gespeichert %s"
#define D_FILE_SAVE_FAILED "Fehler beim Speichern %s"
#define D_FILE_NOT_FOUND "Datei nicht gefunden"
#define D_FILE_SIZE_BYTES "Bytes"
#define D_FILE_SIZE_KILOBYTES "KiB"
#define D_FILE_SIZE_MEGABYTES "MiB"
#define D_FILE_SIZE_GIGABYTES "GiB"
#define D_FILE_SIZE_DIVIDER 1024 // kibi or kilo bytes
#define D_DECIMAL_POINT ","      // decimal comma or point

#define D_SERVICE_STARTING "Starten..."
#define D_SERVICE_STARTED "Gestartet"
#define D_SERVICE_START_FAILED "Fehler beim Start"
#define D_SERVICE_STOPPED "Angehalten"
#define D_SERVICE_DISABLED "Deaktiviert"
#define D_SERVICE_CONNECTED "Verbunden"
#define D_SERVICE_DISCONNECTED "Getrennt"

#define D_SETTING_ENABLED "Aktiviert"
#define D_SETTING_DISABLED "Deaktiviert"
#define D_SETTING_DEFAULT "Standard"

#define D_NETWORK_IP_ADDRESS_RECEIVED "IP Addresse empfangen %s"
#define D_NETWORK_ONLINE "online"
#define D_NETWORK_OFFLINE "offline"
#define D_NETWORK_CONNECTION_FAILED "Verbinden fehlgeschlagen"
#define D_NETWORK_CONNECTION_UNAUTHORIZED "Autorisieren fehlgeschlagen"

#define D_MQTT_DEFAULT_NAME "plate_%s"
#define D_MQTT_CONNECTING "Verbinden..."
#define D_MQTT_CONNECTED "Verbunden mit Broker %s mit ClientID %s"
#define D_MQTT_NOT_CONNECTED "Nicht verbunden ???"
#define D_MQTT_DISCONNECTING "Trennen..."
#define D_MQTT_DISCONNECTED "Getrennt"
#define D_MQTT_RECONNECTING "Getrennt vom Broker, erneut verbinden..."
#define D_MQTT_NOT_CONFIGURED "Broker nicht konfiguriert"
#define D_MQTT_STARTED "Gestartet: %d Bytes"
#define D_MQTT_FAILED "Fehlgeschlagen:"
#define D_MQTT_INVALID_TOPIC "Nachricht hat ungültigen Topic"
#define D_MQTT_SUBSCRIBED "Abboniert von %s"
#define D_MQTT_NOT_SUBSCRIBED "Abbonieren von %s fehlgeschlagen"
#define D_MQTT_HA_AUTO_DISCOVERY "Registriere HA auto-discovery"
#define D_MQTT_PAYLOAD_TOO_LONG "Nutzdaten zu lang (%u Bytes)"

#define D_TELNET_CLOSING_CONNECTION "Schließe Sitzung von %s"
#define D_TELNET_CLIENT_LOGIN_FROM "Client Login von %s"
#define D_TELNET_CLIENT_CONNECT_FROM "Client verbunden von %s"
#define D_TELNET_CLIENT_NOT_CONNECTED "Client nicht verbunden"
#define D_TELNET_INCORRECT_LOGIN_ATTEMPT "Fehlerhafter Anmeldeversuch von %s"
#define D_TELNET_STARTED "Telnet-Konsole gestartet"
#define D_TELNET_FAILED "Fehler beim Start der Telnet-Konsole"
#define D_TELNET_CLIENT_CONNECTED "CClient verbunden"
#define D_TELNET_CLIENT_REJECTED "Client abgewiesen"

#define D_HASP_INVALID_PAGE "Ungültige Seite %u"
#define D_HASP_INVALID_LAYER "System-Layer kann nicht gelöscht werden"
#define D_HASP_CHANGE_PAGE "Seite gewechselt zu %u"
#define D_HASP_CLEAR_PAGE "Seite %u gelöscht"

#define D_OBJECT_DELETED "Objekt entfernt"
#define D_OBJECT_UNKNOWN "Ungekanntes Objekt"
#define D_OBJECT_MISMATCH "Objekte stimmen nicht überein!"
#define D_OBJECT_LOST "Objekt verloren!"
#define D_OBJECT_CREATE_FAILED "Fehler beim erstellen der Objekt ID %u"
#define D_OBJECT_PAGE_UNKNOWN "Seiten ID %u nicht bekannt"
#define D_OBJECT_EVENT_UNKNOWN "Unbekanntes Ereignis %d"

#define D_ATTRIBUTE_UNKNOWN "Unbekannte Eigenschaft %s"
// D_ATTRIBUTE_OBSOLETE D_ATTRIBUTE_INSTEAD can be used together or just D_ATTRIBUTE_OBSOLETE alone
#define D_ATTRIBUTE_OBSOLETE "%s ist veraltet"
#define D_ATTRIBUTE_INSTEAD ", benutze %s stattdessen"
#define D_ATTRIBUTE_READ_ONLY "%s kann nur gelesen werden"
#define D_ATTRIBUTE_PAGE_METHOD_INVALID "Aufruf auf Seite  %s nicht möglich"
#define D_ATTRIBUTE_ALIGN_INVALID "Ungültige Ausrichtung: %s"
#define D_ATTRIBUTE_COLOR_INVALID "Ungültige Farbe: %s"
#define D_ATTRIBUTE_LONG_MODE_INVALID "Ungültiger long mode: %s"

#define D_OOBE_SSID_VALIDATED "SSID %s überprüft"
#define D_OOBE_AUTO_CALIBRATE "Autokalibrierung aktiviert"
#define D_OOBE_CALIBRATED "Bereits kalibriert"

#define D_DISPATCH_COMMAND_NOT_FOUND "Kommando '%s' nicht gefunden"
#define D_DISPATCH_INVALID_PAGE "Ungültige Seite %s"
#define D_DISPATCH_REBOOT "Neustart der MCU jetzt!"

#define D_JSON_FAILED "JSON-Analyse fehlgeschlagen:"
#define D_JSONL_FAILED "JSONL-Analyse fehlgeschlagen in Zeile %u"
#define D_JSONL_SUCCEEDED "Jsonl-Analyse komplett"

#define D_OTA_CHECK_UPDATE "Probiere Update URL: %s"
#define D_OTA_CHECK_COMPLETE "Update-Test komplett"
#define D_OTA_CHECK_FAILED "Update-Test fehlerhaft: %s"
#define D_OTA_UPDATE_FIRMWARE "OTA Firmware Update"
#define D_OTA_UPDATE_COMPLETE "OTA Update komplett"
#define D_OTA_UPDATE_APPLY "Firmware anwenden & Neustart"
#define D_OTA_UPDATE_FAILED "OTA Update fehlerhaft"
#define D_OTA_UPDATING_FIRMWARE "Aktualisiere Firmware..."
#define D_OTA_UPDATING_FILESYSTEM "Aktualisiere Dateisystem..."

#define D_HTTP_HASP_DESIGN "HASP Design"
#define D_HTTP_INFORMATION "Information"
#define D_HTTP_HTTP_SETTINGS "HTTP Einstellungen"
#define D_HTTP_FTP_SETTINGS "FTP Einstellungen"
#define D_HTTP_WIFI_SETTINGS "Wifi Einstellungen"
#define D_HTTP_MQTT_SETTINGS "MQTT Einstellungen"
#define D_HTTP_GPIO_SETTINGS "GPIO Einstellungen"
#define D_HTTP_MDNS_SETTINGS "mDNS Einstellungen"
#define D_HTTP_TELNET_SETTINGS "Telnet Einstellungen"
#define D_HTTP_DEBUG_SETTINGS "Debug Einstellungen"
#define D_HTTP_GUI_SETTINGS "Display Einstellungen"
#define D_HTTP_SAVE_SETTINGS "Save Einstellungen"
#define D_HTTP_UPLOAD_FILE "Datei hochladen"
#define D_HTTP_ERASE_DEVICE "Alle Einstellungen zurücksetzten"
#define D_HTTP_ADD_GPIO "Neuen Pin hinzufügen"
#define D_HTTP_BACK "Zurück"
#define D_HTTP_REFRESH "Auffrischen"
#define D_HTTP_PREV_PAGE "Vorherige Seite"
#define D_HTTP_NEXT_PAGE "Nächste Seite"
#define D_HTTP_CALIBRATE "Kalibrieren"
#define D_HTTP_ANTIBURN "Run Anti Burn-in"
#define D_HTTP_SCREENSHOT "Bildschirm Foto"
#define D_HTTP_FILE_BROWSER "Datei-Editor"
#define D_HTTP_FIRMWARE_UPGRADE "Firmware Upgrade"
#define D_HTTP_UPDATE_FIRMWARE "Update Firmware"
#define D_HTTP_FACTORY_RESET "Werkseinstellung"
#define D_HTTP_MAIN_MENU "Hauptmenü"
#define D_HTTP_REBOOT "Neustart"
#define D_HTTP_CONFIGURATION "Konfiguration"
#define D_HTTP_CONFIG_CHANGED                                                                                          \
    "Konfiguration wurde geändert, bitte klicke <a href='/reboot'>Neustart</a> zum Speichern der Änderen im Flash."
#define D_HTTP_SENDING_PAGE "Sende %S Seiten an %s"
#define D_HTTP_FOOTER "von Francis Van Roie"

#define D_INFO_VERSION "Version"
#define D_INFO_BUILD_DATETIME "Erstellungsdatum/-zeit"
#define D_INFO_ENVIRONMENT "Umgebung"
#define D_INFO_UPTIME "Betriebszeit"
#define D_INFO_FREE_HEAP "Free Heap"
#define D_INFO_FREE_BLOCK "Free Block"
#define D_INFO_DEVICE_MEMORY "Geräte Speicher"
#define D_INFO_LVGL_MEMORY "LVGL Speicher"
#define D_INFO_TOTAL_MEMORY "Gesamt"
#define D_INFO_FREE_MEMORY "Frei"
#define D_INFO_FRAGMENTATION "Fragmentation"
#define D_INFO_PSRAM_FREE "PSRam Frei"
#define D_INFO_PSRAM_SIZE "PSRam Größe"
#define D_INFO_FLASH_SIZE "Flash Größe"
#define D_INFO_SKETCH_USED "Programmspeicher genutzt"
#define D_INFO_SKETCH_FREE "Programmspeicher frei"
#define D_INFO_FS_SIZE "Dateisystem Größe"
#define D_INFO_FS_USED "Dateisystem genutzt"
#define D_INFO_FS_FREE "Dateisystem frei"
#define D_INFO_MODULE "Module"
#define D_INFO_MODEL "Model"
#define D_INFO_FREQUENCY "Frequenz"
#define D_INFO_CORE_VERSION "Core Version"
#define D_INFO_RESET_REASON "Neustart Ursache"
#define D_INFO_STATUS "Status"
#define D_INFO_SERVER "Server"
#define D_INFO_USERNAME "Benutzer"
#define D_INFO_CLIENTID "Client ID"
// #define D_INFO_CONNECTED "Verbunden"
// #define D_INFO_DISCONNECTED "Getrennt"
#define D_INFO_RECEIVED "Empfangen"
#define D_INFO_PUBLISHED "Publiziert"
#define D_INFO_FAILED "Fehlerhaft"
#define D_INFO_ETHERNET "Ethernet"
#define D_INFO_WIFI "Wifi"
#define D_INFO_LINK_SPEED "Datenrate"
#define D_INFO_FULL_DUPLEX "Full Duplex"
#define D_INFO_BSSID "BSSID"
#define D_INFO_SSID "SSID"
#define D_INFO_RSSI "Signal Stärke"
#define D_INFO_IP_ADDRESS "IP Addresse"
#define D_INFO_MAC_ADDRESS "MAC Addresse"
#define D_INFO_GATEWAY "Gateway"
#define D_INFO_DNS_SERVER "DNS Server"

#define D_OOBE_MSG "Tippen Sie auf den Bildschirm, um WiFi einzurichten oder zum verbindem mit dem Access Point:"
#define D_OOBE_SCAN_TO_CONNECT "Suche zum verbinden"

#define D_WIFI_CONNECTING_TO "Verbinden mit %s"
#define D_WIFI_CONNECTED_TO "Verbinden mit %s, IP anfordern..."
#define D_WIFI_RSSI_EXCELLENT "Exzellent"
#define D_WIFI_RSSI_GOOD "Gut"
#define D_WIFI_RSSI_FAIR "Durchschnittlich"
#define D_WIFI_RSSI_WEAK "Schwach"
#define D_WIFI_RSSI_BAD "Sehr schlecht"

// new
#define D_GPIO_SWITCH "Schalter"
#define D_GPIO_BUTTON "Druckknopf"
#define D_GPIO_TOUCH "Kapazitiver Touch"
#define D_GPIO_LED "LED"
#define D_GPIO_LED_R "Stimmung Rot"
#define D_GPIO_LED_G "Stimmung Grün"
#define D_GPIO_LED_B "Stimmung Blau"
#define D_GPIO_POWER_RELAY "Last Relay"
#define D_GPIO_LIGHT_RELAY "Licht Relay"
#define D_GPIO_PWM "PWM"
#define D_GPIO_DAC "DAC"
#define D_GPIO_SERIAL_DIMMER "Serieller Dimmer"
#define D_GPIO_UNKNOWN "Unbekannt"
#define D_GPIO_PIN "Pin"
#define D_GPIO_GROUP "Gruppe"
#define D_GPIO_GROUP_NONE "Keine"
#define D_GPIO_STATE_NORMAL "Normal"
#define D_GPIO_STATE_INVERTED "Invertiert"

#endif