#include "include/DrumMachine.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <cmath>

int main(int argc, char **argv) {
  using namespace std::chrono_literals;
  bool running = 1;
  int timer = 0;
  int bpm = 110; 
  double bps_ = std::pow((bpm / 60.0), -1) * 1000; 
  int bps = (int) bps_;

  std::cout << "starting with a tempo of " << bpm << "bpm, bps_: " << bps_ << std::endl;
  while(running) {
    auto start = std::chrono::high_resolution_clock::now();
    auto beat_duration = std::chrono::milliseconds(bps);
    std::this_thread::sleep_for(beat_duration);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ellapsed = end - start;
    timer += 1;
    int beat_count = (timer % 4) + 1; 
    std::cout << "running. t: " << timer << ", ms/beat: " << bps
 << ", ellapsed time(ms): " << ellapsed.count() << ", beat_count: " << beat_count << std::endl;
  }

  return 0;
}

