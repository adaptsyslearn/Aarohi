/** \file scanner.ll Define the phrase Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>

#include "scanner.h"
#include "driver.h"
#include <sys/time.h>

/* import the parser's token type into a local typedef */
typedef phrase::Parser::token token;
typedef phrase::Parser::token_type token_type;
 
#define yyterminate() return token::END
struct timeval tp;
long int ms = 0;
int c100 = 0, c101 = 0, c102 = 0, c103 = 0;
int c104 = 0, c105 = 0, c106 = 0, c107 = 0;
int c108 = 0, c109 = 0, c110 = 0, c111 = 0;
int c112 = 0, c113 = 0, c114 = 0, c115 = 0;
int c116 = 0, c117 = 0, c118 = 0, c119 = 0;
int c120 = 0, c121 = 0, c122 = 0, c123 = 0;
int c124 = 0, c125 = 0, c126 = 0, c127 = 0;
int c128 = 0, c129 = 0, c130 = 0, c131 = 0;
int c132 = 0, c133 = 0, c134 = 0, c135 = 0;
int c136 = 0, c137 = 0, c138 = 0, c139 = 0;
int c140 = 0, c141 = 0, c142 = 0, c143 = 0;
int c144 = 0, c145 = 0, c146 = 0, c147 = 0;
int c148 = 0, c149 = 0, c150 = 0, c151 = 0;
int c152 = 0, c153 = 0, c154 = 0, c155 = 0;
int c156 = 0, c157 = 0, c158 = 0, c159 = 0;
int c160 = 0, c161 = 0, c162 = 0, c163 = 0;
int c164 = 0, c165 = 0, c166 = 0, c167 = 0;
int c168 = 0, c169 = 0, c170 = 0, c171 = 0;
int c172 = 0, c173 = 0, c174 = 0, c175 = 0;
int c176 = 0, c177 = 0, c178 = 0, c179 = 0, c180 = 0;

/* This disables inclusion of unistd.h.
 * The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H
%}

/*** Flex Declarations and Options ***/
DIGIT	 [0-9]
P129     "DVS:_file_node_down:".*
P130     "LNet:".*"No_gnilnd_traffic_received_from_".*
P131     "LNet:".*"to_timed_out".*
P132	 "LNet:_Received_down_event_for_nid".*
P133	 Stop_NMI_detected_on_CPU_{DIGIT}
P128	 "RCADSVCS_:_shutdown".*
P127	 "cb_node_unavailable:".*
P134	 "cpu_".*"_apic_timer".*
P135	 "task_PC_stack_pid_father"
P136  	 "init".*			
P137	 "Call_Trace".*		
P138     "Debug_NMI_detected_on_CPU".*
P139	 "Kernel_panic_not_syncing".*"Debug_NMI".*
P152	 "MATLAB_invoked_oom_killer".*
P153	 "MATLAB_cpuset".*
P154 	 "Out_of_memory".*"Kill_process".*
P155	 "Killed_process".*
P156	 "Kernel_panic_not_syncing".*"Fatal".*
P157     "WARNING".*"Node".*"is_down".*"will_not_be_checked".*
P140	 "DVS:_verify_filesystem".*
P141	 "mount:_mounting".*"on".*
P142	 "S01dvs".*"mount_returned_error".*
P143	 "SGI_XPMEM_kernel_module".*
P144	 "<node_health>".*"xtnhd_has_started".*
P145	 "<node_health>".*"Boot_Check".*
P146	 "boot_freemem_data_calculated".*
P147	 "DVS:_parse_options".*
P148	 "[Hardware_Error]".*"CPU".*"Machine_Check_Exception".*
P149	 "[Hardware_Error]".*"TSC".*
P150	 "[Hardware_Error]".*"PROCESSOR".*
P151	 "CPU".*"correctable_MCEs".*
P100	 "slurm_load_partitions".*"Unable_to_contact_slurm_controller".*
P101	 "Lustre".*"Connection_to".*"was_lost".*
P102	 "Lustre".*"Connection".*"restored_to".*
P103	 "Lustre".*"Skipped".*"messages".*
P104 	 "Lustre".*"Request".*
P105 	 "LNet".*"Dropping".*"Connection".*
P106	 "Unloading_nic_compatibility_device_done".*
P107	 "bpmcd_exit".*
P108	 "Invoking".*"stopping_slurmd".*
P109	 "slurmd_is_stopped".*
P110	 "failed".*
P111	 "Unmounting".*"failed_done".*
P112	 "Shutting_down_Cray".*
P113	 "Stopping_MUNGE".*"munged".*
P114	 "Shutting_down".*"aemon".*
P115	 "Shutting_down".*"rpcbind_rpcbind".*
P116	 "rpcbind".*"cannot_open_file".*
P117	 "rpcbind".*"cannot_save_any_registration".*
P118	 "Removing_separate".*"shared_root_for_SLURM".*
P119	 "umount".*"Error_stopping".*
P120	 "Unloading_XPMEM_driver".*
P121	 "Unmounting".*"alps_spool_directory_done".*
P122	 "Initializing".*"Compute_node_runtime_environment".*
P123	 "stop_BIND_mounts".*
P124	 "Stopping_DVS_service:".*
P125	 "Could_not_unmount".*"Skipping_other_dvs_unmounts".*
P126	 "System_halted".*
P158	 "[Hardware_Error]".*"RIP_!INEXACT!".*				
P166	 "[Hardware_Error]".*"Machine_check_events_logged".*
P159	 "[Hardware_Error]".*"Machine_check:".*
P160	 "Processor_has_catastrophic_error".*"assertion_mask".*
P161	 "EXTERNAL_MCE_TOOL".*
P162	 "socket".*"reports".*"externally_asserted_by_socket_"{DIGIT}
P163	 "Extracted_CBo_ToR_Data".*
P164	 "Logging".*"MCE_errors_to_hwerrlog".*
P165	 "mce_notify_irq".*
P167	 "Corrected_memory_errors".*
P168	 "SOCKET".*"CHANNEL".*"DIMM".*
P169	 "HWERR".*"HAL_Completion".*
P170	 "LNet".*"_Quiesce_start".*"critical_hardware_error".*
P171	 "[gsockets]_debug".*"critical_hardware_error".*
P172     "LNet".*"successful_reset_of_all_hardware_resources".*
P173	 "Error".*"extracting".*"Data".*
P174     "[Firmware_Bug]".*"powernow-k8:_No_compatible".*
P175	 "Lustre".*"ptlrpc_expire_one_request".*
P176	 "node_health".*"xtnhd_has_started".*
P177	 "(Filesystem_Test)_WARNING".*
P181	 ^"WARNING".*
P178	 "LNetError".*"Too_long_env_variable".*
P179	 "LNetError".*"Skipped".*"previous_similar_messages".*
P180	 "krsip".*"RSIP_server".*"not_responding".*


