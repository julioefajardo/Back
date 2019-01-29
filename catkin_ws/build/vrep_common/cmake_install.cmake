# Install script for directory: /home/julio/catkin_ws/src/vrep_common

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/julio/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vrep_common/msg" TYPE FILE FILES
    "/home/julio/catkin_ws/src/vrep_common/msg/ForceSensorData.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/JointSetStateData.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/ObjectGroupData.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/ProximitySensorData.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/VisionSensorData.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/VisionSensorDepthBuff.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/VrepInfo.msg"
    "/home/julio/catkin_ws/src/vrep_common/msg/ScriptFunctionCallData.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vrep_common/srv" TYPE FILE FILES
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosAddStatusbarMessage.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetDialogInput.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetUIEventButton.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetJointState.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosAppendStringSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetDialogResult.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetUIHandle.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetJointTargetPosition.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosAuxiliaryConsoleClose.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetDistanceHandle.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetUISlider.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetJointTargetVelocity.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosAuxiliaryConsoleOpen.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetFloatingParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetVisionSensorDepthBuffer.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetModelProperty.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosAuxiliaryConsolePrint.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetFloatSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetVisionSensorImage.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectFloatParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosAuxiliaryConsoleShow.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetInfo.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosLoadModel.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectIntParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosBreakForceSensor.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetIntegerParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosLoadScene.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectParent.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosClearFloatSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetIntegerSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosLoadUI.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectPose.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosClearIntegerSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetJointMatrix.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosPauseSimulation.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectPosition.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosClearStringSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetJointState.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosReadCollision.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectQuaternion.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosCloseScene.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetLastErrors.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosReadDistance.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetObjectSelection.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosCopyPasteObjects.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetModelProperty.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosReadForceSensor.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetSphericalJointMatrix.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosCreateDummy.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectChild.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosReadProximitySensor.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetStringSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosDisablePublisher.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectFloatParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosReadVisionSensor.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetUIButtonLabel.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosDisableSubscriber.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectGroupData.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosRemoveObject.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetUIButtonProperty.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosDisplayDialog.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectHandle.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosRemoveUI.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetUISlider.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosEnablePublisher.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectIntParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetArrayParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetVisionSensorImage.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosEnableSubscriber.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectParent.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetBooleanParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosStartSimulation.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosEndDialog.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectPose.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetFloatingParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosStopSimulation.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosEraseFile.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjectSelection.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetFloatSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSynchronous.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetAndClearStringSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetObjects.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetIntegerParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSynchronousTrigger.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetArrayParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetStringParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetIntegerSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosTransferFile.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetBooleanParameter.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetStringSignal.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetJointForce.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosRemoveModel.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetCollisionHandle.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetUIButtonProperty.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosSetJointPosition.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosGetCollectionHandle.srv"
    "/home/julio/catkin_ws/src/vrep_common/srv/simRosCallScriptFunction.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vrep_common/cmake" TYPE FILE FILES "/home/julio/catkin_ws/build/vrep_common/catkin_generated/installspace/vrep_common-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/julio/catkin_ws/devel/include/vrep_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/julio/catkin_ws/devel/share/roseus/ros/vrep_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/julio/catkin_ws/devel/share/common-lisp/ros/vrep_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/julio/catkin_ws/devel/share/gennodejs/ros/vrep_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/julio/catkin_ws/devel/lib/python2.7/dist-packages/vrep_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/julio/catkin_ws/devel/lib/python2.7/dist-packages/vrep_common")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/julio/catkin_ws/build/vrep_common/catkin_generated/installspace/vrep_common.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vrep_common/cmake" TYPE FILE FILES "/home/julio/catkin_ws/build/vrep_common/catkin_generated/installspace/vrep_common-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vrep_common/cmake" TYPE FILE FILES
    "/home/julio/catkin_ws/build/vrep_common/catkin_generated/installspace/vrep_commonConfig.cmake"
    "/home/julio/catkin_ws/build/vrep_common/catkin_generated/installspace/vrep_commonConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/vrep_common" TYPE FILE FILES "/home/julio/catkin_ws/src/vrep_common/package.xml")
endif()

