#if not defined(REPORT_GENERATOR_GUARD)
#define REPORT_GENERATOR_GUARD

//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Statistics.cc"
#include "Timing_unit.cc"
#include <algorithm>
namespace Singleton {
class Report_generator {
  /*
 بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
 ==Class Description==
 ۞ Type: Static Singleton
 ۞ Author: 215
 ۞ Mechanism: This class is responsible for generating outputs like time average
 waiting times, job average service time etc.
 */
private:
  static inline int total_waiting_time = 0;
  static inline int total_service_time = 0;
  enum class Information_kind { service_time, waiting_time, sojourn_time };
  enum class Average_kind { job, time };

  static double compute_average(Average_kind chosen_average,
                                Information_kind chosen_information) {

    /*
        +Purpose: Compute averages like job averaged waiting time.
        +Mechanism: According to Little's formula the total summation can be
       used to generate job averages and time averages by dividing by total
       number of jobs for job averages and by dividing by total_simulation_time
       for time averages. For details visit the blueprint.
        */
    // remove temporal coupling
    if (total_service_time == 0 and total_waiting_time == 0)
      prepare_report();
    /* Note:
        if z=x÷y
       then x is the dividend
                    and y is the divisor
                    and z is the quotient
       */
    double divisor;
    double dividend;

    // fetch the correct divisor based on the type of average required i.e.
    // whether job average or time average
    switch (chosen_average) {
    case Average_kind::job:
      divisor = Statistics::get_number_of_completed_jobs();
      break;
    case Average_kind::time:
      divisor = Timing_unit::get_current_time();
      break;
    } // end of divisor switch

    // fetch the correct dividend based on the type of information requested
    // e.g. waiting time or sojourn time
    switch (chosen_information) {
    case Information_kind::waiting_time:
      dividend = total_waiting_time;
      break;
    case Information_kind::service_time:
      dividend = total_service_time;
      break;
    case Information_kind::sojourn_time:
      dividend = total_waiting_time + total_service_time;
      break;
    } // end of dividend switch

    return dividend / divisor;
  } // end of compute_average()
  static void prepare_report() {
    // zero total_service_time and total_waiting_time
    total_service_time = total_waiting_time = 0;
    // set values for total_service_time and total_waiting_time
    auto completed_jobs = Statistics::get_list_of_completed_jobs();
    for (auto job : completed_jobs) {
      total_waiting_time += job.get_waiting_time();
      total_service_time += job.get_service_time();
    }
  }

public:
  auto static calculate_server_utilisation() {
    return compute_average(Average_kind::time, Information_kind::service_time);
  }
  auto static calculate_average_number_of_people_inside_system() {
    return compute_average(Average_kind::time, Information_kind::sojourn_time);
  }
  auto static calculate_average_queue_length() {
    return compute_average(Average_kind::time, Information_kind::waiting_time);
  }
  auto static calculate_average_waiting_time() {
    return compute_average(Average_kind::job, Information_kind::waiting_time);
  }
  auto static calculate_average_service_time() {
    return compute_average(Average_kind::job, Information_kind::service_time);
  }
  auto static calculate_average_sojourn_time() {
    return compute_average(Average_kind::job, Information_kind::sojourn_time);
  }
}; // end of class
} // namespace Singleton
#endif // end of guard band