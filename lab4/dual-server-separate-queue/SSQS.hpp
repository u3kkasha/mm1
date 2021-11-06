#if not defined(SSQS_GUARD)
#define SSQS_GUARD

#include "Auto_enabled_id.cc"
#include "Queue.cc"

#include "Server.cc"

class SSQS : public Auto_enabled_id<SSQS> {
private:
  Server server;
  Queue queue;

public:
  auto get_queue_length() { return queue.get_length(); }
  auto get_server_log() { return server.get_log(); }
  auto get_queue_log() { return queue.get_log(); }
  void arrival();
  void departure();
  
};  // end of class

#endif // end of file