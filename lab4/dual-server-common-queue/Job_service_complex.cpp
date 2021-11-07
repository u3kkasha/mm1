//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_GUARD)
#define JSCX_GUARD

#include "Random_variate_generator.cc"
#include "Timing_unit.cc"
#include "Job_service_complex.hpp"
#include "Event_list.cc"
#include "Event_scheduler.hpp"
#include <numeric>

namespace Singleton {

void Job_service_complex::arrival() {
  Job just_arrived_job=Job(Timing_unit::get_current_time(), Random_variate_generator::get_random_service_duration() );

  Event_scheduler::schedule_next_arrival();

      for(auto& server : servers) // assign job to sn idle server
      {
          if(server.is_idle())
          {
              server.set_job_being_served_currently(just_arrived_job);      
              return;
           }      
      }     
      //if all servers are busy
      queue.insert(just_arrived_job);
  

}

void Job_service_complex::termination() { Event_list::clear_all_events(); }

double Job_service_complex:: average_server_utilisation()
{
    return std:: accumulate (std::begin(servers), std::end(servers), 0.0F,
    [](double total,Server& server) {return total+server.get_log().average_load();})
    /servers.size();
}

} // namespace Singleton
#endif // end of file