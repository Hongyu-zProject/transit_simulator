/**
 * @file stop.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <vector>

#include "src/stop.h"

Stop::Stop(int id, double longitude, double latitude) : id_(id),
longitude_(longitude), latitude_(latitude) {
  // Defaults to Westbound Coffman Union stop
  // no initialization of list of passengers necessary
  curr_passenger = 0;
}

int Stop::AddPassengers(Passenger * pass) {
  passengers_.push_back(pass);
  return 0;
}

double Stop::GetLongitude() {
  return longitude_;
}

double Stop::GetLatitude() {
  return latitude_;
}

int Stop::AddingPassengers(Bus * bus) {
  if (!passengers_.empty()) {
    for (std::list<Passenger *>::const_iterator it = passengers_.begin();
    it != passengers_.end(); it++) {
      curr_passenger++;
      bus->LoadPassenger(*it);
    }
    DeletingPassengers();
    return curr_passenger;
  }
  return 0;
}

void Stop::DeletingPassengers() {
  std::list<Passenger *>::iterator temp1 = passengers_.begin();
  std::list<Passenger *>::iterator temp2 = passengers_.end();
  passengers_.erase(temp1, temp2);
}

void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

int Stop::GetId() const {
  return id_;
}

void Stop::Report(std::ostream&) const {
  std::cout << "ID: " << id_ << std::endl;
  std::cout << "Passengers waiting: " << passengers_.size() << std::endl;
  for (std::list<Passenger *>::const_iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report();
  }
}

int Stop::GetCurrP() const {
  return passengers_.size();
}
