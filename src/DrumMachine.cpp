#include "DrumMachine.h"

DrumMachine::DrumMachine() 
{
  this->running = 1;
  this->timer = 0;
  this->tempo = 110; 
   
  SDL_Init(SDL_INIT_AUDIO);
  SDL_AudioSpec wavSpec;

	SDL_LoadWAV("assets/66-hh-01-or.wav", &wavSpec, &this->buffer, &this->sound_length);
  deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
  
  
};

DrumMachine::~DrumMachine()
{
  SDL_FreeWAV(this->buffer);
  SDL_Quit();
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
  this->latency = std::abs(bps - ellapsed.count());
  this->beat_count = (timer % 4) + 1;

  int success = SDL_QueueAudio(this->deviceId, this->buffer, this->sound_length);
	SDL_PauseAudioDevice(this->deviceId, 0);

  return this->running;
};

double DrumMachine::getLatency()
{
  return this->latency;
};


