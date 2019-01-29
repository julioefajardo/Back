// Generated by gencpp from file vrep_common/simRosLoadModelResponse.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSLOADMODELRESPONSE_H
#define VREP_COMMON_MESSAGE_SIMROSLOADMODELRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vrep_common
{
template <class ContainerAllocator>
struct simRosLoadModelResponse_
{
  typedef simRosLoadModelResponse_<ContainerAllocator> Type;

  simRosLoadModelResponse_()
    : result(0)
    , baseHandle(0)  {
    }
  simRosLoadModelResponse_(const ContainerAllocator& _alloc)
    : result(0)
    , baseHandle(0)  {
  (void)_alloc;
    }



   typedef int32_t _result_type;
  _result_type result;

   typedef int32_t _baseHandle_type;
  _baseHandle_type baseHandle;





  typedef boost::shared_ptr< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> const> ConstPtr;

}; // struct simRosLoadModelResponse_

typedef ::vrep_common::simRosLoadModelResponse_<std::allocator<void> > simRosLoadModelResponse;

typedef boost::shared_ptr< ::vrep_common::simRosLoadModelResponse > simRosLoadModelResponsePtr;
typedef boost::shared_ptr< ::vrep_common::simRosLoadModelResponse const> simRosLoadModelResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vrep_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'vrep_common': ['/home/julio/catkin_ws/src/vrep_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e49038cfdf66770b813aa3b2dae39cef";
  }

  static const char* value(const ::vrep_common::simRosLoadModelResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe49038cfdf66770bULL;
  static const uint64_t static_value2 = 0x813aa3b2dae39cefULL;
};

template<class ContainerAllocator>
struct DataType< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vrep_common/simRosLoadModelResponse";
  }

  static const char* value(const ::vrep_common::simRosLoadModelResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 result\n\
int32 baseHandle\n\
\n\
";
  }

  static const char* value(const ::vrep_common::simRosLoadModelResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.baseHandle);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simRosLoadModelResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vrep_common::simRosLoadModelResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vrep_common::simRosLoadModelResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result);
    s << indent << "baseHandle: ";
    Printer<int32_t>::stream(s, indent + "  ", v.baseHandle);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSLOADMODELRESPONSE_H
