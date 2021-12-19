#pragma once

#include "Step.h"
#include <string>
#include <vector>
#include <iostream>

class StepSequencer
{
  public:

  StepSequencer(u8 beats);

  ~StepSequencer(void);

  void setStep(std::string sample, u8 step_count);

  Step getStep(u8 index);

  private:

  std::vector<StepSequencer> subsequencers;

  std::vector<Step*> steps;

};

