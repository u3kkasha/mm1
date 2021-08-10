#if not defined (SIMULATION_GUARD)
#define SIMULATION_GUARD
#pragma once
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Simulation_settings.cc"
#include "Timing_unit.cc"
#include "Event.cc"
#include "Event_list.cc"
#include "Event_scheduler.hpp"


namespace Singleton
{
    class Simulation
    {
           /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Type: Static Singleton
   ۞ Author: 215
   ۞ Mechanism: It is a manipulation class which controls the simulation flow such as starting the simulation etc. Certain parameters of the simulation such as termination time, inputs for random variate generation etc are also stored as simulation settings.
   */
        
        private:
        inline static Simulation_settings settings;
        static void initialise() {
            Timing_unit::reset_clock();
            Event_list::clear_all_events();
        }
        static void run() {
            while(not Event_list::is_empty()) {
                auto current_event = Event_list::remove_event();
                Timing_unit:: update_clock(current_event.get_trigger_time());
                current_event.handle();
            }//end of while
        }
        public:
        static void set_settings(Simulation_settings new_settings) {
            settings = new_settings;
        }
        static Simulation_settings get_settings() {
            return settings;
        }
        static void start() {
            initialise();
            Event_scheduler:: schedule_next_arrival();
            Event_scheduler:: schedule_termination();

            run();
        }

    }; //end of class


}//end of namespace
#endif //end of guard band
