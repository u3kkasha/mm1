#if not defined(EVENT_SCHEDULER_H_GUARD)
#define EVENT_SCHEDULER_H_GUARD
#pragma once

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Enumerations.cc"
namespace Singleton {
class Event_scheduler : private Enumerations //I am inheriting the Enumerations class in order to avoid writing prefixes like Enumerations::Event_kind

{
    /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Name: Event Scheduler
   ۞ Type: Static Singleton
   ۞ Author: 215
   ۞ Mechanism: Schedules next event by adding new event into Event list.
   */

public:
    static void schedule_next_arrival(int target_entity_number);
    static void schedule_next_departure(int target_entity_number);
    static void schedule_termination();
};
}

#endif