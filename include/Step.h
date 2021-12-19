#pragma once

#include "common.h"
#include <vector>
#include <string>

class Step
{
  public:

  Step(int step);

  ~Step(void);

  u8 getStep(void);

  void addSample(std::string file);
  
  void removeSample(std::string file);

  void clearSamples(void);

  private:

  std::vector<std::string> samples;

  bool enabled;

  u8 step;

};

