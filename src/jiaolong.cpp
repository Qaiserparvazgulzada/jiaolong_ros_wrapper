
#include <ros/ros.h>
#include <serial/serial.h>  //ROS has built-in serial port package
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <stdio.h>

serial::Serial ser; //Declaring the serial port object
//Call Back
void write_callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO_STREAM("Writing to serial port" <<msg->data);
    ser.write(msg->data);   //Send Serial Data
}

int main (int argc, char** argv)
{
    //Initialize Node
    ros::init(argc, argv, "serial_example_node");
   //declare the node handle
    ros::NodeHandle nh;
    //订阅主题，并配置回调函数
    ros::Subscriber write_sub = nh.subscribe("write", 1000, write_callback);
    //发布主题
    ros::Publisher read_pub = nh.advertise<std_msgs::String>("read", 1000);
    try
    {
    //设置串口属性，并打开串口
        ser.setPort("/dev/ttyUSB0");
        ser.setBaudrate(115200);
        serial::Timeout to = serial::Timeout::simpleTimeout(1000);
        ser.setTimeout(to);
        ser.open();
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port ");
        return -1;
    }
    //检测串口是否已经打开，并给出提示信息
    if(ser.isOpen())
    {
        ROS_INFO_STREAM("Serial Port initialized");
    }
    else
    {
        return -1;
    }
    //指定循环的频率
    //ros::Rate loop_rate(5);
    while(ros::ok())
    {
        if(ser.available()){

            std_msgs::String result;
            ROS_INFO_STREAM("Reading from serial port\n");
            result.data = ser.readline(65535,"\r\n");
            ROS_INFO_STREAM("Read: " << result.data);
            read_pub.publish(result);


std::string result = "result.data";
std::istringstream iss(test);
std::vector<std::string>  results((std::istream_iterator<std::string>(iss)),
std::istream_iterator<std::string>());
        //处理ROS的信息，比如订阅消息,并调用回调函数
        ros::spinOnce();
       //loop_rate.sleep();
    }
}
