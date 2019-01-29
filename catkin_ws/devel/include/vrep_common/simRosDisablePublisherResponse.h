// Generated by gencpp from file vrep_common/simRosDisablePublisherResponse.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSDISABLEPUBLISHERRESPONSE_H
#define VREP_COMMON_MESSAGE_SIMROSDISABLEPUBLISHERRESPONSE_H


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
struct simRosDisablePublisherResponse_
{
  typedef simRosDisablePublisherResponse_<ContainerAllocator> Type;

  simRosDisablePublisherResponse_()
    : referenceCounter(0)  {
    }
  simRosDisablePublisherResponse_(const ContainerAllocator& _alloc)
    : referenceCounter(0)  {
  (void)_alloc;
    }



   typedef int32_t _referenceCounter_type;
  _referenceCounter_type referenceCounter;





  typedef boost::shared_ptr< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> const> ConstPtr;

}; // struct simRosDisablePublisherResponse_

typedef ::vrep_common::simRosDisablePublisherResponse_<std::allocator<void> > simRosDisablePublisherResponse;

typedef boost::shared_ptr< ::vrep_common::simRosDisablePublisherResponse > simRosDisablePublisherResponsePtr;
typedef boost::shared_ptr< ::vrep_common::simRosDisablePublisherResponse const> simRosDisablePublisherResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b77f442068c4e56b29b4900433a0f3d6";
  }

  static const char* value(const ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb77f442068c4e56bULL;
  static const uint64_t static_value2 = 0x29b4900433a0f3d6ULL;
};

template<class ContainerAllocator>
struct DataType< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vrep_common/simRosDisablePublisherResponse";
  }

  static const char* value(const ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 referenceCounter\n\
\n\
";
  }

  static const char* value(const ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.referenceCounter);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct simRosDisablePublisherResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vrep_common::simRosDisablePublisherResponse_<ContainerAllocator>& v)
  {
    s << indent << "referenceCounter: ";
    Printer<int32_t>::stream(s, indent + "  ", v.referenceCounter);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSDISABLEPUBLISHERRESPONSE_H
