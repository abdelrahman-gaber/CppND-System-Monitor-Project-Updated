#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "linux_parser.h"

class Processor {
 public:
  void UpdateProcessorData();
  float Utilization();
  unsigned long long int GetTotalTime();

  
 private:
    unsigned long long int non_idle_all_time = 0;
    unsigned long long int total_time = 0;
    unsigned long long int prev_non_idle_all_time = 0;
    unsigned long long int prev_total_time = 0;
};

#endif