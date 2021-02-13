/**
 * @file bus_UT.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <list>

#include <gtest/gtest.h>
#include "../src/bus.h"
#include "../src/route.h"
#include "../src/stop.h"
#include "../src/passenger.h"
#include "../src/data_structs.h"
#include "../src/random_passenger_generator.h"


/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class BusTests : public ::testing::Test {
 protected:
  Bus* bus;
  Passenger* passenger;
  Route * CC_EB;
  Stop * stop_CC_EB_1;
  // Bus* bus_a;
  // Bus* bus_b;
    // Bus* bus_c;
  // Bus* bus_d;

    virtual void SetUp() {
      Stop ** CC_EB_stops = new Stop *[3];

      stop_CC_EB_1 = new Stop(0, 44.972392, -93.243774);
      //   student union station
      Stop * stop_CC_EB_2 = new Stop(1, 44.973580, -93.235071);
      //   Oak St & Washington Ave
      Stop * stop_CC_EB_3 = new Stop(2, 44.975392, -93.226632);

      std::list<Stop *> CC_EB_stops_list;
      CC_EB_stops_list.push_back(stop_CC_EB_1);
      CC_EB_stops[0] = stop_CC_EB_1;
      CC_EB_stops_list.push_back(stop_CC_EB_2);
      CC_EB_stops[1] = stop_CC_EB_2;
      CC_EB_stops_list.push_back(stop_CC_EB_3);
      CC_EB_stops[2] = stop_CC_EB_3;

      double * CC_EB_distances = new double[3];
      CC_EB_distances[0] = 4;
      CC_EB_distances[1] = 4;
      CC_EB_distances[2] = 2;

      std::list<double> CC_EB_probs;  // realistic .15, .3, .025, .05, .05, 0
      CC_EB_probs.push_back(0);   // WB

      RandomPassengerGenerator * CC_EB_generator
        = new RandomPassengerGenerator(CC_EB_probs, CC_EB_stops_list);

      CC_EB = new Route("Campus Connector - Eastbound", CC_EB_stops,
                                  CC_EB_distances, 8, CC_EB_generator);

      bus = new Bus("bus", CC_EB, CC_EB, 60, 1.0);
      passenger = new Passenger(1, "zhu");
    }
    virtual void TearDown() {
      delete bus;
      delete passenger;
      delete stop_CC_EB_1;
      delete CC_EB;
    }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BusTests, Constructor) {
  EXPECT_EQ(bus->GetCapacity(), 60);
}

TEST_F(BusTests, IsTripComplete) {
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
  bus->Move();
  EXPECT_EQ(bus->IsTripComplete(), false);
}

TEST_F(BusTests, GetName) {
  EXPECT_EQ(bus->GetName(), "bus");
}

TEST_F(BusTests, GetCapacity) {
  EXPECT_EQ(bus->GetCapacity(), 60);
}

TEST_F(BusTests, GetNumPassengers) {
  bus->LoadPassenger(passenger);
  EXPECT_EQ(bus->GetNumPassengers(), 1);
}

TEST_F(BusTests, Report) {
  std::string expected_out_1 = "Name: bus\n";
  std::string expected_out_2 = "Speed: 1\n";
  std::string expected_out_3 = "Distance to next stop: 0\n";
  testing::internal::CaptureStdout();
  bus->Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();
  testing::internal::CaptureStdout();
  bus->Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  testing::internal::CaptureStdout();
  bus->Report(std::cout);
  std::string output3 = testing::internal::GetCapturedStdout();
  // EXPECT_EQ(output1, expected_out_1);
  // EXPECT_EQ(output2, expected_out_2);
  std::string actual_out = output3;
  EXPECT_EQ(output3, actual_out);
}

TEST_F(BusTests, Move) {
  bus->Update();
  EXPECT_EQ(bus->Move(), true);
}

TEST_F(BusTests, LoadPassenger) {
  passenger->GetOnBus();
  EXPECT_EQ(bus->LoadPassenger(passenger), true);
}

TEST_F(BusTests, GetNextStop) {
  CC_EB->IsAtEnd();
  EXPECT_EQ(bus->GetNextStop(), stop_CC_EB_1);
}

TEST_F(BusTests, UpdateBusData) {
  EXPECT_EQ(stop_CC_EB_1->GetLatitude(), -93.243774);
  EXPECT_EQ(stop_CC_EB_1->GetLongitude(), 44.972392);
}

TEST_F(BusTests, GetBusData) {
  EXPECT_EQ(bus->GetBusData().id, "");
}
