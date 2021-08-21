#if not defined(EVENT_GUARD)
#define EVENT_GUARD

#pragma once
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Enumerations.cc"
#include "Job_service_complex.hpp"

class Event : private Singleton::Enumerations //I am inheriting the Enumerations class in order to avoid writing long prefixes like Singleton::Enumerations::Event_kind
{
    /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Name: Event
   ۞ Type: Non-static non-Singleton
   ۞ Author: 215
   ۞ Mechanism: Stores the time when an event will be triggered and also contains a handler function which will call appropriate function of the job processing system to deal with the event.
   */

private:
    int trigger_time = 0;
    Event_kind event_type; //arrival or departure or termination
    int target_entity_number = 0;

    Event(Event_kind chosen_event, int chosen_trigger_time)
        : event_type(chosen_event)
    {
        //parameter check
        if (chosen_trigger_time > 0)
            trigger_time = chosen_trigger_time;
        //else throw exception
    }

public:
    Event(Event_kind chosen_event, int chosen_trigger_time, int chosen_target_entity_number)
        : Event(chosen_event, chosen_trigger_time)
    {
        if (chosen_target_entity_number >= 0)
            target_entity_number = chosen_target_entity_number;
    }
    void handle()
    {
        using Current_System = Singleton::Job_service_complex; // this alias can be changed to another system with equivalent interface of needed later on
        switch (event_type) {
        case Event_kind::arrival:
            Current_System::arrival(target_entity_number);
            break;
        case Event_kind::departure:
            Current_System::departure(target_entity_number);
            break;
        case Event_kind::termination:
            Current_System::termination();
            break; //break is not necessary here, but just in case I add new cases later and maybe forget to write break statement at that time  in this line here
        } //end of event switch

    } //end of handle()
    auto inline get_trigger_time() const
    {
        return trigger_time;
    }
    auto inline get_event_type()
    {
        return event_type;
    }
    bool operator>(const Event compared_to) const //implemented to use std:: greater<Event> for priority list
    {
        return trigger_time > compared_to.trigger_time;
    }
}; //end of class
#endif //end of guard band
