#if not defined(EVENT_SCHEDULER_GUARD)
#define EVENT_SCHEDULER_GUARD

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Event_scheduler.hpp"
#include "Event.cc"
#include "Event_list.cc"
#include "Random_variate_generator.cc"
#include "Simulation.cc"
#include "Simulation_parameters.cc"
#include "Timing_unit.cc"

namespace Singleton {
void Event_scheduler::schedule_next_arrival() {

  int trigger_time =
      Timing_unit::get_current_time() +
      Random_variate_generator::get_random_inter_arrival_duration();
  Event_list::add_event(Event::Event_kind::arrival, trigger_time);
}
void Event_scheduler::schedule_next_departure(Server& target_entity,
                                              int duration_till_trigger) {

  int trigger_time = Timing_unit::get_current_time() + duration_till_trigger;
  Event_list::add_event(Event::Event_kind::departure, trigger_time,
                        target_entity);
}
void Event_scheduler::schedule_termination() {

  int trigger_time = Simulation_parameters::termination_time;
  Event_list::add_event(Event::Event_kind::termination, trigger_time);
}

} // namespace Singleton
#endif // end of guard band
