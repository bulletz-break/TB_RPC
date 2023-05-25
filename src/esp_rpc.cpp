#include <esp_rpc.h>

bool esp_rpc_subscribed = false;
ThingsBoard tb(esp_rpc_client, ESP_RPC_MAX_MESSAGE_SIZE);
WiFiClient esp_rpc_client;

RPC_Response process_rpc(const RPC_Data &esp_rpc_data) {
    Serial.println(String("[ESP RPC] Comando recebido"));

    int esp_rpc_wait = esp_rpc_data["wait_seconds"];
    Serial.println(String(String("[ESP RPC] esp_rpc_wait: ") + String(esp_rpc_wait)));

    RPC_Response("result", "true");

    Serial.println(String("[ESP RPC] Reiniciando ESP..."));

    delay(esp_rpc_wait * 1000);
    esp_restart();
}