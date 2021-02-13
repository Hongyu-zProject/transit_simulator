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
  * @brief public Reporter for Passenger .
  *s
  * This function will be used for report Destination Stop ID and Name.
  *
  * @param[in] destination_stop_id Destination Stop ID, left bound (not-inclusive)
  * @param[in] name Passenger Name, right bound (inclusive)
  *
  * @return Passenger object with Destination Stop ID and Name.
  */
  Passenger(-1, "Nobody");
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  bool IsOnBus() const;
  int GetDestination() const;
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
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
