#ifndef SERVER_GUARD
#define SERVER_GUARD


#include "Job.cc"
#include "Log.hpp"
#include "Timing_unit.cc"

class Server final {
private:
  bool current_status=0; // true for busy false for idle
  Log history;
  Job job_being_served_currently;


  auto release_job() { return job_being_served_currently; }

  void assign_job(Job new_job);
  
public:
  void set_job_being_served_currently(Job new_job) { assign_job(new_job); }

  auto get_job_being_served_currently() { return release_job(); }

  bool is_busy() {
    bool v = (current_status) ? true : false;
    return v;
  }

  bool is_idle() {
    bool v = (current_status) ? false : true;
    return v;
  }

  Log get_log() { return history; }

  void update_history_log() {
    auto current_time = Singleton::Timing_unit::get_current_time();
    history.add_datum(std::make_pair(current_time, current_status));
  }

  void activate() {
    current_status = true;
    update_history_log();
  }

  void deactivate() {
    current_status = false;
    update_history_log();
  }
  
  void departure();
  
};

#endif // SERVER_H
