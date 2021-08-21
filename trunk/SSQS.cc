#if not defined(SSQS_GUARD)
#define SSQS_GUARD

#include "Auto_enabled_id.cc"
#include "Event_scheduler.hpp"
#include "Log.cc"
#include "Queue.cc"
#include "Server.cc"
class SSQS : public Auto_enabled_id {
private:
    Server server;
    Queue queue;

public:
    void arrival(Job just_arrived_job)
    {

        just_arrived_job.set_arrival_time(get_id(), Singleton::Timing_unit::get_current_time());

        if (server.is_busy()) {

            //insert job to the queue
            queue.insert(just_arrived_job);

        } else //server is idle
        {
            just_arrived_job.set_service_beginning_time(get_id(), Singleton::Timing_unit::get_current_time()); //delay/waiting time is now 0
            server.set_job_being_served_currently(just_arrived_job);
            // make server busy
            server.activate();
            Singleton::Event_scheduler::schedule_next_departure(get_id());
        }

    } //end of arrival()
    Job departure()
    {
        auto departing_job = server.get_job_being_served_currently();
        departing_job.set_departure_time(get_id(), Singleton::Timing_unit::get_current_time());

        if (queue.is_empty()) {
            server.deactivate();
        } else {
            //remove next job from queue
            auto job_to_be_served_next = queue.remove();
            job_to_be_served_next.set_service_beginning_time(get_id(), Singleton::Timing_unit::get_current_time());
            //assign to server
            server.set_job_being_served_currently(job_to_be_served_next);
            Singleton::Event_scheduler::schedule_next_departure(get_id());
        }
        return departing_job;
    } //end of departure()
}; //end of class

#endif //end of file