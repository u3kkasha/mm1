#if not defined(STATISTICS_GUARD)
#define STATISTICS_GUARD

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Job.cc"
#include <list>
#include <numeric>
namespace Singleton {
class Completed_jobs {
  /*
 بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
 ==Class Description==
 ۞ Type: Static Singleton
 ۞ Author: 215
 ۞ Mechanism: It is a log class which stores the competed jobs and other
 information regarding them. It has a list of competed jobs for report
 generation and further analysis.
 */

private:
  static inline std::list<Job> completed_jobs;

public:
  static void add(Job completed_job) {
    completed_jobs.push_back(completed_job);
  }
  
  static auto average_waiting_duration()
  {
      auto total_waiting_time= std::accumulate(completed_jobs.begin(),completed_jobs.end(),0,
      [](int total,Job& job){ return total+job.get_waiting_time();});
      
      return static_cast<double>(total_waiting_time)/get_number_of_completed_jobs();
  }
  
  static auto get_list_of_completed_jobs() { return completed_jobs; }
  static int get_number_of_completed_jobs() { return completed_jobs.size(); }
}; // end of class

} // namespace Singleton
#endif // end of guard band
