
// Football_Scoreboard_Richardson_ Milton
// Dr.T, COSC 1437-58001, Oct-30-2019

/*
   Input Validation with Ref Functions
   A cleaner way to do input validation
   Validating input, an essential process.
   Source:
   http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
   Keeping Dr. McMillan from breaking my code, defend against "dark side of the
   force", and/or legitimate user error.
   //Try and Catch blocks are used in error checking
   Teacher: Dr. Tyson McMillan
*/
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream> // Provides cout, cerr, endl
// Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include <sstream> //for string manipulation and comparison
#include <string>  //for string manipulation
using namespace std;

// Classes for Team & Scoreboard ******

class Team {
private:
	string Name;
	string coachName;
	string homeCity;
	bool homeStatus;
	int score;
	int teamQTR;
	int timeoutCount;
	int newScore;
  string newName;
  string newCouch;
  string newHomeCity;
  string newHomeCity2;

public:
	void setName(string n) {Name = n;}
	string getName() const {return Name;}

	void setcoachName(string cn) {coachName = cn;}
	string getcoachName() const {return coachName;}

	void sethomeCity(string hc) {homeCity = hc;}
	string gethomeCity() const {return homeCity;}

	void sethomeStatus(bool hs) {homeStatus = hs;}
	bool gethomeStatus() const {return homeStatus;}

	void setscore(int s) {score = s;}
	int getscore() const {return score;}

	void setteamQTR(int tf) {teamQTR = tf;}
	int getteamQTR() const {return teamQTR;}

	void settimeoutCount(int tc) {timeoutCount = tc;}
	int gettimeoutCount() const {return timeoutCount;}

	void setnewScore(int ns) {score = ns;}
	int getnewScore() {return newScore;}
  
  void setnewName(string nn){
    newName = nn; 
  }
  string getnewName() {
    return newName;
  }
  void setnewCouch(string nc){
    newCouch = nc; 
  }
  string getnewCouch() {
    return newHomeCity;
  }
  void setnewHomeCity(string hc){
    newHomeCity = hc; 
  }
  string getnewHomeCity() {
    return newHomeCity;
  }
  void setnewHomeCity2(string hc){
    newHomeCity = hc; 
  }
  string getnewHomeCity2() {
    return newHomeCity2;
  }
};

class Scoreboard {
private:
	Team t1; // Allows Acces to class Team
	Team t2; // Allows Acces to class Team
	int period = 0, hasBall = 0;
	bool bonus; // probably an IF statement for this

public:
	Scoreboard() {
		int s = 0;

		period = 0;
		hasBall = 0;   // we can build a IF statment for this
		bonus = false; // set up a IF statement for update.

		t1.setName("Muppets");
		t1.setcoachName("Kermit the Frog");
		t1.sethomeCity("Mississippi");
		t1.sethomeStatus(true);
		t1.setscore(0);
		t1.setteamQTR(0);
		t1.settimeoutCount(0);

		t2.setName("Loony Tunes");
		t2.setcoachName("Bugs Bunny");
		t2.sethomeCity("New York");
		t2.sethomeStatus(false);
		t2.setscore(5);
		t2.setteamQTR(0);
		t2.settimeoutCount(0);
	}

	void sett1(Team tea1) {
		t1 = tea1;
	}
	Team gett1() const {
		return t1;
	}

	void sett2(Team tea2) {
		t2 = tea2;
	}
	Team gett2() const {
		return t2;
	}

	// Update code for Team 1 *********************
	void setScore() // Update Score ********
	{
		int newScore = 0;
		cout << "Enter New Score: " << endl;
		newScore = validateInt(newScore);
		t1.setscore(newScore);
	}

	void setteamQTR() // Update Team QTR ****
	{
		int newQTR = 0;
		cout << "Enter Total Team QTR: " << endl;
		newQTR = validateInt(newQTR);
		t1.setteamQTR(newQTR);
	}

	void settimeOuts() // Update Time Outs ******
	{
		int newtimeOuts = 0;
		cout << "Enter Total Time Outs: " << endl;
		newtimeOuts = validateInt(newtimeOuts);
		t1.settimeoutCount(newtimeOuts);
	}
	// Update code for Team 2 ***********************
	void setScore2() // Update Score ********
	{
		int newScore = 5;
		cout << "Enter New Score: " << endl;
		newScore = validateInt(newScore);
		t2.setscore(newScore);
	}

