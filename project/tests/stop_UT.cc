/**
 * @file stop_UT.cc
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
 #include "../src/random_passenger_generator.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class StopTests : public ::testing::Test {

	protected:
		Passenger * passenger;
		Passenger * passenger2;
		Passenger * passenger3;
		Passenger * passenger4;
		Stop ** CC_EB_stops;
    Stop ** CC_WB_stops;
		Stop * stop_CC_EB_1;
    std::list<Stop *> CC_EB_stops_list;
    std::list<Stop *> CC_WB_stops_list;
		Bus * bus;
		Route * CC_EB;
		Route * CC_WB;

	  virtual void SetUp() {
			CC_EB_stops = new Stop *[8];
	    CC_WB_stops = new Stop *[9];

			stop_CC_EB_1 = new Stop(0, 44.972392, -93.243774);
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

			  double * CC_EB_distances = new double[7];
			  double * CC_WB_distances = new double[8];
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
			  CC_EB_probs.push_back(.15);   // WB
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
			  CC_WB_probs.push_back(.35);     // SPSC
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

			  RandomPassengerGenerator * CC_EB_generator
			    = new RandomPassengerGenerator(CC_EB_probs, CC_EB_stops_list);
			  RandomPassengerGenerator * CC_WB_generator
			    = new RandomPassengerGenerator(CC_WB_probs, CC_WB_stops_list);

			  CC_EB = new Route("Campus Connector - Eastbound", CC_EB_stops,
			                            CC_EB_distances, 8, CC_EB_generator);
			  CC_WB = new Route("Campus Connector - Westbound", CC_WB_stops,
			                            CC_WB_distances, 9, CC_WB_generator);
			  bus = new Bus("one", CC_EB, CC_WB, 60, 1);
			  passenger = new Passenger(1, "zhu");
			  passenger2 = new Passenger(2, "eric");
			  passenger3 = new Passenger(2, "metric");
			  passenger4 = new Passenger(2, "AnhThi");

  	}

  	virtual void TearDown() {
    	delete CC_EB_stops;
    	delete stop_CC_EB_1;
			delete passenger;
			delete passenger2;
			delete passenger3;
			delete passenger4;
			delete bus;
			delete CC_EB;
			delete CC_WB;
    // 	delete stop_b;
    // 	delete stop_c;
    // 	delete stop_d;
  	}

};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(StopTests, Constructor) {
	  Stop* test_stop = new Stop(1,1.0);
  	EXPECT_EQ(test_stop->GetId(), 1);
};

TEST_F(StopTests, GetLongitude) {
  EXPECT_EQ(stop_CC_EB_1->GetLongitude(),44.972392);
};

TEST_F(StopTests, GetLatitude) {
  EXPECT_EQ(stop_CC_EB_1->GetLatitude(),-93.243774);
};

TEST_F(StopTests, Update) {
  	stop_CC_EB_1->AddPassengers(passenger);
  	stop_CC_EB_1->Update();
  	EXPECT_EQ(passenger->GetTotalWait(), 1);
};

TEST_F(StopTests, AddPassengers) {
	stop_CC_EB_1->AddPassengers(passenger);
	stop_CC_EB_1->AddPassengers(passenger2);
	stop_CC_EB_1->AddPassengers(passenger3);
  EXPECT_NE(stop_CC_EB_1->GetCurrP(),0);
};

TEST_F(StopTests, AddingPassengers) {
	stop_CC_EB_1->AddPassengers(passenger);
	stop_CC_EB_1->AddPassengers(passenger2);
	stop_CC_EB_1->AddPassengers(passenger3);
	int current = stop_CC_EB_1->AddingPassengers(bus);
	EXPECT_NE(current,0);
  EXPECT_EQ(stop_CC_EB_1->GetCurrP(),0);
};

TEST_F(StopTests, DeletingPassengers) {

	EXPECT_EQ(bus->GetNumPassengers(),0);
};

TEST_F(StopTests, GetCurrP) {
  EXPECT_NE(stop_CC_EB_1->GetCurrP(),2);
};

TEST_F(StopTests, GetId) {
  	EXPECT_EQ(stop_CC_EB_1->GetId(), 0);
};
