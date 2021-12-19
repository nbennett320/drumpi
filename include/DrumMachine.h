#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

class DrumMachine 
{
  public:

  DrumMachine(void);
  
  ~DrumMachine(void);

  bool run(void);

  double getLatency(void);

  int tempo = 110;
  
  private:

  bool running;
  
  int timer = 0;


  int beat_count;

  bool loop_mode;

  double latency;

  SDL_AudioDeviceID deviceId;

  Uint32 sound_length;

  Uint8 *buffer;
};


