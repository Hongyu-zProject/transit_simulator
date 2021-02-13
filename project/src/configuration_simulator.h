/**
 * @file configuration_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONFIGURATION_SIMULATOR_H_
#define SRC_CONFIGURATION_SIMULATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>

#include "src/config_manager.h"
#include "src/simulator.h"
#include "src/bus.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/passenger_generator.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Route;
class Bus;
class Stop;

/**
 * @brief The main class for the configuration_simulator.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class ConfigurationSimulator {
 public:
      /**
       * @brief Constructs a start
       *
       * @param[in] std::vector<Route *>
       *
       * @return vector with route pointer
       */
        void Start(std::vector<Route *>);
        /**
         * @brief Constructs a update
         * @return update route
         */
        void Update();

 private:
        ConfigManager* configManager_;  // pointer to configManager
        std::vector<int> bus_counters_;  // vector holding int to count bus
        std::vector<int> bus_start_timings_;
        // vector holding int of when bus starts
        std::vector<int> time_since_last_bus_generation_;
        // vector holding int of time since last bus generated
        int simulation_time_elapsed_;  // time elapsed
        std::list<Bus *> active_buses_;  // buses leave scope
        std::vector<Route *> routes;  // vector holidng route pointer
        // prototype_routes and distance lists will be accessed directly
        // list is not efficient at direct selection by index
        // routes below a for copying on bus creation
        std::vector<Route *> prototype_routes;
};

#endif  // SRC_CONFIGURATION_SIMULATOR_H_
