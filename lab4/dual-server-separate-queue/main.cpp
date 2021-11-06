//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Simulation_parameters.cc"
#include "Simulation.cc"

using namespace std;
using namespace Singleton;
int main()
{
    using parameters=Simulation_parameters;
    parameters::mean_inter_arrival_duration=60;
    parameters::mean_service_duration=30;
    parameters::termination_time=1000;
    parameters::random_number_generator_seed=67;
    
    Simulation::start();
}