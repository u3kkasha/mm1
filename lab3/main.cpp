//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ
#include "Job_service_complex.hpp"
#include "Report_generator.cc"
#include "Simulation.cc"
#include "Statistics.cc"
#include "Timing_unit.cc"
#include "debug.h"
#include <iostream>
#include <numeric>
using namespace std;
using namespace Singleton;
void print_all_jobs(std::list<Job> job_list) {
  for (auto job : job_list) {
    printf("SSQS-0:Job-%4d \tWaiting-time=%5d \tService_time=%5d "
           "\tSojourn_time=%5d\n",
           job.get_id(), job.get_waiting_time(0), job.get_service_time(0),
           job.get_sojourn_time(0));
    printf("SSQS:1 Job-%4d \tWaiting-time=%5d \tService_time=%5d "
           "\tSojourn_time=%5d\n",
           job.get_id(), job.get_waiting_time(1), job.get_service_time(1),
           job.get_sojourn_time(1));
  }
}

int print_wait(
    std::list<Job> job_list = Statistics::get_list_of_completed_jobs()) {
  auto sum = 0.0F;
  for (auto job : job_list) {
    sum += job.get_waiting_time(0) + job.get_waiting_time(1);
  }
  return sum;
}

double avg_waiting_time() {
  auto jobs = Statistics::get_list_of_completed_jobs();
  return std::accumulate(std::begin(jobs), std::end(jobs), 0,
                         [](int total, Job job) {
                           return total + job.get_waiting_time();
                         }) /
         jobs.size();
}
int main(int number_of_command_line_arguments, char *command_line_arguments[]) {
  auto mean_inter_arrival_time = stoi(command_line_arguments[1]);
  auto mean_service_time = stoi(command_line_arguments[2]);

  Simulation_settings settings = Simulation::get_settings();
  settings.set_number_of_servers(2);
  settings.set_number_of_queues(2);
  settings.set_mean_inter_arrival_time(0, mean_inter_arrival_time);
  settings.set_mean_service_time(0, mean_service_time);
  settings.set_mean_service_time(1, mean_service_time);
  settings.set_termination_time(1000'000);
  Simulation::set_settings(settings);

  Simulation::start();

  // print_all_jobs(Statistics:: get_list_of_completed_jobs());

  /*cout << avg_waiting_time() << ' '
       << print_wait() << ' '
       << Report_generator::calculate_average_waiting_time();
  */

  cout << '\n'
       << static_cast<double>(mean_service_time) / mean_inter_arrival_time
       << ',' << avg_waiting_time();
  for (int i : {0, 1})
    cout << ',' << Job_service_complex::get_queue_log(i).average_load();
  for (int i : {0, 1})
    cout << ',' << Job_service_complex::get_server_log(i).average_load();
}