	 void setName() // Update Team Fouls ****
	 {
	 	string newName = "" ;
	 	cout << "Enter a New Team Name: " << endl;
		newName = validateString(newName);
		t1.setName(newName);
	 }
   	 void setName2() // Update Team Fouls ****
	 {
	 	string newName2 = "" ;
	 	cout << "Enter a New Team Name: " << endl;
		newName2 = validateString(newName2);
		t2.setName(newName2);
	 }
	 void setCouch() // Update Team Fouls ****
	 {
	 	string newCouch = "" ;
	 	cout << "Enter a New Team Couch: " << endl;
		newCouch = validateString(newCouch);
		t1.setcoachName(newCouch);
	 }
   	 void setCouch2() // Update Team Fouls ****
	 {
	 	string newCouch2 = "" ;
	 	cout << "Enter a New Team Couch: " << endl;
		newCouch2 = validateString(newCouch2);
		t2.setcoachName(newCouch2);
	 }
   void setnewHomeCity() // Update Team Fouls ****
	 {
	 	string newHomeCity = "" ;
	 	cout << "Enter a New Home City: " << endl;
		newHomeCity = validateString(newHomeCity);
		t1.sethomeCity(newHomeCity);
	 }
   	 void setHomeCity2() // Update Team Fouls ****
	 {
	 	string newHomeCity2 = "" ;
	 	cout << "Enter a New Home City: " << endl;
		newHomeCity2 = validateString(newHomeCity2);
		t2.sethomeCity(newHomeCity2);
	 }
	 

	void settimeOuts2() // Update Time Outs ******
	{
		int newtimeOuts = 0;
		cout << "Enter Total Time Outs: " << endl;
		newtimeOuts = validateInt(newtimeOuts);
		t2.settimeoutCount(newtimeOuts);
	}

	//**************TEAM 1 INFO*****************
	void showTeam1() {
		bool loc;

		cout << "\nTEAM " << t1.getName() << " INFO: " << endl;
		cout << "Coach: " << t1.getcoachName() << endl;
		cout << "Home City: " << t1.gethomeCity() << endl;
		//***********delete comments after completion*****
		loc = (t1.gethomeStatus() == true)
			? " HOME "
			: "AWAY "; 

		cout << "Location: " << loc << endl;
		cout << "Score: " << t1.getscore() << endl;
		cout << "Team QTR: " << t1.getteamQTR() << endl;
		cout << "TimeOuts: " << t1.gettimeoutCount() << endl;
	}
	//******TEAM 2 INFO ***********************
	void showTeam2() {
		bool loc;

		cout << "\nTEAM " << t2.getName() << " INFO: " << endl;
		cout << "Coach: " << t2.getcoachName() << endl;
		cout << "Home City: " << t2.gethomeCity() << endl;
		//***********delete comments after completion*****
		loc = (t2.gethomeStatus() == true)
			? " HOME "
			: "AWAY "; // I can't get this code to work correctly
					   // *********************

		cout << "Location: " << loc << endl;
		cout << "Score: " << t2.getscore() << endl;
		cout << "Team QTR: " << t1.getteamQTR() << endl;
		cout << "TimeOuts: " << t2.gettimeoutCount() << endl;
	}
	void menuTeam1() {
		int o = 0;
		cout << "\nMENU to UPDATE TEAM 1 INFO: " << t1.getName() << endl;
    string color = "";
    string reset = "\x1b[m";
    color = "\x1b[" + to_string(93) + ";1m";
		cout << color << "1.) Team 1: Score" << endl;
		cout << "2. Team 1: Team QTR " << endl;
		cout << "3. Team 1: Time Outs " << endl;
    cout << "4. Team 1: Team Name " << endl; 
    cout << "5. Team 1: Team Couch " << endl; 
    cout << "6. Team 1: Home City " << endl; 
    cout << "7. Exit\n" <<  reset << endl; 

		o = validateInt(o); // Input from User *****

		if (o == 1) {
			setScore();
		} else if (o == 2) {
			setteamQTR();
		} else if (o == 3) {
			settimeOuts();
      }else if (o == 4) {
			setName(); 
      }else if (o == 5) {
			setCouch(); 
      }else if (o == 6) {
			setnewHomeCity(); 
      }else if (o == 7)
      {
        
cout << "Thats all folks" << endl; 
      }
		else {
			cout << "\nError Something Went Wrong! " << endl;
		}
		// Clear screen before refresh *************
		cout << "\033[2J\033[1;1H";
	}

