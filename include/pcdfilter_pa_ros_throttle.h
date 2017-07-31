/******************************************************************************
*                                                                             *
* pcdfilter_pa_ros_throttle.h                                                 *
* ===========================                                                 *
*                                                                             *
*******************************************************************************
*                                                                             *
* github repository                                                           *
*   https://github.com/peterweissig/ros_pcdfilter                             *
*                                                                             *
* Chair of Automation Technology, Technische Universität Chemnitz             *
*   https://www.tu-chemnitz.de/etit/proaut                                    *
*                                                                             *
*******************************************************************************
*                                                                             *
* New BSD License                                                             *
*                                                                             *
* Copyright (c) 2015-2017, Peter Weissig, Technische Universität Chemnitz     *
* All rights reserved.                                                        *
*                                                                             *
* Redistribution and use in source and binary forms, with or without          *
* modification, are permitted provided that the following conditions are met: *
*     * Redistributions of source code must retain the above copyright        *
*       notice, this list of conditions and the following disclaimer.         *
*     * Redistributions in binary form must reproduce the above copyright     *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*     * Neither the name of the Technische Universität Chemnitz nor the       *
*       names of its contributors may be used to endorse or promote products  *
*       derived from this software without specific prior written permission. *
*                                                                             *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" *
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *
* ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY      *
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR          *
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT          *
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   *
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH *
* DAMAGE.                                                                     *
*                                                                             *
******************************************************************************/

#ifndef __PCD_FILTER_PA_ROS_THROTTLE_H
#define __PCD_FILTER_PA_ROS_THROTTLE_H

// ros headers
#include <ros/ros.h>

// standard headers
#include <string>

//**************************[cPcdFilterPaRosThrottle]**************************
class cPcdFilterPaRosThrottle {
  public:

    //! default constructor
    cPcdFilterPaRosThrottle();

    //! default destructor
    ~cPcdFilterPaRosThrottle();

    //! checks if the current data is accepted
    bool checkNewInput (ros::Time time = ros::Time::now());

    //! forces the throttle filter to accept next input
    void resetThrottle(void);

    //! parameter for skipping
    //! after each accepted input message skipping the next "count" messages
    int skip_count_;
    //! parameter for skipping
    //! after each accepted input message skipping all messages within "time"
    double skip_time_;

    //! parameter for handling time discontinuities
    //! if set (>= 0) then a message being older than this
    //!   will reset internal time
    double minimum_time_before_reset_;

    //! flag for disabling throttle
    //! if set (true) then every input will be blocked
    bool block_all_input_;

  protected:
    //! number of incoming messages - used for dropping some input
    int count_input_;
    //! ros time of last input
    ros::Time time_;
};


#endif // __PCD_FILTER_PA_ROS_THROTTLE_H
