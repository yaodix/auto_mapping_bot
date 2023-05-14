# how to deploy

this branch is to depoly on jetson nano(B01)

1. mkdir catkin_ws
2. cd catkin_ws
3. git clone ...
4. catkin_make


## rvi配置
 ### 模型问题 
 不使用urdf模型也可以完成建图工作，但必须具备的坐标系转换是odom->base_footprint, lidar->base_footprint, camera->base_footprint(如果有).

 ## rqt 动态参数配置