//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_H)
#define JSCX_H
#include "SSQS.hpp"

namespace Singleton {
class Job_service_complex {
private:
  static inline SSQS first;
  static inline SSQS second;
  static inline SSQS &get_ssqs_with_shortest_queue();

public:
  static SSQS &get_ref_first()    {return first;}
  static void arrival();
  static void termination();

}; // end of class

} // namespace Singleton

#endif