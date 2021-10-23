//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "debug.h"
#include <iostream>
#include "Simulation.cc"
#include "Statistics.cc"
#include "Timing_unit.cc"
using namespace std;
using namespace Singleton;
void print_all_jobs(std::list<Job> job_list)
{
      for(auto job: job_list)
   {
      printf("SSQS-0:Job-%4d \tWaiting-time=%5d \tService_time=%5d \tSojourn_time=%5d\n",job.get_id(),job.get_waiting_time(0),job.get_service_time(0),job.get_sojourn_time(0));      
      printf("SSQS:1 Job-%4d \tWaiting-time=%5d \tService_time=%5d \tSojourn_time=%5d\n",job.get_id(),job.get_waiting_time(1),job.get_service_time(1),job.get_sojourn_time(1));      
    }
}
int main()
{
   Simulation_settings settings=Simulation::get_settings();
    settings. set_number_of_servers(2);
    settings. set_number_of_queues(2);
    settings. set_mean_inter_arrival_time(0,60);
    settings. set_mean_service_time(0,30);
    settings. set_mean_service_time(1,30);
    settings. set_termination_time(1000);
    Simulation::set_settings(settings);
    
    Simulation:: start();

    
    print_all_jobs(Statistics:: get_list_of_completed_jobs());
    
}