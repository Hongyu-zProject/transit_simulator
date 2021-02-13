/**
 * @file configuration_sim.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <fstream>
#include <string>

#include "src/config_manager.h"
#include "src/configuration_simulator.h"

int main(int argc, char**argv) {
  int simLength = 50;
  // NOTE: this usage will change depending on
  //       how you build your config_sim classes
  //   E.g., how will you handle getting the length of simulation value?
  // ifstream f;
  // if (argc == 1) {
  //   filename = "config/config.txt";
  // }
  // else if (argc == 2) {
  //   filename = argv[2];
  // }
  // else {
  // std::cout << "Usage: ./build/bin/configuration_sim <config_filename>";
  // std::cout << std::endl;
  // std::cout << "~~~~~~~~~~~~~Need to add a config file name";
  // std::cout << " ~~~~~~~~~~~~~" << std::endl;
  // }

  // Check command line params for config file name

  // if filename arg present
  //   Create ConfigManager
  //   Call ReadConfig
  //   Create ConfigurationSimulator
  //   Call Start on ConfigurationSimulator
  //   Start for loop, length of simulation (where from?)
  //     Call Update on ConfigurationSimulator
  // else
  //   echo info to the user about needing a config file name
  std::vector<Route *> _routes;
  std::string filename;
  if (argc == 1) {
    ConfigManager _configManager;
    _configManager.ReadConfig("config.txt");
    _routes = _configManager.GetRoutes();
  } else if (argc == 2) {
    ConfigManager _configManager;
    filename = argv[1];
    std::ifstream f(filename);
    if (f.good()) {
    _configManager.ReadConfig(filename);
    } else {
      std::cout << "Invalid file name, using congfig.txt as default";
      std::cout << std::endl;
      std::cout << "Usage: ./build/bin/configuration_sim <config_filename>";
      std::cout << std::endl;
      _configManager.ReadConfig("config.txt");
    }
    _routes = _configManager.GetRoutes();
  } else {
    std::cout << "Usage: ./build/bin/configuration_sim <config_filename>";
    std::cout << std::endl;
  }
  ConfigurationSimulator  _configSim;

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "         STARTING" << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "*************************/" << std::endl;

  _configSim.Start(_routes);

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "*************************/" << std::endl;

  for (int i = 0; i < simLength; i++) {
    _configSim.Update();
  }

  std::cout << "/*************************" << std::endl << std::endl;
  std::cout << "        SIMULATION" << std::endl;
  std::cout << "         COMPLETE" << std::endl;
  std::cout << "*************************/" << std::endl;


  return 0;
}
