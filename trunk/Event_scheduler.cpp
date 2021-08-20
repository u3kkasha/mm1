#if not defined(EVENT_SCHEDULER_GUARD)
#define EVENT_SCHEDULER_GUARD
#pragma once

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Event_scheduler.hpp"
#include "Enumerations.cc"
#include "Event.cc"
#include "Event_list.cc"
#include "Random_variate_generator.cc"
#include "Simulation.cc"
#include "Simulation_settings.cc"
#include "Timing_unit.cc"

namespace Singleton {
void Event_scheduler::schedule_next_arrival(int target_entity_number)
{

    /*
            +Mechanism: adds a arrival event to the Event list with trigger time=current_time+exponential random variate with inter_arrival mean specified in simulation settings in sha Allah.
            
            */
    auto settings = Simulation::get_settings();
    auto mean_inter_arrival_time = settings.get_mean_inter_arrival_time(target_entity_number);
    int trigger_time = Timing_unit::get_current_time() + Random_variate_generator::get_exponential(mean_inter_arrival_time);
    Event_list::add_event(Event_kind::arrival, trigger_time, target_entity_number);
}
void Event_scheduler::schedule_next_departure(int target_entity_number)
{
    auto settings =
        /*
            +Mechanism: adds a departure event to the Event list with trigger time=current_time+exponential random variate with service mean specified in simulation settings in sha Allah.
            
            */
        Simulation::get_settings();
    auto mean_service_time = settings.get_mean_service_time(target_entity_number);
    int trigger_time = Timing_unit::get_current_time() + Random_variate_generator::get_exponential(mean_service_time);
    Event_list::add_event(Event_kind::departure, trigger_time, target_entity_number);
}
void Event_scheduler::schedule_termination()
{

    /*
            +Mechanism: adds a termination event to the Event list with trigger time=termination time specified in simulation settings in sha Allah.
            
            */
    auto settings = Simulation::get_settings();
    int trigger_time = settings.get_termination_time();
    Event_list::add_event(Event_kind::termination, trigger_time);
}

} //end of namespace
#endif //end of guard band
