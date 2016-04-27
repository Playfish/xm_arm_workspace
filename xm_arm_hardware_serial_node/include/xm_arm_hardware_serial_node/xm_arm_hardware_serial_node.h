/*********************************************************************
 *  Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016, Team-Xmbot-Service-Robot
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Team-Xmbot-Service-Robot nor the names
 *     of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ********************************************************************/

// Authors: startar, myyerrol
// Created: 2012.4.8, 2016.4.15

#ifndef ARM_HARDWARE_SERIAL_NODE_H_
#define ARM_HARDWARE_SERIAL_NODE_H_

#include <ros/ros.h>
#include "xm_arm_hardware_serial_port.h"
#include <map>
#include <string>

namespace xm_serial_node
{
class SerialNode
{
public:
    SerialNode(const ros::NodeHandle &nh, const ros::NodeHandle &private_nh);
    virtual ~SerialNode();
private:
    void loadParams();
    void getDatagramCallback(
        const xm_arm_msgs::xm_ArmSerialDatagram::ConstPtr &msg);
    void getSerialCallback(xm_arm_msgs::xm_ArmSerialDatagramPtr ptr_datagram);
private:
    SerialParams                  serial_params_;
    int                           timeout_;
    shared_ptr<SerialPort>        ptr_serial_port_;
    ros::NodeHandle               nh_;
    ros::NodeHandle               private_nh_;
    ros::Subscriber               serial_sub_;
    map<int, string>              topic_name_;
    map<u_int8_t, ros::Publisher> serial_pub_;
};

} // namespace xm_serial_node

#endif // ARM_HARDWARE_SERIAL_NODE_H_