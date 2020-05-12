//  William Baldwin
//  wjb0031
//  project2_wjb0031.cpp
//  Project_2
//
//  Got help from Marco Gonzalez.
//  my brother(for checking over my code).
// Got help from stackoverflow for srand.
// Got help from my brother Rob with testing, while loop,and some other methods.
//  Created by William Baldwin on 1/31/20.
//  Copyright © 2020 William Baldwin. All rights reserved.
//

#include <iostream>

#include <stdlib.h>

#include <assert.h>

#include <ctime>

using namespace std;

//Constants
const int shot_chance = 6;
const int aaron_shot_chance = 2;

// Method tests to see if at least two are alive for the duel to keep going.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive) ) {
        return true;
    }
    return false;
}
 


// Method tests Aarons first straegy, which is to shoot first and see if it hits someone.
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    int shoot_target_result;
    shoot_target_result = rand()% shot_chance;
    if (B_alive == false && shoot_target_result < aaron_shot_chance) {
       C_alive = false;
      return;
    }
    if (C_alive == false && shoot_target_result < aaron_shot_chance) {
       B_alive = false;
        return;
    }
    if (C_alive == true && shoot_target_result < aaron_shot_chance) {
       C_alive = false;
        return;
    }
    
}


//Method tests whether Bob is able to hit someone in the duel.
void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shoot_target_result;
    shoot_target_result = rand()% shot_chance;
    if (C_alive == false && shoot_target_result < 3) {
        A_alive = false;
        return;
    }
    if (C_alive == true && shoot_target_result < 3) {
        C_alive = false;
        return;
    }
    
}

// Method tests if charlie hits someone.
void Charlie_shoots(bool& A_alive, bool& B_alive) {
    if (B_alive == false) {
        A_alive = false;
        return;
    }
    if (B_alive == true) {
        B_alive = false;
            return;
       }
    
}

// Method is for Aarons second strategy, which is to intentionally miss first.
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
  int shoot_target_result;
  shoot_target_result = rand()% shot_chance;
 if (B_alive == true && C_alive == true) {
       C_alive = true;
       B_alive = true;
     return;
    }
  if (B_alive == false && shoot_target_result < aaron_shot_chance) {
     C_alive = false;
      return;
  }
  if (C_alive == false && shoot_target_result < aaron_shot_chance) {
     B_alive = false;
      return;
  }
    
}

//Method is made for the user to press enter to advance the code.
void pressEnter(void) {
cout << "Press any key to continue...\n\n";
cin.ignore().get();
}

