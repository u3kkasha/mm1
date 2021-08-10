#if not defined (TIMING_UNIT_GUARD)
#define TIMING_UNIT_GUARD

#pragma once
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

namespace Singleton
{
    class Timing_unit
    {
           /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Type: Static Singleton
   ۞ Author: 215
   ۞ Mechanism: It I a wrapper class for an integer representing the simulation_clock.
   */

        
        private:
        static inline int simulation_clock = 0;

        public:
        static int get_current_time()
        {
            return simulation_clock;
        }
        static void reset_clock()
        {
            simulation_clock=0;
        }
        static void update_clock(int new_time_value)
        {
            simulation_clock=new_time_value;
        }


    };//end of class

}//end of namespace
#endif //end of guard band
