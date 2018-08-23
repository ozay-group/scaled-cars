// Generated by gencpp from file rctestpkg/CentralSignal.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_CENTRALSIGNAL_H
#define RCTESTPKG_MESSAGE_CENTRALSIGNAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rctestpkg
{
template <class ContainerAllocator>
struct CentralSignal_
{
  typedef CentralSignal_<ContainerAllocator> Type;

  CentralSignal_()
    : lanekeeping(false)
    , right_lane(false)
    , cruise_control(false)
    , stop(false)
    , command_v(0.0)
    , servo_pwm(0)  {
    }
  CentralSignal_(const ContainerAllocator& _alloc)
    : lanekeeping(false)
    , right_lane(false)
    , cruise_control(false)
    , stop(false)
    , command_v(0.0)
    , servo_pwm(0)  {
  (void)_alloc;
    }



   typedef uint8_t _lanekeeping_type;
  _lanekeeping_type lanekeeping;

   typedef uint8_t _right_lane_type;
  _right_lane_type right_lane;

   typedef uint8_t _cruise_control_type;
  _cruise_control_type cruise_control;

   typedef uint8_t _stop_type;
  _stop_type stop;

   typedef double _command_v_type;
  _command_v_type command_v;

   typedef uint16_t _servo_pwm_type;
  _servo_pwm_type servo_pwm;




  typedef boost::shared_ptr< ::rctestpkg::CentralSignal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::CentralSignal_<ContainerAllocator> const> ConstPtr;

}; // struct CentralSignal_

typedef ::rctestpkg::CentralSignal_<std::allocator<void> > CentralSignal;

typedef boost::shared_ptr< ::rctestpkg::CentralSignal > CentralSignalPtr;
typedef boost::shared_ptr< ::rctestpkg::CentralSignal const> CentralSignalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::CentralSignal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::CentralSignal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rctestpkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'rctestpkg': ['/home/ubuntu/phil_catkin_ws/src/rctestpkg/msg'], 'sensor_msgs': ['/opt/ros/jade/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::CentralSignal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::CentralSignal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::CentralSignal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::CentralSignal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::CentralSignal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::CentralSignal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::CentralSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7d4286309f6e1dd55dc49e54e2e770cf";
  }

  static const char* value(const ::rctestpkg::CentralSignal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7d4286309f6e1dd5ULL;
  static const uint64_t static_value2 = 0x5dc49e54e2e770cfULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::CentralSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/CentralSignal";
  }

  static const char* value(const ::rctestpkg::CentralSignal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::CentralSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool lanekeeping\n\
bool right_lane\n\
bool cruise_control\n\
bool stop\n\
float64 command_v\n\
uint16 servo_pwm\n\
";
  }

  static const char* value(const ::rctestpkg::CentralSignal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::CentralSignal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.lanekeeping);
      stream.next(m.right_lane);
      stream.next(m.cruise_control);
      stream.next(m.stop);
      stream.next(m.command_v);
      stream.next(m.servo_pwm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CentralSignal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::CentralSignal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::CentralSignal_<ContainerAllocator>& v)
  {
    s << indent << "lanekeeping: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.lanekeeping);
    s << indent << "right_lane: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.right_lane);
    s << indent << "cruise_control: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cruise_control);
    s << indent << "stop: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.stop);
    s << indent << "command_v: ";
    Printer<double>::stream(s, indent + "  ", v.command_v);
    s << indent << "servo_pwm: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.servo_pwm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_CENTRALSIGNAL_H
