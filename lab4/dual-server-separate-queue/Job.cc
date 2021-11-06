#ifndef JOB_H
#define JOB_H

#include "Auto_enabled_id.cc"

class Job : public Auto_enabled_id<Job> {
public:
  // exposing protected member as public.
  using Auto_enabled_id<Job>::get_id;
  
  Job(int arrival_time,int service_duration) : arrival_time(arrival_time), service_duration(service_duration)
  {
      
  }
  
  auto get_waiting_time() {return service_beginning_time-arrival_time;}
  
  
  int service_duration;
  
  int arrival_time;
  int service_beginning_time;
};

#endif // JOB_H
