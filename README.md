# Aarohi

This repo contains some artifacts related to the Aarohi paper. 
For further details, please refer to the related [IPDPS 2020 paper](https://ieeexplore.ieee.org/document/9139847).


### Code Structure
```bash
/                           : Aarohi Root
|-- Algorithm1              : Generation of rule list from failure chains
|-- Code
|   |-- src                 : Flex Bison parser
|   |-- Testfiles           : Sample test files related to Failure Chains
|   |-- README.txt          : Information to compile and run
|-- InterArrivalTimes       : Data and scripts related to inter-arrival times
|-- SampleData              : Sample HPC logs with some node failure information
|-- Speedup                 : Speedup in execution time (of prediction or detection) across different approaches
|-- helperScripts           : Scripts to process files or calculate statistics 
|-- Experiments             : Source codes related to some results
```

## Citation

If you use Aarohi in your work, please cite the following paper:

```
@inproceedings{DBLP:conf/aarohi,
  author       = {Anwesha Das and
                  Frank Mueller and
                  Barry Rountree},
  title        = {Aarohi: Making Real-Time Node Failure Prediction Feasible},
  booktitle    = {International Parallel and Distributed Processing Symposium
                  (IPDPS)},
  pages        = {1092--1101},
  publisher    = {{IEEE}},
  year         = {2020}
}
```
