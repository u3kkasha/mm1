//بسم الله الرحمن الرحيم


#include <iostream>
#include "Enumerations.cc"
#include "Report_generator.cc"
#include "Simulation.cc"
#include "Simulation_settings.cc"
#include "Job_processing_system.hpp"
#include "Log.cc"
#include <list>
using namespace Singleton;
using namespace std;

template <typename datatype>
void get_value_from_user(datatype& variable,std::string message)
{
std::cout<<message<<std::endl;
std::cin>>variable;

}


void setup_simulation()
{
//Setup Simulation
Simulation_settings current_settings;

int termination_time;
double mean_inter_arrival_time;
double mean_service_time;

get_value_from_user(termination_time,"How long do you want to run the simulation");
get_value_from_user(mean_inter_arrival_time,"How long is the time between arrival of two consecutive customers on average?");
get_value_from_user(mean_service_time,"How long is the service time on average?");


current_settings.set_termination_time(termination_time);
current_settings.set_mean_inter_arrival_time(mean_inter_arrival_time);
current_settings.set_mean_service_time(mean_service_time);
Simulation::set_settings(current_settings);
Simulation::start();




}

void show_output_variables()
{
using Singleton::Enumerations;
auto calculate=Singleton::Report_generator::compute_average;
Report_generator::prepare_report();

cout<<"Average delay per customer "<<calculate(Enumerations::Average_kind::job,Enumerations::Information_kind::waiting_time)<<endl;
cout<<"Average service time per customer "<<calculate(Enumerations::Average_kind::job,Enumerations::Information_kind::service_time)<<endl;
cout<<"Average system time per customer "<<calculate(Enumerations::Average_kind::job,Enumerations::Information_kind::sojourn_time)<<endl;
cout<<"Average queue length per time unit "<<calculate(Enumerations::Average_kind::time,Enumerations::Information_kind::waiting_time)<<endl;
cout<<"Average server utilisation "<<calculate(Enumerations::Average_kind::time,Enumerations::Information_kind::service_time)*100<<'%'<<endl;
cout<<"Average number of people inside system per time unit "<<calculate(Enumerations::Average_kind::time,Enumerations::Information_kind::sojourn_time)<<endl;


}
void print_log(Log log,std::string name)
{
     printf("\tTime\t\t%s\n",name.c_str());
      for(auto [time,data]: log.get_full_log() )
        printf("%10d\t\t%10d\n",time,data);

}

void print_all_jobs(list<Job> job_list)
{
      for(auto job: job_list)
      printf("Job-%4d \tWaiting-time=%5d \tService_time=%5d \tSojourn_time=%5d\n",job.get_id(),job.get_waiting_time(),job.get_service_time(),job.get_sojourn_time());      

}

void option_to_view_logs()
{
bool user_chose_to_view=false;
get_value_from_user(user_chose_to_view, "Do you want to see the server's log?-----Type 1 for 'yes' otherwise press 0");

if(user_chose_to_view)
{auto server_log=Job_processing_system::get_server_log(0);
print_log(server_log,"Server Status");
}

get_value_from_user(user_chose_to_view, "Ok, so do you want to see the queues's log?-----Type 1 for 'yes' else press 0");
if(user_chose_to_view)
{auto queue_log=Job_processing_system::get_waiting_line_log(0);
print_log(queue_log,"Queue Length");
}

get_value_from_user(user_chose_to_view, "In sha Allah this is the last one, do you want to see the details of each departed customer?-----Type 1 for 'yes' else press 0");
if(user_chose_to_view)
{auto job_log=Statistics::get_list_of_completed_jobs();
print_all_jobs(job_log);
}



} 


int main()
{
cout<<"Welcome to SSQS Simulation by ID-215 and ID-216\nPlease enter the following parameters to run the simulation in sha Allah\n";

setup_simulation();

show_output_variables();

option_to_view_logs();

cout<<"End of Program";
return 0;
}