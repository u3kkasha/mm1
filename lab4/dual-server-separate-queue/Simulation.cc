#if not defined(SIMULATION_GUARD)
#define SIMULATION_GUARD
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Event.cc"
#include "Event_list.cc"
#include "Event_scheduler.hpp"
#include "Job_service_complex.hpp"
#include "Random_variate_generator.cc"
#include "Simulation_parameters.cc"
#include "Timing_unit.cc"
namespace Singleton {
class Simulation {
  /*
 بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
 ==Class Description==
 ۞ Type: Static Singleton
 ۞ Author: 215
 ۞ Mechanism: It is a manipulation class which controls the simulation flow such
 as starting the simulation etc. Certain parameters of the simulation such as
 termination time, inputs for random variate generation etc are also stored as
 simulation settings.
 */

private:
  static void initialise() {
    // Job_service_complex::setup(2);
    Timing_unit::reset_clock();
    Event_list::clear_all_events();
    Random_variate_generator::set_seed(
        Simulation_parameters::random_number_generator_seed);
  }
  static void run() {
    while (not Event_list::is_empty()) {
      auto current_event = Event_list::remove_event();
      Timing_unit::update_clock(current_event.get_trigger_time());
      current_event.handle();
    } // end of while
  }

public:
  static void start() {

    initialise();
    Event_scheduler::schedule_next_arrival();
    Event_scheduler::schedule_termination();

    run();
  }

}; // end of class

} // namespace Singleton
#endif // end of guard band
