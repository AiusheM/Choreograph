/*
 *  Sequenceable.h
 *  sc-Choreograph
 *
 *  Created by David Wicks on 2/14/11.
 *  Copyright 2011 David Wicks. All rights reserved.
 *
 */

#pragma once
#include "cinder/Cinder.h"

namespace cinder
{
	namespace tween
	{
		//! Base interface for anything that can go on a Sequence
		class Sequenceable
		{
		public:
			Sequenceable():
			mReversed(false)
			{}
			virtual ~Sequenceable(){};
			//! advance time a specified amount
			virtual void step( double timestep ){};
			//! go to a specific time
			virtual void stepTo( double time ) = 0;
			
			//! push back the action's start time
			void delay( double amt ){ mStartTime += amt; }
			//! set the action's start time
			void setStartTime( double time ){ mStartTime = time; }
			
			//! change how time behaves
			void reverse( bool isReversed=true ){ mReversed = isReversed; }
			//! loop infinitely:-1, count:1-n
			//void loop(){}
			//! pinpong infinitely:-1, count:1–n
			//void pingpong(){}
			
			//! is the sequenceable action finished?
			virtual bool isComplete(){ return false; }
		protected:
			double mStartTime;
			bool mReversed;
		private:
		};
		
		typedef std::shared_ptr<Sequenceable> SeqRef;
	}
}