Timestamp ^(19|20)\d\d[- /.](0[1-9]|1[012])[- /.](0[1-9]|[12][0-9]|3[01])$T[0-9][0-9]:[0-9][0-9]:[0-9][0-9]+"."[0-9]*"-08:00" /* Valid Date Timestamps: year:month:day:T:hh:mm:ss. To be tokenized for eventual timestamp consideration */
NodeID ^c(\d-\d)$c(\d|\d\d)$s(\d|\d\d)$n[0-3] /* Valid Node ID */

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "PhraseFlexLexer" */
%option prefix="Phrase"

/* Some optimization */
%option batch

/* enable scanner to generate debug output */
%option debug

/* no support for include files */
%option yywrap nounput 

/* the use of start condition stacks */
%option stack

/* Each time yylex is invoked, the begin position is moved onto the end position. */ 
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN PHRASE - Change the phrase lexer rules below ***/

 /* gobble up timestamps */
{Timestamp} {
    std::cout << "Valid Date Timestamp found " << std::endl;
    yylloc->step();
}

{NodeID} {
    std::cout << "Valid Node ID found " << std::endl;
    yylloc->step();
}

{P129}            { c129 = c129+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms;
  		   /*std::cout << "Start time is " << yylval->longVal << " milliseconds" << std::endl; */
		   return token::P1; }

{P130}            { c130 = c130+1; 
	           gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P2; }

{P131}            { c131 = c131+1;
	           gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P3; }

{P132}            { c132 = c132+1;
                   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P4; }

{P133}            { c133 = c133+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P5; }

{P128}            { c128 = c128+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P6; }

{P127}            { c127 = c127+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P7; }

