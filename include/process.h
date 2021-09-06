#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <unistd.h>
#include <cctype>
#include <sstream>
#include <vector>

#include "linux_parser.h"
#include "processor.h"

using std::string;
using std::to_string;
using std::vector;

/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int id);
  int Pid();                               
  std::string User();                      
  std::string Command();                   
  float CpuUtilization();                  
  std::string Ram();                       
  long int UpTime();                       
  bool IdleProcess();
  bool operator<(Process & a); 

  // Declare any necessary private members
 private:
    int pid_ = 0;
    unsigned long long int prev_proc_time = 0 ;
    unsigned long long int prev_proc_uptime = 0;
    Processor processor_; //GetTotalTime(){
};

#endif