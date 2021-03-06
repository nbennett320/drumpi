#include "DrumMachine.h"

DrumMachine::DrumMachine() 
{
  this->tempo = 110;
  this->running = 1;
  this->timer = 0;
  this->time_signature_ratio = 6;
  this->time_signature = std::tuple<u8, u8>(8, 4);
  u8 numerator = std::get<0>(this->time_signature);
  std::cout << "num: " << (int)numerator << std::endl;

  this->step_sequencer = new StepSequencer(numerator);
   
  SDL_Init(SDL_INIT_AUDIO);

  deviceId = SDL_OpenAudioDevice(NULL, 0, &this->spec, NULL, 0);
  
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
  this->beat_count = (timer % this->time_signature_ratio) + 1; 
  std::cout << "running. t: " << timer << ", ms/beat: " << bps
<< ", ellapsed time(ms): " << ellapsed.count() << ", beat_count: " << beat_count << std::endl;
  this->latency = std::abs(bps - ellapsed.count());
  
  Step step = this->step_sequencer->getStep(this->beat_count-1);
  auto files = step.getSampleFiles();
  for(u8 i = 0; i < files.size(); i++)
  {
    std::string file = files[i];
    SDL_LoadWAV(file.c_str(), &this->spec, &this->buffer, &this->sound_length);

  };


  int success = SDL_QueueAudio(this->deviceId, this->buffer, this->sound_length);
	SDL_PauseAudioDevice(this->deviceId, 0);
  // SDL_FreeWAV(this->buffer);

  return this->running;
};

double DrumMachine::getLatency()
{
  return this->latency;
};

void DrumMachine::setTempo(int bpm)
{
  this->tempo = bpm;
};

int DrumMachine::getTempo()
{
  return this->tempo;
};

void DrumMachine::addSampleToStep(std::string file, u8 step)
{
  this->step_sequencer->setStep(file, step);
  // this->step_samples.push_back(std::tuple(file, step));
};
