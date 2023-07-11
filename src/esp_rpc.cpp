#include <esp_rpc.h>

bool esp_rpc_subscribed = false;
ThingsBoard tb(esp_rpc_client, ESP_RPC_MAX_MESSAGE_SIZE);
WiFiClient esp_rpc_client;

void processSharedAttrUpd(const Shared_Attribute_Data &data) {
    Serial.println(String("Shared Update Event Received"));
    for(auto i = data.begin(); i != data.end(); ++i) {
        Serial.println("");
        Serial.println(String("Key = " + String(i->key().c_str())));
        Serial.println(String(String("Value = ") + String(i->value().as<const char*>())));
        Serial.println("");
    }
}

RPC_Response process_rpc(const RPC_Data &esp_rpc_data) {
    Serial.println(String("[ESP RPC] Comando recebido"));
    return RPC_Response(Telemetry("result", true));
}