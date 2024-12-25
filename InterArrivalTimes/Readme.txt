
  The following details relate to Figure-5 of Aarohi Paper:
  =================================================

The folder contains two data files:  NodeA_orig.txt, NodeB_orig.txt
                    two source files: InterArrivalTimesScatter.gnu and timediff.sh


        Run: bash timediff.sh	
        Output: Interarrivalcumulativelogscale.eps

       

timediff.sh
============

This script takes two files (console logs of failed nodes) as input and  
computes the time differences between the adjacent phrases followed by the cumulative 
inter-arrival times. To generate the figure, run:

	bash timediff.sh

	Input: NodeA_orig.txt, NodeB_orig.txt
	Produces intermediate files: NodeA_Times.log, NodeB_Times.log

InterArrivalTimesScatter.gnu
=============================    
        
	Input: NodeA_Times.log, NodeB_Times.log
	Generates: Interarrivalcumulativelogscale.eps
 

	

        