	void menuTeam2() {
		int o = 0;
		cout << "\nMENU to UPDATE TEAM 2 INFO: " << t2.getName() << endl;
    string color = "";
    string reset = "\x1b[m";
    color = "\x1b[" + to_string(94) + ";1m";
		cout << color << "1. Team 2: Score" << endl;
		cout << "2. Team 2: Team QTR " << endl;
		cout << "3. Team 2: Time Outs " << endl;
    cout << "4. Team 2: Team Name " << endl; 
    cout << "5. Team 2: Team Couch " << endl; 
     cout << "6. Team 2: Home City " << endl; 
    cout << "7. Exit\n "<<  reset  << endl; 

		o = validateInt(o); // Input from User ******

			if (o == 1) {
			setScore2();
		} else if (o == 2) {
			setteamQTR();
		} else if (o == 3) {
			settimeOuts2();
      }else if (o == 4) {
			setName2(); 
      }else if (o == 5) {
			setCouch2(); 
      }else if (o == 6) {
			setHomeCity2(); //bug
      }else if (o == 7)
      {
        
cout << "Thats all folks" << endl; 
      }
		else {
			cout << "\nError Something Went Wrong! " << endl;
		}
		// Clear screen before refresh *************
		cout << "\033[2J\033[1;1H";
	}
	void updateTeaminfo() {
		int option = 0, i = 0, o = 0;
    string color = "";
    string reset = "\x1b[m";
    color = "\x1b[" + to_string(92) + ";1m";
		cout << color << "\nWhat would you like to update? " << reset << endl;
    color = "\x1b[" + to_string(93) + ";1m";
		cout << color << "1. Team 1: " << t1.getName() << reset << endl;
    color = "\x1b[" + to_string(94) + ";1m";
		cout << color << "2. Team 2: " << t2.getName() << reset << endl;
        color = "\x1b[" + to_string(95) + ";1m";
		cout << color << "3. Scoreboard Info " << reset << endl;
    color = "\x1b[" + to_string(96) + ";1m";
    cout << color << "4. Exit " << reset << endl; 
		option = validateInt(option);

		if (option == 1) {
			menuTeam1();
		} else if (option == 2) {
			menuTeam2();
		} else if (option == 3) {
		} 
    else if ( option == 4)
      {
cout << "Thats all folks"  << endl; 
      }
    else {
			cout << "\nError Something went wrong!" << endl;
		option = validateInt(option);
		}
	}
  void displayBoard()
  {
     string color = "";
    string reset = "\x1b[m";
    color = "\x1b[" + to_string(91) + ";1m";
    cout << color << "\n           Football Scoreboard        " << reset << endl; 
    cout << "          " << t1.gethomeCity() << " vs " << t2.gethomeCity() << endl; 
    cout << "-------------------------------------------" << endl;
    cout << "Couch: " << t1.getcoachName() << "   " << "Couch: " << t2.getcoachName() << endl; 
    cout << "-------------------------------------------" << endl; 
    cout << "Team 1: " << t1.gethomeCity() << "--------" << "Team 2: " << t2.gethomeCity() << endl;
    cout << "Score" << "                                 " << "Score" << endl; 
    cout << "" << "[" << t1.getscore() << "]" << "                                    " << "[" << t2.getscore()<< "]" << endl;
    
    cout << "--------------------------------------------" << endl;
    cout << "                     " << "QTR " << t1.getteamQTR() << endl; 
     cout << "--------------------------------------------" << endl;
     cout << "Location: " << t1.gethomeStatus() << "                    " << "Location: " << t2.gethomeStatus() << endl;
     cout << "--------------------------------------------" << endl;
      cout << "TimeOuts: " << t1.gettimeoutCount() << "                    " << "TimeOuts: " << t2.gettimeoutCount() << endl;
      cout << "--------------------------------------------" << endl;
    
  }
  

}; // End of class Scoreboard **************



//*******************Int Main********************
int main() {
	// Local Variables ******
	Scoreboard s;
	int option = 0;
  Team t1;


 
	do {
     
    s.displayBoard(); 
		s.updateTeaminfo();
    	//s.showTeam1();
		//s.showTeam2();
   

	} while (option != 7); // tried making this a == 4 but that broken the loop.. 

	/*Need a loop that refreshes the Scoreboard (updated) and then displays the
	 * menu again*/
cout << "\033[2J\033[1;1H" << endl; 
	cout << "\nThats all folks!!! " << endl; // porky pig

	return 0;
}

