#ifndef HMM_H
#define HMM_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>

using namespace std;

class HMM {
	public:
		HMM(int,int,map<int,map<int,double> >, map<int,map<int,double> >);//Constructor functions
		HMM();
		
		//Getters and setters
		int getStates();
		int getObservations();
		void setStates(int);
		void setObservations(int);
		
		void trainModel(double*);
		
	private:
		int number_of_states,number_of_observations;
		double *prior_probabilities;
		map<int, map<int, double> > transition_probabilities;
		map<int, map<int, double> > observation_probabilities;
		
		//Training functions
		void initialiseParameters();
		void eStep(double*);
			double forwardProbability(double*);
			double backwardProbability(double*);
		void mStep(double*);
			void maximisePriors(double*);
			void maximiseTransitions(double*);
			void maximiseObservationDistribution(double*);
			
		//Viterbi Functions
};

#endif