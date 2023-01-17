/**
 * @file scout_gazebo_node.cpp
 * @author Muhammad Syamim (Syazam33@gmail.com)
 * @brief Controller node for Agilex Scout V2
 * @version 0.1
 * @date 2023-01-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>
#include <geometry_msgs/msg/twist.hpp>

using std::placeholders::_1;

class robotcore : public rclcpp::Node{
    public:
    robotcore(std::string robot_name): robot_name(robot_name){
        //Initialise topics
        cmd_topic = "/cmd_vel";
        motor_fl_topic = robot_name + "/scout_motor_fr_controller/command";
        motor_fr_topic = robot_name + "/scout_motor_fl_controller/command";
        motor_rl_topic = robot_name + "/scout_motor_rr_controller/command";
        motor_rr_topic = robot_name + "/scout_motor_rl_controller/command";

    }

    ~robotcore(){}

    void SetupPublishers(){
        //Control Subscriber
        cmd_sub = this->create_subscription<geometry_msgs::msg::Twist>(cmd_topic, 10, std::bind(&robotcore::cmd_callback, this, _1));

        //Command Publishers
        motor_fl_pub = this->create_publisher<std_msgs::msg::Float64>(motor_fl_topic, 10);
        motor_fr_pub = this->create_publisher<std_msgs::msg::Float64>(motor_fr_topic, 10);
        motor_rr_pub = this->create_publisher<std_msgs::msg::Float64>(motor_rl_topic, 10);
        motor_rl_pub = this->create_publisher<std_msgs::msg::Float64>(motor_rr_topic, 10);

    }

    private:
    void cmd_callback(const geometry_msgs::msg::Twist msg) const {

    }

    //Robot Variables
    std::string robot_name;

    //Topics
    std::string cmd_topic;
    std::string motor_fr_topic;
    std::string motor_fl_topic;
    std::string motor_rr_topic;
    std::string motor_rl_topic;

    //Handlers
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr motor_fr_pub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr motor_fl_pub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr motor_rr_pub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr motor_rl_pub;
}

int main(int argc, char** argv){
    //Setup ROS node
    rclcpp::init(argc, argv);

    robot = std::make_shared<rclcpp::Node>("Scout_Gazebo");
    std::cout << "Starting Scout Mobility Sim ..." << std::endl;

}