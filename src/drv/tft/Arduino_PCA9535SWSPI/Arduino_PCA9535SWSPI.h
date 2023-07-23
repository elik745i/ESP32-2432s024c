#ifndef _Arduino_PCA9535SWSPI_H_
#define _Arduino_PCA9535SWSPI_H_

#if defined(ESP32) && (CONFIG_IDF_TARGET_ESP32S3) && defined(HASP_USE_ARDUINOGFX)

#include <Wire.h>

#include "Arduino_DataBus.h"

#define PCA9535_IIC_ADDRESS 0X20

#define PCA9535_INPUT_PORT_0_REG 0X00
#define PCA9535_INPUT_PORT_1_REG 0X01
#define PCA9535_OUTPUT_PORT_0_REG 0X02
#define PCA9535_OUTPUT_PORT_1_REG 0X03
#define PCA9535_INVERSION_PORT_0_REG 0X04
#define PCA9535_INVERSION_PORT_1_REG 0X05
#define PCA9535_CONFIG_PORT_0_REG 0X06
#define PCA9535_CONFIG_PORT_1_REG 0X07

class Arduino_PCA9535SWSPI : public Arduino_DataBus
{
public:
  Arduino_PCA9535SWSPI(int8_t sda, int8_t scl, int8_t pwd, int8_t cs, int8_t sck, int8_t mosi, TwoWire *wire = &Wire);

  bool begin(int32_t speed = GFX_NOT_DEFINED, int8_t dataMode = GFX_NOT_DEFINED) override;
  void beginWrite() override;
  void endWrite() override;
  void writeCommand(uint8_t) override;
  void writeCommand16(uint16_t) override;
  void write(uint8_t) override;
  void write16(uint16_t) override;
  void writeRepeat(uint16_t p, uint32_t len) override;
  void writePixels(uint16_t *data, uint32_t len) override;

#if !defined(LITTLE_FOOT_PRINT)
  void writeBytes(uint8_t *data, uint32_t len) override;
#endif // !defined(LITTLE_FOOT_PRINT)

  void pinMode(uint8_t pin, uint8_t mode);
  void pinMode8(uint8_t port, uint8_t pin, uint8_t mode);

  void digitalWrite(uint8_t pin, uint8_t val);
  int digitalRead(uint8_t pin);

protected:
  void writeRegister(uint8_t reg, uint8_t *data, size_t len);
  uint8_t readRegister(uint8_t reg, uint8_t *data, size_t len);

  uint8_t _address;
  bool is_found;

  int8_t _sda, _scl, _pwd, _cs, _sck, _mosi;
  TwoWire *_wire;

private:
};

#endif

#endif // _Arduino_PCA9535SWSPI_H_
