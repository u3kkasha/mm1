#ifndef JOB_H
#define JOB_H

#include "Auto_enabled_id.cc"


class Job : public Auto_enabled_id
{
    public:
        //exposing protected member as public.
        using Auto_enabled_id::get_id;
        int get_arrival_time() { return arrival_time; }
        void set_arrival_time(int val) { arrival_time = val; }
        int get_service_beginning_time() { return service_beginning_time; }
        void set_service_beginning_time(int val) { service_beginning_time = val; }
        int get_departure_time() { return departure_time; }
        void set_departure_time(int val) { departure_time = val; }
        int get_waiting_time(){return service_beginning_time-arrival_time;}
        int get_service_time(){return departure_time-service_beginning_time;}
        int get_sojourn_time(){return get_waiting_time()+get_service_time();}

    protected:

    private:
        int arrival_time;
        int service_beginning_time;
        int departure_time;
};

#endif // JOB_H
