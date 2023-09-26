#if not defined (ENUMERATIONS_GUARD)
#define ENUMERATIONS_GUARD

#pragma once
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

namespace Singleton
{
   /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Name: Enumerations
   ۞ Type: Static Singleton
   ۞ Author: 215
   ۞ Mechanism: Enum classses
   ۞ Usage Example: 
   auto event_type=Singleton:: Enumerations::Event_kind:: arrival;
   Client classes using these enumerations can also privately inherit enumerations class in order to avoid writing long prefixes. e.g. class Report_generator: private Enumerations
    
   */
    class Enumerations
    {
        public:
        enum class Event_kind
        {
            arrival,
            departure,
            termination
        };
        enum class Information_kind
        {
            service_time,
            waiting_time,
            sojourn_time
        };
        enum class Average_kind
        {
            job,
            time
        };
    }; //end of class

} //end of namespace
#endif //end of guard band
