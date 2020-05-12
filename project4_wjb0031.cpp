//  William Baldwin
//  wjb0031
//  project4_wjb0031.cpp
//  Project_4
//
//  got help from Marco Gonzalez
//  and my brother(for helping with some of the functions).
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <locale>
#include <cstdlib>
#include <assert.h>
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// Trivia Node
////////////////////////////////////////////////////////////////////////////////
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;
};

trivia_node* NewTriviaNode(string question, string answer, int point) {
  trivia_node* newTriviaNode = new trivia_node();
  newTriviaNode->question = question;
  newTriviaNode->answer = answer;
  newTriviaNode->point = point;
  return newTriviaNode;
}

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////
void init_question_list(trivia_node* q_list);
void Unit_Test();
void add_question(trivia_node* q_list);
void add_questions(trivia_node* q_list);
int ask_question(trivia_node* q_list, int num_ask);
int ask_questions(trivia_node* q_list, int num_ask);

////////////////////////////////////////////////////////////////////////////////
// Helpers
////////////////////////////////////////////////////////////////////////////////
void GetInput(string& input) {
  if (cin.peek() == '\n') {
    cin.ignore();
  }
  getline(cin, input);
}

////////////////////////////////////////////////////////////////////////////////
// List
////////////////////////////////////////////////////////////////////////////////

trivia_node* NewList() {
  return new trivia_node();
}

void Push(trivia_node* list, trivia_node* nextNode) {
  // Part 1: is list null?
  if (list == NULL) {
    return;
  }
  // Part 2: find last node in list
  trivia_node* current = list;
  while (current != NULL && current->next != NULL) {
    current = current->next;
  }
  // Part 3: add next node to end of list
  current->next = nextNode;
}

int Length(trivia_node* list) {
  if (list == NULL){
    return -1;
  }
  int count = 0;
  trivia_node* current = list;
  while (current != NULL){
    current = current->next;
    count++;
  }
  return count - 1;
}

trivia_node* Get(trivia_node* list, int position) {
  int count = 0;
  trivia_node* current = list;
  while (count != position + 1){
    if (current == NULL) {
      return NULL;
    }
    current = current->next;
    count++;
  }
  return current;
}

////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////

//uncomment to change modes
 #define trivia_quiz
//#define UNIT_TESTING

int main() {
#ifdef trivia_quiz
    trivia_node* node_list = NewList();
    init_question_list(node_list);
    cout << "*** Welcome to William's trivia quiz game ***\n";
    add_questions(node_list);
    ask_questions(node_list, Length(node_list));
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
#endif
#ifdef UNIT_TESTING
    Unit_Test();
#endif

  return 0;
}

void init_question_list(trivia_node* q_list) {
    Push(q_list,
      NewTriviaNode(
        "How long was the shortest war on record?",
        "38",
        100));

    Push(q_list,
      NewTriviaNode(
        "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)",
        "Bank of Italy",
        50));

    Push(q_list,
      NewTriviaNode(
        "What is the best selling game of all time? (Hint: Wii Sports or Call of Duty)? ",
        "Wii Sports",
        20));
}

void add_question(trivia_node* q_list) {
  trivia_node* new_ptr = new trivia_node();
  // Part 1: Get question
  cout << "Enter a new question: ";
  GetInput(new_ptr->question);
  // Part 2: Get answer
  cout << "Enter an answer: ";
  GetInput(new_ptr->answer);
  // Part 3: Get points
  cout << "Enter award points: ";
  string point;
  GetInput(point);
  new_ptr->point = atoi(point.c_str());
  // Part 4: Push
  Push(q_list, new_ptr);
}

void add_questions(trivia_node* q_list) {
  string user_decision;
  bool shouldKeepRunning = true;
  while (shouldKeepRunning == true){
      add_question(q_list);
      do {
        cout << "Continue? (Yes/No): ";
        GetInput(user_decision);
        if (user_decision == "No"|| user_decision == "Yes") {
          if (user_decision == "No") {
            shouldKeepRunning = false;
            break;
          }
          break;
        } else {
          cout << "Please enter Yes or No!";
        }
      } while(true);
  }
}

int ask_question(trivia_node* q_list, int num_ask) {
  string user_answer;
  trivia_node* cur_ptr = Get(q_list, num_ask);
  cout << "\nQuestion: " << cur_ptr->question << "\n";
  cout << "Answer: ";
  GetInput(user_answer);
  if (user_answer == cur_ptr->answer) {
    cout << "Your answer is correct. You receive " << cur_ptr->point << " points." << endl;
    return cur_ptr->point;
  }
  else {
      cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
  }

  return 0;
}

int ask_questions(trivia_node* q_list, int num_ask) {
  int length = Length(q_list);
  if (length < 1)
    return 0;
  if (num_ask < 1) {
    cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
      return -1;
  } else if (length < num_ask) {
    cout << "Warning - There is only " << length << " trivia in the list.";
      return -2;
  } else {
    int points = 0;
    for(int i = 0; i < num_ask; i++) {
      points += ask_question(q_list, i);
      cout << "Your Total points: " << points << endl;
    }
    return points;
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// Unit Tests
////////////////////////////////////////////////////////////////////////////////

void Unit_Test() {
  trivia_node* node_list = NewList();
  init_question_list(node_list);

  cout << "*** This is a debugging version ***\n";
  cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
  assert(ask_questions(node_list, 0) == -1);
  cout << "\nCase 1 Passed\n\n";

  cout << "Unit Test Case 2.1: Ask 1 question in the linked list.  The tester enters an incorrect answer." << endl;
  assert(ask_questions(node_list, 1) == 0);
  cout << "\nCase 2.1 Passed\n\n";

  cout << "Unit Test Case 2.2: Ask 1 question in the linked list.  The tester enters an correct answer." << endl;
  assert(ask_questions(node_list, 1) == 100);
  cout << "\nCase 2.2 Passed\n\n";

  cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
  ask_questions(node_list, Length(node_list));
  // is points equal to X?
  cout << "\nCase 3 Passed\n\n";

  cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    assert(ask_questions(node_list, 5) == -2);
  cout << "\nCase 4 Passed\n\n";

  cout << "\n\n*** End of the Debugging Version ***";
}

