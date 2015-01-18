/*
 * BeatThat.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: Alan Chen
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  srand (time(NULL));
  char input;
  char cont;
  float change = 0;
  int hscore = 10;
  int cscore = 10;


  cout << "Welcome to Beat That++!" << endl;
  while ((hscore >= 0) && (cscore >= 0)) {
    int num1 = rand() % 6 + 1;
    int num2 = rand() % 6 + 1;
    int csum = 0;
    int num3 = rand() % 6 + 1;
    int num4 = rand() % 6 + 1;
    int hsum = 0;

    if (num1 >= num2) {
      csum = num1 * 10 + num2;
    }
    else if (num1 < num2) {
      csum = num2 * 10 + num1;
    }
    cout << "Computer rolled " << num1 << " and " << num2 << ", so score is " << csum << "..." << endl;
    cout << "You rolled " << num3 << ", roll again? ";

    do {
      cin >> input;
      if ((input == 'y') || (input == 'Y')) {
	    if (num3 >= num4) {
	      hsum = num3 * 10 + num4;
	    }
	    else if (num3 < num4) {
		  hsum = num4 * 10 + num3;
	    }
	    cout << "You rolled " << num3 << " and " << num4 << ", so score is " << hsum << "... ";
      }
      else if ((input == 'n') || (input == 'N')) {
	    hsum = num3 * 10 + num3;
	    cout << "You rolled " << num3 << " and " << num3 << ", so score is " << hsum << "... ";
      }
      else {
	    cout << "** Oops type 'y/Y' or 'n/N' ";
      }
    } while ((input != 'y') && (input != 'Y') && (input != 'n') && (input != 'N'));

    if (hsum == csum) {
	  cout << "tied..." << endl;
	  cout << "You have $" << hscore << ", computer has $" << cscore << endl;
    }
    if (hsum > csum){
	  change = (hsum - csum) * .1;
	  change = round(change);
	  hscore = hscore + change;
	  cscore = cscore - change;
	  cout << "You won $" << change << "..." << endl;
	    if (cscore <= 0) {
		  cscore = 0;
		  hscore = 20;
		  break;
	    }
	  cout << "You have $" << hscore << ", computer has $" << cscore << endl;
    }

    if (hsum < csum) {
	  change = (csum - hsum) * .1;
	  change = round(change);
	  hscore = hscore - change;
	  cscore = cscore + change;
	  cout << "You lost $" << change << "..." << endl;
	    if (hscore <= 0) {
		  hscore = 0;
		  cscore = 20;
		  break;
	    }
	  cout << "You have $" << hscore << ", computer has $" << cscore << endl;

    }
    cout << "Continue? ";
    do {
      cin >> cont;
      if ((cont == 'y') || (cont == 'Y')) {

      }
      else if ((cont == 'n') || (cont == 'N')) {
        break;
      }
      else {
        cout << "** Oops type 'y/Y' or 'n/N' ";
      }
    } while ((cont != 'y') && (cont != 'Y') && (cont != 'n') && (cont != 'N'));

    if ((cont == 'n') || (cont == 'N')) {
      break;
    }
  }
  cout << "Final: you have $" << hscore << ", computer has $" << cscore << ", thanks for gaming with me.";
  return 0;
}





