#if not defined(EVENT_GUARD)
#define EVENT_GUARD

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Job_service_complex.hpp"
#include "Server.hpp"
#include <stdexcept>

class Event {
  /*
 بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
 ==Class Description==
 ۞ Name: Event
 ۞ Type: Non-static non-Singleton
 ۞ Author: 215
 ۞ Mechanism: Stores the time when an event will be triggered and also contains
 a handler function which will call appropriate function of the job processing
 system to deal with the event.
 */

public:
  enum class Event_kind { arrival, departure, termination };

  explicit Event(Event::Event_kind chosen_event, int chosen_trigger_time)
      : event_type(chosen_event) {
    if (chosen_trigger_time > 0)
      trigger_time = chosen_trigger_time;
    else
      throw std::invalid_argument("Received a negative trigger_time");
  }

  explicit Event(Event::Event_kind chosen_event, int chosen_trigger_time,
                 Server& chosen_target_entity)
      :Event(chosen_event, chosen_trigger_time) {
          target_entity=chosen_target_entity;
      }

  void handle() {
    using Current_System =
        Singleton::Job_service_complex; // this alias can be changed to another
                                        // system with equivalent interface of
                                        // needed later on
    switch (event_type) {
    case Event::Event_kind::arrival:
      Current_System::arrival();
      break;
    case Event::Event_kind::departure:
      target_entity.get().departure();
      break;
    case Event::Event_kind::termination:
      Current_System::termination();
      break; // break is not necessary here, but just in case I add new cases
             // later and maybe forget to write break statement at that time  in
             // this line here
    }        // end of event switch

  } // end of handle()

  auto inline get_trigger_time() const { return trigger_time; }
  auto inline get_event_type() { return event_type; }
  bool operator>(const Event compared_to)
      const // implemented to use std:: greater<Event> for priority list
  {
    return trigger_time > compared_to.trigger_time;
  }

private:
  int trigger_time = 0;
  Event::Event_kind event_type; // arrival or departure or termination
  std::reference_wrapper<Server> target_entity=Singleton::Job_service_complex::servers[0];

};     // end of class
#endif // end of guard band
