cmake_minimum_required(VERSION 2.8.3)
project(foot_grasping)



# Add support for c++11
add_definitions(-std=c++11 -O3)

find_package(PkgConfig)

pkg_search_module(Eigen3 REQUIRED eigen3)


find_package(catkin REQUIRED COMPONENTS
  utils_math
  custom_msgs
  custom_msgs_gripper
  roscpp
  rospy
  std_msgs
  surgical_task
  surgical_system_service_manager
)


catkin_package(
 INCLUDE_DIRS
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS roscpp rospy std_msgs custom_msgs custom_msgs_gripper utils_math surgical_task surgical_system_service_manager
)


include_directories(include ${catkin_INCLUDE_DIRS} ${Eigen3_INCLUDE_DIRS})

# add_executable(foot_grasping src/foot_grasping_node.cpp src/foot_grasping.cpp)

# add_dependencies(foot_grasping ${catkin_EXPORTED_TARGETS})

# target_link_libraries(foot_grasping ${catkin_LIBRARIES})
