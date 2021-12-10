/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  add_chain_tb.h -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

/******************************************************************************/
/***************************   Testbench Function        **********************/
/******************************************************************************/
/*									      */
/*	The testbench module has the following hierarchy:		      */
/*									      */
/*	testbench							      */
/*	  - RESET_STIM							      */
/*	  - DATA_GEN							      */
/*									      */
/******************************************************************************/

#include "common.h"

struct testbench : public sc_module {
  sc_signal<int>	addr;	     // Address of input memory 
  sc_signal<bool>     	reset;
  sc_signal<bool>     	ready;
  signal_bool_vector8 	data;
  signal_bool_vector4 	sum;

  /*** Constructor ***/ 
  testbench ( const sc_module_name& NAME,
	      sc_clock&             TICK  )

    : sc_module()
    {
  	f_RESET_STIM  	("RD1", TICK, ready, reset, addr);
	f_DATA_GEN    	("DG1", TICK, ready, data, addr);
	f_add_chain 	("AC1", TICK, reset, data, sum, ready);
        f_DISPLAY	("D1",  ready, data, sum);
    }
};
