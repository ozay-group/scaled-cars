// Generated by gencpp from file rctestpkg/ComputeControlResponse.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_COMPUTECONTROLRESPONSE_H
#define RCTESTPKG_MESSAGE_COMPUTECONTROLRESPONSE_H


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
struct ComputeControlResponse_
{
  typedef ComputeControlResponse_<ContainerAllocator> Type;

  ComputeControlResponse_()
    : u(0.0)  {
    }
  ComputeControlResponse_(const ContainerAllocator& _alloc)
    : u(0.0)  {
  (void)_alloc;
    }



   typedef double _u_type;
  _u_type u;




  typedef boost::shared_ptr< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ComputeControlResponse_

typedef ::rctestpkg::ComputeControlResponse_<std::allocator<void> > ComputeControlResponse;

typedef boost::shared_ptr< ::rctestpkg::ComputeControlResponse > ComputeControlResponsePtr;
typedef boost::shared_ptr< ::rctestpkg::ComputeControlResponse const> ComputeControlResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::ComputeControlResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "988df341e727ad40b85d2b8acf9471e9";
  }

  static const char* value(const ::rctestpkg::ComputeControlResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x988df341e727ad40ULL;
  static const uint64_t static_value2 = 0xb85d2b8acf9471e9ULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/ComputeControlResponse";
  }

  static const char* value(const ::rctestpkg::ComputeControlResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 u\n\
\n\
";
  }

  static const char* value(const ::rctestpkg::ComputeControlResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.u);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ComputeControlResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::ComputeControlResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::ComputeControlResponse_<ContainerAllocator>& v)
  {
    s << indent << "u: ";
    Printer<double>::stream(s, indent + "  ", v.u);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_COMPUTECONTROLRESPONSE_H
