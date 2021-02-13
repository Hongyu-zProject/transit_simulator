
/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the passengers.
 *
 * Calls to \ref Generate function to get a new instance of a passenger.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class Passenger {  // : public Reporter {
 public:
 /**
  * @brief Constructs a passenger with a standard name and destination stop id.
  *
  *
  * @param[in] int holding an destination stop id number.
  * @param[in] string holding a name of a created passenger.
  *
  * @return Passenger object with Destination Stop ID and Name.
  */
  explicit Passenger(int = -1, std::string = "Nobody");
  /**
   * @brief Constructs a Update
   * @return update the time on bus or wait time.
   */
  void Update();
  /**
   * @brief Constructs a GetOnBus
   * @return time on the bus add 1
   */
  void GetOnBus();
  /**
   * @brief Constructs a GetTotalWait
   * @return addtion of waiting time and time on the bus
   */
  int GetTotalWait() const;
  /**
   * @brief Constructs a IsOnBus
   * @return whether passenger is the on the bus.
   */
  bool IsOnBus() const;
  /**
   * @brief Constructs a GetDestination
   * @return an int holding destinatin stop id
   */
  int GetDestination() const;
  /**
   * @brief Constructs a Report
   * @return report information
   */
  void Report() const;

 private:
 /**
  * @brief global count.
  *
  * @return ID for new instances.
  */
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;   // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
