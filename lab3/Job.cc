#ifndef JOB_H
#define JOB_H

#include "Auto_enabled_id.cc"
#include "Joblet.cc"
#include <numeric>
#include <vector>
class Job : public Auto_enabled_id<Job> {
public:
  // exposing protected member as public.
  using Auto_enabled_id<Job>::get_id;
  int get_arrival_time(int index) {
    return subjobs.at(index).get_arrival_time();
  }
  void set_arrival_time(int index, int val) {
    subjobs.at(index).set_arrival_time(val);
  }
  int get_service_beginning_time(int index) {
    return subjobs.at(index).get_service_beginning_time();
  }
  void set_service_beginning_time(int index, int val) {
    subjobs.at(index).set_service_beginning_time(val);
  }
  int get_departure_time(int index) {
    return subjobs.at(index).get_departure_time();
  }
  void set_departure_time(int index, int val) {
    subjobs.at(index).set_departure_time(val);
  }
  int get_waiting_time(int index) {
    return subjobs.at(index).get_service_beginning_time() -
           subjobs.at(index).get_arrival_time();
  }
  int get_service_time(int index) {
    return subjobs.at(index).get_departure_time() -
           subjobs.at(index).get_service_beginning_time();
  }
  int get_sojourn_time(int index) {
    return get_waiting_time(index) + get_service_time(index);
  }
  int get_waiting_time() {
    return std::accumulate(
        std::begin(subjobs), std::end(subjobs), 0,
        [](int sum, Joblet joblet) { return sum + joblet.get_waiting_time(); });
  }
  int get_service_time() {
    return std::accumulate(
        std::begin(subjobs), std::end(subjobs), 0,
        [](int sum, Joblet joblet) { return sum + joblet.get_service_time(); });
  }
  int get_sojourn_time() { return get_waiting_time() + get_service_time(); }

private:
  std::vector<Joblet> subjobs = std::vector<Joblet>(2);
};

#endif // JOB_H
