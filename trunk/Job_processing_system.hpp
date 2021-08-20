#if not defined(JOB_PROCESSING_SYSTEM_GUARD)
#define JOB_PROCESSING_SYSTEM_GUARD

#pragma once
//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Log.cc"
#include "Queue.cc"
#include "Server.cc"
#include <vector>
namespace Singleton {
class Job_processing_system {
    /*
   بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
   ==Class Description==
   ۞ Name: Job processing system
   ۞ Type: Static Singleton
   ۞ Author: 215
   ۞ Mechanism: It has a vectors of servers and queues. And contains events handlers to manipulate them.
   */

private:
    inline static auto waiting_lines = std::vector<Queue>(1); //default is single Queue
    inline static auto servers = std::vector<Server>(1); // default is single Server
public:
    static void setup() = delete; //setup is deleted for now
    static void arrival();
    static void departure();
    static void termination();
    static Log get_server_log(int server_number) { return servers.at(server_number).get_log(); }
    static Log get_waiting_line_log(int queue_number) { return waiting_lines.at(queue_number).get_log(); }
};

} //end of namespace
#endif //end of guard band
