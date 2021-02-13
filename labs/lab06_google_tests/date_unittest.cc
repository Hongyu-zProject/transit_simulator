#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  
TEST_F(DateTest, GetDateTest){
 
  EXPECT_EQ(first_day.GetDate(),"2018-09-04") << "first_day.GetDate() incorrect";
  EXPECT_EQ(last_day.GetDate(),"2018-12-11") << "last_day.GetDate() incorrect";
  Date current_date_actual;
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  Date current_date_expected(now->tm_year+1900,now->tm_mon+1,now->tm_mday);

  EXPECT_EQ(current_date_actual.GetDate(),current_date_expected.GetDate()) << "GetDate() incorrect (standard)";
}


TEST_F(DateTest,GetUsDateTest){
  Date current_date_actual;
  Date test;
  EXPECT_EQ(current_date_actual.GetUsDate(),test.GetUsDate())<<"GetUsDate() incorrect (standard)";
  EXPECT_EQ(first_day.GetUsDate(),"09-04-2018") << "first_day not set up correctly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "last_day not set up correctly";

  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  char current[100];
  sprintf(current,"%02d-%02d-%d",now->tm_mon+1,now->tm_mday,now->tm_year+1900);
	
  EXPECT_EQ(current_date_actual.GetUsDate(),std::string(current)) << "GetUsDate() incorrect (standard)";
}


TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly (standard dates)";
  EXPECT_EQ(last_day.DaysBetween(first_day), 98) << "Days between is not calculated properly (reverse dates)";
  EXPECT_EQ(first_day.DaysBetween(first_day), 0) << "Days between same date not calculated properly";
  EXPECT_EQ(last_day.DaysBetween(last_day), 0) << "Days between same date not calculated properly";
  
  //1/1/2016 to 3/1/2016 is 60 days, but this version returns 59
  Date day1(2016, 1, 1);
  Date day2(2016, 3, 1);
  EXPECT_EQ(day1.GetUsDate(),"01-01-2016")<<"First day of class not setup properly";
  EXPECT_EQ(day2.GetUsDate(), "03-01-2016") << "Last day of class not setup properly";
  EXPECT_EQ(day1.DaysBetween(day2), 60) << "Days between is not calculated properly (reverse dates)";
}

//+ operator test
TEST_F(DateTest, OperatorPlusTest){
  Date first_day_plus = first_day + 3;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-07") << "plus operator incorrect (standard)";

  first_day_plus = first_day + -1;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-03") << "plus operator incorrect (sneaky negative)";

  first_day_plus = first_day + 7.5;//should automatically truncate float
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-11") << "plus operator incorrect (float)";

  first_day_plus = first_day + 30;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-10-04") << "plus operator incorrect (add month)";

  first_day_plus = first_day + 0;
  EXPECT_EQ(first_day_plus.GetDate(),"2018-09-04") << "plus operator incorrect (zero)";
}

//- operator test
TEST_F(DateTest, OperatorMinusTest){
  Date first_day_minus = first_day - 2;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-02") << "minus operator incorrect (subtract 2 days)";
  
  first_day_minus = first_day - 365;
  EXPECT_EQ(first_day_minus.GetDate(),"2017-09-04") << "minus operator incorrect (subtract whole year)";

  first_day_minus = first_day - 0;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-04") << "minus operator incorrect (zero)";

  first_day_minus = first_day - (-2);
  EXPECT_EQ(first_day_minus.GetDate(),"2018-09-06") << "minus operator incorrect (add 2 days)";

  first_day_minus = first_day - 31;
  EXPECT_EQ(first_day_minus.GetDate(),"2018-08-04") << "minus operator incorrect (subtract 1 month)";

  Date first_day_March (2019, 3, 1);
  EXPECT_EQ((first_day_March-1).GetDate(),"2019-02-28") << "Operation minus not defined properly";
  
  Date first_day_new_year (2000, 1, 10);
  EXPECT_EQ((first_day_new_year-10).GetDate(),"1999-12-31") << "Operation minus not defined properly";
}

//constructor test: void
TEST_F(DateTest, ConstructorVoidTest){
  //these two should almost always get the same time, since time_t only
  //stores down to the second and the CPU is faster than that
  Date current_date_actual;

  //the following is taken or inspired by the given code,
  //written by Professor Amy Larson
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  Date current_date_expected(now->tm_year+1900,now->tm_mon+1,now->tm_mday);

  EXPECT_EQ(current_date_actual.GetDate(),current_date_expected.GetDate()) << "void constructor incorrect (standard)";
}

//constructor test: epoch
TEST_F(DateTest, ConstructorEpochTest){
  Date epoch_date_zero(0);
  Date epoch_date_negative(-100000);
  Date epoch_date_float(230000.5);
  Date epoch_date_standard(10000000);
  Date epoch_date_max_int(2147483647);
  Date epoch_date_min_int(-2147483648);

  EXPECT_EQ(epoch_date_zero.GetDate(),"1970-01-01") << "epoch constructor incorrect (zero)";
  EXPECT_EQ(epoch_date_negative.GetDate(),"1969-12-30") << "epoch constructor incorrect (negative)";
  EXPECT_EQ(epoch_date_float.GetDate(),"1970-01-03") << "epoch constructor incorrect (float)";
  EXPECT_EQ(epoch_date_standard.GetDate(),"1970-04-26") << "epoch constructor incorrect (standard)";
  EXPECT_EQ(epoch_date_max_int.GetDate(),"2038-01-19") << "epoch constructor incorrect (max int)";
  EXPECT_EQ(epoch_date_min_int.GetDate(),"1901-12-13") << "epoch constructor incorrect (min int)";
}

//constructor test: 3 ints
TEST_F(DateTest, ConstructorThreeIntsTest){
  //year mutations
  Date year_zero(0,1,1);
  Date year_negative (-10, 1,1);
  Date year_float(5.5,1,1);
  EXPECT_EQ(year_zero.GetDate(),"0-01-01") << "three ints constructor incorrect (year zero)";
  EXPECT_EQ(year_negative.GetDate(),"-10-01-01") << "three ints constructor incorrect (year negative)";
  EXPECT_EQ(year_float.GetDate(),"5-01-01") << "three ints constructor incorrect (year float)";
  //month mutations
  Date month_zero(1970,0,1);
  Date month_negative(1970,-10,1);
  Date month_float(1970,5.5,1);
  EXPECT_EQ(month_zero.GetDate(),"1970-00-01") << "three ints constructor incorrect (month zero)";
  EXPECT_EQ(month_negative.GetDate(),"1970-0-10-01") << "three ints constructor incorrect (month negative)";
  EXPECT_EQ(month_float.GetDate(),"1970-05-01") << "three ints constructor incorrect (month float)";
  //day mutations
  Date day_zero(1970,1,0);
  Date day_negative(1970,1,-10);
  Date day_float(1970,1,5.5);
  EXPECT_EQ(day_zero.GetDate(), "1970-01-00") << "three ints constructor incorrect (day zero)";
  EXPECT_EQ(day_negative.GetDate(), "1970-01-0-10")  << "three ints constructor incorrect (day negative)";
  EXPECT_EQ(day_float.GetDate(), "1970-01-05") << "three ints constructor incorrect (day float)";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
