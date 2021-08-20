#ifndef JOB_H
#define JOB_H

#include "Auto_enabled_id.cc"
#include <vector>
class Job : public Auto_enabled_id {
public:
    //exposing protected parent method as public.
    using Auto_enabled_id::get_id;
    int get_arrival_time(int index) { return arrival_time[index]; }
    void set_arrival_time(int index, int val) { arrival_time[index] = val; }
    int get_service_beginning_time(int index) { return service_beginning_time[index]; }
    void set_service_beginning_time(int index, int val) { service_beginning_time[index] = val; }
    int get_departure_time(int index) { return departure_time[index]; }
    void set_departure_time(int index, int val) { departure_time[index] = val; }
    int get_waiting_time(int index) { return service_beginning_time[index] - arrival_time[index]; }
    int get_service_time(int index) { return departure_time[index] - service_beginning_time[index]; }
    int get_sojourn_time(int index) { return get_waiting_time(index) + get_service_time(index); }

private:
    std::vector<int> arrival_time;
    std::vector<int> service_beginning_time;
    std::vector<int> departure_time;
};

#endif // JOB_H
