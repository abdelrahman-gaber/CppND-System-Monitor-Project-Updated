#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstddef>
#include <set>

#include "process.h"
#include "processor.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

class System {
 public:
  Processor& Cpu();                   
  std::vector<Process>& Processes();  
  float MemoryUtilization();    
  long UpTime();                      
  int TotalProcesses();               
  int RunningProcesses();             
  std::string Kernel();               
  std::string OperatingSystem();      

  // Define any necessary private members
 private:
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
};

#endif