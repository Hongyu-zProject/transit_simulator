/**
 * @file route.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/route.h"

Route::Route(std::string name, Stop ** stops, double * distances, int num_stops,
PassengerGenerator * generator_new) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }
  generator_ = generator_new;
  generator_new->GeneratePassengers();
  name_ = name;
  num_stops_ = num_stops;
  destination_stop_ = stops_.front();
  destination_stop_index_ = 0;
}

Route * Route::Clone() {
  Stop ** copy_stop = new Stop * [stops_.size()];
  std::copy(stops_.begin(), stops_.end(), copy_stop);

  double * copy_distances = new double[distances_between_.size()];
  std::copy(distances_between_.begin(), distances_between_.end(),
  copy_distances);

  return new Route(name_, copy_stop, copy_distances, num_stops_, generator_);
}

void Route::Update() {
  for ( std::list<Stop *>::iterator it = stops_.begin(); it != stops_.end();
  it++) {
    (*it)->Update();
  }
  UpdateRouteData();
}

void Route::Report(std::ostream&) {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Num stops: " << num_stops_ << std::endl;
  int stop_counter = 0;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
  it != stops_.end(); it++) {
    (*it)->Report(std::cout);
    stop_counter++;
  }
}

bool Route::IsAtEnd() const {
  if (destination_stop_index_ == num_stops_+1) {
    return true;
  } else {
    return false;
  }
}

void Route::NextStop() {
  destination_stop_index_++;
  int temp = 1;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
  it != stops_.end(); it++) {
    if (destination_stop_index_ == temp) {
      destination_stop_ = (*it);
      break;
    }
    temp++;
  }
}

Stop * Route::GetDestinationStop() const {
  return destination_stop_;
}

double Route::GetTotalRouteDistance() const {
  double total_amount = 0;
  for (std::list<double>::const_iterator it = distances_between_.begin();
  it != distances_between_.end(); it++) {
      total_amount += (*it);
    }
    return total_amount;
}

double Route::GetNextStopDistance() const {
  int temp = 1;
  for (std::list<double>::const_iterator it = distances_between_.begin();
  it != distances_between_.end(); it++) {
    if (destination_stop_index_ == temp) {
      return (*it);
    }
    temp++;
  }
}

int Route::GenerateNewPassengers() {
  generator_->GeneratePassengers();
  return 0;
}

std::string Route::GetName() {
  return name_;
}

std::list<Stop *>Route::GetStops() {
  return stops_;
}

void Route::UpdateRouteData() {
  r.id = name_;
  std::vector<StopData> _stops;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
  it != stops_.end(); it++) {
    _this.id = std::to_string((*it)->GetId());
    _this.position.x = (*it)->GetLongitude();
    _this.position.y = (*it)->GetLatitude();
    _this.num_people = (*it)->GetCurrP();
    _stops.push_back(_this);
  }
  r.stops = _stops;
}

RouteData Route::GetRouteData() {
  return r;
}
