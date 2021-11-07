#ifndef JOB_H
#define JOB_H

#include "Auto_enabled_id.cc"

class Job : public Auto_enabled_id<Job> {
public:
  // exposing protected member as public.
  using Auto_enabled_id<Job>::get_id;
  
  auto get_waiting_time() { return service_beginning_time - arrival_time; }
  Job(int arrival_time, int service_duration)
      : arrival_time(arrival_time), service_duration(service_duration) {}

  Job()=default;

  int arrival_time;
  int service_beginning_time;
  
  int service_duration;
};

#endif // JOB_H
