/*
 * SPDX-FileCopyrightText: 2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_DEV_IMU_NWC_ROS2_H
#define YARP_DEV_IMU_NWC_ROS2_H

#include "GenericSensor_nwc_ros2.h"
#include <sensor_msgs/msg/imu.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

/**
 * @ingroup dev_impl_wrapper
 *
 * \brief `IMU_nwc_ros2`: This wrapper connects to a device and publishes a ROS topic of type sensor_msgs::Imu.
 *
 * | YARP device name |
 * |:-----------------:|
 * | `Imu_nwc_ros2` |
 *
 * The parameters accepted by this device are:
 * | Parameter name | SubParameter   | Type    | Units          | Default Value    | Required                    | Description                                                       | Notes |
 * |:--------------:|:--------------:|:-------:|:--------------:|:----------------:|:--------------------------: |:-----------------------------------------------------------------:|:-----:|
 * | topic_name     |      -         | string  | -              |   -              | Yes                         | The name of the ROS topic opened by this device.                  | MUST start with a '/' character |
 * | node_name      |      -         | string  | -              |   -              | Yes                         | The name of the ROS node opened by this device                    | Autogenerated by default |
 * | sensor_name    |      -         | string  | -              |   -              | Yes                         | The name of the sensor the data are coming from                   |  |
 */
class Imu_nwc_ros2 : public GenericSensor_nwc_ros2<sensor_msgs::msg::Imu>,
                     public yarp::dev::IThreeAxisLinearAccelerometers,
                     public yarp::dev::IThreeAxisGyroscopes,
                     public yarp::dev::IOrientationSensors
{
private:
    sensor_msgs::msg::Imu m_currentData;

public:
    using GenericSensor_nwc_ros2<sensor_msgs::msg::Imu>::GenericSensor_nwc_ros2;

    using GenericSensor_nwc_ros2<sensor_msgs::msg::Imu>::open;
    using GenericSensor_nwc_ros2<sensor_msgs::msg::Imu>::close;

protected:
    void subscription_callback(const std::shared_ptr<sensor_msgs::msg::Imu> msg) override;
public:
    /* IThreeAxisLinearAccelerometers methods */
    size_t getNrOfThreeAxisLinearAccelerometers() const override;
    yarp::dev::MAS_status getThreeAxisLinearAccelerometerStatus(size_t sens_index) const override;
    bool getThreeAxisLinearAccelerometerName(size_t sens_index, std::string &name) const override;
    bool getThreeAxisLinearAccelerometerFrameName(size_t sens_index, std::string &frameName) const override;
    bool getThreeAxisLinearAccelerometerMeasure(size_t sens_index, yarp::sig::Vector& out, double& timestamp) const override;

    /* IThreeAxisGyroscopes methods */
    size_t getNrOfThreeAxisGyroscopes() const override;
    yarp::dev::MAS_status getThreeAxisGyroscopeStatus(size_t sens_index) const override;
    bool getThreeAxisGyroscopeName(size_t sens_index, std::string &name) const override;
    bool getThreeAxisGyroscopeFrameName(size_t sens_index, std::string &frameName) const override;
    bool getThreeAxisGyroscopeMeasure(size_t sens_index, yarp::sig::Vector& out, double& timestamp) const override;

    /* IOrientationSensors methods */
    size_t getNrOfOrientationSensors() const override;
    yarp::dev::MAS_status getOrientationSensorStatus(size_t sens_index) const override;
    bool getOrientationSensorName(size_t sens_index, std::string &name) const override;
    bool getOrientationSensorFrameName(size_t sens_index, std::string &frameName) const override;
    bool getOrientationSensorMeasureAsRollPitchYaw(size_t sens_index, yarp::sig::Vector& rpy, double& timestamp) const override;
};

#endif // YARP_DEV_IMU_NWC_ROS2_H