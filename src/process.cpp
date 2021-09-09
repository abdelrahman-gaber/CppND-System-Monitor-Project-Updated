#include "process.h"

Process::Process(int id) : pid_(id) { }

// Return this process's ID
int Process::Pid() { 
    return pid_; 
}

bool Process::IdleProcess(){
    std::string state = LinuxParser::State(pid_);
    return state=="I";
}

// Return this process's CPU utilization
float Process::CpuUtilization() {
    unsigned long int utime, stime, cutime, cstime;
    vector<std::string> cpu_fields = LinuxParser::CpuUtilization(pid_);
    utime = std::stol(cpu_fields[0]);
    stime = std::stol(cpu_fields[1]);
    cutime = std::stol(cpu_fields[2]);
    cstime = std::stol(cpu_fields[3]);

    unsigned long long int total_time_clk = utime + stime + cutime + cstime;
    unsigned long long int total_time = total_time_clk / sysconf(_SC_CLK_TCK);

    float percentage = total_time / UpTime();

    return percentage; }

// Return the command that generated this process
string Process::Command() { 
    return LinuxParser::Command(pid_);
}

// Return this process's memory utilization
string Process::Ram() { 
    std::string ram = LinuxParser::Ram(pid_);
    int ram_mb = std::stof(ram)*0.001;
    ram = std::to_string(ram_mb);
    return ram;
}

// Return the user (name) that generated this process
string Process::User() { 
    return LinuxParser::User(pid_);
}

// Return the age of this process (in seconds)
long int Process::UpTime() { 
    long system_uptime = LinuxParser::UpTime();
    long process_start_time = LinuxParser::UpTime(pid_)/sysconf(_SC_CLK_TCK);
    long time = system_uptime - process_start_time;
    return time; 
}

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process &a) {
    return std::stoi(Ram()) < std::stoi(a.Ram());
}