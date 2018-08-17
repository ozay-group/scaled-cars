// Generated by gencpp from file rctestpkg/MPC_LKResponse.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_MPC_LKRESPONSE_H
#define RCTESTPKG_MESSAGE_MPC_LKRESPONSE_H


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
struct MPC_LKResponse_
{
  typedef MPC_LKResponse_<ContainerAllocator> Type;

  MPC_LKResponse_()
    : s(0.0)  {
    }
  MPC_LKResponse_(const ContainerAllocator& _alloc)
    : s(0.0)  {
  (void)_alloc;
    }



   typedef double _s_type;
  _s_type s;




  typedef boost::shared_ptr< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MPC_LKResponse_

typedef ::rctestpkg::MPC_LKResponse_<std::allocator<void> > MPC_LKResponse;

typedef boost::shared_ptr< ::rctestpkg::MPC_LKResponse > MPC_LKResponsePtr;
typedef boost::shared_ptr< ::rctestpkg::MPC_LKResponse const> MPC_LKResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::MPC_LKResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "63117583c3ceae63ea2c1910b9db9c41";
  }

  static const char* value(const ::rctestpkg::MPC_LKResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x63117583c3ceae63ULL;
  static const uint64_t static_value2 = 0xea2c1910b9db9c41ULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/MPC_LKResponse";
  }

  static const char* value(const ::rctestpkg::MPC_LKResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 s\n\
\n\
";
  }

  static const char* value(const ::rctestpkg::MPC_LKResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.s);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MPC_LKResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::MPC_LKResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::MPC_LKResponse_<ContainerAllocator>& v)
  {
    s << indent << "s: ";
    Printer<double>::stream(s, indent + "  ", v.s);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_MPC_LKRESPONSE_H
