/*
 * BankSimApp.cpp
 * 
 * Description: Drives the Bank simluation of the priority queue, binary heap and queue.
 *
 * Author: Amogh Madhavan and Juliet Hu
 * Date: March 27 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BinaryHeap.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"
using namespace std;


int main(int argc, char *argv[]) {
 
  //creates a queue and priorityqueue
  Queue<Event>* bankline = new Queue<Event>();
  PriorityQueue<Event>* eventPriorityQueue = new PriorityQueue<Event>();

  

  // //assign string variables for string break up process whilst reading the file, as show below in the code.
  string aLine = "";
  string aWord = "";
  string time;
  string lenght;
  string delimiter = " ";
  size_t pos = 0;
  int timenum;
  int total = 0;
  float compute = 0;
  int lenghtnum;
  int currenttime = 0;
  int departuretime;

  // //read the file
  istream &myfile(cin);
  

    while (!myfile.eof())
    {
       getline(myfile,aLine);
       pos = aLine.find(delimiter);
       time = aLine.substr(0, pos);
       timenum = stoi(time);
       aLine.erase(0, pos + delimiter.length());
       lenght = aLine;
       lenghtnum = stoi(lenght);
       // event object is created and is passed info extracted from the file
       Event anEvent('A', timenum, lenghtnum);
      //  try catch block to catch exceptions.
         try  
          { 
              total++;
              eventPriorityQueue->enqueue(anEvent);               
          }
          catch(EmptyDataCollectionException& ex){
          }
    }

    //runs the bank simulation using the queue and priority queue and outputs the result of the simutlation.
    bool telleravaliable = true;
    cout<<"Simulation Begins"<<endl;
    while(!eventPriorityQueue->isEmpty()){
      Event newEvent = eventPriorityQueue->peek();
      currenttime = newEvent.getTime();
      if(newEvent.getType() == 'A'){
          cout<<"Processing an arrival event at time:\t"<<currenttime<<endl;
          eventPriorityQueue->dequeue();
        if(bankline->isEmpty() && telleravaliable){
          departuretime = currenttime + newEvent.getLength();
          Event newDepartureEvent('D', departuretime);
          eventPriorityQueue->enqueue(newDepartureEvent);
          telleravaliable = false;
        }
        else{
          bankline->enqueue(newEvent);
        }
      }
      else{
        cout<<"Processing a departure event at time:\t"<<departuretime<<endl;
        eventPriorityQueue->dequeue();
        currenttime = newEvent.getTime();
        if(!bankline->isEmpty()){
          newEvent = bankline->peek();
          compute = compute + (departuretime - newEvent.getTime());
          bankline->dequeue();
          departuretime = currenttime + newEvent.getLength();
          Event newDepartureEvent('D', departuretime);
          eventPriorityQueue->enqueue(newDepartureEvent);
        }
        else{
          telleravaliable = true;
        }
      }
    }
    cout<<"Simulation Ends"<<endl;
    cout<<endl;
    cout<<"Final Statistics:"<<endl;
    cout<<endl;
    cout<<"\t"<<"Total number of people processed: "<<total<<endl;
    cout<<"\t"<<"Average amount of time spent waiting: "<<(compute/total)<<endl;
  

  //delete the objects to free all the memory

  delete eventPriorityQueue;
  eventPriorityQueue = NULL;
  delete bankline;
  bankline = NULL;
  return 0;
}
