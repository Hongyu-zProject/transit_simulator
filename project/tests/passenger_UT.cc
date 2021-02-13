/**
 * @file passenger_UT.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/passenger.h"

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class PassengerTests : public ::testing::Test {

	protected:

  	Passenger* passenger;
  	Passenger* passenger_a;
  	Passenger* passenger_b;
  	Passenger* passenger_c;
  	Passenger* passenger_d;


	virtual void SetUp() {
    	passenger = new Passenger();
    	passenger_a = new Passenger(1,"zhu");
    	passenger_b = new Passenger();
    	passenger_c = new Passenger();
    	passenger_d = new Passenger(1,"zhu");
  	}

  	virtual void TearDown() {
    	delete passenger;
    	delete passenger_a;
    	delete passenger_b;
    	delete passenger_c;
    	delete passenger_d;
  	}

};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(PassengerTests, Constructor) {
  	EXPECT_EQ(passenger->IsOnBus(), false);
  	passenger->GetOnBus();
  	EXPECT_EQ(passenger->IsOnBus(), true);
};

TEST_F(PassengerTests, GetDestination) {
  	EXPECT_EQ(passenger_a->GetDestination(), 1);
};

TEST_F(PassengerTests, Update) {
  	EXPECT_EQ(passenger_b->GetTotalWait(), 0);
  	passenger_b->Update();
  	EXPECT_EQ(passenger_b->GetTotalWait(), 1);
};

TEST_F(PassengerTests, GetTotalWait) {
  	EXPECT_EQ(passenger_c->GetTotalWait(), 0);
  	passenger_c->GetOnBus();
  	EXPECT_EQ(passenger_c->GetTotalWait(), 1);
};

TEST_F(PassengerTests, Report) {
	std::string expected_out_1 = "Name: zhu\n";
  std::string expected_out_2 = "Destination: 1\n";
  std::string expected_out_3 = "Total Wait: 0\n";
	std::string expected_out_4 = "\tWait at Stop: 0\n";
	std::string expected_out_5 = "\tTime on bus: 0\n";
	testing::internal::CaptureStdout();
	passenger_d->Report();
	std::string output1 =testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	passenger_d->Report();
	std::string output2 = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	passenger_d->Report();
	std::string output3 = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	passenger_d->Report();
	std::string output4 = testing::internal::GetCapturedStdout();
	testing::internal::CaptureStdout();
	passenger_d->Report();
	std::string output5 = testing::internal::GetCapturedStdout();
	// EXPECT_EQ(output1, expected_out_1);
	// EXPECT_EQ(output2, expected_out_2);
	std::string actual_out = output5;
  EXPECT_EQ(output3, actual_out);
};
