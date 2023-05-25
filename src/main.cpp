#include <Arduino.h>
#include <WiFi.h>
#include <ThingsBoard.h>
#include <esp_rpc.h>

bool wifi_connect(String wifi_ssid, String wifi_pass);
bool tb_connect(String host, String token);

void setup() {
    Serial.begin(921600);

    Serial.println("");
    Serial.println("Setup");
}

void loop() {
    if(WiFi.status() != WL_CONNECTED) { wifi_connect("wifi_ssid", "wifi_pass"); }
    if(!tb.connected()) { tb_connect("host.com.br", "token"); }

    if(!esp_rpc_subscribed) {
        Serial.println(String("[ESP RPC] Subscribing..."));
        if(tb.RPC_Subscribe(esp_rpc_callbacks.cbegin(), esp_rpc_callbacks.cend())) {
            esp_rpc_subscribed = true;
            Serial.println(String("[ESP RPC] Subscribe success"));
        }
    }

    tb.loop();
    delay(1000);
}





bool wifi_connect(String wifi_ssid, String wifi_pass) {
    Serial.print(String(String("[WiFi] Conectando à ") + String(wifi_ssid) + String("...")));
    WiFi.begin(wifi_ssid.c_str(), wifi_pass.c_str());
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(String("."));
        delay(300);
    }
    Serial.println(String(" Conectado!"));
    return true;
}

bool tb_connect(String host, String token) {
    Serial.print(String(String("Conectando à ") + String(host) + String(" com o token: ") + String(token) + String("...")));

    tb.connect(host.c_str(), token.c_str(), 1883);
    while(!tb.connected()) {
        Serial.print(String("."));
        delay(300);
    }
    Serial.println(String(" Conectado!"));
    return true;
}