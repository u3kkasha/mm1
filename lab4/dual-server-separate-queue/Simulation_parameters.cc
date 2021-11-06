#ifndef SIMULATION_SETTINGS_H
#define SIMULATION_SETTINGS_H

namespace Singleton{
class Simulation_parameters {

public:
  int static inline mean_inter_arrival_duration=0;
  int static inline mean_service_duration=0;
  int static inline termination_time=0;
  int static inline random_number_generator_seed=0;
};

}//end of namespace
#endif // SIMULATION_SETTINGS_H
