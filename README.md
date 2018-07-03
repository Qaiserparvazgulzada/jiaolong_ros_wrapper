# Drone_sensor
-----------------
drone_sensor aims to provide a data acquisition interface to get data from stereo camera, MPU9150/6050, ultrasonic range finder, ublox NEO-m8P, Lidar(UST 20-LX)
## parameters and settings
Now we have two kinds of settings:
  1. launch parameters:
    - Sensor selection: Set it to `true` if you don't what it.
      - no_imu
      - no_sonar
      - no_vision
      - no_flow
      - no_gnss
      - no_lidar
      - no_rgbd
      - camera_module

        default="USB30W02M",now we have USB30W02M, USB30W01,USBFHD01M_720p,USBFHD01M_1080p

      - gps_module

        default="NEO-M8P",Now we have NEO-M8P-2-10

    - Sensor behavior: this part *can* be put in 2.Sensor Settings, but kept here for compatibility
      - fps: Requaired processing fps, default=30
      - order: Camera order, default="normal", to reverte the camera use "revert"
      - compress: Will the image be compressed. ORB-SLAM require non-compressed data
      - gnss_port: port used by NEO-M8P, default="/dev/ttyACM0"
      - gnss_frame_id: gnss topic name, default="gnss"

  2. Sensor config files

    Under `config` folder, in the formate of `yaml` .

## Prerequisite
- To make drone_sensor work properly, it requires the IMU module to install the arduino code (See '[MPU9150_raw](https://bitbucket.org/sjtu_uav/mpu9150_raw)' project)
- To make the gnss work, driver need to be installed. See [ublox_M8](https://Urotropine@bitbucket.org/sjtu_uav/ublox_m8.git).
