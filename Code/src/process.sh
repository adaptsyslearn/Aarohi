#!/bin/bash
#################### Generates the source files of Figure 13 in Aarohi Pact 2019 version #############
################### The file names and paths have to be changed eventually to run Figure13.sh ########

sys1_src="/pvfs2/$USER@oss-storage-0-108/pvfs2/adas4/edison/edisondata/p0/p0_2016"
sys2_src="/pvfs2/$USER@oss-storage-0-108/pvfs2/adas4/hopper/hopperdata/p0-directories/p0-2015-data"
sys3_src="/pvfs2/$USER@oss-storage-0-108/pvfs2/adas4/cori/coridata/p0-directories/p0_2016"
sys4_src="/pvfs2/$USER@oss-storage-0-108/pvfs2/adas4/ZIB_Extracted/log/P0_Directories"
grep "c3-0c1s11n0" $sys1_src/p0-20160316t165401/console-20160415 > F1.txt
grep "c5-0c2s5n3" $sys4_src/p0-20161025t092340/console-20161128 > F2.txt
grep "c5-3c0s12n3" $sys1_src/p0-20160128t215339/console-20160202 > F3.txt
grep "c4-0c0s1n0" $sys4_src/p0-20161025t092340/console-20161127 > F4.txt
grep "c8-0c2s13n3" $sys4_src/p0-20161025t092340/console-20161027 > F5.txt
grep "c6-3c0s5n0" $sys1_src/p0-20160101t141002/console-20160106 > F6.txt
grep "c8-0c2s8n3" $sys3_src/p0-20160524t200707/console-20160525 > F7.txt
grep "c3-0c1s1n2" $sys2_src/p0-20150203t163940/console-20150203 > F8.txt
grep "c7-3c1s14n1" $sys1_src/p0-20160128t215339/console-20160202 > F9.txt
grep "c1-0c2s14n0" $sys4_src/p0-20161025t092340/console-20161026 > F10.txt
 
bash spaceToUnderscore.sh F1
bash spaceToUnderscore.sh F2
bash spaceToUnderscore.sh F3
bash spaceToUnderscore.sh F4
bash spaceToUnderscore.sh F5
bash spaceToUnderscore.sh F6
bash spaceToUnderscore.sh F7
bash spaceToUnderscore.sh F8
bash spaceToUnderscore.sh F9
bash spaceToUnderscore.sh F10

rm F1.txt F2.txt F3.txt F4.txt F5.txt F6.txt F7.txt F8.txt F9.txt F10.txt
