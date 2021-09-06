#include "processor.h"

void Processor::UpdateProcessorData() {
    unsigned long long int user_time, nice_time, system_time, idle_time;
    unsigned long long int io_wait, irq, soft_irq, steal;

    // "cpu", user, nice, system, idle, iowait, irq, softirq, steal, guest, guestnice
    std::vector<std::string> cpu_fields = LinuxParser::CpuUtilization();

    user_time = std::stol(cpu_fields[1]);
    nice_time = std::stol(cpu_fields[2]);
    system_time = std::stol(cpu_fields[3]);
    idle_time = std::stol(cpu_fields[4]);
    io_wait = std::stol(cpu_fields[5]);
    irq = std::stol(cpu_fields[6]);
    soft_irq = std::stol(cpu_fields[7]);
    steal = std::stol(cpu_fields[8]);
    // Guest time is already accounted in usertime, so will not use it
 
    unsigned long long int idle_all_time = idle_time + io_wait;
    unsigned long long int system_all_time = system_time + irq + soft_irq;
    non_idle_all_time = user_time + nice_time + system_all_time + steal;
    total_time = non_idle_all_time + idle_all_time ;
}

// Return the CPU utilization
float Processor::Utilization() { 
    UpdateProcessorData();
    float non_idle_d = non_idle_all_time - prev_non_idle_all_time;
    float total_time_d = total_time - prev_total_time;
    float percentage = non_idle_d/total_time_d;
    prev_non_idle_all_time = non_idle_all_time;
    prev_total_time = total_time;

    return percentage; 
}

unsigned long long int Processor::GetTotalTime(){
    UpdateProcessorData();
    return total_time;
}