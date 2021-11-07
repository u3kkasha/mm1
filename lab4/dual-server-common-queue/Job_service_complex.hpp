//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#if not defined(JSCX_H)
#define JSCX_H
#include "Server.hpp"
#include "Queue.cc"
#include <vector>

namespace Singleton {
class Job_service_complex {
public:
  static inline std::vector<Server> servers=std::vector<Server>(2);
  static inline Queue queue;
  static void arrival();
  static void termination();
  static double average_server_utilisation();
}; // end of class

} // namespace Singleton

#endif