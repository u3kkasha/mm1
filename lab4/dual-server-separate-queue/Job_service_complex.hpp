//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_H)
#define JSCX_H
#include "SSQS.hpp"
#include <utility>
namespace Singleton {
class Job_service_complex {
private:
  static inline std::pair<SSQS, SSQS> job_processing_systems;
  SSQS &get_ssqs_with_shortest_queue();

public:

  static void arrival();
  static void termination();

}; // end of class

} // namespace Singleton

#endif