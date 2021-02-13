/**
 * @file route_UT.cc
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

class RouteTests : public ::testing::Test {

	protected:
    Stop ** CC_EB_stops;
    Stop ** CC_WB_stops;
    std::list<Stop *> CC_EB_stops_list;
    std::list<Stop *> CC_WB_stops_list;
    double * CC_EB_distances;
    double * CC_WB_distances;
    Route * route;
    RandomPassengerGenerator * generator_new;

  virtual void SetUp() {
    CC_EB_stops = new Stop *[8];
    CC_WB_stops = new Stop *[9];
    Stop * stop_CC_EB_1 = new Stop(0, 44.972392, -93.243774);
    //   student union station
    Stop * stop_CC_EB_2 = new Stop(1, 44.973580, -93.235071);
    //   Oak St & Washington Ave
    Stop * stop_CC_EB_3 = new Stop(2, 44.975392, -93.226632);
    //   before transit
    Stop * stop_CC_EB_4 = new Stop(3, 44.975837, -93.222174);
    //   tway
    Stop * stop_CC_EB_5 = new Stop(4, 44.980753, -93.180669);
    //   Fairgrounds
    Stop * stop_CC_EB_6 = new Stop(5, 44.983375, -93.178810);
    //   Buford & Gartner
    Stop * stop_CC_EB_7 = new Stop(6, 44.984540, -93.181692);
    //   SPSC
    Stop * stop_CC_EB_8 = new Stop(7, 44.984630, -93.186352);

    // CC Westbound stops
    //   SPSC
    Stop * stop_CC_WB_1 = new Stop(8, 44.984630, -93.186352);
    //   Buford & Gartner
    Stop * stop_CC_WB_2 = new Stop(9, 44.984482, -93.181657);
    //   Fairgrounds
    Stop * stop_CC_WB_3 = new Stop(10, 44.983703, -93.178846);
    //   Tway
    Stop * stop_CC_WB_4 = new Stop(11, 44.980663, -93.180808);
    //   before transit
    Stop * stop_CC_WB_5 = new Stop(12, 44.976397, -93.221801);
    //   Ridder
    Stop * stop_CC_WB_6 = new Stop(13, 44.978058, -93.229176);
    //   Jones-Eddy
    Stop * stop_CC_WB_7 = new Stop(14, 44.978366, -93.236038);
    //   Bruininks
    Stop * stop_CC_WB_8 = new Stop(15, 44.974549, -93.236927);
    //   Blegen
    Stop * stop_CC_WB_9 = new Stop(16, 44.972638, -93.243591);

    CC_EB_stops_list.push_back(stop_CC_EB_1);
    CC_EB_stops[0] = stop_CC_EB_1;
    CC_EB_stops_list.push_back(stop_CC_EB_2);
    CC_EB_stops[1] = stop_CC_EB_2;
    CC_EB_stops_list.push_back(stop_CC_EB_3);
    CC_EB_stops[2] = stop_CC_EB_3;
    CC_EB_stops_list.push_back(stop_CC_EB_4);
    CC_EB_stops[3] = stop_CC_EB_4;
    CC_EB_stops_list.push_back(stop_CC_EB_5);
    CC_EB_stops[4] = stop_CC_EB_5;
    CC_EB_stops_list.push_back(stop_CC_EB_6);
    CC_EB_stops[5] = stop_CC_EB_6;
    CC_EB_stops_list.push_back(stop_CC_EB_7);
    CC_EB_stops[6] = stop_CC_EB_7;
    CC_EB_stops_list.push_back(stop_CC_EB_8);
    CC_EB_stops[7] = stop_CC_EB_8;

    CC_WB_stops_list.push_back(stop_CC_WB_1);
    CC_WB_stops[0] = stop_CC_WB_1;
    CC_WB_stops_list.push_back(stop_CC_WB_2);
    CC_WB_stops[1] = stop_CC_WB_2;
    CC_WB_stops_list.push_back(stop_CC_WB_3);
    CC_WB_stops[2] = stop_CC_WB_3;
    CC_WB_stops_list.push_back(stop_CC_WB_4);
    CC_WB_stops[3] = stop_CC_WB_4;
    CC_WB_stops_list.push_back(stop_CC_WB_5);
    CC_WB_stops[4] = stop_CC_WB_5;
    CC_WB_stops_list.push_back(stop_CC_WB_6);
    CC_WB_stops[5] = stop_CC_WB_6;
    CC_WB_stops_list.push_back(stop_CC_WB_7);
    CC_WB_stops[6] = stop_CC_WB_7;
    CC_WB_stops_list.push_back(stop_CC_WB_8);
    CC_WB_stops[7] = stop_CC_WB_8;
    CC_WB_stops_list.push_back(stop_CC_WB_9);
    CC_WB_stops[8] = stop_CC_WB_9;

    CC_EB_distances = new double[7];
    CC_WB_distances = new double[8];
    CC_EB_distances[0] = 4;
    CC_EB_distances[1] = 4;
    CC_EB_distances[2] = 2;
    CC_EB_distances[3] = 19;
    CC_EB_distances[4] = 1;
    CC_EB_distances[5] = 1;
    CC_EB_distances[6] = 2;

    CC_WB_distances[0] = 2;
    CC_WB_distances[1] = 1;
    CC_WB_distances[2] = 2;
    CC_WB_distances[3] = 19;
    CC_WB_distances[4] = 3;
    CC_WB_distances[5] = 3;
    CC_WB_distances[6] = 2;
    CC_WB_distances[7] = 3;


    std::list<double> CC_EB_probs;  // realistic .15, .3, .025, .05, .05, 0
    CC_EB_probs.push_back(.3);   // WB
    CC_EB_probs.push_back(.3);    // CMU
    CC_EB_probs.push_back(.025);  // O&W
    CC_EB_probs.push_back(.05);   // Pre-transit
    CC_EB_probs.push_back(.05);   // post-transit
    CC_EB_probs.push_back(.01);   // State fair
    CC_EB_probs.push_back(.01);   // Buford
    CC_EB_probs.push_back(0);     // SPSC - MUST BE 0
    // TODO(staff): is this always true? If so,
    //  we may want to reduce the length of probs to_char_type
    //    remove possibility of generating passengers with nowhere to go

    std::list<double> CC_WB_probs;  // realistic .35, .05, .01, .01, .2, 0
    CC_WB_probs.push_back(.3);     // SPSC
    CC_WB_probs.push_back(.05);     // Buford
    CC_WB_probs.push_back(.01);     // State fair
    CC_WB_probs.push_back(.01);     // post-transit
    CC_WB_probs.push_back(.025);    // pre-transit
    CC_WB_probs.push_back(.05);     // Ridder
    CC_WB_probs.push_back(.1);      // Jones-Eddy
    CC_WB_probs.push_back(.3);      // Bruininks
    CC_WB_probs.push_back(0);       // Blegen

    // Staticly defined objects get destroyed at end of Start()!
    // Must be dynamic...
    // RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
    // RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);

    generator_new
      = new RandomPassengerGenerator(CC_EB_probs, CC_EB_stops_list);
    RandomPassengerGenerator * CC_WB_generator
      = new RandomPassengerGenerator(CC_WB_probs, CC_WB_stops_list);

    route = new Route("Campus Connector - Eastbound", CC_EB_stops,
                              CC_EB_distances, 8, generator_new);
  }

  virtual void TearDown() {
    delete CC_EB_stops;
    delete CC_WB_stops;
    delete CC_EB_distances;
    delete CC_WB_distances;
    delete route;
    delete generator_new;
    }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(RouteTests, Constructor) {
  	EXPECT_EQ(generator_new->GeneratePassengers(), 0);
};

TEST_F(RouteTests, GetTotalRouteDistance) {
  EXPECT_EQ(route -> GetTotalRouteDistance(), 33);
};

TEST_F(RouteTests, GetName) {
  	EXPECT_EQ(route -> GetName(), "Campus Connector - Eastbound");
};

TEST_F(RouteTests, GenerateNewPassengers) {
  	EXPECT_EQ(generator_new -> GeneratePassengers(), 0);
};

TEST_F(RouteTests, GetNextStopDistance) {
  EXPECT_NE(route -> GetNextStopDistance(),0);
};


TEST_F(RouteTests, Update) {
  route->Update();
  std::list<Stop *> test_stop_list = route->GetStops();
  Stop * test_stop = test_stop_list.back();
  EXPECT_EQ(test_stop->GetCurrP(),0);
};

TEST_F(RouteTests,Clone) {
  Route * test_clone = route->Clone();
  EXPECT_EQ(test_clone->GetName(),route->GetName());
  EXPECT_EQ(test_clone->GetStops(),route->GetStops());
};

TEST_F(RouteTests, GetDestinationStop) {
  Stop * test_stop = route -> GetDestinationStop();
  std::list<Stop *> test_stop_list = route->GetStops();
  EXPECT_EQ(test_stop -> GetId(), test_stop_list.front()->GetId());
};


TEST_F(RouteTests,NextStop) {
  std::list<Stop *> test_stop_list = route->GetStops();
  route->NextStop();
  std::list<Stop *>::const_iterator it = test_stop_list.begin();
  std::advance(it, 1);
  Stop * test_stop = route->GetDestinationStop();
  EXPECT_EQ(test_stop->GetId(),0);
}


TEST_F(RouteTests, IsAtEnd) {
  	EXPECT_EQ(route -> IsAtEnd(), false);
};

TEST_F(RouteTests, GetStops) {
  std::list<Stop *> testlist = route ->GetStops();
	EXPECT_EQ(CC_EB_stops_list.size(),testlist.size());
};

TEST_F(RouteTests, UpdateRouteData) {
  route->UpdateRouteData();
  RouteData data = route->GetRouteData();
  EXPECT_EQ(data.id, "Campus Connector - Eastbound");
};

TEST_F(RouteTests, GetRouteData) {
  EXPECT_EQ(route -> GetRouteData().id,"");
};
