#include "random.h"
#include <random>
#include <ctime>

namespace Random
{
  std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  double getRandomDouble(double min, double max)
  {
    std::uniform_real_distribution dist{ min, max };
    return dist(mersenne);
  }

  int getRandomInt(int min, int max)
  {
    std::uniform_int_distribution dist{ min, max };
    return dist(mersenne);
  }

  bool drawStraws(int numberOfStraws)
  {
    return getRandomInt(1, numberOfStraws) == 1;
  }
}
