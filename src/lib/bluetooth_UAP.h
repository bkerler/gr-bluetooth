/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_BLUETOOTH_UAP_H
#define INCLUDED_BLUETOOTH_UAP_H

#include "bluetooth_block.h"
#include "bluetooth_packet.h"
#include "bluetooth_piconet.h"
#include <stdio.h>
#include <stdlib.h>

class bluetooth_UAP;
typedef boost::shared_ptr<bluetooth_UAP> bluetooth_UAP_sptr;

/*!
 * \brief Return a shared_ptr to a new instance of bluetooth_UAP.
 */
bluetooth_UAP_sptr bluetooth_make_UAP (int LAP);

/*!
 * \brief Sniff Bluetooth packets.
 * \ingroup block
 */
class bluetooth_UAP : public bluetooth_block
{
private:
	// The friend declaration allows bluetooth_make_UAP to
	// access the private constructor.

	friend bluetooth_UAP_sptr bluetooth_make_UAP (int LAP);

protected:
	bluetooth_UAP (int LAP);	// private constructor

	/* remember the sample count of the previous packet for interval computation */
	int d_previous_packet_time;

	/* the piconet we are monitoring */
	bluetooth_piconet_sptr d_piconet;

public:
  ~bluetooth_UAP ();	// public destructor

  // Where all the action really happens

  int work (int noutput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_BLUETOOTH_UAP_H */
