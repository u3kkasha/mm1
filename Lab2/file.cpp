
void show_output_variables()
{
using Singleton::Enumerations;
auto calculate=Singleton::Report_generator::compute_average;
Report_generator::prepare_report();

ofstream file("simulation_outputs.csv",ios::app); //ios::app is for appending

auto current_settings=Simulation::get_settings();

file<<current_settings.get_mean_inter_arrival_time()<<','
<<current_settings.get_mean_service_time()<<','
<<"Average delay per customer "<<calculate(Enumerations::Average_kind::job,Enumerations::Information_kind::waiting_time)<<endl;
file<<"Average service time per customer "<<calculate(Enumerations::Average_kind::job,Enumerations::Information_kind::service_time)<<endl;
file<<"Average system time per customer "<<calculate(Enumerations::Average_kind::job,Enumerations::Information_kind::sojourn_time)<<endl;
file<<"Average queue length per time unit "<<calculate(Enumerations::Average_kind::time,Enumerations::Information_kind::waiting_time)<<endl;
file<<"Average server utilisation "<<calculate(Enumerations::Average_kind::time,Enumerations::Information_kind::service_time)*100<<'%'<<endl;
file<<"Average number of people inside system per time unit "<<calculate(Enumerations::Average_kind::time,Enumerations::Information_kind::sojourn_time)<<'\n'


}
