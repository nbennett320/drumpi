#include "Step.h"

Step::Step(int _step):
step_count(_step)
{};

Step::~Step()
{};

void Step::addSample(std::string file) 
{
  this->samples.push_back(file);
};

u8 Step::getStepCount()
{
  return this->step_count;
};

std::vector<std::string> Step::getSampleFiles()
{
  return this->samples;
};

void Step::removeSample(std::string file)
{
  for(u32 i = 0; i < this->samples.size(); i++)
  {
    if(samples.at(i) == file)
    {
      samples.at(i).erase(i);
    }
  }
};

void Step::clearSamples()
{
  this->samples.clear();
};

