/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>

#include "src/passenger.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
struct BusData;
struct Position;

/**
 * @brief The main class for the bus.
 *
 * Calls to \ref Generate function to get a new bus.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class Bus {
 public:
 /**
  * @brief Constructs a bus with a standard name, route pointer,route pointer,
  * capacity,speed.
  *
  *
  * @param[in] string holding an name of bus.
  * @param[in] route pointer to outgoing route.
  * @param[in] route pointer to incoming route.
  * @param[in] int holding capacity.
  * @param[in] double holding speed.
  *
  * @return Bus object with name, route, capacity and speed.
  */
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  /**
   * @brief Constructs a LoadPassenger with a passenger pointer.
   * @param[in] Passenger pointer
   * @return if bus is not full then load passenger list.
   */
  bool LoadPassenger(Passenger *);  // returning revenue delta
  /**
   * @brief Constructs a UnLoadPassenger with passenger pointer.
   * @param[in] Passenger pointer
   * @return if bus is at stop, unload the passengers who need to get off.
   */
  bool UnLoadPassenger(Passenger *);
  /**
   * @brief Constructs a move
   * @return Bus moves to the next stop.
   */
  bool Move();
  /**
   * @brief Constructs a update
   * @return update move
   */
  void Update();
  /**
   * @brief Constructs a report with a standard ostream,
   * @return string for a report.
   */
  void Report(std::ostream&);
  /**
   * @brief Constructs a IsTripComplete
   * @return true if trip is complete.
   */
  bool IsTripComplete();
  /**
   * @brief Constructs a UpdateBusData
   * @return update bus data from data struct
   */
  void UpdateBusData();
  /**
   * @brief Constructs a GetBusData
   * @return new bus data
   */
  BusData GetBusData();
  /**
   * @brief Constructs a GetName
   * @return string with bus name
   */
  std::string GetName() const;
  /**
   * @brief Constructs a GetNextStop
   * @return Stop* to next stop
   */
  Stop * GetNextStop();
  /**
   * @brief Constructs a GetNumPassengers
   * @return size_t holding passenger size
   */
  size_t GetNumPassengers();
  /**
   * @brief Constructs a GetCapacity
   * @return int holding bus max capacity
   */
  int GetCapacity();

 private:
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  std::string name_;
  int sig;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  Stop * this_s;  // the current stop pointer
  BusData b;  // new bus data
  Stop * prev_s;  // the previous stop
};
#endif  // SRC_BUS_H_
