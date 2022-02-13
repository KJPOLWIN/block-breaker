#ifndef RANDOM_H
#define RANDOM_H

  #include <random>
  #include <ctime>

  namespace Random
  {
    double getRandomDouble(double min, double max);
    int getRandomInt(int min, int max);

    bool drawStraws(int numberOfStraws);
  }

#endif
