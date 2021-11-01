#if not defined(EVENT_SCHEDULER_H_GUARD)
#define EVENT_SCHEDULER_H_GUARD
#pragma once

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

namespace Singleton {
class Event_scheduler {
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
} // namespace Singleton

#endif