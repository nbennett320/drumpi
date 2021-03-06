#include "DrumMachine.h"
#include <iostream>

int main(int argc, char **argv) {
  auto dm = new DrumMachine();
  dm->addSampleToStep("assets/66-bd-01.wav", 0);
  dm->addSampleToStep("assets/66-hh-01-or.wav", 1);
  dm->addSampleToStep("assets/66-hh-01-or.wav", 2);
  dm->addSampleToStep("assets/66-sd-01.wav", 3);
  dm->addSampleToStep("assets/66-hh-01-or.wav", 4);
  dm->addSampleToStep("assets/66-hh-01-or.wav", 5);
  dm->addSampleToStep("assets/66-sd-01.wav", 6);
  dm->setTempo(160);

  // dm->addSampleToStep("assets/66-sd-01.wav", 0);

  while(dm->run()) 
  {
    std::cout << "machine running @ " << dm->getTempo() << " with " << dm->getLatency() << "ms latentcy" << std::endl;
  }

  return 0;
}

