#include <Relay.h>

Relay::Relay(byte pin)
{
  this->_pin = pin;
  this->_activeTime = 0;
  this->_state = false;
  pinMode(this->_pin, OUTPUT);
  off();
}

void Relay::alwaysOn()
{
  this->_state = true;
  digitalWrite(this->_pin, this->_state);
}

void Relay::on(uint16_t duration)
{
  this->_activeTime = millis();
  this->_duration = duration * 1000;
  this->_state = true;
  digitalWrite(this->_pin, this->_state);
}

void Relay::off()
{
  this->_activeTime = 0;
  this->_state = false;
  digitalWrite(_pin, _state);
}

bool Relay::state()
{
  return this->_state;
}

bool Relay::timeout()
{
  if (this->_activeTime > 0 && millis() - this->_activeTime >= this->_duration)
  {
    off();
    return true;
  }
  return false;
}

uint32_t Relay::activeTime()
{
  return this->_activeTime;
}