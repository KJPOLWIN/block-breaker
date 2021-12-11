#ifndef RANDOM_H
#define RANDOM_H

  #include <random>
  #include <ctime>

  namespace Random
  {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    double getRandom(double min, double max)
    {
      std::uniform_real_distribution dist{ min, max };
      return dist(mersenne);
    }
  }

#endif
