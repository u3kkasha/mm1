#if not defined(STATISTICS_GUARD)
#define STATISTICS_GUARD

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Job.cc"
#include <list>
namespace Singleton {
class CompletedJobs {
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
  static auto get_list_of_completed_jobs() { return completed_jobs; }
  static auto get_number_of_completed_jobs() { return completed_jobs.size(); }
}; // end of class

} // namespace Singleton
#endif // end of guard band
