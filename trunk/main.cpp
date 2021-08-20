//بسم الله الرحمن الرحيم

#include "Enumerations.cc"
#include "Job_processing_system.hpp"
#include "Log.cc"
#include "Report_generator.cc"
#include "Simulation.cc"
#include "Simulation_settings.cc"
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
using namespace Singleton;
using namespace std;

template <typename datatype>
void get_value_from_user(datatype& variable, std::string message)
{
    std::cout << message << std::endl;
    std::cin >> variable;
}

void setup_simulation(string mean_inter_arrival, string mean_service)
{
    //Setup Simulation
    Simulation_settings current_settings;

    int termination_time = pow(10, 8);
    double mean_inter_arrival_time = stoi(mean_inter_arrival);
    double mean_service_time = stoi(mean_service);

    current_settings.set_termination_time(termination_time);
    current_settings.set_mean_inter_arrival_time(mean_inter_arrival_time);
    current_settings.set_mean_service_time(mean_service_time);
    Simulation::set_settings(current_settings);
    Simulation::start();
}

void show_output_variables()
{
    using Singleton::Enumerations;
    auto calculate = Singleton::Report_generator::compute_average;
    Report_generator::prepare_report();

    ofstream file("simulation_outputs.csv", ios::app); //ios::app is for appending

    auto current_settings = Simulation::get_settings();

    /*Simulation Inputs*/

    file << current_settings.get_mean_inter_arrival_time() << ','
         << current_settings.get_mean_service_time() << ',';

    /**Simualtion Outputs**/

    /*Server Utilisation*/
    file << calculate(Enumerations::Average_kind::time, Enumerations::Information_kind::service_time) << ','
         /*Average number of people inside system per time unit*/
         << calculate(Enumerations::Average_kind::time, Enumerations::Information_kind::sojourn_time) << ','
         /*Average queue length per time unit*/
         << calculate(Enumerations::Average_kind::time, Enumerations::Information_kind::waiting_time) << ','
         /*Average delay per customer*/
         << calculate(Enumerations::Average_kind::job, Enumerations::Information_kind::waiting_time) << ','
         /*Average service time per customer*/
         << calculate(Enumerations::Average_kind::job, Enumerations::Information_kind::service_time) << ','
         /*Average system time per customer*/
         << calculate(Enumerations::Average_kind::job, Enumerations::Information_kind::sojourn_time) << '\n';
}
void print_log(Log log, std::string name)
{
    printf("\tTime\t\t%s\n", name.c_str());
    for (auto [time, data] : log.get_full_log())
        printf("%10d\t\t%10d\n", time, data);
}

void print_all_jobs(list<Job> job_list)
{
    for (auto job : job_list)
        printf("Job-%4d \tWaiting-time=%5d \tService_time=%5d \tSojourn_time=%5d\n", job.get_id(), job.get_waiting_time(), job.get_service_time(), job.get_sojourn_time());
}

void option_to_view_logs()
{
    bool user_chose_to_view = false;
    get_value_from_user(user_chose_to_view, "Do you want to see the server's log?-----Type 1 for 'yes' otherwise press 0");

    if (user_chose_to_view) {
        auto server_log = Job_processing_system::get_server_log(0);
        print_log(server_log, "Server Status");
    }

    get_value_from_user(user_chose_to_view, "Ok, so do you want to see the queues's log?-----Type 1 for 'yes' else press 0");
    if (user_chose_to_view) {
        auto queue_log = Job_processing_system::get_waiting_line_log(0);
        print_log(queue_log, "Queue Length");
    }

    get_value_from_user(user_chose_to_view, "In sha Allah this is the last one, do you want to see the details of each departed customer?-----Type 1 for 'yes' else press 0");
    if (user_chose_to_view) {
        auto job_log = Statistics::get_list_of_completed_jobs();
        print_all_jobs(job_log);
    }
}

int main(int number_of_arguments, char* command_line_arguments[])
{
    //cout<<"Welcome to SSQS Simulation by ID-215 and ID-216\nPlease enter the following parameters to run the simulation in sha Allah\n";

    setup_simulation(command_line_arguments[1], command_line_arguments[2]);

    show_output_variables();

    //option_to_view_logs();

    //cout<<"End of Program";
    return 0;
}