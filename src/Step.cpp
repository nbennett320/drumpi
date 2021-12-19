#include "Step.h"

Step::Step(int _step):
step(_step)
{};

Step::~Step(int _step)
{};

void Step::addSample(std::string file) 
{
  this->samples.push_back(file);
};

u8 Step::getStep()
{
  return this->step;
};

void Step::removeSample(std::string file);
{
  for(u32 i = 0; i < this->samples.length; i++)
  {
    if(samples.at(file) == file)
    {
      sample.erase(i);
    }
  }
};

void clearSamples()
{
  this->samples.clear();
};

