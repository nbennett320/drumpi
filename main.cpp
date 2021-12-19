#include "DrumMachine.h"
#include <iostream>

int main(int argc, char **argv) {
  auto dm = new DrumMachine();

  while(dm->run()) 
  {
    std::cout << "machine running @ " << dm->tempo << " with " << dm->getLatency() << "ms latentcy" << std::endl;
  }

  return 0;
}

