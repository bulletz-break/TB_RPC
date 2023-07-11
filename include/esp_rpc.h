#ifndef ESP_RPC_H
#define ESP_RPC_H

#include <ThingsBoard.h>
#include <WiFi.h>

#define ESP_RPC_MAX_MESSAGE_SIZE 512

extern WiFiClient esp_rpc_client;
extern ThingsBoard tb;
extern bool esp_rpc_subscribed;

constexpr std::array<const char*, 1U> SUBSCRIBED_SHARED_ATTRIBUTES = {
  "TesteString"
};

RPC_Response process_rpc(const RPC_Data &esp_rpc_data);
void processSharedAttrUpd(const Shared_Attribute_Data &data);
const Shared_Attribute_Callback callback(SUBSCRIBED_SHARED_ATTRIBUTES.cbegin(), SUBSCRIBED_SHARED_ATTRIBUTES.cend(), processSharedAttrUpd);

const std::array<RPC_Callback, 1U> esp_rpc_callbacks = {
    RPC_Callback{"restart_esp", process_rpc}
};

#endif