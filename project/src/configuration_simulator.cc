/**
 * @file configuration_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/configuration_simulator.h"

#include <vector>
#include <list>

#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/random_passenger_generator.h"
// ConfigurationSimulator::ConfigurationSimulator(ConfigManager* configM) {
//     configManager_ = configM;
// }
//
// ConfigurationSimulator::~ConfigurationSimulator() {
//
// }

void ConfigurationSimulator::Start(std::vector<Route *> _routes) {
    simulation_time_elapsed_ = 0;

    // int num_round_trips = 10;
    int num_round_trips = 1;
    for (int i = 0; i < num_round_trips; i++) {
      time_since_last_bus_generation_.push_back(0);
    }
    for (std::vector<Route *>::iterator it = _routes.begin();
    it != _routes.end(); it++) {
      prototype_routes.push_back(*it);
      (*it)->Report(std::cout);
    }

    bus_counters_.push_back(10000);
    bus_start_timings_.push_back(10);
}

void ConfigurationSimulator::Update() {
  // increase time
  simulation_time_elapsed_++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed_;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;

  // various route-indexed list iterators
  std::vector<int>::iterator bus_gen_timing_iter = bus_start_timings_.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters_.begin();
  std::vector<Route *>::iterator prototype_route_iter =
                                                     prototype_routes.begin();

  // increase each time since last bus
  // various iterators parallel the time_since_last iterator
  for (std::vector<int>::iterator it = time_since_last_bus_generation_.begin();
      it != time_since_last_bus_generation_.end();
      it++, bus_gen_timing_iter++, bus_counter_iter++) {
    (*it)++;
    std::cout << "this is a test break ------------";
    // if time since last [index] == bus gen timing[index]
    if (0 >= (*bus_gen_timing_iter)) {
      // create a new bus! routes are:
      // prototype_routes[index * 2] & prototype_routes[index * 2 + 1]
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;

      active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
                                  outbound->Clone(), inbound->Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  // for each bus
  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
      bus_iter != active_buses_.end(); bus_iter++) {
    // update bus
    (*bus_iter)->Update();
    // bus report
    (*bus_iter)->Report(std::cout);

    // REQUIRES USE OF IsTripComplete, which was not required
    // Buses which are "done" will just keep having Update() called
    //   Students MAY need to deal with this, not sure yet...
    // remove bus if trip is complete
    // if ((*bus_iter)->IsTripComplete()) {
    //   bus_iter = active_buses_.erase(bus_iter);
    //   bus_iter--;
    // }
  }

  // for each stop
  for (std::vector<Route *>::iterator route_iter = prototype_routes.begin();
      route_iter != prototype_routes.end(); route_iter++) {
    // update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }
}
