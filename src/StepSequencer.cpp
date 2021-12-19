#include "StepSequencer.h"

StepSequencer::StepSequencer(u8 beats)
{
  std::cout << "constructed, beats: " << (int)beats << std::endl;
  for(u8 i; i < beats; i++)
  {
    Step *step = new Step(i);
    steps.push_back(step);
  }
};

StepSequencer::~StepSequencer()
{}

void StepSequencer::setStep(std::string sample, u8 step_count)
{
  std::cout << "step_count: " << (int)step_count << ", sample: " << sample << std::endl; 
  this->steps.at(step_count)->addSample(sample);
};

Step StepSequencer::getStep(u8 index)
{
  return *this->steps.at(index);
};

