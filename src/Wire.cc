#include "arduino-mock/Wire.h"

static WireMock* p_WireMock = NULL;
WireMock* WireMockInstance() {
  if (!p_WireMock) {
    p_WireMock = new WireMock();
  }
  return p_WireMock;
}

void releaseWireMock() {
  if (p_WireMock) {
    delete p_WireMock;
    p_WireMock = NULL;
  }
}

void TwoWire::begin() {
  p_WireMock->begin();
}

void TwoWire::begin(uint8_t a) {
  p_WireMock->begin(a);
}

void TwoWire::begin(int a) {
  p_WireMock->begin(a);
}

void TwoWire::beginTransmission(uint8_t a) {
  p_WireMock->beginTransmission(a);
}


uint8_t TwoWire::endTransmission(void) {
  return p_WireMock->endTransmission();
}

size_t TwoWire::write(uint8_t a) {
  return p_WireMock->write(a);
}

size_t TwoWire::write(const uint8_t* a, uint8_t b) {
  return p_WireMock->write(a, b);
}

int TwoWire::available(void) {
  return p_WireMock->available();
}

int TwoWire::read(void) {
  return p_WireMock->read();
}

void TwoWire::onReceive(uint8_t* a) {
  p_WireMock->onReceive(a);
}

void TwoWire::onRequest(uint8_t* a) {
  p_WireMock->onRequest(a);
}

uint8_t TwoWire::endTransmission(uint8_t a) {
  return p_WireMock->endTransmission(a);
}

uint8_t TwoWire::requestFrom(uint8_t a, uint8_t b) {
  return p_WireMock->requestFrom(a, b);
}

uint8_t TwoWire::requestFrom(uint8_t a, uint8_t b, uint8_t c) {
  return p_WireMock->requestFrom(a, b, c);
}

// Preinstantiate Objects
TwoWire Wire;
