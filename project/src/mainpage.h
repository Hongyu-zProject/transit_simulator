/**
 * @file mainpage.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage CSCI3081w
 *
 * \section intro_sec Introduction
 *
 * \section this Iteration for csci3081w_f19.
 * \section User Guide:
 * The purpose of designing this software project is to simulate a transit process. This simulation can be displayed through a graphics window and designed to have controls through external configuration without alternating any code.
In this project, we  will put all the pieces in place for development including base code, unit tests with Google Test, class structure, Google style guide compliance, design documentation using UML, doxygen documentation, Git usage, and self-documenting code (i.e. good organization and naming conventions).
What we did in the second iteration are about configuration and visual simulation. We added a few new elements to our design from above so that it allows for configuration and visualization of our simulations. Most of the code has already been designed and implemented. The primary task is to extend our domain elements to produce the data needed for visualization and merging the provided configuration and visualization code.
Thus all we needed to modify are the files including configuration files and simulation files and makefiles. \n
 * \section What you will learn:
 * 1.Basic Linux commands that needed to run this project\n
 * 2.How to clone, pull and push\n
 * 3.How to run simulations \n
 * 4.How to run tests\n
 * \n
 * \section Basic commands:
 * First you will need to check if your computer has git installed. You can check this by simply open your terminal and type in the following command:\n
 * \n
 * $git --version \n
 * \n
 * This will establish if it is installed.\n
 * \n
 * $git config --global user.name “Your Name” \n
 * $git config --global user.email your_email \n
 * \n
 * These commands set the configuration to know what identification to use. Be awe of that the name appears between double quotes since it has spaces in it. Your email on the second is the email address. \n
 * \section Clone, pull and push:
 * In order to clone the project code, you first need to know where to clone from. Open your browser and enter the following URL:\n
 * https://github.umn.edu/umn-csci-3081-f19/repo-zhu00091 \n
 * Note that the account currently is in private mode due to the class requirements.\n
 * When you are successfully in this repository page, you should see a green button above the list of files called “Clone or download”. Under “Clone or download”, ensure that HTTPS is selected and click on the copy icon on the far right. This will copy the repository reference to the clipboard. We will refer this url as <clone_URL>. Next, you can clone the repository from the remote Github to your own local workspace. \n
 * Now we need to clone the project to your local machine so that you can view or modify the code as you prefer.\n
 * Go back to your terminal. Choose a location where you want to store the files. Then create a Transit Simulator directory with any name you prefer, and move into that directory. Then clone your individual repo into this directory. Replace <clone_URL> below with the repository reference we copied earlier. \n
 * \n
 * $(optional) cd <clone_URL> \n
 * $mkdir Transit Simulator \n
 * $cd Transit Simulator \n
 * $ git clone <clone_URL> \n
 * $ls \n
 * \n
 * You just made a new directory in your account by using mkdir. Then you move into that directory using cd. Then you clone the url reference which you put in the <clone_URL> to your local machine. Using ls, you are able to view the list of the newly created directory with the name of the repository which it contains. These directories function exactly like all other linux directories. There are hidden files that track changes to the repository.\n
 * \n
 * To add changes to the repository both locally and on the server, you will need to stage all the changes first. This will prepare the changes to be permanently part of the repository. When you do the commit on those changes, they will be saved to your local repository, which lives in your account. When you push, your changes will be copied to the repository on the server. Then difference between the commit and push is what separates git from centralized version control systems. \n
 * \n
 * $git add * \n
 * $git commit -m “Any comment.” \n
 * $git push \n
 * \n
 * You just stage all the changes you made by using add *.  Please be awe of that the add does not mean you are adding a new file or a new directory, it only means you are adding a change. Then the staged changes you just added are committed to your local repository and tagged with the comment you put in “Any comment.” followed with -m. Finally, the changes are pushed to the server.\n
 * If your local repository is not the latest version, you could simply use the following command to get your local repository updated. \n
 * \n
 * $git pull \n
 * $ls \n
 * \n
 * Please perform a pull every time before making changes to a repository. It is an excellent idea to make a habit.\n
 * The basic setup is completed.\n
 * \n
 * \section Run simulations:
 * Now in order to compile the code, you will need to navigate to base project directory(project/). \n
 * \n
 * $cd project/ \n
 * \n
 * Then navigate to src folder. \n
 * \n
 * $cd src/ \n
 * \n
 * After successfully navigating to the src file, you can choose to compile in one of the following methods as you desire. \n
 * \n
 * $make \n
 * \n
 * The make command searches for the first target listed in the makefile and execute that command. I have modified the makefile so that when you simply make, it will execute both configuration simulation(config_sim) and visual simulation(vis_sim). \n
 * If you want only one of the two simulations to execute, then you can try either of the following: \n
 * \n
 * $make config_sim \n
 * or \n
 * $make vis_sim \n
 * \n
 * To start the server for visual sim: \n
 * \n
 * $cd .. \n
 * $./build/bin/vis_sim <port_number> \n
 * \n
 * Note that you must run by doing ./build/bin/<sim executable> <port_number>. You cannot cd to bin/ and run ./<sim executable> <port_number>. \n
 * <port_number> can be anything. Try and pick numbers above 8000 and not multiples of 10. \n
 * Then open your browser and navigate to the following address on your local machine: \n
 * http://127.0.0.1:<port_number>/web_graphics/project.html \n
 * To run configuration simulation you will do similar to above: \n
 * \n
 * $ls \n
 * \n
 * Check if you are in the project directory, note that you should not execute the following command if you are not in project directory. \n
 * \n
 * $./build/bin/config_sim <config_filename> \n
 * \n
 * <config_filename> should be a configuration file under the config folder in txt format. So far there is already a file named config.txt which is set as default file to open when executing the command above. \n
 * Note that if you run the command without <config_filename> or with a file name that does not exist under config folder, then it will use config.txt as default file. \n
 * \n
 * \section Run tests:
 * $cd tests \n
 * $make \n
 * $../build/bin/unittest \n
 * Navigate to tests folder, then execute the command make.  After that, you can navigate to the bin folder under build and execute test by running ./unittest. \n
 * \n
 * Developer Guide:\n
 * The purpose of designing this software project is to simulate a transit process. This simulation can be displayed through a graphics window and designed to have controls through external configuration without alternating any code.\n
 * For this specific iteration, we  will put all the pieces in place for development including base code, unit tests with Google Test, class structure, Google style guide compliance, design documentation using UML, doxygen documentation, Git usage, and self-documenting code (i.e. good organization and naming conventions). \n
 * In the first iteration, we will limit the simulation to a single scenario involving campus transit via bus here at the University of Minnesota. Describing in a big picture, we simulate a bus which will have two routes--incoming route and outgoing route. Each route has a list of stops. When the bus arrives at the stop, we will have functions to unload passengers and load passengers from the stop. \n
 * The UML diagram in the following shows how each class connects to each other:\n
 * \image html UML_FINAL_1.png
 * \n
 * So far, we only need to modify classes including bus, passenger, stop and route since all other files are given. \n
 * For class Bus, we have functionalities such as bus, load passenger,unload passenger, move, update, report, and is trip complete. Function bus as its own constructor, it simply returns the name, outcoming route, incoming route, passenger max capacity, speed, distance remaining. Function load passenger is a boolean function. It returns if the bus is full and decide whether load passenger should be set to true. Function move is also a boolean function, it checks if the bus moved. Then find out which direction the bus is going and point to the next stop. Finally subtract the distance from current stop to next stop so the bus is able to move. Update function calls the move function whenever updated. The last function is report which returns the information including name, speed, distance to the next stop and the amount of passengers.\n
 * For class Passenger, we have constructors such as passenger, update, get on bus, get total wait, is on bus, get destination and report. Function passenger as its own constructor, it returns name destination stop id, wait at stop, time on bus and id. And both wait at stop and time on bus are initialized, while passenger count add one more. Constructor update for passenger check if the passenger is on the bus. If passenger is on the bus, then time on the bus gets to increase. If not, then it means the passenger is waiting at the stop and waiting time will increase. Constructor get on bus checks if passenger is currently on the bus, then return time on bus. Constructor get total wait returns the combination of waiting time and time on the bus. Constructor is on bus simply checks if passenger is on the bus by checking time on the bus.Constructor get destination returns the destination stop id. The last constructor is report which prints out the information including name, destination, total wait, wait at stop, time on bus.\n
 * For class Stop, we have constructor stop, add passenger, adding passenger, update, get id, and report. Function stop as its own constructor, it returns its id, longitude and latitude. I didn’t find longitude and latitude helpful in my case. Maybe they are meant for the project in the future. Constructor add passenger adds passengers to passenger list at the stop. Constructor adding passenger checks whether there’s passengers at the stop. If yes, then it will call function to load passengers to the bus and then erase the passengers at the stop as they are already on the bus. Constructor update updates the passenger list. Constructor get id returns the stop id. Then the usual report constructor prints out the id and passengers waiting at the stop.\n
 * For class Route, we have constructor route, clone, update, report, is at end, next stop, get destination stop, etc. Constructor route generates a list of stops and distance between them. Constructor clone’s functionality is to clone a route. Constructor update simply updates the stop list. Constructor report prints out name and number of stops.\n
 * \n
 * In additional to the iteration1, we added more functionalities beyond that. we need to add a few new elements to our design in order to allow for configuration and visualization of our simulations. Much of this has already been designed and implemented. The primary task will be to extend the domain elements to produce the data needed for visualization and merging the provided configuration and visualization code into the previous project code.\n
 * According to the new data sturct file, we added more functions to class route, bus, stop.\n
 * In the bus class, we implemented UpdateBusData, GetBusData, GetName, GetNextStop, GetNumPassengers, GetCapacity.\n
 * In the route class, we implemented GetName, GetStops, UpdateRouteData, GetRouteData.\n
 * In the stop class, we implemented GetLongitude, GetLatitude, GetCurrP.\n
 * We also modified make file in the src directory in order to make config_sim and vis_sim compile successfully. \n
 * You can follow the user guide above to clone and run the code. \n
 */
#endif  // SRC_MAINPAGE_H_
