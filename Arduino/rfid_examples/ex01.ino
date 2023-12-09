#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Create instance of the MFRC522 class

void setup() {
    Serial.begin(9600); // Initialize serial communication
    SPI.begin(); // Initialize SPI bus
    rfid.PCD_Init(); // Initialize MFRC522 RFID module

    Serial.println("Place your RFID card near the reader...");
}

void loop() {
    // Check if a new card is present
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
        // Get the UID of the card
        String uid = "";
        for (byte i = 0; i < rfid.uid.size; i++) {
            uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
            uid += String(rfid.uid.uidByte[i], HEX);
        }

        Serial.print("Card UID: ");
        Serial.println(uid);

        rfid.PICC_HaltA(); // Halt PICC
        rfid.PCD_StopCrypto1(); // Stop encryption on PCD

        delay(1000); // Wait for 1 second before scanning for another card
    }
}

void loop() {
    // Check if a new card is present
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
        // Get the UID of the card
        String uid = "";
        for (byte i = 0; i < rfid.uid.size; i++) {
            uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
            uid += String(rfid.uid.uidByte[i], HEX);
        }

        Serial.print("Card UID: ");
        Serial.println(uid);

        rfid.PICC_HaltA(); // Halt PICC
        rfid.PCD_StopCrypto1(); // Stop encryption on PCD

        delay(1000); // Wait for 1 second before scanning for another card
    }
}
