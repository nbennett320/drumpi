#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

class DrumMachine 
{
  public:

  DrumMachine(void);

  bool run(void);

  double getLatency(void);

  private:

  bool running;
  
  int timer = 0;

  int tempo = 110;

  int beat_count;

  bool loop_mode;

  double latency;
};


