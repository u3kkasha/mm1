#ifndef SERVER_H
#define SERVER_H

#include "Job.cc"
#include "Log.hpp"
#include "Timing_unit.cc"
#include <optional>

class Server final
{
private:
  bool current_status; // true for busy false for idle
  Log history;
  std::optional<Job> job_being_served_currently;

public:
  auto extract_serviced_job() 
  { 
    return std::move(job_being_served_curently).value(); 
  }
  
  void assign_job(Job new_job) 
  {
    job_being_served_currently = new_job;
  }

  bool is_busy()
  {
    bool v = (current_status) ? true : false;
    return v;
  }

  bool is_idle()
  {
    bool v = (current_status) ? false : true;
    return v;
  }

  Log get_log() 
  { 
      return history;
  }

  void update_history_log()
  {
    auto current_time = Singleton::Timing_unit::get_current_time();
    history.add_datum(std::make_pair(current_time, current_status));
  }

  void activate()
  {
    current_status = true;
    update_history_log();
  }

  void deactivate()
  {
    current_status = false;
    update_history_log();
  }

};

#endif // SERVER_H
