// Generated by gencpp from file rctestpkg/MPC_CCRequest.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_MPC_CCREQUEST_H
#define RCTESTPKG_MESSAGE_MPC_CCREQUEST_H


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
struct MPC_CCRequest_
{
  typedef MPC_CCRequest_<ContainerAllocator> Type;

  MPC_CCRequest_()
    : vr(0.0)
    , u0(0.0)
    , i0(0.0)
    , wv(0.0)
    , wi(0.0)
    , i_max(0.0)
    , i_min(0.0)  {
    }
  MPC_CCRequest_(const ContainerAllocator& _alloc)
    : vr(0.0)
    , u0(0.0)
    , i0(0.0)
    , wv(0.0)
    , wi(0.0)
    , i_max(0.0)
    , i_min(0.0)  {
  (void)_alloc;
    }



   typedef double _vr_type;
  _vr_type vr;

   typedef double _u0_type;
  _u0_type u0;

   typedef double _i0_type;
  _i0_type i0;

   typedef double _wv_type;
  _wv_type wv;

   typedef double _wi_type;
  _wi_type wi;

   typedef double _i_max_type;
  _i_max_type i_max;

   typedef double _i_min_type;
  _i_min_type i_min;




  typedef boost::shared_ptr< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> const> ConstPtr;

}; // struct MPC_CCRequest_

typedef ::rctestpkg::MPC_CCRequest_<std::allocator<void> > MPC_CCRequest;

typedef boost::shared_ptr< ::rctestpkg::MPC_CCRequest > MPC_CCRequestPtr;
typedef boost::shared_ptr< ::rctestpkg::MPC_CCRequest const> MPC_CCRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::MPC_CCRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6d63799ae9c8d735efe96102018bc751";
  }

  static const char* value(const ::rctestpkg::MPC_CCRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6d63799ae9c8d735ULL;
  static const uint64_t static_value2 = 0xefe96102018bc751ULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/MPC_CCRequest";
  }

  static const char* value(const ::rctestpkg::MPC_CCRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 vr\n\
float64 u0\n\
float64 i0\n\
float64 wv\n\
float64 wi\n\
float64 i_max\n\
float64 i_min\n\
";
  }

  static const char* value(const ::rctestpkg::MPC_CCRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.vr);
      stream.next(m.u0);
      stream.next(m.i0);
      stream.next(m.wv);
      stream.next(m.wi);
      stream.next(m.i_max);
      stream.next(m.i_min);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MPC_CCRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::MPC_CCRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::MPC_CCRequest_<ContainerAllocator>& v)
  {
    s << indent << "vr: ";
    Printer<double>::stream(s, indent + "  ", v.vr);
    s << indent << "u0: ";
    Printer<double>::stream(s, indent + "  ", v.u0);
    s << indent << "i0: ";
    Printer<double>::stream(s, indent + "  ", v.i0);
    s << indent << "wv: ";
    Printer<double>::stream(s, indent + "  ", v.wv);
    s << indent << "wi: ";
    Printer<double>::stream(s, indent + "  ", v.wi);
    s << indent << "i_max: ";
    Printer<double>::stream(s, indent + "  ", v.i_max);
    s << indent << "i_min: ";
    Printer<double>::stream(s, indent + "  ", v.i_min);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_MPC_CCREQUEST_H
