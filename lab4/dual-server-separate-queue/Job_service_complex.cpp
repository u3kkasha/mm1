//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_GUARD)
#define JSCX_GUARD

#include "Job_service_complex.hpp"
#include "Event_list.cc"
#include "Event_scheduler.hpp"
#include "SSQS.hpp"

namespace Singleton {

SSQS &Job_service_complex::get_ssqs_with_shortest_queue() {
  if (first.get_queue_length() <
      second.get_queue_length())
    return first;
  else
    return second;
}

void Job_service_complex::arrival() {
  get_ssqs_with_shortest_queue().arrival();
  Event_scheduler::schedule_next_arrival();
}

void Job_service_complex::termination() { Event_list::clear_all_events(); }

} // namespace Singleton

#endif // end of file