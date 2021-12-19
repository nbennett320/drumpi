#pragma once

#include "StepSequencer.h"
#include "common.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <tuple>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

class DrumMachine 
{
  public:

  DrumMachine(void);
  
  ~DrumMachine(void);

  bool run(void);

  double getLatency(void);

  void setTempo(int bpm);

  int getTempo(void);

  void addSampleToStep(std::string file, u8 step);

  bool loadSample(std::string file);
  
  private:
  
  StepSequencer *step_sequencer;
  
  bool running;
  
  int timer = 0;

  int tempo;
  
  u8 beat_count;

  std::tuple<u8, u8> time_signature;

  u8 max_beat_index;

  bool loop_mode;

  double latency;

  SDL_AudioDeviceID deviceId;
  SDL_AudioSpec spec;

  u32 sound_length;
  u8* buffer;

  // u8 ptr and respective len
  std::vector<std::tuple<std::string, int>> step_samples;
  


};


