#include "system.h"

// Return the system's CPU
Processor& System::Cpu() { 
    return cpu_; 
}

// Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    std::vector<int> pids_vec = LinuxParser::Pids();
    //processes_.clear();
    for(int id : pids_vec){
        // check if this process already exists
        auto it = std::find_if(processes_.begin(), processes_.end(), [&id](Process& obj) {return obj.Pid() == id;});
        if (it == processes_.end()){ // did not find matching element
          Process proc(id);
          if (!proc.IdleProcess()){
            processes_.emplace_back(proc);
          } 
        }
    }
    std::sort(processes_.begin(), processes_.end());
    std::reverse(processes_.begin(), processes_.end());
    return processes_; }

// Return the system's kernel identifier (string)
std::string System::Kernel() { 
    return LinuxParser::Kernel(); }

// Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization(); }

// Return the operating system name
std::string System::OperatingSystem() { 
    return LinuxParser::OperatingSystem(); }

// Return the number of processes actively running on the system
int System::RunningProcesses() { 
    return LinuxParser::RunningProcesses(); }

// Return the total number of processes on the system
int System::TotalProcesses() { 
    return LinuxParser::TotalProcesses(); }

// Return the number of seconds since the system started running
long System::UpTime() { 
    return LinuxParser::UpTime();
}
