#include "DrumMachine.h"

DrumMachine::DrumMachine() 
{
  this->running = 1;
  this->timer = 0;
  this->tempo = 110; 
   

};

bool DrumMachine::run() 
{
  using namespace std::chrono_literals;
  double bps_ = std::pow((tempo / 60.0), -1) * 1000; 
  int bps = (int) bps_;

  std::cout << "starting with a tempo of " << tempo << "bpm, bps_: " << bps_ << std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  auto beat_duration = std::chrono::milliseconds(bps);
  std::this_thread::sleep_for(beat_duration);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> ellapsed = end - start;
  timer += 1;
  int beat_count = (timer % 4) + 1; 
  std::cout << "running. t: " << timer << ", ms/beat: " << bps
<< ", ellapsed time(ms): " << ellapsed.count() << ", beat_count: " << beat_count << std::endl;
  this->latency = bps - ellapsed.count();
  this->beat_count = (timer % 4) + 1;
};

double getLatency()
{
  return this->latency;
};



