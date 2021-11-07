//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined (SERVER_H)
#define SERVER_H

#include "Server.hpp"
#include "Job_service_complex.hpp"
#include "Completed_jobs.cc"
#include "Event_scheduler.hpp"

void Server:: departure()
{
      auto departing_job = get_job_being_served_currently();
         Singleton::Completed_jobs::add(departing_job);   
         
    if (Singleton::Job_service_complex::queue.is_empty()) {
      deactivate();
    } else {
      auto job_to_be_served_next = Singleton::Job_service_complex::queue.remove();
      set_job_being_served_currently(job_to_be_served_next);    
     }
  }

void Server::assign_job(Job new_job)
 { 
  new_job.service_beginning_time=Singleton::Timing_unit::get_current_time();
  job_being_served_currently = new_job; 
  Singleton::Event_scheduler::schedule_next_departure(
          *this, new_job.service_duration);
  }
  
#endif