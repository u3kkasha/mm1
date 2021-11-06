//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined (SSQS_H)
#define SSQS_H

#include "Event_scheduler.hpp"
#include "Log.hpp"
#include "Completed_jobs.cc"
#include "Random_variate_generator.cc"

void SSQS::arrival()
{
    
    if (auto just_arrived_job =Job(Singleton::Timing_unit::get_current_time(),
            Singleton::Random_variate_generator::get_random_service_duration())
    ;server.is_busy()) {
      // insert job to the queue
      queue.insert(just_arrived_job);
    } else // server is idle
    {
      just_arrived_job.service_beginning_time =
          Singleton::Timing_unit::get_current_time();
      server.set_job_being_served_currently(just_arrived_job);
      // make server busy
      server.activate();
      Singleton::Event_scheduler::schedule_next_departure(
          *this, just_arrived_job.service_duration);
    }
}
void SSQS::departure()
{
    auto departing_job = server.get_job_being_served_currently();
    if (queue.is_empty()) {
      server.deactivate();
    } else {
      // remove next job from queue
      auto job_to_be_served_next = queue.remove();
      job_to_be_served_next.service_beginning_time=Singleton::Timing_unit::get_current_time();
      // assign to server
      server.set_job_being_served_currently(job_to_be_served_next);
      Singleton::Event_scheduler::schedule_next_departure(
          *this, job_to_be_served_next.service_duration);
     Singleton::Completed_jobs::add(departing_job);   }

  } // end of departure()








#endif