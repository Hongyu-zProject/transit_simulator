/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus.h"

Bus::Bus(std::string name, Route * out, Route * in, int capacity,
double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
  prev_s = outgoing_route_->GetDestinationStop();
}

bool Bus::IsTripComplete() {
  return (incoming_route_ -> IsAtEnd() || outgoing_route_ -> IsAtEnd());
}

bool Bus::LoadPassenger(Passenger * new_passenger) {
  if (passengers_.size() < passenger_max_capacity_) {
    new_passenger->GetOnBus();
    passengers_.push_back(new_passenger);
    return true;
  } else if (IsTripComplete() || passengers_.size() >=
  passenger_max_capacity_) {
      return false;
    }
}

bool Bus::UnLoadPassenger(Passenger * passenger_off) {
  if (!IsTripComplete() && distance_remaining_ == 0) {
    for (std::list<Passenger *>::iterator it = passengers_.begin();
    it != passengers_.end(); it++) {
    //   if(sig.GetId() == (*it)-> GetDestinationStop()){
    //     it = passengers_.erase(*it);
    //     return true;
    //   }
    }
  } else if (IsTripComplete()) {
      for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
        it = passengers_.erase(it);
        return true;
      }
    }
    return false;
}

bool Bus::Move() {
  if (distance_remaining_ <= 0) {
    if (!outgoing_route_->IsAtEnd()) {
      distance_remaining_ = outgoing_route_->GetNextStopDistance();
      this_s = outgoing_route_->GetDestinationStop();
      sig = this_s->AddingPassengers(this);
      prev_s = this_s;
      outgoing_route_->NextStop();
    } else {
      distance_remaining_ = incoming_route_->GetNextStopDistance();
      this_s = incoming_route_->GetDestinationStop();
      sig = this_s->AddingPassengers(this);
      prev_s = this_s;
      incoming_route_->NextStop();
    }
  } else if (IsTripComplete()) {
    return false;
  }
  if (sig) {
    distance_remaining_ = distance_remaining_ + speed_;
  }
  distance_remaining_ = distance_remaining_ - speed_;
  return true;
}

// bool Refuel() {
//  // This may become more complex in the future
// fuel_ = max_fuel_;
//}

void Bus::Update() {  // using common Update format
  // if (distance_remaining_ <= 0) {
  //   Stop * curr_stop = outgoing_route_->GetDestinationStop();
  // }
  Move();
  UpdateBusData();
}

void Bus::Report(std::ostream&) {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Distance to next stop: " << distance_remaining_ << std::endl;
  std::cout << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
  it != passengers_.end(); it++) {
    (*it)->Report();
  }
}

std::string Bus::GetName() const {
  return name_;
}

size_t Bus::GetNumPassengers() {
  return passengers_.size();
}

int Bus::GetCapacity() {
  return passenger_max_capacity_;
}

Stop * Bus::GetNextStop() {
  if (outgoing_route_->IsAtEnd()) {
    return incoming_route_->GetDestinationStop();
  }
  return outgoing_route_->GetDestinationStop();
}

void Bus::UpdateBusData() {
  b.id = name_;
  double _latitude = prev_s->GetLatitude();
  double _longitude = prev_s->GetLongitude();
  b.position.x = (_longitude + GetNextStop()->GetLongitude())/2.0;
  b.position.y = (_latitude + GetNextStop()->GetLatitude())/2.0;
  b.num_passengers = passengers_.size();
  b.capacity = passenger_max_capacity_;
  std::cout << "latitude: " << _latitude << std::endl;
  std::cout << "longitude: " << _longitude << std::endl;
}

BusData Bus::GetBusData() {
  return b;
}
