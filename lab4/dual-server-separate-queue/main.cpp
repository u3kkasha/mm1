//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Simulation_parameters.cc"
#include "Simulation.cc"
#include "Completed_jobs.cc"
#include "Job_service_complex.hpp"
#include "Timing_unit.cc"
#include "Random_variate_generator.cc"
#include <iostream>
#include "debug.h"
#include <string>
using namespace std;
using namespace Singleton;

template <typename AnyNumber>
AnyNumber avg(AnyNumber first, AnyNumber second)
{
    return (first+second)/2;
}

int main([[maybe_unused]]int number_of_command_line_arguments, char *command_line_arguments[]) {

    using parameters=Simulation_parameters;
    parameters::mean_inter_arrival_duration=60;
    parameters::mean_service_duration=55;
    parameters::termination_time=10000000;
    parameters::random_number_generator_seed=stoi(command_line_arguments[1]);
    
    Simulation::start();
    
    
    auto waiting_delay=Completed_jobs::average_waiting_duration();
    auto queue_length=
        Job_service_complex::get_ref_first().get_queue_log().average_load()
        +
        Job_service_complex::get_ref_second().get_queue_log().average_load();
                                
    
    auto server_utilisation=avg(
        Job_service_complex::get_ref_first().get_server_log().average_load(),
        Job_service_complex::get_ref_second().get_server_log().average_load()
                                 );
                                 
    auto number_of_people=queue_length+ server_utilisation;           
                                 
    //Job_service_complex::get_ref_first().get_queue_log().print();
    
    cout<<waiting_delay<<' '<<number_of_people<<' '<<server_utilisation<<endl;
    

}