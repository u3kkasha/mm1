#if not defined(EVENT_LIST_GUARD)
#define EVENT_LIST_GUARD

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Event.cc"
#include <queue>
namespace Singleton {
class Event_list {

  /*
 بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
 ==Class Description==
 ۞ Name: Event list
 ۞ Type: Static Singleton
 ۞ Author: 215
 ۞ Mechanism: It is a wrapper class for a min priority queue of Events sorted
 according to trigger time.
 */

private:
  static inline std::priority_queue<Event, std::deque<Event>,
                                    std::greater<Event>>
      events; // need to use std:: greater<> to get min priority queue

public:
  static void add_event(Event::Event_kind event_type, int trigger_time,
                        int target_entity_number = 0) {
    events.emplace(event_type, trigger_time, target_entity_number);
  }
  static void add_event(Event::Event_kind event_type, int trigger_time) {
    events.emplace(event_type, trigger_time);
  }
  static Event remove_event() {
    auto removed_event = events.top();
    events.pop();
    return removed_event;
  }
  static void clear_all_events(Event::Event_kind deleted_events_type) {
    // place all events inside a vector and then put back all events except
    // events with event_type =deleted_events_type size of vector is same as
    // number of events
    std::vector<Event> all_events;

    while (not events.empty()) {
      all_events.push_back(events.top());
      events.pop();
    }

    for (auto event : all_events)
      if (event.get_event_type() != deleted_events_type)
        events.push(event);
  }
  static void clear_all_events() {
    while (not events.empty())
      events.pop();
  }
  static bool is_empty() { return events.empty(); }
}; // end of class
} // namespace Singleton
#endif // end of guard band
