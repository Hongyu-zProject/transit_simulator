/**
 * @file stop.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_STOP_H_
#define SRC_STOP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Bus;

/**
 * @brief The main class for the stop.
 *
 * Calls to \ref Generate function to get a stop.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class Stop {
 public:
 /**
  * @brief Constructs a stop with a standard name and destination stop id.
  *
  *
  * @param[in] int holding an stop id.
  * @param[in] double holding longitude.
  * @param[in] double holding latitude.
  *
  * @return stop object with id, longitude and latitude.
  */
  explicit Stop(int, double = 44.973723, double = -93.235365);
  // Adding passengers to the stop (from the generator)
  /**
   * @brief Constructs a GetId
   * @return int holding stop id_
   */
  int GetId() const;
  /**
   * @brief Constructs a AddPassengers with passenger pointer
   *
   * @param[in] Passenger pointer
   *
   * @return int holding passengers_
   */
  int AddPassengers(Passenger *);
  /**
   * @brief Constructs a AddingPassengers with bus pointer
   *
   * @param[in] Bus pointer
   *
   * @return int holding current passenger on the bus
   */
  int AddingPassengers(Bus *);
  /**
   * @brief Constructs a Deleting Passengers
   * @return erase passengers in the list
   */
  void DeletingPassengers();
  /**
   * @brief Constructs a Update
   * @return update Passenger pointer
   */
  void Update();
  /**
   * @brief Constructs a report with standard ostream
   *
   * @param[in] standard ostream
   *
   * @return report inforamtion such as ID and Passengers waiting
   */
  void Report(std::ostream&) const;
  /**
   * @brief Constructs a GetLatitude
   * @return double holding Latitude
   */
  double GetLatitude();
  /**
   * @brief Constructs a GetLongitude
   * @return double holding Longitude
   */
  double GetLongitude();
  /**
   * @brief Constructs a GetCurrP const
   * @return int of passenger size
   */
  int GetCurrP() const;

 private:
  int id_;  // stop id
  int curr_passenger;  // current passenger size
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;  // longitude of stop
  double latitude_;  // latitude of stop
  // are we using long/lat coords?
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
