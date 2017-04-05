/*
  Utilisation :
  -
*/

void noteOn(int channel, int pitch, int velocity = 64) {
  Serial.write(0x90 + channel); // status byte
  Serial.write(pitch); // data byte
  Serial.write(velocity); // data byte
}

void noteOff(int channel, int pitch) {
  noteOn(channel, pitch, 0);
}

void MIDI_ControlChange(int channel, int number, int value) {
  Serial.write(0xB0 + channel); // status byte
  Serial.write(number); // data byte
  Serial.write(value); // data byte
}

void MIDI_Bank_Select_MSB(int channel, int value) {
  MIDI_ControlChange(channel, 0x00, value);
}

void MIDI_Bank_Select_LSB(int channel, int value) {
  MIDI_ControlChange(channel, 0x20, value);
}

void MIDI_ProgramChange(int channel, int number) {
  Serial.write(0xC0 + channel); // status byte
  Serial.write(number); // data byte
}

void MIDI_ChannelVolume(int channel, int value) {
  MIDI_ControlChange(channel, 0x07, value);
}
void MIDI_Balance(int channel, int value)       {
  MIDI_ControlChange(channel, 0x08, value);  // 0 = hard left, 64 = center, 127 = hard right
}
void MIDI_Pan(int channel, int value)           {
  MIDI_ControlChange(channel, 0x0A, value);  // 0 = hard left, 64 = center, 127 = hard right
}
void MIDI_AllNotesOff(int channel)              {
  MIDI_ControlChange(channel, 0x7B, 0);
}

