//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Job_processing_system.hpp"
#include "Event_list.cc"
#include "Event_scheduler.hpp"
#include "Job.cc"
#include "Statistics.cc"
#include "Timing_unit.cc"

namespace Singleton {

/*
    +Mechanism: These functions are implemented according to the flowcharts given in blueprint.
    */

void Job_processing_system::arrival()
{
    Event_scheduler::schedule_next_arrival();
    Job just_arrived_job;
    just_arrived_job.set_arrival_time(Timing_unit::get_current_time());

    if (servers[0].is_busy()) {

        //insert job to the queue
        waiting_lines[0].insert(just_arrived_job);

        //if waiting line queue is full then exception will be thrown in sha Allah
        //store arrival time of this job is already done

    } else //server is idle
    {
        just_arrived_job.set_service_beginning_time(Timing_unit::get_current_time()); //delay/waiting time is now 0
        servers[0].set_job_being_served_currently(just_arrived_job);
        //increment number of customers delayed
        Statistics::increment_number_of_jobs_delayed();
        // make server busy
        servers[0].activate();
        Event_scheduler::schedule_next_departure();
    }

} //end of arrival()
void Job_processing_system::departure()
{
    //put completed job which will depart in Statistics:: completed_jobs
    auto departing_job = servers[0].get_job_being_served_currently();
    departing_job.set_departure_time(Timing_unit::get_current_time());
    Statistics::add_completed_job(departing_job);

    if (waiting_lines[0].is_empty()) {
        servers[0].deactivate();
        Event_list::clear_all_events(Enumerations::Event_kind ::departure);
    } else {
        //remove next job from queue
        auto job_to_be_served_next = waiting_lines[0].remove();
        job_to_be_served_next.set_service_beginning_time(Timing_unit::get_current_time());
        //assign to server
        servers[0].set_job_being_served_currently(job_to_be_served_next);
        Statistics::increment_number_of_jobs_delayed();
        Event_scheduler::schedule_next_departure();
    }
}
void Job_processing_system::termination()
{

    Event_list::clear_all_events();
    //now Simulation ::run function will exit while loop and be finished in sha allah
}

} //end of namespace