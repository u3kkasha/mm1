//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_GUARD)
#define JSCX_GUARD

#include "Job_service_complex.hpp"
#include "Event_list.cc"
#include "Event_scheduler.hpp"
#include "SSQS.cc"
#include "Statistics.cc"
#include <vector>
namespace Singleton {

bool Job_service_complex::is_terminal_job_processing_system(int system_number) {
  // checks if system_number is the last index, because index starts from 0 we
  // need to subtract one from size()
  return (job_processing_systems.size() - 1 == system_number);
}
void Job_service_complex::setup(int number_of_job_processing_systems) {
  job_processing_systems.resize(number_of_job_processing_systems);
}
void Job_service_complex::arrival(int target_system_number) {
  Job unprocessed_job;
  job_processing_systems.at(0).arrival(unprocessed_job);
  Event_scheduler::schedule_next_arrival(0);
}
void Job_service_complex::departure(int target_system_number) {
  auto processed_job = job_processing_systems[target_system_number].departure();
  if (is_terminal_job_processing_system(target_system_number))
    Statistics::add_completed_job(processed_job);
  else {
    int next_system = target_system_number + 1;
    job_processing_systems.at(next_system).arrival(processed_job);
  }
}

void Job_service_complex::termination() { Event_list::clear_all_events(); }

} // namespace Singleton

#endif // end of file