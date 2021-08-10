#if not defined (STATISTICS_GUARD)
#define STATISTICS_GUARD

#pragma once
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include <list>
#include "Job.cc"
namespace Singleton
{
    class Statistics
    {
           /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Type: Static Singleton
   ۞ Author: 215
   ۞ Mechanism: It is a log class which stores the competed jobs and other information regarding them. It has a list of competed jobs for report generation and further analysis.
   */
        
        private:
        static int inline number_of_waited_jobs = 0;
        static inline std::list < Job > completed_jobs;
        public:
        static void increment_number_of_jobs_delayed()
        {
            number_of_waited_jobs++;
        }
        static void add_completed_job(Job completed_job)
        {
            completed_jobs.emplace_back(completed_job);
        }
        static auto get_list_of_completed_jobs()
        {
            return completed_jobs;
        }
        static auto get_number_of_completed_jobs()
        {
            return completed_jobs.size();
        }
    };//end of class

} //end of namespace
#endif //end of guard band