//Method is for testing the first method to see if two are alive.
void test_at_least_two_alive(void) {
cout << "Unit Testing 1: Function - at_least_two_alive()\n";
cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";
cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";
cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";
cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";
cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";
cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";
cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";
cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

//Method is used to test who Aaron will be shooting at.
void test_Aaron_shoots1(void) {
cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    bool b_alive = true;
    bool c_alive = true;
cout << "\tCase 1: Bob alive, Charlie alive\n";
cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(b_alive, c_alive);
    assert(b_alive == true);

     b_alive = false;
     c_alive = true;
cout << "\tCase 2: Bob dead, Charlie alive\n";
cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(b_alive, c_alive);
    assert(true == c_alive || false == c_alive);
    
    b_alive = true;
    c_alive = false;
cout << "\tCase 3: Bob alive, Charlie dead\n";
cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(b_alive, c_alive);
    assert(true == b_alive || false == b_alive);
}

//Method is used to see who Bob will be aiming at.
void test_Bob_shoots(void) {
cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

bool a_alive = true;
bool c_alive = true;
cout << "\tCase 1: Aaron alive, Charlie alive\n";
cout << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(a_alive, c_alive);
    assert(true == a_alive);
  
    a_alive = false;
    c_alive = true;
cout << "\tCase 2: Aaron dead, Charlie alive\n";
cout << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(a_alive, c_alive);
    assert(true == c_alive || false == c_alive);
   
    
    a_alive = true;
    c_alive = false;
cout << "\tCase 3: Aaron alive, Charlie dead\n";
cout << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(a_alive, c_alive);
    assert(true == a_alive || false == a_alive);
    
}

//Method is used to see who Cahrlie will be shhoting at.
void test_Charlie_shoots(void) {
cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

bool a_alive = true;
bool b_alive = true;
cout << "\tCase 1: Aaron alive, Bob alive\n";
cout << "\t\tCharlie is shooting at Bob\n";
Charlie_shoots(a_alive, b_alive);
assert(false == b_alive);
   
    a_alive = false;
    b_alive = true;
cout << "\tCase 2: Aaron dead, Bob alive\n";
cout << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(a_alive, b_alive);
    assert(false == b_alive);

    a_alive = true;
    b_alive = false;
cout << "\tCase 3: Aaron alive, Bob dead\n";
cout << "\t\tCharlie is shooting at Aaron\n";
Charlie_shoots(a_alive, b_alive);
assert(false == a_alive);
    
}

//Method tests Aarons second strategy in duel.
void test_Aaron_shoots2(void) {
cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    bool b_alive = true;
    bool c_alive = true;
cout << "\tCase 1: Bob alive, Charlie alive\n";
cout << "\t\tAaron intentionally misses his first shot\n";
cout << "\t\tBoth Bob and Charlie are alive.\n";
    Aaron_shoots2(b_alive, c_alive);
   assert(true == b_alive && true == c_alive);

    b_alive = false;
    c_alive = true;
cout << "\tCase 2: Bob dead, Charlie alive\n";
cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(b_alive, c_alive);
    assert(true == c_alive || false == c_alive);
    
    
    b_alive = true;
    c_alive = false;
cout << "\tCase 3: Bob alive, Charlie dead\n";
cout << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots2(b_alive, c_alive);
   assert(true == b_alive || false == b_alive);
}
 

//Constant
const int total_number_of_runs = 10000;

// Main method is being used to showcase the data.
int main(int argc, const char * argv[]) {
    
//Variables
int aaronwins1 = 0;
int bobwins = 0;
int charliewins = 0;
int aaronwins2 = 0;
srand((unsigned)time(0));
cout << "*** Welcome to William's Duel Simulator ***\n" ;
test_at_least_two_alive();
    pressEnter();
test_Aaron_shoots1();
    pressEnter();
test_Bob_shoots();
    pressEnter();
test_Charlie_shoots();
    pressEnter();
test_Aaron_shoots2();
    pressEnter();
    
cout << "Ready to test strategy 1 (run 10000 times): \n";
pressEnter();
    
           
    for (int i = 0; i < total_number_of_runs ; i++) {
        bool aaronAlive = true;
        bool bobAlive = true;
        bool charlieAlive = true;
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if(aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
            }
            if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
            }
        
        }
        
    if (aaronAlive) {
        aaronwins1++;
    }
    if (bobAlive) {
       bobwins++;
    }
    if (charlieAlive) {
    charliewins++;
    
    }
    }
    cout << "Aaron won " << aaronwins1 << "/10000 duels or " <<
    static_cast<double>(aaronwins1)/total_number_of_runs  * 100 << "%\n";
    
    cout << "Bob won " << bobwins << "/10000 duels or " <<
    static_cast<double>(bobwins)/total_number_of_runs  * 100 << "%\n";
    
    cout << "Charlie won " << charliewins << "/10000 duels or " <<
    static_cast<double>(charliewins)/total_number_of_runs  * 100 << "%\n";
    
    
    
    cout << "\nReady to test strategy 2 (run 10000 times): \n";
    pressEnter();
    
    // Reinitialize variables
     bobwins = 0;
     charliewins = 0;
    
    for (int i = 0; i < total_number_of_runs ; i++) {
        bool aaronAlive = true;
        bool bobAlive = true;
        bool charlieAlive = true;
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if(aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
            }
            if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
            }
        
        }
        
    if (aaronAlive) {
        aaronwins2++;
    }
    if (bobAlive) {
       bobwins++;
    }
    if (charlieAlive) {
    charliewins++;
    
    }
    }
    
    cout << "Aaron won " << aaronwins2 << "/10000 duels or " <<
       static_cast<double>(aaronwins2)/total_number_of_runs  * 100 << "%\n";
       
       cout << "Bob won " << bobwins << "/10000 duels or " <<
       static_cast<double>(bobwins)/total_number_of_runs  * 100 << "%\n";
       
       cout << "Charlie won " << charliewins << "/10000 duels or " <<
       static_cast<double>(charliewins)/total_number_of_runs  * 100 << "%\n";
    
    if (aaronwins1 < aaronwins2) {
        cout << "\nStrategy 2 is better than strategy 1.\n";
    }
    else {
        cout << "\nStrategy 1 is better than strategy 2.\n";
        
    }
    return 0;
}


