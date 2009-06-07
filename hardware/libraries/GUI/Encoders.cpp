#include "Encoders.hh"

#include "Midi.h"

Encoder::Encoder(char *_name) {
  old = 0;
  cur = 0;
  redisplay = false;
  setName(_name);
}

void Encoder::clear() {
  old = 0;
  cur = 0;
}

void Encoder::handle(int val) {
}

void Encoder::update(encoder_t *enc) {
  cur = cur + enc->normal + 5 * enc->button;
}

void RangeEncoder::update(encoder_t *enc) {
  int inc = enc->normal + 5 * enc->button;
  
  cur = limit_value(cur, inc, min, max);
}

void CCEncoder::handle(int val) {
  MidiUart.sendCC(channel, cc, val);
}

void TempoEncoder::handle(int val) {
  MidiClock.setTempo(val);
}


CharEncoder::CharEncoder()  : RangeEncoder(0, 37) {
}

char CharEncoder::getChar() {
  uint8_t val = getValue();
  if (val == 0) {
    return ' ';
  }
  if (val < 27) 
    return val - 1+ 'A';
  else
    return (val - 27) + '0';
}

void CharEncoder::setChar(char c) {
  if (c >= 'A' && c <= 'Z') {
    setValue(c - 'A' + 1);
  } else if (c >= '0' && c <= '9') {
    setValue(c - '0' + 26 + 1);
  } else {
    setValue(0);
  }
}