#ifndef __STATE_T__
#define __STATE_T__

/** 
@brief	Enumeration type of possible machine states
*/
enum state_t 
{
	INIT_STATE, 
	SUBS_STATE, 
	WAIT_ORDERS_STATE,
	PREPARE_TASK_STATE,
	EXECUTE_REPLY_STATE,
	TERMINATION_STATE
};

#endif