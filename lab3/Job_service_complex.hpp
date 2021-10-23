//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_H)
#define JSCX_H
#include "SSQS.cc"
#include <vector>
namespace Singleton {
class Job_service_complex {
private:
    static inline std::vector<SSQS> job_processing_systems=std::vector<SSQS>(2);
    static bool is_terminal_job_processing_system(int system_number);

public:
    static void setup(int number_of_job_processing_systems);
    static void arrival(int target_system_number);
    static void departure(int target_system_number);
    static void termination();

}; //end of class

} //end of namespace

#endif