{P134}	         { c134 = c134+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
  		   return token::P8; } 
{P135}	         { c135 = c135+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P9; }
{P136}            { c136 = c136+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P10; } 
{P137}		 { c137 = c137+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P11; } 
{P138}            { c138 = c138+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P12; } 
{P139}            { c139 = c139+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P13; }
{P152}            { c152 = c152+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P14; }
{P153}		 { c153 = c153+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P15; }
{P154}		 { c154 = c154+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P16; }
{P155}		 { c155 = c155+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P17; }
{P156}		 { c156 = c156+1;
	           gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P18; }
{P157}		 { c157 = c157+1;
		   gettimeofday(&tp, NULL);
		   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
		   yylval->longVal = ms;  
		   return token::P19; }
{P140}		 { c140 = c140+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P20; }
{P141}		 { c141 = c141+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P21; }
{P142}	         { c142 = c142+1;
	 	   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P22; }
{P143}		 { c143 = c143+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P23; }
{P144}		 { c144 = c144+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P24; }
{P145}		 { c145 = c145+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P25; } 
{P146}		 { c146 = c146+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms;
		   return token::P26; }
{P147}		 { c147 = c147+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms;
		   return token::P27; }
{P148}		 { c148 = c148+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P28; }
{P149}		 { c149 = c149+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P29; }
{P150}		 { c150 = c150+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P30; }
{P151}		 { c151 = c151+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P31; }
{P100}            { c100 = c100+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P32; } 
{P101}		 { c101 = c101+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P33; } 
{P102}		 { c102 = c102+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P34; } 
{P103}		 { c103 = c103+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P35; }	
{P104}		 { c104 = c104+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P36; } 
{P105}		 { c105 = c105+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
   		   return token::P37; } 
{P106}		 { c106 = c106+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P38; } 	
{P107}		 { c107 = c107+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P39; }  
{P108}		 { c108 = c108+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P40; }
{P109}		 { c109 = c109+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P41; }
{P110}		 { c110 = c110+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P42; }
{P111}		 { c111 = c111+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P43; }
{P112}		 { c112 = c112+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P44; }
{P113}		 { c113 = c113+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P45; }
{P114}		 { c114 = c114+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P46; }
{P115}		 { c115 = c115+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P47; }
{P116}		 { c116 = c116+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P48; }
{P117}		 { c117 = c117+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P49; }
{P118}		 { c118 = c118+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P50; }
{P119}		 { c119 = c119+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P51; }
{P120}		 { c120 = c120+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P52; }
{P121}		 { c121 = c121+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P53; }
{P122}		 { c122 = c122+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P54; }
{P123}		 { c123 = c123+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P55; }	
{P124}		 { c124 = c124+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P56; }
{P125}		 { c125 = c125+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P57; }
{P126}	  	 { c126 = c126+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P58; }
{P158}            { c158 = c158+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms;
		   return token::P59; }
{P159}            { c159 = c159+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P60; }
{P160}            { c160 = c160+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P61; }
{P161}            { c161 = c161+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P62; }
{P162}            { c162 = c162+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P63; }
{P163}            { c163 = c163+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P64; }
{P164}            { c164 = c164+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P65; }
{P165}            { c165 = c165+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; // in milliseconds
		   return token::P66; }
{P166}            { c166 = c166+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P67; }
{P167}            { c167 = c167+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
     		   return token::P68; }
{P168}            { c168 = c168+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P69; }
{P169}            { c169 = c169+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
   		   return token::P70; }
{P170}            { c170 = c170+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P71; }
{P171}            { c171 = c171+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P72; }
{P172}            { c172 = c172+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P73; }
{P173}            { c173 = c173+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P74; }
{P174}            { c174 = c174+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P75; }
{P175}            { c175 = c175+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P76; }
{P176}            { c176 = c176+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P77; }
{P177}            { c177 = c177+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P78; }
{P178}            { c178 = c178+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P79; }
{P179}            { c179 = c179+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; 
		   return token::P80; }
{P180}            { c180 = c180+1;
		   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; /* in milliseconds */
		   return token::P81; }

{P181}            { c180 = c180+1;
                   gettimeofday(&tp, NULL);
                   ms = tp.tv_sec * 1000 + tp.tv_usec/1000;
                   yylval->longVal = ms; /* in milliseconds */
                   return token::P82; }


[0-9][0-9][0-9]+ { /* Phrases: 3 or more digits since starting with 100..*/
        //yylval->integerVal = atoi(yytext);
        //return token::INTEGER; //skip this token 
}

 /* remove white-spaces */
[ \t\r]+ {
    yylloc->step();
}

 /* remove end-of-lines */
\n {
    yylloc->lines(yyleng); yylloc->step();
    return token::EOL;
}

 /* pass all other characters up to bison */
. {
    //return static_cast<token_type>(*yytext);
    //skip unmatched characters
    yylloc->step();	
}

 /*** END PHRASE - Change the phrase lexer rules above ***/

%% 

namespace phrase {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : PhraseFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

#ifdef yylex
#undef yylex
#endif


int PhraseFlexLexer::yylex()
{
    std::cerr << "in PhraseFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int PhraseFlexLexer::yywrap()
{
    return 1;
}
