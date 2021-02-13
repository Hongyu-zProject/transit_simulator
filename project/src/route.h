/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>
#include <string>

#include "./passenger_generator.h"
#include "./stop.h"
#include "src/data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerGenerator;
class Stop;
struct RouteData;

/**
 * @brief The main class for the route.
 *
 * Calls to \ref Generate function to get a route.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class Route {
 public:
 /**
  * @brief Constructs a route with a standard name and stop pointer, distances,
  * num_stops and passenger generator pointer.
  *
  *
  * @param[in] string holding name of route.
  * @param[in] stop pointer to stop.
  * @param[in] double holding distances pointer.
  * @param[in] int holding the num_stops.
  * @param[in] passenger generator pointer to passenger generator.
  *
  * @return route object with name, stops, distances, num_stops,
  * generator_new.
  */
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator * generator_new);
  /**
   * @brief Constructs a Route pointer Clone
   * @return route pointer to clone the route
   */
  Route * Clone();
  /**
   * @brief Constructs a Update
   * @return update stop list
   */
  void Update();
  /**
   * @brief Constructs a Report with standard ostream
   * @param[in] standard ostream
   * @return report information and increase the stop_counter
   */
  void Report(std::ostream&);
  /**
   * @brief Constructs a IsAtEnd
   * @return true if the bus reached the last stop
   */
  bool IsAtEnd() const;
  /**
   * @brief Constructs a NextStop
   * @return destination_stop_ to the next stop in the route
   */
  void NextStop();  // Change destination_stop_ to next stop
  /**
   * @brief Constructs a Stop pointer GetDestinationStop
   * @return stop pointer to destination_stop_
   */
  Stop * GetDestinationStop() const;    // Get pointer to next stop
  /**
   * @brief Constructs a GetTotalRouteDistance
   * @return total amount of distrance
   */
  double GetTotalRouteDistance() const;
  /**
   * @brief Constructs a GetNextStopDistance
   * @return distances_between_ corrsponding to the index in stop list
   */
  double GetNextStopDistance() const;
  /**
   * @brief Constructs a GetName
   * @return string holding route name
   */
  std::string GetName();
  /**
   * @brief Constructs a GetStop
   * @return list with stop pointer
   */
  std::list<Stop *> GetStops();
  /**
   * @brief Constructs a UpdateRouteData
   * @return update route data
   */
  void UpdateRouteData();
  /**
   * @brief Constructs a GetRouteData
   * @return new route data
   */
  RouteData GetRouteData();

 private:
  int GenerateNewPassengers();  // generates passengers on its route
  PassengerGenerator * generator_;  // pointer to PassengerGenerator
  std::list<Stop *> stops_;  // list with stop pointer
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;  // route name
  int num_stops_;  // number of stops
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;  // stop pointer to next stop
  double trip_time_;  // derived data - total distance travelled on route
  RouteData r;  // new route data
  StopData _this;  // new stop data
};
#endif  // SRC_ROUTE_H_
